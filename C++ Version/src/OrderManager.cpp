#include "OrderManager.h"
#include <iostream>

OrderManager::OrderManager()
    : m_orderBooks{}
{}

void OrderManager::addOrder(
    std::string symbol, OrderType orderType, double price, int quantity
)
{
    std::string key{ symbol };
    if (m_orderBooks.find(key) == m_orderBooks.end())
    {
        m_orderBooks[key] = std::make_unique<OrderBook>(symbol);
    }

    Order newOrder{ symbol, price, quantity, orderType };
    m_orderBooks[key]->addOrder(newOrder);
    std::cout << "Order Added: " << newOrder.getRepresentation() << '\n';
}

void OrderManager::viewOrderBook(std::string_view symbol) const
{
    if (m_orderBooks.find(symbol.data()) == m_orderBooks.end())
    {
        std::cout << "Order book for " << symbol << " does not exist\n";
        return;
    }
    m_orderBooks.at(symbol.data())->displayOrderBook();
}

void OrderManager::viewTrades(std::string_view symbol) const
{
    if (m_orderBooks.find(symbol.data()) == m_orderBooks.end())
    {
        std::cout << "Order book for " << symbol << " does not exist\n";
        return;
    }
    m_orderBooks.at(symbol.data())->displayTrades();
}
