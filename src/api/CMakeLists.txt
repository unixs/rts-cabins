include_directories(include)
link_libraries(libuv::uv_a)

add_library(main_loop OBJECT main_loop.cc)

add_library(cabin_context OBJECT cabin_context.c)
target_link_libraries(cabin_context
	PUBLIC
		mrb_ts)

set(LIB_OBJECTS)
list(APPEND LIB_OBJECTS
	$<TARGET_OBJECTS:main_loop>)

add_library(cabin_api STATIC ${LIB_OBJECTS})
target_link_libraries(cabin_api INTERFACE libuv::uv_a)
target_include_directories(cabin_api INTERFACE include)

add_subdirectory(mrb_api)
