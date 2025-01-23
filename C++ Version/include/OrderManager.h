#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H

#include "OrderBook.h"
#include <memory>
#include <string>
#include <string_view>
#include <unordered_map>

class OrderManager
{
private:
    std::unordered_map<std::string, std::unique_ptr<OrderBook>> orderBooks;

public:
    OrderManager() = default;

    void addOrder(std::string_view symbol, const Order& order);
    void viewOrderBook(std::string_view symbol) const;
    void viewTrades(std::string_view symbol) const;
};

#endif   // ORDERMANAGER_H
