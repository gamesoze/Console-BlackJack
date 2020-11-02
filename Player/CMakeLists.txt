project(Player)

add_library(Player
        Player.cpp Player.h
        HumanPlayer.cpp HumanPlayer.h
        AI.cpp AI.h)

target_include_directories(Player PUBLIC .)

add_subdirectory(test)