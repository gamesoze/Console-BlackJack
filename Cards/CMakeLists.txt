project(Cards)

add_library(Cards Cards.cpp Cards.h)
target_include_directories(Cards PUBLIC .)

add_subdirectory(test)
