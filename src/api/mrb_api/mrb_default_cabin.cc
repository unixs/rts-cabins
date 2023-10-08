#include <mrb_default_cabin.h>
#include <mrb_default_callbacks.h>

RClass_t*
define_default_cabin_class(MrbContext *ctxt) {
  struct RClass* default_cabin = mrb_define_class(
    ctxt->mrb,
    DEFAULT_CABIN_CLASS_NAME,
    ctxt->mrb->object_class
  );

  mrb_define_method(
    ctxt->mrb,
    default_cabin,
    "initialize",
    nil_cb,
    MRB_ARGS_ANY()
  );

  mrb_define_method(
    ctxt->mrb,
    default_cabin,
    "can_switch",
    true_cb,
    MRB_ARGS_ANY()
  );

  mrb_define_method(
    ctxt->mrb,
    default_cabin,
    "switched",
    nil_cb,
    MRB_ARGS_ANY()
  );

  mrb_define_method(
    ctxt->mrb,
    default_cabin,
    "frame",
    nil_cb,
    MRB_ARGS_ANY()
  );

  mrb_define_method(
    ctxt->mrb,
    default_cabin,
    "change_loco",
    nil_cb,
    MRB_ARGS_ANY()
  );

  mrb_define_method(
    ctxt->mrb,
    default_cabin,
    "can_work_with",
    false_cb,
    MRB_ARGS_ANY()
  );

  return default_cabin;
}

