cmake_minimum_required(VERSION 3.17)
project(Console-BlackJack)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Cards)
add_subdirectory(modules/googletest)
add_subdirectory(Hand)
add_subdirectory(Rools)
add_subdirectory(Player)
add_subdirectory(GameTable)

add_executable(Console-BlackJack main.cpp)

target_link_libraries(Console-BlackJack GameTable Player Hand Rools Cards)
