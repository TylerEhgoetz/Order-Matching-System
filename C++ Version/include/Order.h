#ifndef ORDER_H
#define ORDER_H

#include <chrono>
#include <string>
#include <string_view>

class Order
{
public:
    struct OrderType
    {
        enum Type
        {
            BUY,
            SELL
        };

        std::string lower() const { return type == BUY ? "buy" : "sell"; }

        std::string capatalize() const { return type == BUY ? "Buy" : "Sell"; }

        Type type;
    };

private:
    std::string orderID;
    std::string symbol;
    double      price;
    int         quantity;
    OrderType   type;
    std::time_t timestamp;

public:
    Order(std::string_view symbol, double price, int quantity, OrderType type);

    std::string toString() const;

    void operator<(const Order& other) const;
};

#endif   // ORDER_H
