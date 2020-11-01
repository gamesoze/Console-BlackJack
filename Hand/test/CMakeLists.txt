project(Hand_test)

add_executable(Hand_test main_test.cpp)

target_link_libraries(Hand_test Hand gtest Cards Rools)

enable_testing()
add_test(
        NAME Hand_test
        COMMAND Hand_test
)