#include "OrderBook.h"
#include <iostream>

OrderBook::OrderBook(std::string_view symbol)
    : symbol{ symbol }
{}

void OrderBook::addOrder(const Order& order)
{
    if (order.getType() == Order::OrderType::BUY)
    {
        bids.push(order);
    }
    else
    {
        asks.push(order);
    }
    matchOrders();
}

void OrderBook::matchOrders()
{
    while (!empty())
    {
        // Get the bid and ask orders
        Order bidOrder         = bids.top();
        Order askOrder         = asks.top();

        // Get the best bid and ask prices
        const int bestBidPrice = bidOrder.getPrice();
        const int bestAskPrice = askOrder.getPrice();

        if (bestBidPrice >= bestAskPrice)
        {
            const int tradePrice    = bestAskPrice;
            const int tradeQuantity = std::min(
                bidOrder.getQuantity(), askOrder.getQuantity()
            );

            Trade trade{ bidOrder.getOrderID(),
                         askOrder.getOrderID(),
                         symbol,
                         tradePrice,
                         tradeQuantity };

            trades.push_back(trade);
            std::cout << "Trade Executed: " << trade.getRepresentation()
                      << '\n';

            bidOrder.setQuantity(bidOrder.getQuantity() - tradeQuantity);
            askOrder.setQuantity(askOrder.getQuantity() - tradeQuantity);

            bids.pop();
            if (bidOrder.getQuantity() > 0)
            {
                bids.push(bidOrder);
            }

            asks.pop();
            if (askOrder.getQuantity() > 0)
            {
                asks.push(askOrder);
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
    std::cout << "Order Book for " << symbol << '\n';
    std::cout << "Buy Orders:\n";
    std::priority_queue<Order> bidsCopy = bids;
    while (!bidsCopy.empty())
    {
        std::cout << bidsCopy.top().getRepresentation() << '\n';
        bidsCopy.pop();
    }

    std::cout << "Sell Orders:\n";
    std::priority_queue<Order, std::vector<Order>, std::greater<Order>>
        asksCopy = asks;
    while (!asksCopy.empty())
    {
        std::cout << asksCopy.top().getRepresentation() << '\n';
        asksCopy.pop();
    }
}

void OrderBook::displayTrades() const
{
    std::cout << "Trades for " << symbol << '\n';
    for (const Trade& trade : trades)
    {
        std::cout << trade.getRepresentation() << '\n';
    }
}
