from collections import deque
from order import Order


class OrderBook:
    def __init__(self, symbol):
        self.symbol = symbol
        self.bids = deque()  # Highest price first
        self.asks = deque()  # Lowest price first
        self.trades = []

    def add_order(self, order: Order) -> None:
        if order.is_buy_order:
            self.bids.append(order)
        else:
            self.asks.append(order)

    def match_orders(self) -> None:
        pass

    def get_trades(self) -> list:
        return self.trades

    def get_order_book(self) -> dict:
        return {"bids": self.bids, "asks": self.asks}
