from order_manager import OrderManager
from CLI_options import CLIOptions
from order_type import OrderType


def handle_submit_order(manager: OrderManager):
    symbol = input("Enter security symbol: ").upper()
    while True:
        order_type = input("Enter order type (BUY/SELL): ").upper() == "BUY"
        if order_type == OrderType.BUY.name:
            order_type = OrderType.BUY.value
            break
        elif order_type == OrderType.SELL.name:
            order_type = OrderType.SELL.value
            break
        else:
            print("Invalid order type. Please try again.")
    quantity = int(input("Enter quantity: "))
    price = float(input("Enter price: "))
    manager.submit_order(symbol, order_type, quantity, price)


def main():
    manager = OrderManager()
    while True:
        print("Simple Order Matching System")
        print(f"{CLIOptions.SUBMIT_ORDER.value}. Submit Order")
        print(f"{CLIOptions.DISPLAY_ORDER_BOOK.value}. Display Order Book")
        print(f"{CLIOptions.DISPLAY_TRADES.value}. Display Trades")
        print(f"{CLIOptions.EXIT.value}. Exit")
        choice = input("Enter choice: ")

        if choice == str(CLIOptions.SUBMIT_ORDER.value):
            handle_submit_order(manager)
        elif choice == str(CLIOptions.DISPLAY_ORDER_BOOK.value):
            symbol = input("Enter security symbol to view Order Book: ").upper()
            manager.display_order_book(symbol)
        elif choice == str(CLIOptions.DISPLAY_TRADES.value):
            symbol = input("Enter security symbol to view Trades: ").upper()
            manager.display_trades(symbol)
        elif choice == str(CLIOptions.EXIT.value):
            break
        else:
            print("Invalid choice. Please try again.")

    print("Exiting Order Matching System, Thank you!")


if __name__ == "__main__":
    main()
