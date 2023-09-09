#include <cmath>

#include <main_loop.h>

MainLoop::MainLoop(const float delay): delay(delay)  {
  loop = new uv_loop_t;
  uv_loop_init(loop);
}

MainLoop::~MainLoop() {
  uv_loop_close(loop);
  delete loop;
}

void
MainLoop::run(const float frame_time) {
  step_time += frame_time;
  time += frame_time;

  if (step_time > delay) {
    step_time = 0;
    uv_run(loop, UV_RUN_NOWAIT);
  }
}

float
MainLoop::cabin_time_raw() {
  return time;
}

unsigned long
MainLoop::cabin_time() {
  return lroundf(time);
}

uv_loop_t*
MainLoop::get_loop() {
  return loop;
}
