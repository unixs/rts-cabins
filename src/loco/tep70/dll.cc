#include <tep70.h>
#include <pool.h>

// static uv_timer_t timer;

static void switch_timer(uv_timer_t *timer) {
  DieselLocomotive *loco = (DieselLocomotive *) timer->data;

  loco->PostTriggerCab(24);
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved) {
  switch(fdwReason) {
      case DLL_PROCESS_ATTACH:
        init_pool();
        // printf("Dll has been attached to process.\n");
        // Initialize once for each new process.
        // Return FALSE to fail DLL load.
        break;

      case DLL_PROCESS_DETACH:
        // Perform any necessary cleanup.
        break;
  }

  return TRUE;  // Successful DLL_PROCESS_ATTACH.
}
//---------------------------------------------------------------------------

extern "C" __export void Run(ElectricEngine *eng,
                             const ElectricLocomotive *loco,
                             unsigned long State, float time,
                             float AirTemperature) {

  // cab_ctxt->main_loop->run(time);
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

  if (cab->Switch()) {
    cab->SetDisplayState(20, 1);
  }
  else {
    cab->SetDisplayState(20, 0);
  }

  if (cab->Switch(113)) {
    cab->SetDisplayState(120, 1);
  }
  else {
    cab->SetDisplayState(120, 0);
  }

  loco->PostTriggerCab(24);

/*
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
*/
}

extern "C" bool __export Init(DieselEngine *eng, DieselLocomotive *loco,
                              unsigned long State, float time,
                              float AirTemperature) {
  // init_cabin_context();
  return true;
}

extern "C" void __export ChangeLoco(Locomotive *loco, const Locomotive *Prev,
                                    unsigned long State) {}

extern "C" bool __export CanWorkWith(const Locomotive *loco,
                                     const wchar_t *Type) {
  return false;
}
