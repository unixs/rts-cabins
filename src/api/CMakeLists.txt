include_directories(include)
link_libraries(libuv::uv_a)

add_library(main_loop OBJECT main_loop.cc)

add_library(mrb_default_cb OBJECT mrb_default_cb.c)

set(LIB_OBJECTS)
list(APPEND LIB_OBJECTS
	$<TARGET_OBJECTS:main_loop>)

add_library(cabin_api STATIC ${LIB_OBJECTS})
target_link_libraries(cabin_api INTERFACE libuv::uv_a)
target_include_directories(cabin_api INTERFACE include)

add_subdirectory(mrb_api)
