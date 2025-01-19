#ifndef ORDER_H
#define ORDER_H

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

    std::string_view toString() const;

    void operator<(const Order& other) const;
};

#endif   // ORDER_H
