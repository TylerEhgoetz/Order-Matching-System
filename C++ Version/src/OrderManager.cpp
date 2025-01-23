#include "OrderManager.h"
#include <iostream>

void OrderManager::addOrder(
    std::string_view symbol,
    Order::OrderType orderType,
    double           price,
    int              quantity
)
{
    Order       order{ symbol, price, quantity, orderType };
    std::string key{ symbol.data() };
    if (orderBooks.find(key) == orderBooks.end())
    {
        orderBooks[key] = std::make_unique<OrderBook>(symbol);
    }

    orderBooks[key]->addOrder(order);
    std::cout << "Order Added: " << order.getRepresentation() << '\n';
}

void OrderManager::viewOrderBook(std::string_view symbol) const
{
    if (orderBooks.find(symbol.data()) == orderBooks.end())
    {
        std::cout << "Order book for " << symbol << " does not exist\n";
        return;
    }
    orderBooks.at(symbol.data())->displayOrderBook();
}

void OrderManager::viewTrades(std::string_view symbol) const
{
    if (orderBooks.find(symbol.data()) == orderBooks.end())
    {
        std::cout << "Order book for " << symbol << " does not exist\n";
        return;
    }
    orderBooks.at(symbol.data())->displayTrades();
}
