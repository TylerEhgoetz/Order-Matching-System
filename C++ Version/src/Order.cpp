#include "Order.h"
#include <sstream>

Order::Order(
    std::string_view symbol, double price, int quantity, OrderType type
)
    : symbol{ symbol },
      price{ price },
      quantity{ quantity },
      type{ type },
      timestamp{
          std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())
      }
{
    orderID        = symbol.data() + std::to_string(timestamp);
    representation = toString();
}

bool Order::operator<(const Order& other) const
{
    if (type.type == other.type.type)
    {
        if (price == other.price)
            return timestamp < other.timestamp;
        return price < other.price;
    }
    return false;
}
