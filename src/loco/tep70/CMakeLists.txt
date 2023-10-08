include_directories(include)

add_library(tep70_common OBJECT tep70.cc)

add_library(tep70 MODULE dll.cc)
target_link_options(tep70 PRIVATE "-static")
target_link_libraries(tep70
	PRIVATE
		tep70_common
		cabin_api)
		#default_cabin
		#cabin_context)
