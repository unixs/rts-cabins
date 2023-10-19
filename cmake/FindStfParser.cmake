message(STATUS "CMake Find module for STF Parser was loaded.")

find_package(Java 17.0 REQUIRED)

include(CMakePrintHelpers)
include(UseJava)

find_jar(StfParser_JAR stf-parser
	NAMES
	rts-stf-parser-0.1.1-jar-with-dependencies
	rts-stf-parser
	rts-stf-parser-jar-with-dependencies
	rts-parser
	rts-stf-parser-with-dependencies
	stf-parser-with-dependencies
	REQUIRED
	NO_CMAKE_FIND_ROOT_PATH
	PATHS
	${PROJECT_SOURCE_DIR}/tools
	$ENV{HOME}
	$ENV{CLASSPATH}
	NO_CMAKE_FIND_ROOT_PATH
)

find_package_handle_standard_args(StfParser
	FOUND_VAR
	StfParser_FOUND
	REQUIRED_VARS
	StfParser_JAR
)

cmake_print_variables(StfParser_JAR)

function(stf_parser_command source)
	set(HEADER_EXTENSION .hpp)

	get_filename_component(OUTPUT_DIR ${source} DIRECTORY CACHE)
	get_filename_component(OUTPUT_FILE ${source} NAME_WE CACHE)

	add_custom_command(
		OUTPUT "${OUTPUT_DIR}/${OUTPUT_FILE}.${HEADER_EXTENSION}"
		COMMAND ${Java_JAVA_EXECUTABLE} -jar ${StfParser_JAR} ${CMAKE_CURRENT_LIST_DIR}/${source}
		DEPENDS ${CMAKE_CURRENT_LIST_DIR}/${source}
		VERBATIM
	)
endfunction()
