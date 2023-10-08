#pragma once

#include <main_loop.h>
#include <mrb_context.h>

class CabinContext {
  MrbContext *mrb_ctxt;
  MainLoop *main_loop;

public:
  CabinContext(MrbContext *mrb_ctxt, MainLoop *main_loop);
  ~CabinContext();
};


CabinContext*
init_cabin_context();


//#ifdef __cplusplus
//  extern "C" {
//#endif

//#ifdef __cplusplus
//  }
//#endif

