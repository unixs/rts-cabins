include_directories(include)
link_libraries(Mruby::Mruby)

add_library(ts_mod OBJECT ts_mod.c)

set(LIB_OBJECTS)
list(APPEND LIB_OBJECTS
	$<TARGET_OBJECTS:ts_mod>)

add_library(mrb_ts STATIC ${LIB_OBJECTS})
target_link_libraries(mrb_ts INTERFACE Mruby::Mruby)
target_include_directories(mrb_ts INTERFACE include)
