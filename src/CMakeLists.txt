include_directories(include)

link_libraries(Mruby::Mruby)

add_library(mrb_locomotive
	OBJECT mrb_locomotive.c)


#add_library(mrb_cabin_interface
#	OBJECT mrb_cabin_interface.c)


#add_library(default_cabin
#	OBJECT default_cabin.c)
#target_link_libraries(default_cabin
#	PRIVATE
#		mrb_default_cb)


add_library(cabin_context
	OBJECT cabin_context.c)
target_link_libraries(cabin_context
	PUBLIC
		default_cabin)


add_library(tep70 MODULE tep70.cc)
target_link_options(tep70 PRIVATE "-static")
target_link_libraries(tep70
	PRIVATE
		cabin_api
		default_cabin
		cabin_context)


add_executable(uvtest uvtest.cc)
target_link_options(uvtest PRIVATE "-static")
target_link_libraries(uvtest
	PRIVATE
		cabin_api
		mrb_default_cb
		default_cabin
		cabin_context)


add_subdirectory(api)
