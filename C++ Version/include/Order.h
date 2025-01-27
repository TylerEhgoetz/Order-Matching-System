#ifndef ORDER_H
#define ORDER_H

#include <chrono>
#include <string>

enum class OrderType
{
    BUY,
    SELL
};

class Order
{
private:
    std::string m_orderId;
    std::string m_symbol;
    double      m_price;
    int         m_quantity;
    OrderType   m_type;
    std::time_t m_timestamp;

    const std::string buildRepresentation() const;

public:
    Order(std::string_view symbol, double price, int quantity, OrderType type);

    const std::string getRepresentation() const
    {
        return buildRepresentation();
    }

    OrderType        getType() const { return m_type; }
    double           getPrice() const { return m_price; }
    int              getQuantity() const { return m_quantity; }
    void             setQuantity(int newQuantity) { m_quantity = newQuantity; }
    std::string_view getOrderID() const { return m_orderId; }
    std::time_t      getTimestamp() const { return m_timestamp; }
};

#endif   // ORDER_H
