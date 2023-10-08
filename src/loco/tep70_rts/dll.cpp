//---------------------------------------------------------------------------

#define RTS_STACKSIZE 16
#define RTS_ADAPTER_COMPLY

#include <fix.h>
/*#define RTS_NODIRECTOBJLINKS*/
#include <cmath>
#include <cstdio>
#include <ts.h>

#define UR_CHARGE_RATE 0.25
#define UR_DISCHARGE_RATE -0.25
#define UR_EMERGENCY_RATE -1.00
#define PIPE_CHARGE_Q_REL 0.8
#define PIPE_CHARGE_Q 0.5
#define PIPE_DISCHARGE_SLOW -0.005
#define UR_DISCHARGE2 0.003
#define CHARGE_PIPE_VALUE 5.0
#define EPT_RELEASE_RATE 0.4
#define EPT_RELEASE_RATE1 0.8
#define EPT_APPLY_RATE 0.25
#define EPT_MAX 6.0

#define COMPUTER_R1BOT 0.628
#define COMPUTER_R1HGT 0.444

#define BATTERY_DEADLINE 14.0
#define BATTERY_DEADLINE_DIESEL 25.0

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

#pragma argsused
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason,
                         void *lpReserved) {
  return 1;
}
//---------------------------------------------------------------------------

void SwitchLights(const DieselLocomotive *loco, UINT State) {
  switch (State) {
  case 0:
    loco->SwitchLight(0, false, 0.0, 0);
    loco->SwitchLight(1, false, 0.0, 0);
    loco->SwitchLight(5, false, 0.0, 0);
    loco->SwitchLight(6, false, 0.0, 0);
    break;
  case 1:
    loco->SwitchLight(0, true, 0.0, 0);
    loco->SwitchLight(1, false, 0.0, 0);
    loco->SwitchLight(5, true, 0.0, 0);
    loco->SwitchLight(6, false, 0.0, 0);
    break;
  case 2:
    loco->SwitchLight(0, false, 0.0, 0);
    loco->SwitchLight(1, true, 0.0, 0);
    loco->SwitchLight(5, false, 0.0, 0);
    loco->SwitchLight(6, true, 0.0, 0);
    break;
  case 3:
    loco->SwitchLight(36, true, 0.0, 0);
    break;
  case 4:
    loco->SwitchLight(36, false, 0.0, 0);
    break;
  case 5:
    loco->SwitchLight(12, true, 0.0, 0);
    break;
  case 6:
    loco->SwitchLight(12, false, 0.0, 0);
    break;
  case 7:
    loco->SwitchLight(11, true, 0.0, 0);
    break;
  case 8:
    loco->SwitchLight(11, false, 0.0, 0);
    break;
  case 9:

    break;
  case 10:

    break;
  case 11:
    loco->SwitchLight(45, false, 0.0, 0);
    loco->SwitchLight(46, false, 0.0, 0);
    loco->SwitchLight(31, false, 0.0, 0);
    loco->SwitchLight(32, false, 0.0, 0);
    break;
  case 12:
    loco->SwitchLight(45, true, 0.0, 0);
    loco->SwitchLight(46, false, 0.0, 0);
    loco->SwitchLight(31, true, 0.0, 0);
    loco->SwitchLight(32, false, 0.0, 0);
    break;
  case 13:
    loco->SwitchLight(45, false, 0.0, 0);
    loco->SwitchLight(46, true, 0.0, 0);
    loco->SwitchLight(31, false, 0.0, 0);
    loco->SwitchLight(32, true, 0.0, 0);
    break;
  case 14:
    loco->SwitchLight(10, true, 0.0, 0);
    break;
  case 15:
    loco->SwitchLight(10, false, 0.0, 0);
    break;
  case 16:
    loco->SwitchLight(38, true, 0.0, 0);
    break;
  case 17:
    loco->SwitchLight(38, false, 0.0, 0);
    break;
  case 18:
    loco->SwitchLight(37, true, 0.0, 0);
    break;
  case 19:
    loco->SwitchLight(37, false, 0.0, 0);
    break;
  case 20:
    loco->SwitchLight(47, true, 0.0, 0);
    break;
  case 21:
    loco->SwitchLight(47, false, 0.0, 0);
    break;
  };
};

unsigned long IsLocoOn(const DieselLocomotive *loco, const DieselEngine *eng,
                       unsigned long Flags) {
  if (!eng->cab)
    return 0;
  Cabin *cab = loco->Cab();
  unsigned long Res = 0;
  switch (loco->LibParam) {
  case 1:
    if (eng->var[4] >= BATTERY_DEADLINE)
      Res |= 1;
    else
      return 0;
    if (eng->DieselOn == 1 || eng->DieselOn == 3)
      Res |= 2;
    if (cab->Switch(19))
      Res |= 4;
    if (cab->Switch(20))
      Res |= 8;
    if (Flags & 16) {
      if (cab->Switch(26))
        Res |= 16;
      if (cab->Switch(27) && cab->Switch(41))
        Res |= 256;
      Res |= 32;
    };
    if (Flags & 32) {
      if (cab->Switch(126))
        Res |= 16;
      if (cab->Switch(127) && cab->Switch(41))
        Res |= 256;
      Res |= 64;
    };
    if (cab->Switch(119))
      Res |= 128;
    return Res;
  };
  return 0;
};

//---------------------------------------------------------------------------

/*

Stack variables

 0 - Main timer

 1 - diesel start timer

 2 - Oil temperature

 3 - Water temperature

 4 - Battery voltage

 5 - SlaveFlags

 6 - Flags
 1bite
  1bit - protection incurred, throttle cut off
  2bit - water shades opened
  3bit - oil shades opened
  4bit - brake release button pressed
  5bit - front control
  6bit - back control
  7bit - emergency brake incurred
  8bit - compressor on
 2bite
  1bit - EPK sound on

 7 - [VACANT]

 8 - EPT value

 9 - AsyncFlags

 10 - AsyncThrottlePos

 11 - Async

 12 - Async

 13 - speed limit

 14 - signal aspect

 15 - EPK state
  0 - free
  1 - signal change (non-critical)
  2 - approaching red
  3 - overspeed
  4 - approaching red
  5 - approaching signal limit

 16 - EPK timer



Sound triggers

 8,9 - Tifon
 10,11 - whistle
 4,5 - sanding
 12,13 - compressor
 17,18 - switches

 101,102 - Enable/Disable radio station
 103 - diesel starts
 105 - play coolant sound
 106 - switches (back cabin)
 107 - valves (back cabin)




LocoOn
 1bite
  1 - battery on
  2 - engine on
  3 - major control on
  4 - control traction on
  5 - EDT on
  6 - front control
  7 - back control
  8 - major control on (back)
 2bite
  1 - EPT on

*/

extern "C" bool __export Init(DieselEngine *eng, DieselLocomotive *loco,
                              unsigned long State, float time,
                              float AirTemperature) {
  loco->IndependentBrakePressure = 4.0;
  loco->MainResPressure = 2.3;

  eng->DieselOn = 0;
  eng->FuelConsuming = 0.0;
  eng->RPM = 0.0;
  eng->Power = 0.0;
  eng->Force = 0.0;
  eng->BrakeForce = 0.0;
  eng->IndependentBrakeValue = 4.0;
  eng->TrainPipeRate = 0.0;
  eng->ChargingRate = 0.0;
  eng->HandbrakePercent = 100.0;
  eng->DynamicBrakePercent = 0.0;
  eng->EPTvalue = -1.0;
  eng->BrakeSystemsEngaged = 1;
  eng->ALSNOn = 0;
  eng->Sanding = 0;
  eng->Reverse = 0;
  eng->ThrottlePosition = 0;

  eng->var[2] = 20.0;
  eng->var[3] = 20.0;
  eng->var[4] = 65.0;
  eng->var[6] = 0.0;
  eng->UR = 0.0;
  eng->var[8] = 0.0;
  eng->var[9] = 0.0;
  eng->var[10] = 0.0;
  eng->var[11] = 0.0;
  eng->var[12] = 0.0;
  eng->var[13] = 25.0;
  eng->var[14] = 0.0;
  eng->var[15] = 0.0;
  eng->var[16] = 0.0;

  ULONG &Flags = *(unsigned long *)&eng->var[6];
  Cabin *cab = loco->Cab();

  switch (State & 0xFF) {
  case 1:
    eng->DieselOn = 1;
    eng->RPM = 350.0;
    eng->Power = 875.0;
    eng->var[2] = 40.0;
    eng->var[3] = 30.0;
    eng->UR = 5.0;
    loco->MainResPressure = 8.0;
    loco->TrainPipePressure = 5.0;
    loco->IndependentBrakePressure = 4.0;
    loco->AuxiliaryPressure = 5.0;
    loco->ChargingPipePressure = 5.0;
    eng->IndependentBrakeValue = 4.0;
    cab->SetSwitch(3, 4, true);
    cab->SetSwitch(103, 4, true);
    break;
  case 2:
  case 3:
    eng->DieselOn = 1;
    eng->RPM = 350.0;
    eng->Power = 875.0;
    eng->var[2] = 40.0;
    eng->var[3] = 30.0;
    eng->UR = 5.2;
    loco->MainResPressure = 9.0;
    loco->TrainPipePressure = 5.2;
    loco->AuxiliaryPressure = 5.1;
    loco->ChargingPipePressure = 6.0;
    loco->IndependentBrakePressure = 0.0;
    loco->BrakeCylinderPressure = 0.0;
    eng->IndependentBrakeValue = 0.0;
    cab->SetSwitch(3, 5, true);
    cab->SetSwitch(103, 5, true);
    cab->SetSwitch(4, 4, true);
    cab->SetSwitch(104, 4, true);
    if (loco->Velocity < 0.0 ^ bool(!(loco->Flags & 1))) {
      if ((State >> 8) & 1) {
        cab->SetSwitch(19, 1, false);
        cab->SetSwitch(20, 1, false);
        cab->SetSwitch(1, 2, false);
        cab->SetSwitch(26, 1, false);
        cab->SetSwitch(27, 1, false);
        cab->SetSwitch(41, 1, false);
        Flags |= 16;
      };
      eng->Reverse = 1;
    } else {
      if ((State >> 8) & 1) {
        cab->SetSwitch(119, 1, false);
        cab->SetSwitch(120, 1, false);
        cab->SetSwitch(101, 2, false);
        cab->SetSwitch(126, 1, false);
        cab->SetSwitch(127, 1, false);
        cab->SetSwitch(41, 1, false);
        Flags |= 32;
      };
      eng->Reverse = -1;
    };
    if (loco->Flags & 1)
      eng->Reverse = -eng->Reverse;
    break;
  };
  eng->HandbrakePercent = 0.0;

  if ((State >> 8) & 1)
    eng->ShowMessage(GMM_BOX, L"Welcome!");

  return true;
};

