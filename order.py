from datetime import datetime
from order_type import OrderType


class Order:
    def __init__(self, symbol: str, quantity: int, price: float, order_type: OrderType):
        self.symbol = symbol
        self.quantity = quantity
        self.price = price
        self.is_buy_order = order_type
        self.timestamp = datetime.now()
        self.order_id = self.generate_order_id()

    def __repr__(self):
        return f"Order({self.symbol}, {self.quantity}, {self.price}, {self.is_buy_order}, {self.timestamp})"

    def generate_order_id(self):
        return f"{self.symbol}-{self.timestamp}"
