include_directories(include)

link_libraries(Mruby::Mruby)

#add_library(mrb_locomotive
#	OBJECT mrb_locomotive.c)


#add_library(mrb_cabin_interface
#	OBJECT mrb_cabin_interface.c)


#add_library(default_cabin
#	OBJECT default_cabin.c)
#target_link_libraries(default_cabin
#	PRIVATE
#		mrb_default_cb)


add_executable(uvtest uvtest.cc)
target_link_options(uvtest PRIVATE "-static")
target_link_libraries(uvtest
	PRIVATE
		cabin_api
		mrb_default_callbacks
		default_cabin
		cabin_context)

add_executable(dlltest dlltest.cc)
#target_link_options(parser_test PRIVATE "-static")
#target_link_libraries(parser_test
#	PRIVATE
#		cabin_api)

add_subdirectory(api)
add_subdirectory(loco)
