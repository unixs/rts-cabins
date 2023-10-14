#pragma once

#include <main_loop.hpp>
#include <mrb_context.hpp>

class Context {
  MrbContext *mrb_ctxt;
  MainLoop *main_loop;

public:
  Context(MrbContext *mrb_ctxt, MainLoop *main_loop);
  ~Context();

  /**
   * Запускает итерацию главного цикла
   */
  void
  run(const float frame_time);
};


Context *
init_context();


// #ifdef __cplusplus
//   extern "C" {
// #endif

// #ifdef __cplusplus
//   }
// #endif
