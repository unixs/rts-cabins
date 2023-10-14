#undef __APPLE__
#define MRB_USE_ETEXT_RO_DATA_P
#include <mruby.h>

#ifdef __cpusplus
  extern "C" {
#endif


mrb_value
true_cb(struct mrb_state *mrb, mrb_value self);

mrb_value
false_cb(struct mrb_state *mrb, mrb_value self);

mrb_value
nil_cb(struct mrb_state *mrb, mrb_value self);


#ifdef __cpusplus
  }
#endif
