cmake_minimum_required(VERSION 3.24)
project(PWR_IV_PIAA)

set(CMAKE_CXX_STANDARD 14)

add_executable(main345 main345.cpp)
add_executable(main12 main12.cpp)
add_executable(main6 main6.cpp)
add_executable(main7 main7.cpp)
add_executable(main8 main8.cpp zad8/Node.cpp zad8/LinkedList.cpp zad8/Queue.cpp)
add_executable(main9 main9.cpp zad9/Node.cpp zad9/Dequeue.cpp)