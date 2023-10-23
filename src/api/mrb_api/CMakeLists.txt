include_directories(include)
link_libraries(Mruby::Mruby)

add_compile_definitions(
	MRB_USE_FLOAT32
	MRB_INT32
	MRB_GC_ARENA_SIZE=300
	MRB_USE_RATIONAL
	MRB_USE_COMPLEX
	MRB_USE_BIGINT
)

add_library(mrb_context
	OBJECT mrb_context.cc)

add_library(mrb_rts_mod
	OBJECT mrb_rts_mod.cc)

add_library(mrb_default_cabin
	OBJECT mrb_default_cabin.cc)
target_link_libraries(mrb_default_cabin
	PUBLIC mrb_default_callbacks)

add_library(mrb_default_callbacks
	OBJECT mrb_default_callbacks.cc)

set(LIB_OBJECTS)
list(APPEND LIB_OBJECTS
	$<TARGET_OBJECTS:mrb_context>
	$<TARGET_OBJECTS:mrb_rts_mod>
	$<TARGET_OBJECTS:mrb_default_cabin>
	$<TARGET_OBJECTS:mrb_default_callbacks>)

add_library(mrb_api
	STATIC ${LIB_OBJECTS})

target_link_libraries(mrb_api
	INTERFACE Mruby::Mruby)
target_include_directories(mrb_api
	INTERFACE include)
