from order_book import OrderBook
from order_type import OrderType
from order_book_enums import OrderBookSide
from order import Order


class OrderManager:
    def __init__(self):
        self.order_books = {}

    def submit_order(
        self, symbol: str, order_type: OrderType, quantity: int, price: float
    ):
        order = Order(symbol, quantity, price, order_type)
        if symbol not in self.order_books:
            self.order_books[symbol] = OrderBook(symbol)
        self.order_books[symbol].add_order(order)
        print(f"Order submitted: {order}")

    def display_order_book(self, symbol: str):
        if symbol in self.order_books:
            order_book = self.order_books[symbol].get_order_book()
            print(f"Buy Orders for {symbol}:")
            for order in order_book[OrderBookSide.BID.value]:
                print(order)
            print(f"Sell Orders for {symbol}:")
            for order in order_book[OrderBookSide.ASK.value]:
                print(order)
        else:
            print(f"No orders found for {symbol}")

    def display_trades(self, symbol: str):
        if symbol in self.order_books:
            trades = self.order_books[symbol].get_trades()
            print(f"Trades for {symbol}:")
            for trade in trades:
                print(trade)
        else:
            print(f"No trades found for {symbol}")
