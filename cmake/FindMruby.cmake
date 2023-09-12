message(STATUS "CMake Find module for mruby was loaded.")
cmake_policy(SET CMP0074 NEW)
cmake_policy(SET CMP0144 NEW)

include(FindPackageHandleStandardArgs)
include(SelectLibraryConfigurations)
include(CMakePrintHelpers)

find_path(Mruby_INCLUDE_DIR
	NAMES mruby.h
	REQUIRED
)

find_library(Mruby_LIBRARY
	NAMES mruby
	PATH_SUFFIXES build/cross-mingw/lib
	REQUIRED
	NO_CACHE
)

set(Mruby_COMPILER_NAME mrbc)
set(Mruby_WIN32_COMPILER_NAME ${Mruby_COMPILER_NAME}${CMAKE_EXECUTABLE_SUFFIX})

set(Mruby_EXE_NAME mruby)
set(Mruby_WIN32EXE_NAME ${Mruby_EXE_NAME}${CMAKE_EXECUTABLE_SUFFIX})

find_program(Mruby_WIN32_COMPILER_PROG
	NAMES ${Mruby_WIN32_COMPILER_NAME}
	PATH_SUFFIXES build/cross-mingw/bin
	REQUIRED
)

find_program(Mruby_COMPILER_PROG
	NAMES ${Mruby_COMPILER_NAME}
	REQUIRED
)

find_program(Mruby_WIN32_PROG
	NAMES ${Mruby_WIN32EXE_NAME}
	PATH_SUFFIXES build/cross-mingw/bin
	REQUIRED
	NO_CACHE
)

# cmake_print_variables(Mruby_INCLUDE_DIR)
# cmake_print_variables(Mruby_LIBRARY)
# cmake_print_variables(Mruby_WIN32_COMPILER_NAME)
# cmake_print_variables(Mruby_WIN32_COMPILER_PROGRAM)
# cmake_print_variables(Mruby_COMPILER_NAME)
# cmake_print_variables(Mruby_COMPILER_PROGRAM)
# cmake_print_variables(Mruby_WIN32_PROG)

find_package_handle_standard_args(Mruby
	FOUND_VAR
		Mruby_FOUND
	REQUIRED_VARS
		Mruby_LIBRARY
  		Mruby_INCLUDE_DIR
		Mruby_WIN32_COMPILER_PROG
		Mruby_COMPILER_PROG
    	Mruby_WIN32_PROG
)

if(Mruby_FOUND)
	set(Mruby_LIBRARIES ${Mruby_LIBRARY})
	set(Mruby_INCLUDE_DIRS ${Mruby_INCLUDE_DIR})
	set(Mruby_WIN32COMPILER_EXECUTABLE ${Mruby_WIN32_COMPILER_PROG})
	set(Mruby_COMPILER_EXECUTABLE ${Mruby_COMPILER_PROG})
	set(Mruby_WIN32_EXECUTABLE ${Mruby_WIN32_PROG})
endif()

if(Mruby_FOUND AND NOT TARGET Mruby::Mruby)
  add_library(Mruby::Mruby UNKNOWN IMPORTED)
  set_target_properties(Mruby::Mruby PROPERTIES
    IMPORTED_LOCATION "${Mruby_LIBRARY}"
    # INTERFACE_COMPILE_OPTIONS "${PC_Foo_CFLAGS_OTHER}"
    INTERFACE_INCLUDE_DIRECTORIES "${Mruby_INCLUDE_DIR}"
  )
endif()

mark_as_advanced(
	Mruby_INCLUDE_DIR
	Mruby_LIBRARY
	Mruby_WIN32_PROG
	Mruby_COMPILER_PROG
	Mruby_WIN32_COMPILER_PROG
	Mruby_EXE_NAME
	Mruby_WIN32EXE_NAME
	Mruby_COMPILER_NAME
	Mruby_WIN32_COMPILER_NAME
)
