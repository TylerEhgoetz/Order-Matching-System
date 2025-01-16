from datetime import datetime


class Trade:
    def __init__(
        self,
        buy_order_id: str,
        sell_order_id: str,
        symbol: str,
        quantity: int,
        price: float,
    ):
        self.buy_order_id = buy_order_id
        self.sell_order_id = sell_order_id
        self.symbol = symbol
        self.quantity = quantity
        self.price = price
        self.timestamp = datetime.now()

    def __repr__(self):
        return f"Executed Trade for {self.symbol}: {self.quantity} @ {self.price} ({self.timestamp})"
