set(MOD_NAME 2te116)

link_libraries(cabin_api)
include_directories(include model)
add_compile_definitions(DIESEL)

stf_parser_command(model/cab.sd)
stf_parser_command(model/state.xml)

add_library(${MOD_NAME}_light OBJECT light.cc)

add_library(${MOD_NAME}_dizel OBJECT dizel.cc)
target_sources(${MOD_NAME}_dizel PRIVATE model/cab.hpp)

add_library(${MOD_NAME} MODULE dll.cpp)
target_sources(${MOD_NAME} PRIVATE model/cab.hpp)
target_sources(${MOD_NAME} PRIVATE model/state.hpp)
target_link_libraries(${MOD_NAME}
	PRIVATE
	${MOD_NAME}_light
	${MOD_NAME}_dizel
)
target_link_options(${MOD_NAME} PRIVATE "-static")
