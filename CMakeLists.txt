cmake_minimum_required(VERSION 3.16)
project(OOP_lab2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

enable_testing()

add_executable(main main.cpp string.cpp)
add_executable(string_tests gtests.cpp string.cpp)
target_link_libraries(string_tests PRIVATE GTest::gtest_main)
add_test(NAME string_tests COMMAND string_tests)
