from datetime import datetime
from order_type import OrderType


class Order:
    def __init__(self, symbol: str, quantity: int, price: float, order_type: OrderType):
        self.symbol = symbol
        self.quantity = quantity
        self.price = price
        self.order_type = order_type
        self.timestamp = datetime.now()
        self.order_id = self.generate_order_id()

    def __repr__(self):
        return f"{self.order_type.lower().capitalize()} {self.symbol} {self.quantity} @ {self.price} ({self.timestamp})"

    def __lt__(self, other):
        if self.order_type == other.order_type:
            if self.price == other.price:
                return self.timestamp < other.timestamp
            return self.price < other.price
        return False

    def generate_order_id(self):
        return f"{self.symbol}-{self.timestamp}"
