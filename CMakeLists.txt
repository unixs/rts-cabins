cmake_minimum_required(VERSION 3.27 FATAL_ERROR)

project(rts-cabins
	LANGUAGES C CXX
	VERSION 0.0.1)

cmake_policy(SET CMP0028 NEW)

include(CMakePrintHelpers)

message(STATUS "CPU: ${CMAKE_HOST_SYSTEM_PROCESSOR}")
cmake_print_variables(CMAKE_FIND_ROOT_PATH)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_FLAGS "-pipe -fleading-underscore -static-libgcc")
set(CMAKE_CXX_FLAGS "-pipe -fleading-underscore -static-libgcc -static-libstdc++")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

set(CMAKE_C_FLAGS_DEBUG "-O0 -g -Wall -Wextra -Wno-unused-parameter")
set(CMAKE_C_FLAGS_RELEASE "-O3 -s")

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -Wall -Wextra -Wno-unused-parameter -Wno-cast-function-type")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -s")

# Force -fPIC
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "Release")
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# set(CMAKE_SHARED_LIBRARY_PREFIX "")

# list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_LIST_DIR}/opt/uv)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

# cmake_print_variables(CMAKE_MODULE_PATH)
find_package(libuv CONFIG REQUIRED)
find_package(Mruby MODULE REQUIRED)
find_package(StfParser MODULE REQUIRED)

# find_package(jansson CONFIG REQUIRED)
add_subdirectory("src")
