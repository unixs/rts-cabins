include_directories(include)

add_library(tep70 MODULE tep70.cpp)
target_link_options(tep70 PRIVATE "-static")
target_link_libraries(tep70 PRIVATE cabin_api)

add_executable(uvtest uvtest.cc)
target_link_options(uvtest PUBLIC "-static")
target_link_libraries(uvtest PRIVATE cabin_api)

add_subdirectory(api)
