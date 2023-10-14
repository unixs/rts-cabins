//---------------------------------------------------------------------------

#include <fix.h>
#include <ts.h>

#pragma argsused
int WINAPI
DllEntryPoint(HINSTANCE hinst, unsigned long reason, void *lpReserved)
{
  return 1;
}
//---------------------------------------------------------------------------

extern "C" void __export
Run(DieselEngine *eng, const DieselLocomotive *loco, unsigned long State,
    float time, float AirTemperature)
{
}

extern "C" bool __export
CanSwitch(const DieselLocomotive *loco, DieselEngine *eng,
          unsigned int SwitchID, unsigned int setState)
{
  return true;
}

extern "C" void __export
Switched(const DieselLocomotive *loco, DieselEngine *eng, unsigned int SwitchID,
         unsigned int PrevState)
{
}

extern "C" bool __export
Init(DieselEngine *eng, DieselLocomotive *loco, unsigned long State, float time,
     float AirTemperature)
{
  return true;
}

extern "C" void __export
ChangeLoco(Locomotive *loco, const Locomotive *Prev, unsigned long State)
{
}

extern "C" bool __export
CanWorkWith(const Locomotive *loco, const wchar_t *Type)
{
  return true;
}
