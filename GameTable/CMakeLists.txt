project(GameTable)

add_library(GameTable GameTable.cpp GameTable.h)
target_include_directories(GameTable PUBLIC .)

add_subdirectory(test)