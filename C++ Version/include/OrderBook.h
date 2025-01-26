#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include "Order.h"
#include "Trade.h"
#include <algorithm>
#include <queue>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

struct BuyOrderComparator
{
    bool operator()(const Order& lhs, const Order& rhs) const
    {
        if (lhs.getPrice() == rhs.getPrice())
        {
            return lhs.getTimestamp() < rhs.getTimestamp();
        }
        return lhs.getPrice() < rhs.getPrice();
    }
};

struct SellOrderComparator
{
    bool operator()(const Order& lhs, const Order& rhs) const
    {
        if (lhs.getPrice() == rhs.getPrice())
        {
            return lhs.getTimestamp() < rhs.getTimestamp();
        }
        return lhs.getPrice() > rhs.getPrice();
    }
};

class OrderBook
{
private:
    std::string                                                        m_symbol;
    std::priority_queue<Order, std::vector<Order>, BuyOrderComparator> m_bids;
    std::priority_queue<Order, std::vector<Order>, SellOrderComparator> m_asks;
    std::vector<Trade> m_trades;

public:
    OrderBook(std::string_view symbol);

    void addOrder(const Order& order);
    void matchOrders();
    void displayOrderBook() const;
    void displayTrades() const;

    bool bids_or_ask_empty() const { return m_bids.empty() || m_asks.empty(); }
};

#endif   // ORDERBOOK_H
