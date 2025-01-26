#ifndef TRADE_H
#define TRADE_H

#include <chrono>
#include <string>
#include <string_view>

class Trade
{
private:
    std::string m_buyOrderId;
    std::string m_sellOrderId;
    std::string m_symbol;
    double      m_price;
    int         m_quantity;
    std::string m_representation;

    std::string buildRepresentation() const;

public:
    Trade(
        std::string_view buyOrderId,
        std::string_view sellOrderId,
        std::string_view symbol,
        double           price,
        int              quantity
    );

    std::string_view getRepresentation() const { return m_representation; }
};

#endif   // TRADE_H
