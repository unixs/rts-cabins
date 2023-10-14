include_directories(include)
link_libraries(libuv::uv_a)

add_library(contextptr
	OBJECT contextptr.cc)
target_link_libraries(contextptr
	PUBLIC mrb_api)

add_library(main_loop
	OBJECT main_loop.cc)

add_library(context
	OBJECT context.cc)
target_link_libraries(context
	PUBLIC mrb_api)

add_library(context_pool
	OBJECT context_pool.cc)
target_link_libraries(context_pool
	PUBLIC context)

set(LIB_OBJECTS)
list(APPEND LIB_OBJECTS
	$<TARGET_OBJECTS:main_loop>
	$<TARGET_OBJECTS:context_pool>
	$<TARGET_OBJECTS:context>
	$<TARGET_OBJECTS:contextptr>)

add_library(cabin_api STATIC ${LIB_OBJECTS})
target_link_libraries(cabin_api
	INTERFACE libuv::uv_a
	INTERFACE mrb_api)
target_include_directories(cabin_api INTERFACE include)

add_subdirectory(mrb_api)
