project(Rools)

add_library(Rools Rools.cpp Rools.h)
target_include_directories(Rools PUBLIC .)

add_subdirectory(test)