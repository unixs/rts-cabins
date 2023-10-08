include_directories(include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-write-strings")
#add_compile_options(-Wno-write-strings)

# My
add_subdirectory(tep70)
add_subdirectory(2te116)

# RTS
add_subdirectory(chme3_rts)
add_subdirectory(tep70_rts)
