from order_manager import OrderManager


def main():
    manager = OrderManager()
    while True:
        print("Simple Order Matching System")
        print("1. Submit Order")
        print("2. Display Order Book")
        print("3. Display Trades")
        print("4. Exit")
        choice = input("Enter choice: ")

        if choice == "1":
            symbol = input("Enter security symbol: ").upper()
            order_type = input("Enter order type (BUY/SELL): ").upper()
            quantity = int(input("Enter quantity: "))
            price = float(input("Enter price: "))
            manager.submit_order(symbol, order_type, quantity, price)
        elif choice == "2":
            symbol = input("Enter security symbol to view Order Book: ").upper()
            manager.display_order_book(symbol)
        elif choice == "3":
            symbol = input("Enter security symbol to view Trades: ").upper()
            manager.display_trades(symbol)
        elif choice == "4":
            break
        else:
            print("Invalid choice. Please try again.")

    print("Exiting Order Matching System, Thank you!")


if __name__ == "__main__":
    main()
