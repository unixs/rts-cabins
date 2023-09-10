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

uv_timer_t*
MainLoop::setInterval(uv_timer_cb cb, uint64_t repeat, void *data, int *libuv_res) {
  int internal_res = 0;
  int *res = libuv_res ? libuv_res : &internal_res;

  uv_timer_t *timer = new uv_timer_t;

  timer->data = data;

  *res = uv_timer_init(loop, timer);
  *res = uv_timer_start(timer, cb, repeat, repeat);

  return timer;
}

void
MainLoop::clearInterval(uv_timer_t* timer, int *libuv_res) {
  int internal_res = 0;
  int *res = libuv_res ? libuv_res : &internal_res;

  *res = uv_timer_stop(timer);

  delete timer;
}

uv_timer_t*
MainLoop::setTimeout(uv_timer_cb cb, uint64_t timeout, void *data, int *libuv_res) {
  int internal_res = 0;
  int *res = libuv_res ? libuv_res : &internal_res;

  uv_timer_t *timer = new uv_timer_t;

  timer->data = data;

  *res = uv_timer_init(loop, timer);
  *res = uv_timer_start(timer, cb, timeout, 0);

  return timer;
}

void
MainLoop::clearTimeout(uv_timer_t* timer, int *libuv_res) {
  clearInterval(timer, libuv_res);
}
