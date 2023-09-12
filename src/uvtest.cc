#include <stdio.h>
#include <uv.h>
#include <main_loop.h>

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
    loop = new MainLoop(0.003);

    printf("Run empty loop 1.\n");
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

    uv_timer_t *timer;

    auto cb = [](uv_timer_t *timer) {
      printf("Lambda timer.\n");
    };

    timer = loop->setInterval(cb, 1000);

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

    for (short i = 0; i < 100; i++) {
      Sleep(200);
      printf("Cycle.\n");
      loop->run(1.0);

      if (i == 50) {
        loop->setIntervalRepeat(timer, 500);
      }
    }
    loop->clearInterval(timer);

    Sleep(1000);

    printf("Set timeout function.\n");

    timer = loop->setTimeout(cb, 1000);

    Sleep(300);

    // loop->setIntervalRepeat(timer, 200);

    Sleep(700);

    for (short i = 0; i < 20; i++) {
      Sleep(100);
      loop->run(1.0);
    }

    uv_stop(loop->get_loop());

    delete loop;
    system("PAUSE");

    return 0;
}
