import heapq
from order import Order
from order_type import OrderType
from trade import Trade
from order_book_enums import OrderBookSide


class OrderBook:
    def __init__(self, symbol: str):
        self.symbol = symbol
        self.bids = []  # Highest price first (max heap)
        self.asks = []  # Lowest price first (min heap)
        self.trades = []

    def add_order(self, order: Order) -> None:
        if order.order_type == OrderType.BUY.value:
            heapq.heappush(self.bids, (-order.price, order.timestamp, order))
        else:
            heapq.heappush(self.asks, (order.price, order.timestamp, order))
        self.match_orders()

    def match_orders(self) -> None:
        while self.bids and self.asks:
            best_bid, bid_time, bid_order = self.bids[0]
            best_ask, ask_time, ask_order = self.asks[0]

            best_bid = -best_bid

            if best_bid >= best_ask:
                trade_price = best_ask
                trade_quantity = min(bid_order.quantity, ask_order.quantity)

                trade = Trade(
                    bid_order.order_id,
                    ask_order.order_id,
                    self.symbol,
                    trade_quantity,
                    trade_price,
                )
                self.trades.append(trade)
                print(f"Trade executed: {trade}")

                bid_order.quantity -= trade_quantity
                ask_order.quantity -= trade_quantity

                heapq.heappop(self.bids)
                if bid_order.quantity > 0:
                    heapq.heappush(self.bids, (-best_bid, bid_time, bid_order))

                heapq.heappop(self.asks)
                if ask_order.quantity > 0:
                    heapq.heappush(self.asks, (best_ask, ask_time, ask_order))
            else:
                break

    def get_trades(self) -> list:
        return self.trades

    def get_order_book(self) -> dict:
        return {OrderBookSide.BID.value: self.bids, OrderBookSide.ASK.value: self.asks}
