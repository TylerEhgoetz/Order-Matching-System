#include "OrderBook.h"
#include <iostream>

OrderBook::OrderBook(std::string_view symbol)
    : m_symbol{ symbol }, m_bids{}, m_asks{}, m_trades{}
{}

void OrderBook::addOrder(const Order& order)
{
    if (order.getType() == OrderType::BUY)
    {
        m_bids.push(order);
    }
    else
    {
        m_asks.push(order);
    }
    matchOrders();
}

void OrderBook::matchOrders()
{
    while (!bids_or_ask_empty())
    {
        // Get the bid and ask orders
        Order bidOrder            = m_bids.top();
        Order askOrder            = m_asks.top();

        // Get the best bid and ask prices
        const double bestBidPrice = bidOrder.getPrice();
        const double bestAskPrice = askOrder.getPrice();

        if (bestBidPrice >= bestAskPrice)
        {
            const double tradePrice    = bestAskPrice;
            const int    tradeQuantity = std::min(
                bidOrder.getQuantity(), askOrder.getQuantity()
            );

            Trade trade{ bidOrder.getOrderID().data(),
                         askOrder.getOrderID().data(),
                         m_symbol,
                         tradePrice,
                         tradeQuantity };

            m_trades.push_back(trade);
            std::cout << "Trade Executed: " << trade.getRepresentation()
                      << '\n';

            m_asks.pop();
            m_bids.pop();

            int remainingBidQuantity = bidOrder.getQuantity() - tradeQuantity;
            int remainingAskQuantity = askOrder.getQuantity() - tradeQuantity;

            if (remainingBidQuantity > 0)
            {
                Order newBid = bidOrder;
                newBid.setQuantity(remainingBidQuantity);
                m_bids.push(newBid);
            }

            if (remainingAskQuantity > 0)
            {
                Order newAsk = askOrder;
                newAsk.setQuantity(remainingAskQuantity);
                m_asks.push(newAsk);
            }
        }
        else
        {
            break;
        }
    }
}

void OrderBook::displayOrderBook() const
{
    std::cout << "Order Book for " << m_symbol << '\n';
    std::cout << "Buy Orders:\n";
    std::priority_queue<Order, std::vector<Order>, BuyOrderComparator>
        bidsCopy = m_bids;
    while (!bidsCopy.empty())
    {
        std::cout << bidsCopy.top().getRepresentation() << '\n';
        bidsCopy.pop();
    }

    std::cout << "Sell Orders:\n";
    std::priority_queue<Order, std::vector<Order>, SellOrderComparator>
        asksCopy = m_asks;
    while (!asksCopy.empty())
    {
        std::cout << asksCopy.top().getRepresentation() << '\n';
        asksCopy.pop();
    }
}

void OrderBook::displayTrades() const
{
    std::cout << "Trades for " << m_symbol << '\n';
    for (const Trade& trade : m_trades)
    {
        std::cout << trade.getRepresentation() << '\n';
    }
}
