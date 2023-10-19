link_libraries(cabin_api)
include_directories(model)

stf_parser_command(model/cab.sd)

add_library(2te116 MODULE dll.cpp)
target_sources(2te116 PRIVATE model/cab.hpp)
target_link_options(2te116 PRIVATE "-static")
