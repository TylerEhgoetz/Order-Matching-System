#include "Trade.h"
#include <iomanip>
#include <sstream>

Trade::Trade(
    std::string_view buyOrderId,
    std::string_view sellOrderId,
    std::string_view symbol,
    double           price,
    int              quantity
)
    : m_buyOrderId{ buyOrderId },
      m_sellOrderId{ sellOrderId },
      m_symbol{ symbol },
      m_price{ price },
      m_quantity{ quantity },
      m_representation{}
{
    m_representation = buildRepresentation();
}

std::string Trade::buildRepresentation() const
{
    std::ostringstream oss;
    oss << "Trade: " << m_buyOrderId << " -> " << m_sellOrderId << " "
        << m_symbol << " " << m_quantity << " @ " << std::fixed
        << std::setprecision(2) << m_price;
    return oss.str();
}
