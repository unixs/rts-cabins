#include <cabin_context.h>
#include <default_cabin.h>

#include <stdio.h>
#include <mruby/dump.h>

void
load_cabin_script(CabinContext_t *ctxt, const char *filename) {
  FILE *fp = fopen(filename, "r");

  mrb_load_irep_file(ctxt->mrb, fp);

    mrb_print_error(ctxt->mrb);
    mrb_print_backtrace(ctxt->mrb);

  fclose(fp);
}

mrb_bool
init_cabin_env(CabinContext_t *ctxt) {
  ctxt->mrb = mrb_open();

  if (!ctxt->mrb) {
    return FALSE;
  }

  ctxt->cabin_defined = FALSE;
  ctxt->cabin_class = NULL;
  ctxt->cabin_obj = mrb_nil_value();
  ctxt->resp_to_switched = FALSE;

  ctxt->cabin_class_sym = mrb_intern_str(
    ctxt->mrb,
    mrb_str_new_lit(ctxt->mrb, CABIN_CLASS_NAME)
  );

  ctxt->switched_method_sym = mrb_intern_str(
    ctxt->mrb,
    mrb_str_new_lit(ctxt->mrb, SWITCHED_METHOD_NAME)
  );

  define_default_cabin_class(ctxt);

  return TRUE;
}

mrb_bool
load_cabin_class(CabinContext_t *ctxt) {
  // check Cabin class
  ctxt->cabin_defined = mrb_class_defined_id(
    ctxt->mrb,
    ctxt->cabin_class_sym
  );

  printf("Cabin sym %d\n", ctxt->cabin_class_sym);

  if (!ctxt->cabin_defined) {
    printf("Cabin is NOT defined.\n");

    return FALSE;
  }

  printf("Cabin is defined.\n");

  ctxt->cabin_class = mrb_class_get_id(
    ctxt->mrb,
    ctxt->cabin_class_sym
  );

  ctxt->cabin_obj = mrb_obj_new(
    ctxt->mrb,
    ctxt->cabin_class,
    0,
    NULL
  );

  ctxt->resp_to_switched = mrb_obj_respond_to(
    ctxt->mrb,
    ctxt->cabin_class,
    ctxt->switched_method_sym
  );

  return TRUE;
}
