project(Player_test)

add_executable(Player_test main_test.cpp)

target_link_libraries(Player_test Hand gtest Cards Rools)

enable_testing()
add_test(
        NAME Hand_test
        COMMAND Hand_test
)