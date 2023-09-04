//---------------------------------------------------------------------------

#include <common.h>
#include <model.h>
#include <switches.h>

#pragma argsused
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason,
                         void *lpReserved) {
  return 1;
}
//---------------------------------------------------------------------------

extern "C" __export void Run(ElectricEngine *eng,
                             const ElectricLocomotive *loco,
                             unsigned long State, float time,
                             float AirTemperature) {
}

extern "C" __export bool CanSwitch(const ElectricLocomotive *loco,
                                   ElectricEngine *eng, unsigned int SwitchID,
                                   unsigned int setState) {
  return true;
}

extern "C" void __export Switched(const ElectricLocomotive *loco,
                                  ElectricEngine *eng, unsigned int SwitchID,
                                  unsigned int PrevState) {

  switch (SwitchID) {
    case SW_EDT_1:
    case SW_EDT_2:
      process_SW_EDT(SwitchID, PrevState, loco, eng);
      break;
  }
}

extern "C" bool __export Init(ElectricEngine *eng, ElectricLocomotive *loco,
                              unsigned long State, float time,
                              float AirTemperature) {
  return true;
}

extern "C" void __export ChangeLoco(Locomotive *loco, const Locomotive *Prev,
                                    unsigned long State) {}

extern "C" bool __export CanWorkWith(const Locomotive *loco,
                                     const wchar_t *Type) {
  return false;
}