extern "C" void __export ChangeLoco(Locomotive *loco, const Locomotive *Prev,
                                    unsigned long State) {
  if (!Prev)
    loco->LocoFlags |= 1;
  else if (!Prev->Cab()->Switch(20) && !Prev->Cab()->Switch(120)) {
    loco->LocoFlags |= 1;
  };
};

extern "C" bool __export CanWorkWith(const Locomotive *loco,
                                     const wchar_t *Type) {
  if (!lstrcmpiW(Type, L"tep70") || !lstrcmpW(Type, L"tep70bs"))
    return true;
  return false;
};

extern "C" bool __export CanSwitch(const DieselLocomotive *loco,
                                   const DieselEngine *eng,
                                   unsigned int SwitchID,
                                   unsigned int SetState) {
  Cabin *cab = loco->Cab();
  ULONG &Flags = *(unsigned long *)&eng->var[6];
  ULONG LocoOn = IsLocoOn(loco, eng, Flags);

  switch (loco->LibParam) {
  case 1:

    switch (SwitchID) {
    case 0:
      if (!(LocoOn & 32))
        return false;
      if (!cab->Switch(2)) {
        if (SetState < 8)
          return false;
      } else {
        if (SetState > 8)
          return false;
      };
      break;
    case 100:
      if (!(LocoOn & 64))
        return false;
      if (!cab->Switch(102)) {
        if (SetState < 8)
          return false;
      } else {
        if (SetState > 8)
          return false;
      };
      break;
    case 1:
    case 101:
      if (eng->ThrottlePosition != 0)
        return false;
      break;
    case 2:
      if (cab->Switch(0) != 8)
        return false;
      if (eng->BrakeForce || eng->Force)
        return false;
      break;
    case 102:
      if (cab->Switch(100) != 8)
        return false;
      if (eng->BrakeForce || eng->Force)
        return false;
      break;
    };

    if ((SwitchID == 2 || SwitchID >= 5) && SwitchID < 100)
      loco->PostTriggerCab(15);
    else if ((SwitchID == 102 || SwitchID >= 105) && SwitchID < 200)
      loco->PostTriggerCab(15);
    else if (SwitchID == 3 || SwitchID == 4)
      loco->PostTriggerCab(17);
    else if (SwitchID == 103 || SwitchID == 104)
      loco->PostTriggerCab(17);

    break;
  };
  return true;
};

