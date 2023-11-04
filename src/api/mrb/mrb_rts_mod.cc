#include <mrb_rts_mod.h>

RClass_t *
define_rts_mod(MrbContext *ctxt) {
  RClass_t *mod = mrb_define_module(ctxt->mrb, RTS_MOD_NAME);

  ctxt->rts_mod = mod;

  return mod;
}
