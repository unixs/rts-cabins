set(MOD_NAME 2te116)

link_libraries(cabin_api)
include_directories(include model)
add_compile_definitions(DIESEL)

stf_parser_command(model/cab.sd)

add_library(${MOD_NAME}_light OBJECT light.cc)
add_library(${MOD_NAME}_dizel OBJECT dizel.cc)

add_library(${MOD_NAME} MODULE dll.cpp)
target_sources(${MOD_NAME} PRIVATE model/cab.hpp)
target_link_libraries(${MOD_NAME}
	PRIVATE
	${MOD_NAME}_light
	${MOD_NAME}_dizel
)
target_link_options(${MOD_NAME} PRIVATE "-static")
