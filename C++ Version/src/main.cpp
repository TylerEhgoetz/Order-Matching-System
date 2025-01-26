#include "OrderManager.h"
#include <iostream>
#include <string>

int main()
{
    OrderManager orderManager;

    while (true)
    {
        std::cout << "\n Simple Order Matching System\n";
        std::cout << "1. Submit Order\n";
        std::cout << "2. View Order Book\n";
        std::cout << "3. View Trades\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1: {
            std::string symbol;
            double      price;
            int         quantity;
            std::string orderType;

            std::cout << "Enter Symbol: ";
            std::cin >> symbol;
            std::cout << "Enter Price: ";
            std::cin >> price;
            std::cout << "Enter Quantity: ";
            std::cin >> quantity;
            std::cout << "Enter Order Type (buy/sell): ";
            std::cin >> orderType;

            OrderType type = orderType == "buy" ? OrderType::BUY
                                                : OrderType::SELL;
            orderManager.addOrder(symbol, type, price, quantity);

            break;
        }
        case 2: {
            std::string symbol;
            std::cout << "Enter Symbol: ";
            std::cin >> symbol;
            orderManager.viewOrderBook(symbol);
            break;
        }
        case 3: {
            std::string symbol;
            std::cout << "Enter Symbol: ";
            std::cin >> symbol;
            orderManager.viewTrades(symbol);
            break;
        }
        case 4: {
            std::cout << "Exiting...\n";
            return 0;
        }
        default: std::cout << "Invalid choice\n";
        }
    }
}
