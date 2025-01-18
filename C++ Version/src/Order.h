#ifndef ORDER_H
#define ORDER_H

#include "Random.h"
#include <chrono>
#include <string>
#include <string_view>

class Order
{
public:
    enum OrderType
    {
        BUY,
        SELL
    };

private:
    std::string                           orderID;
    std::string                           symbol;
    double                                price;
    int                                   quantity;
    OrderType                             type;
    std::chrono::system_clock::time_point timestamp;

public:
    Order(std::string_view symbol, double price, int quantity, OrderType type);

    std::string_view                      getOrderID() const;
    std::string_view                      getSymbol() const;
    double                                getPrice() const;
    int                                   getQuantity() const;
    OrderType                             getType() const;
    std::chrono::system_clock::time_point getTimestamp() const;
    std::string_view                      getTypeString() const;
    std::string_view                      getTimestampString() const;
    std::string_view                      toString() const;

    void operator<(const Order& other) const;
};

#endif   // ORDER_H
