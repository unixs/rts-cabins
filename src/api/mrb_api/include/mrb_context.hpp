#pragma once

#include <mrb.h>

#define CABIN_CLASS_NAME "Cabin"
#define SWITCHED_METHOD_NAME "switched"
#define DEFAULT_SCRIPT_NAME = "cabin.mrb"

class MrbContext {
public:
  mrb_state *mrb;

  RClass_t *rts_mod;

  mrb_sym cabin_class_sym;
  mrb_sym switched_method_sym;

  mrb_bool cabin_defined;
  RClass_t *cabin_class;
  mrb_value cabin_obj;

  mrb_bool resp_to_switched;

  MrbContext();
  ~MrbContext();
};

