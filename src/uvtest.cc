#include <stdio.h>
#include <uv.h>

static uv_loop_t *loop;

static void
wait_for_a_while(uv_idle_t* handle) {
  printf("Idling...\n");
}

static void
timer_cb(uv_timer_t *handle) {
  printf("Timer.\n");
}

int main() {
    loop = (uv_loop_t *) malloc(sizeof(uv_loop_t));
    uv_loop_init(loop);

    printf("Run empty loop 1.\n");
    uv_run(loop, UV_RUN_NOWAIT);

    printf("Run empty loop 2.\n");
    uv_run(loop, UV_RUN_NOWAIT);

    uv_idle_t idler;

    uv_idle_init(loop, &idler);
    uv_idle_start(&idler, wait_for_a_while);

    printf("Run idle loop 3.\n");
    uv_run(loop, UV_RUN_NOWAIT);

    printf("Run idle loop 4.\n");
    uv_run(loop, UV_RUN_NOWAIT);

    uv_timer_t timer;

    uv_timer_init(loop, &timer);
    uv_timer_start(&timer, timer_cb, 0, 1000);

    printf("Run timer+idle loop 5.\n");
    uv_run(loop, UV_RUN_NOWAIT);

    Sleep(1000);

    printf("Run timer+idle loop  after sleep 1000 6.\n");
    uv_run(loop, UV_RUN_NOWAIT);

    printf("Run timer+idle loop 7.\n");
    uv_run(loop, UV_RUN_NOWAIT);

    Sleep(500);

    printf("Run timer+idle loop  after sleep 500 8.\n");
    uv_run(loop, UV_RUN_NOWAIT);

    Sleep(1500);

    printf("Run timer+idle loop  after sleep 1500 9.\n");
    uv_run(loop, UV_RUN_NOWAIT);

    while (true) {
      Sleep(300);

      printf("Cycle.\n");
      uv_run(loop, UV_RUN_NOWAIT);
    }

    uv_stop(loop);

    uv_loop_close(loop);
    free(loop);

    system("PAUSE");

    return 0;
}