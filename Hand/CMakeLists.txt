project(Hand)

add_library(Hand Hand.h Hand.cpp)
target_include_directories(Hand PUBLIC .)

add_subdirectory(test)