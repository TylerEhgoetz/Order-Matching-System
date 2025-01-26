#include "Order.h"
#include <iomanip>
#include <sstream>

std::string generateOrderID(std::string_view symbol, std::time_t timestamp)
{
    std::ostringstream oss;
    oss << symbol << "_" << timestamp;
    return oss.str();
}

Order::Order(
    std::string_view symbol, double price, int quantity, OrderType type
)
    : m_orderId{},
      m_symbol{ symbol },
      m_price{ price },
      m_quantity{ quantity },
      m_type{ type },
      m_timestamp{
          std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())
      },
      m_representation{}
{
    m_orderId        = generateOrderID(symbol, m_timestamp);
    m_representation = buildRepresentation();
}

std::string Order::buildRepresentation() const
{
    std::ostringstream oss;
    oss << "Order: " << m_symbol << " "
        << (m_type == OrderType::BUY ? "Buy" : "Sell") << " " << m_quantity
        << " @ " << std::fixed << std::setprecision(2) << m_price;
    return oss.str();
}

bool Order::operator<(const Order& other) const
{
    // For priority_queue, we define less-than based on price and timestamp
    // Higher price has higher priority for BUY orders
    // Lower price has higher priority for SELL orders
    // Time priority: earlier orders have higher priority

    if (m_type == other.m_type)
    {
        if (m_price == other.m_price)
        {
            return m_timestamp
                   > other.m_timestamp;   // Earlier orders have higher priority
        }
        if (m_type == OrderType::BUY)
        {
            return m_price
                   < other.m_price;   // Higher price has higher priority
        }
        else
        {
            return m_price > other.m_price;   // Lower price has higher priority
        }
    }
    // If different types, BUY orders have higher priority
    return m_type == OrderType::BUY;
}
