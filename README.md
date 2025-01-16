# Order-Matching-System
A basic stock order matching engine to process buy and sell orders, matches them based on predefined rules, and maintains order books for different securities.

## Functional Requirements
1. Users can submit buy or sell orders for a particular stock by specifying:
    - Stock symbol
    - Quantity
    - Price
    - Side (buy or sell)
    - Order ID
    - Timestamp
2. Order Matching Engine matches buy and sell orders based on the following rules:
    - A buy order matches with a sell order if the price of the buy order is greater than or equal to the price of the sell order.
    - The order in which the orders are received is used as a tie-breaker for orders with the same price.
    - If there are multiple sell orders at the same price, the order with the earliest timestamp is matched first.
    - If there are multiple buy orders at the same price, the order with the earliest timestamp is matched first.
3. Order books are maintained for each stock to keep track of the buy and sell orders.
4. Trade records are maintained for each stock, inlcuding:
    - Buy Order ID
    - Sell Order ID
    - Quantity
    - Price
    - Timestamp
5. User Interface:
    - Users can submit buy and sell orders.
    - Users can view the order book for a particular stock.
    - Users can view the trade records for a particular stock.

