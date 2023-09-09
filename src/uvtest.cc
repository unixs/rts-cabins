#include <stdio.h>
#include <uv.h>
#include <main_loop.h>

// static uv_loop_t *loop;
static MainLoop *loop;

static void
wait_for_a_while(uv_idle_t* handle) {
  printf("Idling...\n");
}

static void
timer_cb(uv_timer_t *handle) {
  printf("Timer.\n");
}

int main() {
    loop = new MainLoop(10000);
    // uv_loop_init(loop);

    printf("Run empty loop 1.\n");
    // uv_run(loop, UV_RUN_NOWAIT);
    loop->run(1.0);

    printf("Run empty loop 2.\n");
    loop->run(1.0);

    uv_idle_t idler;

    uv_idle_init(loop->get_loop(), &idler);
    uv_idle_start(&idler, wait_for_a_while);

    printf("Run idle loop 3.\n");
    loop->run(1.0);

    printf("Run idle loop 4.\n");
    loop->run(1.0);

    uv_timer_t timer;

    uv_timer_init(loop->get_loop(), &timer);
    uv_timer_start(&timer, timer_cb, 0, 1000);

    printf("Run timer+idle loop 5.\n");
    loop->run(1.0);

    Sleep(1000);

    printf("Run timer+idle loop  after sleep 1000 6.\n");
    loop->run(1.0);

    printf("Run timer+idle loop 7.\n");
    loop->run(1.0);

    Sleep(500);

    printf("Run timer+idle loop  after sleep 500 8.\n");
    loop->run(1.0);

    Sleep(1500);

    printf("Run timer+idle loop  after sleep 1500 9.\n");
    loop->run(1.0);

    while (true) {
      Sleep(300);

      printf("Cycle.\n");
      loop->run(1.0);
    }

    uv_stop(loop->get_loop());

    // uv_loop_close(loop);
    // free(loop);
    delete loop;

    system("PAUSE");

    return 0;
}