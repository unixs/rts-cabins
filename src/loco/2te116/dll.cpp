//---------------------------------------------------------------------------

#include <fix.h>
#include <ts.h>
#include <cab.hpp>
#include <common.hpp>



using namespace model;

int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
    return 1;
}
//---------------------------------------------------------------------------

extern "C" void __export Run (DieselEngine *eng, const DieselLocomotive *loco,unsigned long State, float time,float AirTemperature) {
}

extern "C" bool __export CanSwitch(const DieselLocomotive *loco, DieselEngine *eng, unsigned int SwitchID, unsigned int setState) {
    return true;
}

extern "C" void __export Switched(const DieselLocomotive *loco,DieselEngine *eng, unsigned int SwitchID,unsigned int PrevState) {

  CABIN;

  // АБ, ДИзель, топливный насос автомат, топливный насос тумблер 1 секции, пуск дизеля
 if (SW(sw::AB_64) && SW(sw::diz_52) && SW(sw::tn1_7) && SW(sw::PD1_33))
 {
   DI_ON(disp::sn_17);
   loco->PostTriggerCab(103);
 }
 else
 {
   DI_ON(disp::sn2_18);
 }

 cab->SetDisplayState(19,1);

}

extern "C" bool __export Init(DieselEngine *eng,DieselLocomotive *loco,unsigned long State, float time,float AirTemperature) {
    return true;
}

extern "C" void __export ChangeLoco (Locomotive *loco,const Locomotive *Prev,unsigned long State) {
}

extern "C" bool __export CanWorkWith (const Locomotive *loco,const wchar_t *Type)  {
    return true;
}
