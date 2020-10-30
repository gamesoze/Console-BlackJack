project(Cards_test)

add_executable(Cards_test main_test.cpp)

target_link_libraries(Cards_test Cards gtest)

enable_testing()
add_test(
        NAME Cards_test
        COMMAND Cards_test
)