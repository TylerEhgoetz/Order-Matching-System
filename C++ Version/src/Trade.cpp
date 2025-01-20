#include "Trade.h"

Trade::Trade(
    std::string_view buy_order_id,
    std::string_view sell_order_id,
    std::string_view symbol,
    double           price,
    int              quantity
)
    : buy_order_id{ buy_order_id },
      sell_order_id{ sell_order_id },
      symbol{ symbol },
      price{ price },
      quantity{ quantity }
{
    representation = toString();
}
