project(Rools_test)

add_executable(Rools_test main_test.cpp)

target_link_libraries(Rools_test Rools gtest)

enable_testing()
add_test(
        NAME Rools_test
        COMMAND Rools_test
)