extern "C" void __export Switched(const DieselLocomotive *loco,
                                  DieselEngine *eng, unsigned int SwitchID,
                                  unsigned int PrevState) {

  Cabin *cab = loco->Cab();
  UINT st, st1;
  ULONG &Flags = *(unsigned long *)&eng->var[6];
  ULONG LocoOn = IsLocoOn(loco, eng, Flags);
  FreeAnimation *anim;

  switch (loco->LibParam) {
  case 1:

    if (SwitchID == 47)
      SwitchID = 46;
    else if (SwitchID == 44)
      SwitchID = 45;
    else if (SwitchID == 147)
      SwitchID = 146;
    else if (SwitchID == 144)
      SwitchID = 145;

    switch (SwitchID) {
    case 0:
      if ((LocoOn & 37) == 37) {
        st = cab->Switch(0);
        if (!(Flags & 1)) {
          if (st >= 8) {
            eng->ThrottlePosition = st - 8;
          };
          if (st <= 8)
            eng->DynamicBrakePercent = (8 - st) * 12.5;
        } else if (st == 8) {
          Flags &= ~1;
        };
      };
      break;
    case 100:
      if ((LocoOn & 65) == 65) {
        st = cab->Switch(100);
        if (!(Flags & 1)) {
          if (st >= 8) {
            eng->ThrottlePosition = st - 8;
          };
          if (st <= 8)
            eng->DynamicBrakePercent = (8 - st) * 12.5;
        } else if (st == 8) {
          Flags &= ~1;
        };
      };
      break;
    case 1:
      if ((LocoOn & 37) == 37) {
        eng->Reverse = signed(cab->Switch(1)) - 1;
        // if(loco->Flags&1)
        // eng->Reverse=-eng->Reverse;
      };
      break;
    case 101:
      if ((LocoOn & 65) == 65) {
        eng->Reverse = 1 - signed(cab->Switch(101));
        // if(loco->Flags&1)
        // eng->Reverse=-eng->Reverse;
      };
      break;
    case 3:
      if (LocoOn & 32) {
        st = cab->Switch(3);
        if (st < 3)
          eng->EngineFlags &= ~3;
      };
      break;
    case 103:
      if (LocoOn & 64) {
        st = cab->Switch(103);
        if (st < 3)
          eng->EngineFlags &= ~3;
      };
      break;
    case 4:
      if (!(LocoOn & 32))
        break;
      st = cab->Switch(4);
      switch (st) {
      case 5:
        eng->IndependentBrakeValue = 0.0;
        break;
      case 4:
      case 3:
      case 2:
      case 1:
      case 0:
        st = 4 - st;
        if (loco->IndependentBrakePressure > st * 1.0)
          eng->IndependentBrakeValue = loco->IndependentBrakePressure;
        else
          eng->IndependentBrakeValue = st * 1.0;
        break;
      };
      if (st < 4) {
        eng->EngineFlags &= ~2;
        Flags &= ~8;
      };
      break;
    case 104:
      if (!(LocoOn & 64))
        break;
      st = cab->Switch(104);
      switch (st) {
      case 5:
        eng->IndependentBrakeValue = 0.0;
        break;
      case 4:
        eng->IndependentBrakeValue = loco->IndependentBrakePressure;
        break;
      case 3:
        eng->IndependentBrakeValue = 1.0;
        break;
      case 2:
        eng->IndependentBrakeValue = 2.0;
        break;
      case 1:
        eng->IndependentBrakeValue = 3.0;
        break;
      case 0:
        eng->IndependentBrakeValue = 4.0;
        break;
      };
      if (st < 4) {
        eng->EngineFlags &= ~2;
        Flags &= ~8;
      };
      break;
    case 6:
      if (!PrevState && ((LocoOn & 37) == 37)) {
        Flags |= 8;
        eng->EngineFlags |= 3;
      };
      break;
    case 106:
      if (!PrevState && ((LocoOn & 65) == 65)) {
        Flags |= 8;
        eng->EngineFlags |= 3;
      };
      break;
    case 7:
    case 107:
      if (LocoOn & 96) {
        eng->var[15] = 0.0;
        eng->var[16] = 0.0;
      };
      break;
    case 8:
    case 32:
      if ((cab->Switch(8) || cab->Switch(32)) && ((LocoOn & 5) == 5)) {
        loco->PostTriggerBoth(8);
      } else {
        loco->PostTriggerBoth(9);
      };
      break;
    case 108:
    case 132:
      if ((cab->Switch(108) || cab->Switch(132)) && ((LocoOn & 129) == 129)) {
        loco->PostTriggerBoth(8);
      } else {
        loco->PostTriggerBoth(9);
      };
      break;
    case 9:
    case 31:
      if ((cab->Switch(9) || cab->Switch(31)) && ((LocoOn & 5) == 5)) {
        loco->PostTriggerBoth(10);
      } else {
        loco->PostTriggerBoth(11);
      };
      break;
    case 109:
    case 131:
      if ((cab->Switch(109) || cab->Switch(131)) && ((LocoOn & 129) == 129)) {
        loco->PostTriggerBoth(10);
      } else {
        loco->PostTriggerBoth(11);
      };
      break;
    case 12:
    case 112:
      if ((cab->Switch(12) || cab->Switch(112)) && (LocoOn & 1)) {
        loco->PostTriggerCab(101);
      } else {
        loco->PostTriggerCab(102);
      };
      break;
    case 13:
      if (cab->Switch(13) && (LocoOn & 1)) {
        SwitchLights(loco, 3);
      } else {
        SwitchLights(loco, 4);
      };
      break;
    case 14:
      if (cab->Switch(14) && (LocoOn & 1)) {
        SwitchLights(loco, 5);
      } else {
        SwitchLights(loco, 6);
      };
      break;
    case 15:
      if (cab->Switch(15) && (LocoOn & 1)) {
        SwitchLights(loco, 7);
      } else {
        SwitchLights(loco, 8);
      };
      break;
    case 16:
      if (cab->Switch(16) && (LocoOn & 1)) {
        SwitchLights(loco, 9);
      } else {
        SwitchLights(loco, 10);
      };
      break;
    case 113:
      if (cab->Switch(113) && (LocoOn & 1)) {
        SwitchLights(loco, 14);
      } else {
        SwitchLights(loco, 15);
      };
      break;
    case 114:
      if (cab->Switch(114) && (LocoOn & 1)) {
        SwitchLights(loco, 16);
      } else {
        SwitchLights(loco, 17);
      };
      break;
    case 115:
      if (cab->Switch(115) && (LocoOn & 1)) {
        SwitchLights(loco, 18);
      } else {
        SwitchLights(loco, 19);
      };
      break;
    case 116:
      if (cab->Switch(116) && (LocoOn & 1)) {
        SwitchLights(loco, 20);
      } else {
        SwitchLights(loco, 21);
      };
      break;
    case 21:
      if (cab->Switch(21) && ((LocoOn & 1) == 1))
        cab->SwitchLight(2, true);
      else
        cab->SwitchLight(2, false);
      break;
    case 121:
      if (cab->Switch(121) && ((LocoOn & 1) == 1))
        cab->SwitchLight(6, true);
      else
        cab->SwitchLight(6, false);
      break;
    case 24:
    case 124:
      if ((cab->Switch(24) || cab->Switch(124)) && ((LocoOn & 1) == 1))
        cab->SwitchLight(3, true);
      else
        cab->SwitchLight(3, false);
      break;
    case 33:
    case 34:
      if (cab->Switch(34) && ((LocoOn & 1) == 1)) {
        cab->SwitchLight(1, true);
        cab->SetLightColour(1, 0xeeccccdd);
      } else if (cab->Switch(33) && ((LocoOn & 1) == 1)) {
        cab->SwitchLight(1, true);
        cab->SetLightColour(1, 0xeeccbb80);
      } else
        cab->SwitchLight(1, false);
      break;
    case 133:
    case 134:
      if (cab->Switch(134) && ((LocoOn & 1) == 1)) {
        cab->SwitchLight(5, true);
        cab->SetLightColour(5, 0xeeccccdd);
      } else if (cab->Switch(133) && ((LocoOn & 1) == 1)) {
        cab->SwitchLight(5, true);
        cab->SetLightColour(5, 0xeeccbb80);
      } else
        cab->SwitchLight(5, false);
      break;
    case 10:
      if (cab->Switch(10) && ((LocoOn & 32) == 32)) {
        eng->Sanding = 1;
        loco->PostTriggerBoth(4);
      } else {
        eng->Sanding = 0;
        loco->PostTriggerBoth(5);
      };
      break;
    case 110:
      if (cab->Switch(110) && ((LocoOn & 65) == 65)) {
        eng->Sanding = 1;
        loco->PostTriggerBoth(4);
      } else {
        eng->Sanding = 0;
        loco->PostTriggerBoth(5);
      };
      break;
    case 18:
      if (cab->Switch(19) && (LocoOn & 1)) {
        if (eng->DieselOn == 2 || eng->DieselOn == 0) {
          if (cab->Switch(18))
            eng->DieselOn = 2;
        };
      };
      break;
    case 118:
      if (cab->Switch(119) && (LocoOn & 1)) {
        if (eng->DieselOn == 2 || eng->DieselOn == 0) {
          if (cab->Switch(118))
            eng->DieselOn = 2;
        };
      };
      break;
    case 17:
      if (cab->Switch(19) && (LocoOn & 1)) {
        eng->DieselOn = 0;
      };
      break;
    case 117:
      if (cab->Switch(119) && (LocoOn & 1)) {
        eng->DieselOn = 0;
      };
      break;
    case 19:
      if (cab->Switch(19) && (LocoOn & 1))
        cab->SetDisplayState(0, 1);
      else
        cab->SetDisplayState(0, 0);
      Switched(loco, eng, 8, 1);
      Switched(loco, eng, 9, 1);
      Switched(loco, eng, 20, 1);
      Switched(loco, eng, 22, 1);
      Switched(loco, eng, 30, 1);
      break;
    case 20:
      if ((LocoOn & 1) && cab->Switch(20)) {
        cab->SetDisplayState(1, 1);
        cab->SetDisplayState(18, 1);
        if (!cab->Switch(120))
          Flags |= 16;
      } else {
        cab->SetDisplayState(1, 0);
        cab->SetDisplayState(18, 0);
        Flags &= ~16;
      };
      Switched(loco, eng, 0, 1);
      Switched(loco, eng, 1, 1);
      Switched(loco, eng, 10, 1);
      break;
    case 119:
      if (cab->Switch(119) && (LocoOn & 1))
        cab->SetDisplayState(9, 1);
      else
        cab->SetDisplayState(9, 0);
      Switched(loco, eng, 108, 1);
      Switched(loco, eng, 109, 1);
      Switched(loco, eng, 120, 1);
      Switched(loco, eng, 122, 1);
      Switched(loco, eng, 130, 1);
      break;
    case 120:
      if ((LocoOn & 1) && cab->Switch(120)) {
        cab->SetDisplayState(10, 1);
        cab->SetDisplayState(19, 1);
        if (!cab->Switch(20))
          Flags |= 32;
      } else {
        cab->SetDisplayState(10, 0);
        cab->SetDisplayState(19, 0);
        Flags &= ~32;
      };
      Switched(loco, eng, 100, 1);
      Switched(loco, eng, 101, 1);
      Switched(loco, eng, 110, 1);
      break;
    case 22:
    case 23:
      if (cab->Switch(22) && ((LocoOn & 5) == 5))
        SwitchLights(loco, 2);
      else if (cab->Switch(23) && ((LocoOn & 5) == 5))
        SwitchLights(loco, 1);
      else
        SwitchLights(loco, 0);
      break;
    case 122:
    case 123:
      if (cab->Switch(122) && ((LocoOn & 129) == 129))
        SwitchLights(loco, 13);
      else if (cab->Switch(123) && ((LocoOn & 129) == 129))
        SwitchLights(loco, 12);
      else
        SwitchLights(loco, 11);
      break;
    case 45:
    case 145:
      if (LocoOn & 1) {
        st = 0;
        st1 = 0;
        if (LocoOn & 4) {
          st = cab->Switch(44);
          st1 = cab->Switch(45);
        };
        if (LocoOn & 128) {
          st += cab->Switch(144);
          st1 += cab->Switch(145);
        };
        if (st)
          Flags |= 2;
        else
          Flags &= ~2;
        if (st1)
          Flags |= 4;
        else
          Flags &= ~4;
        if (st || st1) {
          anim = loco->FindAnim(L"jal_holod");
          if (anim) {
            anim->AnimateTo = 1;
          };
        } else {
          anim = loco->FindAnim(L"jal_holod");
          if (anim) {
            anim->AnimateTo = 0;
          };
        };
      };
      break;
    case 46:
      if (cab->Switch(46) && (LocoOn & 1)) {
        if (cab->Switch(47))
          cab->SetLightState(0, 1, 0xeee0ddcc, 0.2);
        else
          cab->SetLightState(0, 1, 0xcce0aa50, 0.5);
      } else
        cab->SwitchLight(0, false);
      break;
    case 146:
      if (cab->Switch(146) && (LocoOn & 1)) {
        if (cab->Switch(147))
          cab->SetLightState(4, 1, 0xeee0ddcc, 0.2);
        else
          cab->SetLightState(4, 1, 0xcce0aa50, 0.5);
      } else
        cab->SwitchLight(4, false);
      break;
    case 201:
      st = cab->ScreenState(0, 20);
      if (PrevState > st) {
        if (st <= 2) {
          cab->SetScreenState(0, 2, 0);
          cab->SetScreenState(0, 5, -1);
          cab->SetScreenState(0, 7, -1);
          cab->SetScreenState(0, 8, -1);
          cab->SetScreenState(0, 9, -1);
          cab->SetScreenState(0, 11, -1);
          cab->SetScreenState(0, 12, -1);
          cab->SetScreenState(0, 13, -1);
          cab->SetScreenState(0, 14, -1);
          cab->SetScreenState(0, 15, -1);
          cab->SetScreenState(0, 16, -1);
          cab->SetScreenState(0, 17, -1);
          cab->SetScreenState(0, 18, 0);
          cab->SetScreenState(0, 20, 3);
          cab->SetScreenState(0, 21, 0);
          cab->SetScreenState(0, 22, 0);
          cab->SetScreenState(0, 23, 0);
          cab->SetScreenState(0, 24, 0);
          cab->SetScreenState(0, 25, 0);
          cab->SetScreenState(0, 26, 0);
          cab->SetScreenState(0, 27, 0);
          cab->SetScreenState(0, 28, 0);
          cab->SetScreenState(0, 29, 0);
          cab->SetScreenState(0, 30, 0);
          cab->SetScreenState(0, 31, 0);
          cab->SetScreenState(0, 32, 0);
        } else if (st <= 5) {
          cab->SetScreenState(0, 2, 1);
          cab->SetScreenState(0, 5, 0);
          cab->SetScreenState(0, 7, 0);
          cab->SetScreenState(0, 8, 0);
          cab->SetScreenState(0, 9, 0);
          cab->SetScreenState(0, 11, 0);
          cab->SetScreenState(0, 12, 0);
          cab->SetScreenState(0, 13, 0);
          cab->SetScreenState(0, 14, 0);
          cab->SetScreenState(0, 15, 0);
          cab->SetScreenState(0, 16, 0);
          cab->SetScreenState(0, 17, 0);
          cab->SetScreenState(0, 18, 1);
          cab->SetScreenState(0, 20, 0);
          cab->SetScreenState(0, 21, -1);
          cab->SetScreenState(0, 22, -1);
          cab->SetScreenState(0, 23, -1);
          cab->SetScreenState(0, 24, -1);
          cab->SetScreenState(0, 25, -1);
          cab->SetScreenState(0, 26, -1);
          cab->SetScreenState(0, 27, -1);
          cab->SetScreenState(0, 28, -1);
          cab->SetScreenState(0, 29, -1);
          cab->SetScreenState(0, 30, -1);
          cab->SetScreenState(0, 31, -1);
          cab->SetScreenState(0, 32, -1);
        };
      };
      break;
    case 251:
      st = cab->ScreenState(9, 20);
      if (PrevState > st) {
        if (st <= 2) {
          cab->SetScreenState(9, 2, 0);
          cab->SetScreenState(9, 5, -1);
          cab->SetScreenState(9, 7, -1);
          cab->SetScreenState(9, 8, -1);
          cab->SetScreenState(9, 9, -1);
          cab->SetScreenState(9, 11, -1);
          cab->SetScreenState(9, 12, -1);
          cab->SetScreenState(9, 13, -1);
          cab->SetScreenState(9, 14, -1);
          cab->SetScreenState(9, 15, -1);
          cab->SetScreenState(9, 16, -1);
          cab->SetScreenState(9, 17, -1);
          cab->SetScreenState(9, 18, 0);
          cab->SetScreenState(9, 20, 3);
          cab->SetScreenState(9, 21, 0);
          cab->SetScreenState(9, 22, 0);
          cab->SetScreenState(9, 23, 0);
          cab->SetScreenState(9, 24, 0);
          cab->SetScreenState(9, 25, 0);
          cab->SetScreenState(9, 26, 0);
          cab->SetScreenState(9, 27, 0);
          cab->SetScreenState(9, 28, 0);
          cab->SetScreenState(9, 29, 0);
          cab->SetScreenState(9, 30, 0);
          cab->SetScreenState(9, 31, 0);
          cab->SetScreenState(9, 32, 0);
        } else if (st <= 5) {
          cab->SetScreenState(9, 2, 1);
          cab->SetScreenState(9, 5, 0);
          cab->SetScreenState(9, 7, 0);
          cab->SetScreenState(9, 8, 0);
          cab->SetScreenState(9, 9, 0);
          cab->SetScreenState(9, 11, 0);
          cab->SetScreenState(9, 12, 0);
          cab->SetScreenState(9, 13, 0);
          cab->SetScreenState(9, 14, 0);
          cab->SetScreenState(9, 15, 0);
          cab->SetScreenState(9, 16, 0);
          cab->SetScreenState(9, 17, 0);
          cab->SetScreenState(9, 18, 1);
          cab->SetScreenState(9, 20, 0);
          cab->SetScreenState(9, 21, -1);
          cab->SetScreenState(9, 22, -1);
          cab->SetScreenState(9, 23, -1);
          cab->SetScreenState(9, 24, -1);
          cab->SetScreenState(9, 25, -1);
          cab->SetScreenState(9, 26, -1);
          cab->SetScreenState(9, 27, -1);
          cab->SetScreenState(9, 28, -1);
          cab->SetScreenState(9, 29, -1);
          cab->SetScreenState(9, 30, -1);
          cab->SetScreenState(9, 31, -1);
          cab->SetScreenState(9, 32, -1);
        };
      };
      break;
    };

    break;
  };
};

