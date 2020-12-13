project(GameTable_test)

add_executable(GameTable_test main_test.cpp)

target_link_libraries(GameTable_test Hand gtest Cards Rools)

enable_testing()
add_test(
        NAME GameTable_test
        COMMAND GameTable_test
)