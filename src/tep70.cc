//---------------------------------------------------------------------------

#include <fix.h>
#include <main_loop.h>
#include <ts.h>

#include <cabin_context.h>

#define MAIN_LOOP_DELAY 0.3

#define CABIN_MOD_NAME "Cabin"
#define CABIN_SWITCHED_METHOD_NAME "switched"

static uv_timer_t timer;
static MainLoop *main_loop;
// static uv_loop_t *main_loop ;

static CabinContext_t *cab_ctxt;

static void init_mruby_context() {
  cab_ctxt = new CabinContext_t;

  mrb_bool ok = init_cabin_env(cab_ctxt);

  if (!ok) {
    printf("MRUBY initialization failed. Sad day..");
  } else {
    load_cabin_script(cab_ctxt, "cabin.mrb");
  }
}

static void call_cabin_switched(CabinContext_t *ctxt,
                                const ElectricLocomotive *loco,
                                ElectricEngine *engine, unsigned int switch_id,
                                unsigned int prev_state) {

  // Здесь нужно перед передачей управления в Руби
  // поменять указатели в интерфейсных объектах

  // cabin_context_reattach_ptrs(ctxt, loco, engine);
  // call_cabin_switched_rb(ctxt);
}

static void switch_timer(uv_timer_t *timer) {
  DieselLocomotive *loco = (DieselLocomotive *)timer->data;

  loco->PostTriggerCab(24);
}

int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason,
                         void *lpReserved) {
  return TRUE;
}
//---------------------------------------------------------------------------

extern "C" __export void Run(ElectricEngine *eng,
                             const ElectricLocomotive *loco,
                             unsigned long State, float time,
                             float AirTemperature) {

  main_loop->run(time);
}

extern "C" __export bool CanSwitch(const ElectricLocomotive *loco,
                                   ElectricEngine *eng, unsigned int SwitchID,
                                   unsigned int setState) {
  return true;
}

extern "C" void __export Switched(const ElectricLocomotive *loco,
                                  ElectricEngine *engine,
                                  unsigned int switch_id,
                                  unsigned int prev_state) {

  Cabin *cab = loco->Cab();

  mrb_value r_switch_id = mrb_fixnum_value(switch_id);
  mrb_value r_loco;

  call_cabin_switched(cab_ctxt, loco, engine, switch_id, prev_state);

  if (cab->Switch(13) || cab->Switch(113)) {
    cab->SetDisplayState(20, 1);
    cab->SetDisplayState(120, 1);

    if (!timer.loop) {
      uv_timer_init(main_loop->get_loop(), &timer);
      timer.data = (void *)loco;
    }

    uv_timer_start(
        &timer,
        [](uv_timer_t *timer) {
          DieselLocomotive *loco = (DieselLocomotive *)timer->data;

          loco->PostTriggerCab(24);
        },
        2000, 2000);

  } else {
    cab->SetDisplayState(20, 0);
    cab->SetDisplayState(120, 0);

    if (timer.loop) {
      uv_timer_stop(&timer);
    }
  }

  loco->PostTriggerCab(24);
}

extern "C" bool __export Init(DieselEngine *eng, DieselLocomotive *loco,
                              unsigned long State, float time,
                              float AirTemperature) {

  main_loop = new MainLoop(MAIN_LOOP_DELAY);

  init_mruby_context();

  return true;
}

extern "C" void __export ChangeLoco(Locomotive *loco, const Locomotive *Prev,
                                    unsigned long State) {}

extern "C" bool __export CanWorkWith(const Locomotive *loco,
                                     const wchar_t *Type) {
  return false;
}
