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
    std::string      orderID;
    std::string      symbol;
    double           price;
    int              quantity;
    OrderType        type;
    std::time_t      timestamp;
    std::string_view representation;

    std::string_view toString() const
    {
        return "Order: " + symbol + " " + type.capatalize() + " "
               + std::to_string(quantity) + " @ " + std::to_string(price);
    }

public:
    Order(std::string_view symbol, double price, int quantity, OrderType type);

    std::string_view getRepresentation() const { return representation; }

    void operator<(const Order& other) const;
};

#endif   // ORDER_H
