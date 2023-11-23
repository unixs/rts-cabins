#pragma once

#include <main_loop.hpp>
#include <mrb_context.hpp>

class Context {
  MrbContext *mrb_ctxt;
  MainLoop *main_loop;

public:
  Context(MrbContext *mrb_ctxt, MainLoop *main_loop);
  Context();
  ~Context();

  /**
   * #### Возвращает главный цикл кабины
   */
  MainLoop *
  loop();

  /**
   * Запускает итерацию главного цикла
   */
  void
  run(const float frame_time);
};


Context *
init_context();

/**
 * #### Запускает итерацию главного цикла
 */
inline void
main_loop_run(Context *ctxt, const float time)
{
  if (ctxt) {
    ctxt->run(time);
  }
  else {
    // TODO: some debug output
  }
}

// #ifdef __cplusplus
//   extern "C" {
// #endif

// #ifdef __cplusplus
//   }
// #endif
