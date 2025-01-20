#ifndef TRADE_H
#define TRADE_H

#include <chrono>
#include <string>
#include <string_view>

class Trade
{
private:
    std::string buy_order_id;
    std::string sell_order_id;
    std::string symbol;
    double      price;
    int         quantity;

    std::string_view representation;

    std::string_view toString() const
    {
        return "Trade: " + buy_order_id + " -> " + sell_order_id + " " + symbol
               + " " + std::to_string(quantity) + " @ " + std::to_string(price);
    }

public:
    Trade(
        std::string_view buy_order_id,
        std::string_view sell_order_id,
        std::string_view symbol,
        double           price,
        int              quantity
    );

    std::string_view getRepresentation() const { return representation; }
};

#endif   // TRADE_H
