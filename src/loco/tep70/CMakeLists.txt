include_directories(include)

add_library(switches OBJECT switches.cc)

add_library(tep70 MODULE tep70.cpp)
target_link_libraries(tep70
  PRIVATE
  switches)