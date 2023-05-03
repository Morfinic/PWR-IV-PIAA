cmake_minimum_required(VERSION 3.24)
project(PWR_IV_PIAA)

set(CMAKE_CXX_STANDARD 14)

add_executable(main main.cpp include/Movie.cpp include/Movie.h include/quickSort.cpp include/quickSort.h include/mergeSort.cpp include/mergeSort.h include/bucketSort.cpp include/bucketSort.h)