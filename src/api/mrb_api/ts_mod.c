#include <mrb_ts.h>

#define TS_MOD_NAME "TS"

RClass_t
define_ts_mod(CabinContext_t *ctxt) {
  RClass_t mod = mrb_define_module(ctxt->mrb, TS_MOD_NAME);

  ctxt->ts_mod = mod;

  return mod;
}
