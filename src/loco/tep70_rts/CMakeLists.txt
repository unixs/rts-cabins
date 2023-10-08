set(MOD_NAME tep70_rts_orig)

add_library(${MOD_NAME} MODULE dll.cpp)
target_link_options(${MOD_NAME} PRIVATE "-static")
