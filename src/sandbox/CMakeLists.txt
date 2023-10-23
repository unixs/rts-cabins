add_executable(uvtest uvtest.cc)
target_link_options(uvtest PRIVATE "-static")
target_link_libraries(uvtest
	PRIVATE
	cabin_api
	mrb_default_callbacks
	default_cabin
	cabin_context)

add_executable(dlltest dlltest.cc)
target_link_options(dlltest PRIVATE "-static")
target_link_libraries(dlltest
	PRIVATE
	tep70_common
	cabin_api)

# target_link_options(parser_test PRIVATE "-static")
# target_link_libraries(parser_test
# PRIVATE
# cabin_api)
add_subdirectory(dll)
