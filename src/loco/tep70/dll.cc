#define CONTEXT_CELL 50

#include <tep70.hpp>

using namespace model;
using namespace cabin;

static State state;

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
  auto ctxt = static_cast<Context *>(new Tep70Context());

  save_context_ptr(&ctxt, &eng->var[CONTEXT_CELL], 5);

  return true;
}

extern "C" __export void
Run(DieselEngine *eng, const DieselLocomotive *loco, unsigned long State,
    float time, float AirTemperature)
{
  CONTEXT(Tep70Context);

  main_loop_run(ctxt, time);
}

extern "C" __export bool
CanSwitch(const DieselLocomotive *loco, DieselEngine *eng,
          unsigned int SwitchID, unsigned int setState)
{
  return true;
}

extern "C" void __export
Switched(const DieselLocomotive *loco, DieselEngine *eng,
         unsigned int switch_id, unsigned int prev_state)
{
  CAB_CONTEXT(Tep70Context);
  state.setVar(eng->var);

  auto time = state.get_dizel_oil_time();

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

  if (SW(sw::AZV31_11)) {
    DI_ON(disp::LAMP91_30);
    ctxt->state()->svistok_timer = ctxt->loop()->setInterval(
        [](uv_timer_t *timer) {
          auto loc = reinterpret_cast<DieselLocomotive *>(timer->data);
          auto ctxt = static_cast<Tep70Context *>(
              restore_context_ptr(&(loc->loco->var[50])));

          if (ctxt->state()->svist_is_on) {
            loc->PostTriggerCab(127);
            ctxt->state()->svist_is_on = false;
          }
          else {
            loc->PostTriggerCab(126);
            ctxt->state()->svist_is_on = true;
          }
        },
        2000, (void *) loco, NULL);
  }
  else {
    if (ctxt->state()->svistok_timer) {
      DI_OFF(disp::LAMP91_30);
      ctxt->loop()->clearInterval(ctxt->state()->svistok_timer);
      ctxt->state()->svistok_timer = nullptr;
    }
  }

  loco->PostTriggerCab(24);
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