extern "C" void __export ALSN(Locomotive *loco, SignalsInfo *sigAhead,
                              UINT NumSigAhead, SignalsInfo *sigBack,
                              UINT NumSigBack, SignalsInfo *sigPassed,
                              UINT NumPassed, float SpeedLimit, float NextLimit,
                              float DistanceToNextLimit, bool Backwards) {
  UINT CountGreen = 0;
  bool FirstNormalFound = false;
  UINT Aspect = SIGASP_STOP, State = 8;
  Cabin *cab = loco->Cab();
  if (!Backwards) {
    for (UINT i = 0; i < NumSigAhead; i++) {
      if (sigAhead[i].Flags & 1) {
        if (!FirstNormalFound) {
          Aspect = sigAhead[i].Aspect[0];
          FirstNormalFound = true;
        };
        if (sigAhead[i].Aspect[0] == SIGASP_CLEAR_1 ||
            sigAhead[i].Aspect[0] == SIGASP_CLEAR_2)
          CountGreen++;
        else
          break;
      };
    };
  } else {
    for (UINT i = 0; i < NumSigBack; i++) {
      if (sigBack[i].Flags & 1) {
        if (!FirstNormalFound) {
          Aspect = sigBack[i].Aspect[0];
          FirstNormalFound = true;
        };
        if (sigBack[i].Aspect[0] == SIGASP_CLEAR_1 ||
            sigBack[i].Aspect[0] == SIGASP_CLEAR_2)
          CountGreen++;
        else
          break;
      };
    };
  };
  if (cab->Signal.Aspect[0] == SIGASP_BLOCK_OBSTRUCTED)
    Aspect = SIGASP_BLOCK_OBSTRUCTED;
  if (Aspect != SIGASP_CLEAR_2) {
    switch (Aspect) {
    case SIGASP_STOP_AND_PROCEED:
      State = 6;
      break;
    case SIGASP_RESTRICTING:
      State = 8;
      break;
    case SIGASP_APPROACH_1:
    case SIGASP_APPROACH_2:
    case SIGASP_APPROACH_3:
      State = 5;
      break;
    case SIGASP_CLEAR_1:
      State = 4;
      break;
    case SIGASP_BLOCK_OBSTRUCTED:
      State = 7;
      break;
    };
  } else {
    if (CountGreen > 3)
      State = 1;
    else
      State = 4 - CountGreen;
  };

  Engine *eng = loco->Eng();
  ULONG &Flags = *(unsigned long *)&eng->var[6];
  ULONG LocoOn = IsLocoOn((DieselLocomotive *)loco, (DieselEngine *)eng, Flags);
  if (loco->LibParam == 1) {
    if ((LocoOn & 33) == 33) {
      cab->SetDisplayState(8, State);
    } else
      cab->SetDisplayState(8, 0);
    if ((LocoOn & 65) == 65) {
      cab->SetDisplayState(17, State);
    } else
      cab->SetDisplayState(17, 0);
  };

  eng->var[13] = 25.0;
  if (SpeedLimit > 7.0)
    eng->var[13] = SpeedLimit * 3.6;
  else
    eng->var[13] = 25.0;
};

UINT ApproachRed(float SigDist, float Vel) {
  UINT res = 0;
  if (SigDist < 500.0) {
    if (Vel > 11.55)
      res = 1;
    if (SigDist < 300.0) {
      if (Vel > 11.55)
        res = 2;
      if (SigDist < 250.0) {
        if (Vel > 5.55 && res < 1)
          res = 1;
        if (SigDist < 150.0) {
          if (Vel > 5.55)
            res = 2;
          if (SigDist < 100.0) {
            if (Vel > 4.0 && res < 1)
              res = 1;
            if (SigDist < 50.0) {
              if (Vel > 2.7)
                res = 2;
              else if (Vel > 1.4 && res < 1)
                res = 1;
              if (SigDist < 20.0)
                if (Vel > 1.4)
                  res = 2;
            };
          };
        };
      };
    };
  };
  return res;
};

