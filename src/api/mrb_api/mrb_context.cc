#include <mrb_context.h>
#include <mrb_default_cabin.h>

#include <stdio.h>
#include <mruby/dump.h>

static mrb_bool
init_cabin_class(MrbContext *ctxt) {
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

static void
load_cabin_script(MrbContext *ctxt, const char *filename) {
  FILE *fp = fopen(filename, "r");

  mrb_load_irep_file(ctxt->mrb, fp);

  mrb_print_error(ctxt->mrb);
  mrb_print_backtrace(ctxt->mrb);

  fclose(fp);
}

MrbContext::MrbContext() {
  this->mrb = mrb_open();

  this->cabin_defined = FALSE;
  this->cabin_class = NULL;
  this->cabin_obj = mrb_nil_value();
  this->resp_to_switched = FALSE;

  this->cabin_class_sym = mrb_intern_str(
    this->mrb,
    mrb_str_new_lit(this->mrb, CABIN_CLASS_NAME)
  );

  this->switched_method_sym = mrb_intern_str(
    this->mrb,
    mrb_str_new_lit(this->mrb, SWITCHED_METHOD_NAME)
  );

  // define_cabin_interface(ctxt);

  define_default_cabin_class(this);
  // init_cabin_class(ctxt);
}

MrbContext::~MrbContext() {
  printf("FREE MRB CONTEXT\n");
}
