#include <tep70.hpp>

// static uv_timer_t timer;

using namespace model;

BOOL WINAPI
DllMain(HINSTANCE hinstDLL, DWORD reason, LPVOID lpReserved)
{
  switch (reason) {
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

  return TRUE; // Successful DLL_PROCESS_ATTACH.
}
//---------------------------------------------------------------------------

extern "C" bool __export
Init(DieselEngine *eng, DieselLocomotive *loco, unsigned long State, float time,
     float AirTemperature)
{
  auto ctxt = init_context();

  save_context_ptr(&ctxt, eng->var, 5);

  return true;
}

extern "C" __export void
Run(ElectricEngine *eng, const ElectricLocomotive *loco, unsigned long State,
    float time, float AirTemperature)
{
}

extern "C" __export bool
CanSwitch(const ElectricLocomotive *loco, ElectricEngine *eng,
          unsigned int SwitchID, unsigned int setState)
{
  return true;
}

extern "C" void __export
Switched(const ElectricLocomotive *loco, ElectricEngine *eng,
         unsigned int switch_id, unsigned int prev_state)
{
  CABIN;

  Context *ctxt;

  api_status error = restore_context_ptr(eng->var, &ctxt);

  if (!error) {
    // ctxt->run(time);
  }
  else {
    // TODO: some debug output
  }

  if (SW(sw::AZV51_13)) {
    DI_ON(disp::LAMP011_20);
  }
  else {
    DI_OFF(disp::LAMP011_20);
  }

  if (SW(sw::AZV5_113)) {
    DI_ON(disp::LAMP1_120);
  }
  else {
    DI_OFF(disp::LAMP1_120);
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

extern "C" void __export
ChangeLoco(Locomotive *loco, const Locomotive *Prev, unsigned long State)
{
}

extern "C" bool __export
CanWorkWith(const Locomotive *loco, const wchar_t *Type)
{
  return false;
}
