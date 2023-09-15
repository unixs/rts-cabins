#pragma once

#include <mrb.h>

#define CABIN_CLASS_NAME "Cabin"
#define SWITCHED_METHOD_NAME "switched"
#define DEFAULT_SCRIPT_NAME = "cabin.mrb"


typedef struct CabinContext {
  mrb_state *mrb;

  mrb_sym cabin_class_sym;
  mrb_sym switched_method_sym;

  mrb_bool cabin_defined;
  struct RClass *cabin_class;
  mrb_value cabin_obj;

  mrb_bool resp_to_switched;

  struct RClass *ts_mod;
  struct RClass *ts_loco_mod;
  struct RClass *ts_diesel_loco_mod;
  struct RClass *ts_loco_cabin_class;
} CabinContext_t;

#ifdef __cplusplus
  extern "C" {
#endif

void
load_cabin_script(CabinContext_t *ctxt, const char *filename);

mrb_bool
init_cabin_env(CabinContext_t *ctxt);

#ifdef __cplusplus
  }
#endif

