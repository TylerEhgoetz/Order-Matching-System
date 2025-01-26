cmake_minimum_required(VERSION 3.20)
project(OrderMatchingSystem)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include_directories(include)

set(SOURCES
    src/main.cpp
    src/Order.cpp
    src/Trade.cpp
    src/OrderBook.cpp
    src/OrderManager.cpp
)

add_executable(OrderMatchingSystem ${SOURCES})

