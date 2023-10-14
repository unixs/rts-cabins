#include <context.hpp>

#ifndef MAIN_LOOP_DELAY
#  define MAIN_LOOP_DELAY MAIN_LOOP_DEFAULT_DELAY
#endif

Context::Context(MrbContext *mrb_ctxt, MainLoop *main_loop)
    : mrb_ctxt(mrb_ctxt), main_loop(main_loop)
{
}

Context::~Context()
{
  // BUG: mem leek
  delete this->main_loop;
  delete this->mrb_ctxt;
}

void
Context::run(const float frame_time)
{
  this->main_loop->run(frame_time);
}


Context *
init_context()
{
  MainLoop *loop = new MainLoop(MAIN_LOOP_DEFAULT_DELAY);
  MrbContext *mrb = new MrbContext();

  Context *ctxt = new Context(mrb, loop);

  return ctxt;
}
