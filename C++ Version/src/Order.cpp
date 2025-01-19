#include "Order.h"
#include <sstream>

Order::Order(
    std::string_view symbol, double price, int quantity, OrderType type
)
    : symbol{ symbol },
      price{ price },
      quantity{ quantity },
      type{ type },
      timestamp{ std::chrono::system_clock::now() }
{
    orderID = symbol.data()
              + std::to_string(std::chrono::system_clock::to_time_t(timestamp));
}
