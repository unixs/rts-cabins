set(MOD_NAME chme3_rts_orig)

add_library(${MOD_NAME} MODULE dll.cpp)
target_link_options(${MOD_NAME} PRIVATE "-static")
