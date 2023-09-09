include_directories(include)

add_library(tep70 MODULE tep70.cpp)
target_link_libraries(tep70 PRIVATE cabin_api)

add_executable(uvtest uvtest.cc)
target_link_libraries(uvtest PRIVATE libuv::uv_a)

add_subdirectory(api)
