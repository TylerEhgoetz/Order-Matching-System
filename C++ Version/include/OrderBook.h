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

class OrderBook
{
private:
    std::priority_queue<Order>                                          bids;
    std::priority_queue<Order, std::vector<Order>, std::greater<Order>> asks;
    std::vector<Trade>                                                  trades;
    std::string                                                         symbol;
    std::unordered_map<std::string, std::vector<Order>> orderBook;

public:
    OrderBook(std::string_view symbol);

    void addOrder(const Order& order);
    void matchOrders();
    void displayOrderBook() const;
    void displayTrades() const;

    bool empty() const { return bids.empty() && asks.empty(); }
};

#endif   // ORDERBOOK_H
