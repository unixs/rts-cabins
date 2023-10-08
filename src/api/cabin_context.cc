#include <cabin_context.h>

CabinContext::CabinContext(MrbContext *mrb_ctxt, MainLoop *main_loop):
  mrb_ctxt(mrb_ctxt), main_loop(main_loop) {

}

CabinContext::~CabinContext() {
  // BUG: mem leek
  delete this->main_loop;
  delete this->mrb_ctxt;
}


CabinContext*
init_cabin_context() {
  MainLoop *loop = new MainLoop(MAIN_LOOP_DEFAULT_DELAY);
  MrbContext *mrb = new MrbContext();

  CabinContext *ctxt = new CabinContext(mrb, loop);

  return ctxt;
}
