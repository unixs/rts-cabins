//---------------------------------------------------------------------------

#include <common.h>
#include <ts.h>
#include <uv.h>
#include <main_loop.h>

#define MAIN_LOOP_DELAY 0.3

static uv_timer_t timer;
static MainLoop *main_loop;
// static uv_loop_t *main_loop ;

static void
switch_timer(uv_timer_t *timer) {
  DieselLocomotive *loco = (DieselLocomotive *) timer->data;

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
  // uv_run(main_loop, UV_RUN_NOWAIT);
}

extern "C" __export bool CanSwitch(const ElectricLocomotive *loco,
                                   ElectricEngine *eng, unsigned int SwitchID,
                                   unsigned int setState) {
  return true;
}

extern "C" void __export Switched(const ElectricLocomotive *loco,
                                  ElectricEngine *eng, unsigned int SwitchID,
                                  unsigned int PrevState) {
  Cabin *cab = loco->Cab();

  if (cab->Switch(13) || cab->Switch(113)) {
    cab->SetDisplayState(20, 1);
    cab->SetDisplayState(120, 1);

    if (!timer.loop) {
      uv_timer_init(main_loop->get_loop(), &timer);
      timer.data = (void *) loco;
    }

    uv_timer_start(&timer, [](uv_timer_t *timer) {
      DieselLocomotive *loco = (DieselLocomotive *) timer->data;

      loco->PostTriggerCab(24);
    }, 2000, 2000);

  } else {
    cab->SetDisplayState(20, 0);
    cab->SetDisplayState(120, 0);

    if (timer.loop) {
      uv_timer_stop(&timer);
    }
  }

  loco->PostTriggerCab(24);
}

extern "C" bool __export Init(ElectricEngine *eng, ElectricLocomotive *loco,
                              unsigned long State, float time,
                              float AirTemperature) {

  main_loop = new MainLoop(MAIN_LOOP_DELAY);
  // main_loop = (uv_loop_t *) malloc(sizeof(uv_loop_t));
  // uv_loop_init(main_loop);

  return true;
}

extern "C" void __export ChangeLoco(Locomotive *loco, const Locomotive *Prev,
                                    unsigned long State) {}

extern "C" bool __export CanWorkWith(const Locomotive *loco,
                                     const wchar_t *Type) {
  return false;
}