extern "C" void __export Run(DieselEngine *eng, const DieselLocomotive *loco,
                             unsigned long State, float time,
                             float AirTemperature) {

  ULONG &Flags = *(unsigned long *)&eng->var[6];
  FreeAnimation *anim;
  wchar_t str[32];
  UINT LocoOn = 0, v1;
  float PowerAvailable = 1.0;
  Cabin *cab = loco->Cab();
  SMSObject *soundExt = loco->SoundEng(), *soundCab = loco->SoundCab();
  float Current, Voltage, SetForce, SetBrakeForce, BatteryCharge = 0.0, Temp,
                                                   Temp1;

  // Diesel
  float SetPower = 0.0;
  if (eng->DieselOn == 2)
    if (eng->var[4] < BATTERY_DEADLINE_DIESEL)
      eng->DieselOn = 0;
  if (loco->FuelAmount < 1.0)
    eng->DieselOn = 0;
  if (eng->var[4] < BATTERY_DEADLINE) {
    eng->DieselOn = 0;
    if (loco->LibParam == 1)
      Switched(loco, eng, 19, 1);
  };
  if (eng->var[2] >= 95.0 || eng->var[3] >= 95.0) {
    eng->ThrottlePosition = 0;
    SetForce = 0.0;
    Flags |= 1;
  };
  if (!eng->DieselOn) {
    eng->Power -= 70.0 * time;
    if (eng->Power < 0.0)
      eng->Power = 0.0;
  } else {
    SetPower = 875.0 + eng->ThrottlePosition * 108.0;
    if (SetPower > eng->Power) {
      eng->Power += 50.0 * time;
      if (eng->Power > SetPower)
        eng->Power = SetPower;
    } else {
      eng->Power -= 70.0 * time;
      if (eng->Power < SetPower)
        eng->Power = SetPower;
    };
  };

  if (eng->DieselOn == 1)
    if (eng->RPM < 300.0) {
      eng->DieselOn = 0;
    };
  if (eng->DieselOn == 3) {
    eng->var[1] -= time;
    if (eng->var[1] < 0.0 && eng->RPM > 300.0) {
      eng->DieselOn = 1;
      eng->ShowMessage(GMM_HINT, L"?????? ???????");
    };
  };
  if (eng->DieselOn == 2)
    if (eng->RPM >= 250.0) {
      eng->DieselOn = 3;
      loco->PostTriggerBoth(103);
      eng->var[1] = 10.0;
    };

  LocoOn = IsLocoOn(loco, eng, Flags);

  // Compressor
  eng->MainResRate = 0.0;
  if (LocoOn & 96)
    eng->MainResRate = -7e-4 * loco->MainResPressure;
  if ((LocoOn & 1) && eng->DieselOn == 1) {
    if (loco->MainResPressure < 7.0 && !(Flags & 128)) {
      Flags |= 128;
      loco->PostTriggerBoth(12);
    } else if ((Flags & 128) && loco->MainResPressure >= 10.0) {
      Flags &= ~128;
      loco->PostTriggerBoth(13);
    };
    if (Flags & 128) {
      eng->MainResRate = 0.04 * (10.21 - loco->MainResPressure);
    };
  } else if (Flags & 128) {
    Flags &= ~128;
    loco->PostTriggerBoth(13);
  };

  // Battery charge
  if (LocoOn & 1) {
    if (LocoOn & 132)
      eng->var[4] -= 0.03 * time;
    BatteryCharge = 0.0;
    if (LocoOn & 2) {
      Voltage = (98.0 - eng->var[4]) * 0.01;
      if (Voltage > 0.7)
        Voltage = 0.7;
      BatteryCharge = (98.0 - eng->var[4]) * 2.0;
      if (BatteryCharge > 40.0)
        BatteryCharge = 40.0;
      Current = Voltage * 300.0 * eng->var[4];
      if (Current > 30.0)
        PowerAvailable -= 0.001 * Current / eng->Power;
    } else if (eng->DieselOn == 2)
      eng->var[4] -= 1.2 * time;
    else if (eng->ExternalPowerSource && eng->ExternalPowerSourceVoltage) {
      BatteryCharge =
          eng->ExternalPowerSource / eng->ExternalPowerSourceVoltage;
      if (BatteryCharge > 40.0)
        BatteryCharge = 40.0;
    };
    eng->var[4] += BatteryCharge * 0.005 * time;
  };

  // Force
  if (eng->ThrottlePosition) {
    float Vel = loco->Velocity * eng->Reverse;
    float VelMax = -4.025 + eng->ThrottlePosition * 0.125;
    float VelMaxGG = 12.5 + (eng->ThrottlePosition - 1) * 2.5;
    float Force1 = loco->GetParameter(L"Force1", 201.25);
    float Force2 = loco->GetParameter(L"Force2", 2.04);
    float Force3 = loco->GetParameter(L"Force3", 0.058);
    float GGc = 0.0;
    if (Vel <= VelMax)
      SetForce = 800000.0;
    else {
      if (Vel > VelMaxGG) {
        GGc = (Vel - VelMaxGG) * 0.8;
        GGc *= GGc * 200.0;
      };
      Vel -= VelMax;
      SetForce = 10.0 * (eng->Power * PowerAvailable * Force1) /
                 pow(Vel, Force2 - eng->ThrottlePosition * Force3);
      if (GGc > SetForce)
        SetForce = 0.0;
      else
        SetForce -= GGc;
    };
  } else
    SetForce = 0.0;
  if (!(LocoOn & 1)) {
    SetForce = 0.0;
    eng->Force = 0.0;
  };

  // EDT
  if (((LocoOn & 17) == 17) && eng->DynamicBrakePercent && eng->Reverse) {
    float Vel = loco->Velocity * eng->Reverse;
    float Brake1 = loco->GetParameter(L"Brake1", 9.29);
    SetBrakeForce = eng->DynamicBrakePercent * 10.0 * (Brake1 * Vel + 9.38);
    if (SetBrakeForce < 0.0)
      SetBrakeForce = 0.0;
    else {
      if (Vel < 200.0 / eng->DynamicBrakePercent)
        SetBrakeForce *= Vel / (200.0 / eng->DynamicBrakePercent);
    };
  } else {
    if (!((LocoOn & 17) == 17))
      eng->BrakeForce = 0.0;
    SetBrakeForce = 0.0;
  };
  if (LocoOn & 1) {
    anim = loco->FindAnim(L"jal_edt");
    if (anim) {
      if (((LocoOn & 17) == 17) && eng->Reverse && cab->Switch(2))
        anim->AnimateTo = 1;
      else if (!eng->BrakeForce)
        anim->AnimateTo = 0;
    };
  };
  anim = loco->FindAnim(L"rod_edt");
  if (anim) {
    if ((LocoOn & 1) && eng->BrakeForce) {
      anim->Flags |= 1;
      anim->Speed = eng->BrakeForce / 40000.0;
      if (anim->Speed < 0.3)
        anim->Speed = 0.3;
    } else {
      anim->Flags &= ~1;
    };
  };

  // Smoothing force and brake force change
  float ForceCur = eng->Force * eng->Reverse;
  if (ForceCur > SetForce) {
    Current = (ForceCur - SetForce) * 0.3;
    if (Current < 15000.0)
      Current = 15000.0;
    ForceCur -= Current * time;
    if (ForceCur < SetForce)
      ForceCur = SetForce;
  } else if (ForceCur < SetForce) {
    Current = (SetForce - ForceCur) * 0.3;
    if (Current < 6000.0)
      Current = 6000.0;
    ForceCur += Current * time;
    if (ForceCur > SetForce)
      ForceCur = SetForce;
  };
  eng->Force = ForceCur * eng->Reverse;
  if (SetBrakeForce != eng->BrakeForce) {
    Current = (SetBrakeForce - eng->BrakeForce) * 0.3;
    if (Current > 0.0) {
      if (Current < 3000.0)
        Current = 3000.0;
      eng->BrakeForce += Current * time;
      if (eng->BrakeForce > SetBrakeForce)
        eng->BrakeForce = SetBrakeForce;
    } else {
      if (Current > -20000.0)
        Current = -20000.0;
      eng->BrakeForce += Current * time;
      if (eng->BrakeForce < SetBrakeForce)
        eng->BrakeForce = SetBrakeForce;
    };
  };

  // protection
  Current = fabs(eng->Force) * 0.0168;
  if (Current >= 6000.0) {
    eng->ThrottlePosition = 0;
    // eng->Force=0.0;
    SetForce = 0.0;
    Flags |= 1;
  } else if (eng->ThrottlePosition && loco->BrakeCylinderPressure > 0.5) {
    eng->ThrottlePosition = 0;
    SetForce = 0.0;
    Flags |= 1;
  };

  // Diesel RPM and fuel
  eng->RPM = eng->Power * PowerAvailable * 0.4;
  if (eng->Force)
    eng->RPM *= 1.0 - fabs(eng->Force) / 1000000.0;
  eng->FuelConsuming = eng->Power * 0.22 * 0.756 / 3600.0;
  if (eng->DieselOn == 3)
    eng->FuelConsuming *= 3.0;

  // Water and oil temperature
  if (eng->RPM) {
    Temp = eng->Power * eng->Power * 0.01694 / eng->RPM;
    if (Temp < 20.0)
      Temp = 20.0;
  } else {
    Temp = 20.0;
  };
  Temp1 = Temp;
  if (Flags & 2) {
    Temp *= 0.9;
    if (Temp < 20.0)
      Temp = 20.0;
  };
  if (Temp > eng->var[3]) {
    Current = Temp - eng->var[3];
    Current *= 0.004;
    if (Flags & 2)
      Current *= 0.5;
    Current *= Current;
    eng->var[3] += Current * time;
  } else if (Temp < eng->var[3]) {
    Current = Temp - eng->var[3];
    Current *= 0.005;
    if (Flags & 2)
      Current *= 2.0;
    if (!eng->DieselOn)
      Current *= 0.4;
    Current *= Current;
    eng->var[3] -= Current * time;
  };
  Temp = Temp1;
  if (Flags & 4) {
    Temp *= 0.9;
    if (Temp < 20.0)
      Temp = 20.0;
  };
  if (Temp > eng->var[2]) {
    Current = Temp - eng->var[2];
    Current *= 0.002;
    if (Flags & 4)
      Current *= 0.5;
    Current *= Current;
    eng->var[2] += Current * time;
  } else if (Temp < eng->var[2]) {
    Current = Temp - eng->var[2];
    Current *= 0.003;
    if (Flags & 4)
      Current *= 2.0;
    if (!eng->DieselOn)
      Current *= 0.4;
    Current *= Current;
    eng->var[2] -= Current * time;
  };

  // EPK
  if ((LocoOn & 1) && (LocoOn & 96)) {
    UINT Asp = cab->Signal.Aspect[0], PrevAsp = eng->var[14];
    float Vel = loco->Velocity, SigDist = cab->Signal.Distance;
    if (Vel < 0.0)
      Vel = -Vel;
    if (Asp == SIGASP_BLOCK_OBSTRUCTED)
      Asp = SIGASP_STOP;
    bool Moving = (Vel > 0.1) && (eng->Reverse != 0);
    float Limit = eng->var[13];
    if (Moving && Limit > 0.0) {
      Limit /= 3.6;
      if (Vel > Limit) {
        if (eng->var[16] < 30.0)
          eng->var[16] = 30.0;
        eng->var[15] = 3.0;
        if (Vel > Limit + 8.0)
          eng->var[16] = 60.0;
      };
    };
    if (Asp != PrevAsp) {
      if (PrevAsp > Asp) {
        // Signal change to lower
        if (Asp >= SIGASP_APPROACH_1) {
          if (eng->var[15] < 2.0 || int(eng->var[15]) == 5) {
            eng->var[15] = 1.0;
            eng->var[16] = 30.0;
          };
        } else {
          eng->var[15] = 2.0;
          eng->var[16] = 35.0;
        };
      } else {
        // Signal changed to higher
        if (eng->var[15] < 3.0) {
          eng->var[15] = 0.0;
          // loco->PostTriggerCab(111);
        };
      };
    };
    if (Moving) {
      if (Asp < SIGASP_APPROACH_1) {
        if (Asp == SIGASP_STOP_AND_PROCEED) {
          eng->var[15] = 2.0;
          // Approaching red signal
          UINT warn = ApproachRed(SigDist, Vel);
          switch (warn) {
          case 1:
            if (eng->var[16] < 35.0)
              eng->var[16] = 35.0;
            eng->var[15] = 4.0;
            break;
          case 2:
            eng->var[16] = 60.0;
            break;
          };
        };
        if (eng->var[15] < 2.0 || int(eng->var[15]) == 5)
          eng->var[15] = 2.0;
      } else if (cab->Signal.SpeedLimit >= 0.0) {
        if (eng->var[15] < 1.0) {
          if (Vel > cab->Signal.SpeedLimit) {
            eng->var[15] = 5.0;
            if (eng->var[16] < 15.0)
              eng->var[16] = 15.0;
          };
        } else if (int(eng->var[15]) == 5) {
          if (Vel <= cab->Signal.SpeedLimit) {
            eng->var[15] = 0.0;
            // loco->PostTriggerCab(111);
          };
        };
      };
    };

    if (eng->var[15] > 0.0) {
      if (eng->var[16] >= 32.0) {
        if (!(Flags & 256)) {
          Flags |= 256;
          loco->PostTriggerCab(56);
        };
        if (eng->var[16] > 45.0) {
          Flags |= 64;
        };
      };
      eng->var[16] += time;
    } else {
      eng->var[16] = 0.0;
    };
    if (Flags & 256) {
      if (eng->var[15] < 1.0 || eng->var[16] < 32.0) {
        loco->PostTriggerCab(57);
        Flags &= ~256;
      };
    };
    eng->var[14] = Asp;
    if (!loco->Velocity) {
      Flags &= ~64;
      eng->var[15] = 0.0;
    };
  } else {
    eng->var[14] = 0.0;
    eng->var[15] = 0.0;
    eng->var[16] = 0.0;
    Flags &= ~2;
    if (Flags & 256) {
      loco->PostTriggerCab(57);
      Flags &= ~256;
    };
  };

  // Brakes
  eng->BrakeSystemsEngaged = 1;
  if (loco->LibParam == 1) {
    if (LocoOn & 96) {
      eng->BrakeSystemsEngaged = 1;
      if (LocoOn & 256)
        eng->BrakeSystemsEngaged |= 2;
      UINT brake, brakeset;
      bool EnableTrainPipeCharge = false;

      // Train brake
      if (LocoOn & 32) {
        brake = cab->Switch(3);
        brakeset = cab->SwitchSet(3);
      } else {
        brake = cab->Switch(103);
        brakeset = cab->SwitchSet(103);
      };
      eng->ChargingRate = (6.0 - loco->ChargingPipePressure) * PIPE_CHARGE_Q;
      if (Flags & 64) {
        eng->TrainPipeRate = UR_EMERGENCY_RATE;
        if (eng->BrakeSystemsEngaged & 2)
          eng->EPTvalue = 6.0;
      };
      switch (brake) {
      case 6:
        if (Flags & 64)
          break;
        if (brakeset != 6)
          break;
        eng->UR += UR_CHARGE_RATE * time;
        if (eng->UR > loco->MainResPressure)
          eng->UR = loco->MainResPressure;
        eng->TrainPipeRate =
            (eng->UR - loco->TrainPipePressure) * PIPE_CHARGE_Q_REL;
        if (eng->TrainPipeRate < 0.0)
          eng->TrainPipeRate = 0.0;
        else if (eng->TrainPipeRate > 1.5)
          eng->TrainPipeRate = 1.5;
        eng->var[8] -= EPT_RELEASE_RATE1 * time;
        if (eng->var[8] < 0.0)
          eng->var[8] = 0.0;
        if (eng->BrakeSystemsEngaged & 2)
          eng->EPTvalue = eng->var[8];
        EnableTrainPipeCharge = true;
        break;
      case 5:
        if (Flags & 64)
          break;
        if (eng->UR < 5.2)
          eng->UR += UR_CHARGE_RATE * time;
        if (eng->UR > loco->MainResPressure)
          eng->UR = loco->MainResPressure;
        eng->TrainPipeRate =
            (eng->UR - loco->TrainPipePressure) * PIPE_CHARGE_Q;
        if (eng->TrainPipeRate < 0.0) {
          if (eng->TrainPipeRate > -0.1) {
            eng->TrainPipeRate = 0.0;
          };
        } else if (eng->TrainPipeRate > 1.5)
          eng->TrainPipeRate = 1.5;
        if (eng->TrainPipeRate > 0.0)
          eng->UR -= UR_DISCHARGE2 * time;
        eng->var[8] -= EPT_RELEASE_RATE * time;
        if (eng->var[8] < 0.0)
          eng->var[8] = 0.0;
        if (eng->BrakeSystemsEngaged & 2)
          eng->EPTvalue = eng->var[8];
        EnableTrainPipeCharge = true;
        break;
      case 4:
        if (Flags & 64)
          break;
        eng->TrainPipeRate = eng->UR - loco->TrainPipePressure;
        if (eng->TrainPipeRate > PIPE_DISCHARGE_SLOW)
          eng->TrainPipeRate = PIPE_DISCHARGE_SLOW;
        if (eng->BrakeSystemsEngaged & 2)
          eng->EPTvalue = eng->var[8];
        break;
      case 3:
        if (Flags & 64)
          break;
        eng->TrainPipeRate = eng->UR - loco->TrainPipePressure;
        if (eng->TrainPipeRate > 0.0)
          eng->TrainPipeRate *= 0.1;
        if (eng->TrainPipeRate > 0.05)
          eng->TrainPipeRate = 0.05;
        if (eng->BrakeSystemsEngaged & 2)
          eng->EPTvalue = eng->var[8];
        break;
      case 2:
        if (Flags & 64)
          break;
        if (brakeset > 2)
          break;
        if (eng->BrakeSystemsEngaged & 2) {
          eng->var[8] += EPT_APPLY_RATE * time;
          if (eng->var[8] > EPT_MAX)
            eng->var[8] = EPT_MAX;
          eng->EPTvalue = eng->var[8];
        };
        eng->TrainPipeRate = eng->UR - loco->TrainPipePressure;
        if (eng->TrainPipeRate > 0.0)
          eng->TrainPipeRate = 0.0;
        break;
      case 1:
        if (Flags & 64)
          break;
        if (brakeset > 1)
          if (!(eng->BrakeSystemsEngaged & 2))
            break;
        eng->UR += UR_DISCHARGE_RATE * time;
        if (eng->UR < 0.0)
          eng->UR = 0.0;
        eng->TrainPipeRate = eng->UR - loco->TrainPipePressure;
        if (eng->TrainPipeRate > 0.0)
          eng->TrainPipeRate = 0.0;
        eng->var[8] += EPT_APPLY_RATE * time;
        if (eng->var[8] > EPT_MAX)
          eng->var[8] = EPT_MAX;
        if (eng->BrakeSystemsEngaged & 2)
          eng->EPTvalue = -1.0; // eng->var[8];
        break;
      case 0:
        // eng->ChargingRate=0.0;
        eng->UR += UR_EMERGENCY_RATE * time;
        if (eng->UR < 0.0)
          eng->UR = 0.0;
        eng->var[8] = EPT_MAX;
        if (eng->BrakeSystemsEngaged & 2)
          eng->EPTvalue = EPT_MAX;
        eng->TrainPipeRate = UR_EMERGENCY_RATE;
        break;
      };
    };
  };
  if (eng->IndependentBrakeValue > loco->IndependentBrakePressure)
    eng->MainResRate -= 0.05;
  /*if(Flags&8){
   eng->IndependentBrakeValue=0.0;
  };*/

  if (soundCab) {
    soundCab->Var2[0] = eng->Power / 2500.0;
    soundCab->Var3[0] = fabs(eng->Force) / 200000.0;
    soundCab->Var4[0] = eng->RPM / 1000.0;
    soundCab->Var5[0] = eng->BrakeForce / 200000.0;
  };
  if (soundExt) {
    soundExt->Var2[0] = eng->Power / 2500.0;
    soundExt->Var3[0] = fabs(eng->Force) / 200000.0;
    soundExt->Var4[0] = eng->RPM / 1000.0;
    soundExt->Var5[0] = eng->BrakeForce / 200000.0;
  };

  if (eng->DieselOn == 1) {
    float Mag = 1.0, Disp = 1.0, Rate = 1.0, Col = 1.0;
    ULONG Colour = 0xcc555557;
    if (SetPower > eng->Power) {
      Rate += (SetPower - eng->Power) / 750.0;
      Disp += (SetPower - eng->Power) / 1000.0;
      Mag += (SetPower - eng->Power) / 1000.0;
      Col += (SetPower - eng->Power) / 450.0;
      if (Col > 2.5)
        Col = 2.5;
      Colour = ((char(0xcc + 10 * Col) & 0xFF) << 24) |
               ((char(0x55 * Col) & 0xFF) << 16) |
               ((char(0x55 * Col) & 0xFF) << 8) | (char(0x57 * Col) & 0xFF);
    };
    if (!eng->ThrottlePosition)
      Disp *= 0.2;
    Exhaust(loco, 0, Rate * eng->Power / 1000.0, Mag * eng->Power / 1000.0,
            Disp * eng->Power / 500.0, Colour, 0);
    Exhaust(loco, 1, Rate * eng->Power / 1000.0, Mag * eng->Power / 1000.0,
            Disp * eng->Power / 500.0, Colour, 0);
  } else if (eng->DieselOn == 3) {
    Exhaust(loco, 0, eng->Power / 750.0, eng->Power / 250.0, eng->Power / 80.0,
            0xdd505060, 0);
    Exhaust(loco, 1, eng->Power / 750.0, eng->Power / 250.0, eng->Power / 80.0,
            0xdd505060, 0);
  } else {
    Exhaust(loco, 0, 0.0, 0.0, 0.0, 0, 0);
    Exhaust(loco, 1, 0.0, 0.0, 0.0, 0, 0);
  };

  if ((State >> 8) & 1) {
    float val;
    float area[4];
    cab->SetScreenState(20, 0, -1);
    cab->SetScreenState(20, 1, -1);
    cab->SetScreenState(21, 0, -1);
    cab->SetScreenState(21, 1, -1);

    if (loco->LibParam == 1 && cab->DisplayState(0)) {
      if ((LocoOn & 1) && cab->Switch(20)) {
        _itow(fabs(loco->Velocity) * 3.6, str, 10);
        cab->SetScreenLabel(1, 0, str);
        swprintf(str, L"%0.0f", eng->var[13]);
        cab->SetScreenLabel(1, 1, str);
        swprintf(str, L"%0.1f", eng->CurrentMilepost);
        cab->SetScreenLabel(18, 0, str);
        if (eng->var[15] > 0.0 && eng->var[16] > 30.0) {
          UINT EPKstate = eng->var[15];
          cab->SetScreenState(20, 0, 0);
          switch (EPKstate) {
          case 1:
            cab->SetScreenFade(20, 0, -1.0, 0.8);
            break;
          case 2:
            cab->SetScreenFade(20, 0, -1.0, 0.0);
            break;
          case 3:
            cab->SetScreenFade(20, 0, -1.0, 0.5);
            break;
          case 4:
            cab->SetScreenFade(20, 0, -1.0, 0.3);
            break;
          case 5:
            cab->SetScreenFade(20, 0, -1.0, 0.8);
            break;
          };
        };
        if (Flags & 64)
          cab->SetScreenState(20, 1, 0);
      };
      if (eng->Reverse > 0)
        cab->SetScreenState(0, 10, 0);
      else if (eng->Reverse < 0)
        cab->SetScreenState(0, 10, 1);
      else
        cab->SetScreenState(0, 10, -1);
      if (eng->DieselOn && eng->ThrottlePosition) {
        _itow(eng->ThrottlePosition, str, 10);
      } else if (eng->DynamicBrakePercent) {
        _itow(eng->DynamicBrakePercent / 12.5, str, 10);
      } else
        _itow(0, str, 10);
      cab->SetScreenLabel(0, 6, str);
      if (eng->DieselOn == 1 || eng->DieselOn == 3) {
        if (eng->ThrottlePosition && eng->Reverse)
          cab->SetScreenState(0, 4, 1);
        else if (!eng->Force &&
                 (cab->Switch(2) && cab->Switch(26) && cab->Switch(20)) &&
                 eng->Reverse)
          cab->SetScreenState(0, 4, 2);
        else
          cab->SetScreenState(0, 4, 0);
      } else
        cab->SetScreenState(0, 4, 3);

      switch (cab->ScreenState(0, 2)) {
      case 1:
        cab->SetScreenValue(0, 5, fabs(loco->Velocity));
        val = loco->Velocity * 3.6;
        swprintf(str, L"%0.1f", val);
        cab->SetScreenLabel(0, 7, str);
        val = loco->Acceleration;
        cab->SetScreenValue(0, 11, val);
        swprintf(str, L"%0.1f", val);
        cab->SetScreenLabel(0, 8, str);
        if (eng->Force)
          val = eng->Force / 10000.0;
        else if (eng->BrakeForce)
          val = -eng->BrakeForce / 10000.0;
        cab->SetScreenValue(0, 12, val);
        swprintf(str, L"%0.0f", val);
        cab->SetScreenLabel(0, 9, str);

        Current = fabs(eng->Force) * 0.0028;
        cab->SetScreenValue(0, 13, Current);
        // area[1]=COMPUTER_R1BOT-(Current/1500.0)*COMPUTER_R1HGT;
        // cab->SetScreenArea(0,13,area,2);

        Current *= 6.0;
        // area[1]=COMPUTER_R1BOT-(Current/8000.0)*COMPUTER_R1HGT;
        // cab->SetScreenArea(0,14,area,2);
        cab->SetScreenValue(0, 14, Current);

        if (Current)
          Voltage = eng->RPM * PowerAvailable * 1.015;
        else
          Voltage = 0.0;
        // area[1]=COMPUTER_R1BOT-(Voltage/1000.0)*COMPUTER_R1HGT;
        // cab->SetScreenArea(0,15,area,2);
        cab->SetScreenValue(0, 15, Voltage);

        Voltage = 2500.0 * (eng->RPM / 800.0);
        // area[1]=COMPUTER_R1BOT-(Voltage/4000.0)*COMPUTER_R1HGT;
        // cab->SetScreenArea(0,16,area,2);
        cab->SetScreenValue(0, 16, Voltage);

        if (Voltage > 1000.0)
          Current = 8.0 + (1.0 - PowerAvailable) * 32000.0 / Voltage;
        else
          Current = Voltage * 0.003;
        // area[1]=COMPUTER_R1BOT-(Current/250.0)*COMPUTER_R1HGT;
        // cab->SetScreenArea(0,17,area,2);
        cab->SetScreenValue(0, 17, Current);
        break;
      case 0:
        val = eng->RPM * 0.0121;
        swprintf(str, L"%0.1f", val);
        cab->SetScreenLabel(0, 21, str);
        cab->SetScreenValue(0, 27, val);

        val = eng->var[3];
        _itow(val, str, 10);
        cab->SetScreenLabel(0, 22, str);
        cab->SetScreenValue(0, 28, val);

        val = eng->var[2];
        _itow(val, str, 10);
        cab->SetScreenLabel(0, 23, str);
        cab->SetScreenValue(0, 29, val);

        _itow(BatteryCharge, str, 10);
        cab->SetScreenLabel(0, 24, str);
        cab->SetScreenValue(0, 30, BatteryCharge);

        val = eng->Power * 0.0022;
        if (loco->FuelAmount < 20.0)
          val *= loco->FuelAmount / 20.0;
        swprintf(str, L"%0.1f", val);
        cab->SetScreenLabel(0, 25, str);
        cab->SetScreenValue(0, 31, val);

        Voltage = 2500.0 * (eng->RPM / 800.0);
        _itow(Voltage, str, 10);
        cab->SetScreenLabel(0, 26, str);
        cab->SetScreenValue(0, 32, Voltage);
        break;
      };
    };

    if (loco->LibParam == 1 && cab->DisplayState(9)) {
      if (LocoOn & 65) {
        _itow(fabs(loco->Velocity) * 3.6, str, 10);
        cab->SetScreenLabel(10, 0, str);
        swprintf(str, L"%0.0f", eng->var[13]);
        cab->SetScreenLabel(10, 1, str);
        swprintf(str, L"%0.1f", eng->CurrentMilepost);
        cab->SetScreenLabel(19, 0, str);

        if (eng->var[15] > 0.0 && eng->var[16] > 30.0) {
          UINT EPKstate = eng->var[15];
          cab->SetScreenState(21, 0, 0);
          switch (EPKstate) {
          case 1:
            cab->SetScreenFade(21, 0, -1.0, 0.8);
            break;
          case 2:
            cab->SetScreenFade(21, 0, -1.0, 0.0);
            break;
          case 3:
            cab->SetScreenFade(21, 0, -1.0, 0.5);
            break;
          case 4:
            cab->SetScreenFade(21, 0, -1.0, 0.3);
            break;
          case 5:
            cab->SetScreenFade(21, 0, -1.0, 0.8);
            break;
          };
        };
        if (Flags & 64)
          cab->SetScreenState(21, 1, 0);
      };
      if (eng->Reverse < 0)
        cab->SetScreenState(9, 10, 0);
      else if (eng->Reverse > 0)
        cab->SetScreenState(9, 10, 1);
      else
        cab->SetScreenState(9, 10, -1);
      if (eng->DieselOn && eng->ThrottlePosition) {
        _itow(eng->ThrottlePosition, str, 10);
      } else if (eng->DynamicBrakePercent) {
        _itow(eng->DynamicBrakePercent / 12.5, str, 10);
      } else
        _itow(0, str, 10);
      cab->SetScreenLabel(9, 6, str);
      if (eng->DieselOn == 1 || eng->DieselOn == 3) {
        if (eng->ThrottlePosition && eng->Reverse)
          cab->SetScreenState(9, 4, 1);
        else if (!eng->Force &&
                 (cab->Switch(2) && cab->Switch(26) && cab->Switch(20)) &&
                 eng->Reverse)
          cab->SetScreenState(9, 4, 2);
        else
          cab->SetScreenState(9, 4, 0);
      } else
        cab->SetScreenState(9, 4, 3);

      switch (cab->ScreenState(9, 2)) {
      case 1:
        cab->SetScreenValue(9, 5, fabs(loco->Velocity));
        val = -loco->Velocity * 3.6;
        swprintf(str, L"%0.1f", val);
        cab->SetScreenLabel(9, 7, str);
        val = -loco->Acceleration;
        cab->SetScreenValue(9, 11, val);
        swprintf(str, L"%0.1f", val);
        cab->SetScreenLabel(9, 8, str);
        if (eng->Force)
          val = -eng->Force / 10000.0;
        else if (eng->BrakeForce)
          val = -eng->BrakeForce / 10000.0;
        cab->SetScreenValue(9, 12, val);
        swprintf(str, L"%0.0f", val);
        cab->SetScreenLabel(9, 9, str);

        Current = fabs(eng->Force) * 0.0028;
        cab->SetScreenValue(0, 13, Current);
        Current *= 6.0;
        cab->SetScreenValue(0, 14, Current);
        if (Current)
          Voltage = eng->RPM * PowerAvailable * 1.015;
        else
          Voltage = 0.0;
        cab->SetScreenValue(0, 15, Voltage);
        Voltage = 2500.0 * (eng->RPM / 800.0);
        cab->SetScreenValue(0, 16, Voltage);
        if (Voltage > 1000.0)
          Current = 8.0 + (1.0 - PowerAvailable) * 32000.0 / Voltage;
        else
          Current = Voltage * 0.003;
        cab->SetScreenValue(0, 17, Current);
        break;
      case 0:
        val = eng->RPM * 0.0121;
        swprintf(str, L"%0.1f", val);
        cab->SetScreenLabel(9, 21, str);
        cab->SetScreenValue(9, 27, val);

        val = eng->var[3];
        _itow(val, str, 10);
        cab->SetScreenLabel(9, 22, str);
        cab->SetScreenValue(9, 28, val);

        val = eng->var[2];
        _itow(val, str, 10);
        cab->SetScreenLabel(9, 23, str);
        cab->SetScreenValue(9, 29, val);

        _itow(BatteryCharge, str, 10);
        cab->SetScreenLabel(9, 24, str);
        cab->SetScreenValue(9, 30, BatteryCharge);

        val = eng->Power * 0.0022;
        if (loco->FuelAmount < 20.0)
          val *= loco->FuelAmount / 20.0;
        swprintf(str, L"%0.1f", val);
        cab->SetScreenLabel(9, 25, str);
        cab->SetScreenValue(9, 31, val);

        Voltage = 2500.0 * (eng->RPM / 800.0);
        _itow(Voltage, str, 10);
        cab->SetScreenLabel(9, 26, str);
        cab->SetScreenValue(9, 32, Voltage);
        break;
      };
    };

    switch (loco->LibParam) {
    case 1:
      cab->SetDisplayValue(2, eng->UR);
      cab->SetDisplayValue(11, eng->UR);
      cab->SetDisplayValue(3, loco->TrainPipePressure);
      cab->SetDisplayValue(12, loco->TrainPipePressure);
      cab->SetDisplayValue(4, loco->MainResPressure);
      cab->SetDisplayValue(13, loco->MainResPressure);
      if (loco->BrakeCylinderPressure > loco->IndependentBrakePressure) {
        cab->SetDisplayValue(5, loco->BrakeCylinderPressure);
        cab->SetDisplayValue(14, loco->BrakeCylinderPressure);
      } else {
        cab->SetDisplayValue(5, loco->IndependentBrakePressure);
        cab->SetDisplayValue(14, loco->IndependentBrakePressure);
      };
      cab->SetDisplayState(6, 0);
      cab->SetDisplayState(7, 0);
      cab->SetDisplayState(15, 0);
      cab->SetDisplayState(16, 0);
      if (LocoOn & 32) {
        if (loco->BrakeCylinderPressure > 0.0 ||
            loco->IndependentBrakePressure > 0.0)
          cab->SetDisplayState(6, 1);
        if (loco->NumSlaves)
          if (loco->SlaveLoco(0)->BrakeCylinderPressure > 0.0 ||
              loco->SlaveLoco(0)->IndependentBrakePressure > 0.0)
            cab->SetDisplayState(7, 1);
      };
      if (LocoOn & 64) {
        if (loco->BrakeCylinderPressure > 0.0 ||
            loco->IndependentBrakePressure > 0.0)
          cab->SetDisplayState(15, 1);
        if (loco->NumSlaves)
          if (loco->SlaveLoco(0)->BrakeCylinderPressure > 0.0 ||
              loco->SlaveLoco(0)->IndependentBrakePressure > 0.0)
            cab->SetDisplayState(16, 1);
      };
      break;
    };
  };
};
