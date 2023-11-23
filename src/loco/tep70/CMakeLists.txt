set(MOD_NAME tep70)

include_directories(include model)

link_libraries(cabin_api mrb_api)

stf_parser_command(model/Cab.sd)
stf_parser_command(model/state.xml)

add_library(${MOD_NAME}_common OBJECT tep70.cc)
add_library(${MOD_NAME}_debug OBJECT debug.cpp)

add_library(${MOD_NAME} MODULE dll.cc)
target_sources(${MOD_NAME} PRIVATE model/Cab.hpp)
target_link_options(${MOD_NAME} PRIVATE "-static")
target_link_libraries(${MOD_NAME}
	PRIVATE
	${MOD_NAME}_common)

# default_cabin
# cabin_context)
