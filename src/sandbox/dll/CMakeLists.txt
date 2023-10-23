include_directories(.)

add_library(somefunc MODULE dll.cpp)

add_executable(dll_test main.cpp)
