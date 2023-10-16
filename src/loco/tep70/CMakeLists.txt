set(MOD_NAME tep70)

include_directories(include model)

link_libraries(cabin_api)

add_library(${MOD_NAME}_common OBJECT tep70.cc)

add_library(${MOD_NAME} MODULE dll.cc)
target_link_options(${MOD_NAME} PRIVATE "-static")
target_link_libraries(${MOD_NAME}
	PRIVATE
	tep70_common)

# default_cabin
# cabin_context)
