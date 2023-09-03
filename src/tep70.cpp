//---------------------------------------------------------------------------

#include <common.h>
#include <ts.h>

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
  Cabin *cab = loco->Cab();

  if (cab->Switch(13) || cab->Switch(113)) {
    cab->SetDisplayState(20, 1);
    cab->SetDisplayState(120, 1);
  } else {
    cab->SetDisplayState(20, 0);
    cab->SetDisplayState(120, 0);
  }
}

extern "C" __export bool CanSwitch(const ElectricLocomotive *loco,
                                   ElectricEngine *eng, unsigned int SwitchID,
                                   unsigned int setState) {
  return true;
}

extern "C" void __export Switched(const ElectricLocomotive *loco,
                                  ElectricEngine *eng, unsigned int SwitchID,
                                  unsigned int PrevState) {}

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
