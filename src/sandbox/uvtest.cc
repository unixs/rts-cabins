#include <stdio.h>
#include <uv.h>
#include <main_loop.h>

#undef __APPLE__
#define MRB_USE_ETEXT_RO_DATA_P
#include <mruby.h>

#include <cabin_context.h>

static MainLoop *loop;


static CabinContext_t *cab_ctxt;


static void
wait_for_a_while(uv_idle_t* handle) {
  printf("Call MRuby.\n");

  if (!cab_ctxt->resp_to_switched) {
    printf("\tswitched is not defined.\n");
    return;
  }

  mrb_funcall_id(
    cab_ctxt->mrb,
    cab_ctxt->cabin_obj,
    cab_ctxt->switched_method_sym,
    1,
    mrb_fixnum_value(10)
  );

  printf("/Call MRuby.\n");
}

static void
timer_cb(uv_timer_t *handle) {
  printf("Timer.\n");
}

void
init_mruby_context() {
  cab_ctxt = new CabinContext_t;

  mrb_bool ok = init_cabin_env(cab_ctxt);

  if (!ok) {
    printf("MRUBY initialization failed. Sad day..");
  } else {
    load_cabin_script(cab_ctxt, "cabin.mrb");
  }
}

int main() {
    loop = new MainLoop(0.003);

    init_mruby_context();

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

    system("PAUSE");

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
