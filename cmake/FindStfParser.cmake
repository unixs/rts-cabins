message(STATUS "CMake Find module for STF Parser was loaded.")

find_package(Java 17.0 REQUIRED)

include(CMakePrintHelpers)
include(UseJava)

set(JAR_VERSION 0.2.3)
set(JAR_MD5 918cafb7b365cb63b78a3bc0b08314f8)
set(JAR_FILENAME parser-${JAR_VERSION})
set(JAR_URL https://github.com/unixs/stf-parser/releases/download/v${JAR_VERSION}/parser-${JAR_VERSION}-jar-with-dependencies.jar)
set(JAR_PROJECT_PATH ${PROJECT_SOURCE_DIR}/tools/${JAR_FILENAME}.jar)

message(STATUS "Checking parser jar.")

if(NOT EXISTS ${JAR_PROJECT_PATH})
	message(STATUS "Downloading jar...")
	file(DOWNLOAD ${JAR_URL}
		${JAR_PROJECT_PATH}
		STATUS JAR_DOWNLOAD_STATUS
		SHOW_PROGRESS)

	list(GET JAR_DOWNLOAD_STATUS 0 JAR_DOWNLOAD_RESULT_CODE)

	if(NOT JAR_DOWNLOAD_RESULT_CODE EQUAL 0)
		message(FATAL_ERROR "Failed downloading! Error: ${JAR_DOWNLOAD_STATUS}.")
	endif()
endif()

find_jar(StfParser_JAR ${JAR_FILENAME}
	NAMES
	parser-${JAR_VERSION}-jar-with-dependencies
	stf-parser
	stf-parser-jar-with-dependencies
	parser
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

# cmake_print_variables(StfParser_JAR)
function(stf_parser_command source)
	set(HEADER_EXTENSION hpp)

	get_filename_component(OUTPUT_DIR ${source} DIRECTORY)
	get_filename_component(OUTPUT_FILE ${source} NAME_WE)

	add_custom_command(
		OUTPUT ${OUTPUT_DIR}/${OUTPUT_FILE}.${HEADER_EXTENSION}
		COMMAND ${Java_JAVA_EXECUTABLE} -jar ${StfParser_JAR} ${CMAKE_CURRENT_LIST_DIR}/${source}
		MAIN_DEPENDENCY ${CMAKE_CURRENT_LIST_DIR}/${source}
		COMMENT "Compiling model files..."
		VERBATIM
	)
endfunction()

mark_as_advanced(
	JAR_FILENAME
	JAR_VERSION
	JAR_URL
	JAR_MD5
	JAR_DOWNLOAD_STATUS
	JAR_DOWNLOAD_RESULT_CODE
	JAR_PROJECT_PATH
)
