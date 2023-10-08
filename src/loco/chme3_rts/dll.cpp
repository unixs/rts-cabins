//---------------------------------------------------------------------------

#define RTS_STACKSIZE 11
#define RTS_ADAPTER_COMPLY

#include <cab.hpp>
#include <fix.h>
#include <math.h>
#include <ts.h>

#define BRAKE_MR_RATIO 0.005
#define BRAKE_PIPE_RATE_CHARGE 2.5
#define BRAKE_UR_RATE_CHARGE 0.3
#define BRAKE_PIPE_RATE 0.4
#define BRAKE_PIPE_EMERGENCY -1.4
#define BRAKE_TP_DISCHARGE_RATE -0.3
#define PIPE_DISCHARGE_SLOW -0.005

#define C_RED 0xf0ff0000
#define C_WHITE 0x80ffffff

//---------------------------------------------------------------------------

using namespace model;

//---------------------------------------------------------------------------

int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason,
                         void *lpReserved)
{
  return 1;
}
//---------------------------------------------------------------------------

void SwitchLights(const DieselLocomotive *loco, UINT State)
{
  Cabin *cab = loco->Cab();
  switch (State) {
  case 0:
    /*loco->lights[0].Flags&=~8;
    loco->lights[3].Flags&=~8;
    loco->lights[4].Flags&=~8;
    loco->lights[6].Flags&=~8;
    loco->lights[7].Flags&=~8;
    loco->lights[8].Flags&=~8;
    loco->lights[9].Flags&=~8;
    loco->lights[10].Flags&=~8;
    loco->lights[11].Flags&=~8;
    if(loco->loco->cab->NumLights>1){
     loco->loco->cab->Light[0].State=0;
     loco->loco->cab->Light[1].State=0;
    };*/
    loco->SwitchLight(0, false);
    loco->SwitchLight(3, false);
    loco->SwitchLight(4, false);
    loco->SwitchLight(6, false);
    loco->SwitchLight(7, false);
    loco->SwitchLight(8, false);
    loco->SwitchLight(9, false);
    loco->SwitchLight(10, false);
    loco->SwitchLight(11, false);
    if (cab->NumLights > 1) {
      cab->SwitchLight(0, false);
      cab->SwitchLight(1, false);
    };
    break;
  case 1:
    loco->SwitchLight(6, true, 0.0, C_WHITE);
    break;
  case 2:
    loco->SwitchLight(6, false);
    break;
  case 3:
    loco->SwitchLight(6, true, 0.0, C_RED);
    break;
  case 4:
    loco->SwitchLight(7, true, 0.0, C_WHITE);
    break;
  case 5:
    loco->SwitchLight(7, false);
    break;
  case 6:
    loco->SwitchLight(7, true, 0.0, C_RED);
    break;
  case 7:
    loco->SwitchLight(8, true);
    loco->SwitchLight(3, true, 150.0, 0xccdddd50);
    break;
  case 8:
    loco->SwitchLight(8, false);
    loco->SwitchLight(3, false);
    break;
  case 9:
    loco->SwitchLight(8, true);
    loco->SwitchLight(3, true, 60.0, 0x80ffffff);
    break;
  case 10:
    loco->SwitchLight(9, true, 0.0, C_RED);
    break;
  case 11:
    loco->SwitchLight(9, false);
    break;
  case 12:
    loco->SwitchLight(9, true, 0.0, C_WHITE);
    break;
  case 13:
    loco->SwitchLight(0, true, 0.0, C_RED);
    break;
  case 14:
    loco->SwitchLight(0, false);
    break;
  case 15:
    loco->SwitchLight(0, true, 0.0, C_WHITE);
    break;
  case 16:
    loco->SwitchLight(10, true);
    loco->SwitchLight(4, true, 150.0, 0xccdddd50);
    break;
  case 17:
    loco->SwitchLight(10, false);
    loco->SwitchLight(4, false);
    break;
  case 18:
    loco->SwitchLight(10, true);
    loco->SwitchLight(4, true, 60.0, 0x80ffffff);
    break;
  case 19:
    loco->SwitchLight(11, false);
    break;
  case 20:
    loco->SwitchLight(11, true);
    break;
  case 21:
    cab->SwitchLight(0, false);
    break;
  case 22:
    cab->SwitchLight(0, true);
    break;
  case 23:
    cab->SetLightState(1, true, 0x80807010, -1.0, 0.0, 0.0);
    break;
  case 24:
    cab->SwitchLight(1, false);
    break;
  case 25:
    cab->SetLightState(1, true, 0x80cccc10, -1.0, 0.0, 0.0);
    break;
  };
};

//---------------------------------------------------------------------------

/*
 Stack variables

 0 - Flags
  1bite
   1bit - Compressor on
   2bit - EPK sound on
   3bit - EPK timer on
   4bit - 1st diesel failure
   5bit - diesel just started
   6bit - OP1
   7bit - OP2

 1 - Sound Flags
  1bite
   1bit -

 2 - Reserved

 3 - Main timer

 4 - [VACANT]

 5,6 - EPK Timers 1,2

 8 - Prev signal aspect

 9 - Water temperature

 10 - Diesel timer 1

 11 - Diesel start timer






 Sound Triggers

 37 - switch click
 100,101 -Radio on/off
 102 - switch click
 103,104 - starter on/off
 105 - RB

 107,108 - Compressor on/off
 109,110 - EPK on/off
 111,112 - sand on/off
 113 - brake release
 114 - brake hold
 115,116 - brake apply start/stop
 117 - EPK release

*/

extern "C" bool __export Init(DieselEngine *eng, DieselLocomotive *loco,
                              unsigned long State, float time,
                              float AirTemperature)
{
  Cabin *cab = loco->Cab();

  eng->DieselOn = 0;
  eng->RPM = 0.0;
  eng->var[0] = 0.0;
  eng->var[1] = 0.0;
  eng->var[2] = 0.0;
  eng->var[3] = 0.0;
  eng->UR = 0.0;
  eng->var[5] = 0.0;
  eng->var[6] = 0.0;
  eng->var[7] = SIGASP_CLEAR_2;
  eng->var[9] = 20.0;
  eng->var[10] = 0.0;
  eng->Power = 0.0;
  eng->Force = 0.0;
  eng->BrakeForce = 0.0;
  eng->IndependentBrakeValue = 4.2;
  eng->TrainPipeRate = 0.0;
  eng->ChargingRate = 0.0;
  eng->MainResRate = 0.0;
  eng->HandbrakePercent = 100.0;
  eng->DynamicBrakePercent = 0.0;
  eng->EPTvalue = -1.0;
  eng->BrakeSystemsEngaged = 1;
  eng->ALSNOn = 0;
  eng->Reverse = 0;
  eng->ThrottlePosition = 0;
  cab->SetSwitch((UINT) sw::C_HANDBR_5, 1, true);

  switch (State & 0xFF) {
  case 0:
    // loco is static, single
    loco->AuxiliaryPressure = 4.2;
    loco->MainResPressure = 6.0;
    loco->IndependentBrakePressure = 4.0;
    loco->BrakeCylinderPressure = 4.2;
    loco->TrainPipePressure = 0.0;
    cab->SetSwitch(2, 5, true);
    cab->SetSwitch(3, 5, true);
    cab->SetSwitch(4, 5, true);
    cab->SetSwitch(5, 1, true);
    break;
  case 1:
    // loco is static, with wagons
    eng->DieselOn = 1;
    eng->RPM = 350.0;
    eng->Power = 464.0;
    eng->HandbrakePercent = 0.0;
    loco->AuxiliaryPressure = 5.0;
    loco->MainResPressure = 6.2;
    loco->IndependentBrakePressure = 4.0;
    loco->BrakeCylinderPressure = 0.0;
    loco->TrainPipePressure = 5.2;
    eng->UR = 5.2;
    cab->SetSwitch(2, 5, true);
    cab->SetSwitch(3, 5, true);
    cab->SetSwitch(5, 0, true);
    cab->SetSwitch(26, 1, true);
    break;
  case 2:
  case 3:
    // loco is moving
    eng->DieselOn = 1;
    eng->RPM = 350.0;
    eng->Power = 464.0;
    eng->HandbrakePercent = 0.0;
    eng->IndependentBrakeValue = 0.0;
    loco->AuxiliaryPressure = 5.0;
    loco->MainResPressure = 7.8;
    loco->IndependentBrakePressure = 0.0;
    loco->BrakeCylinderPressure = 0.0;
    loco->TrainPipePressure = 5.2;
    eng->UR = 5.2;
    if (loco->Velocity >= 0.0) {
      cab->SetSwitch((UINT) sw::C_REV_1, 3, false);
      eng->Reverse = 1;
    }
    else {
      cab->SetSwitch((UINT) sw::C_REV_1, 1, false);
      eng->Reverse = -1;
    };
    cab->SetSwitch((UINT) sw::C_HANDBR_5, 0, true);
    cab->SetSwitch((UINT) sw::SW_STOP_26, 1, true);
    cab->SetSwitch((UINT) sw::SW_ALSN_32, 0, true);
    break;
  };

  return true;
};

extern "C" void __export ChangeLoco(Locomotive *loco, const Locomotive *Prev,
                                    unsigned long State)
{
  if (!Prev) {
    loco->LocoFlags |= 1;
  }
};

extern "C" bool __export CanWorkWith(const Locomotive *loco,
                                     const wchar_t *Type)
{

  if (!lstrcmpiW(Type, L"chme3") || !lstrcmpiW(Type, L"chme3boost") ||
      !lstrcmpiW(Type, L"chme3t")) {
    return true;
  }

  return false;
};

extern "C" bool __export CanSwitch(const DieselLocomotive *loco,
                                   const DieselEngine *eng,
                                   unsigned int SwitchID, unsigned int SetState)
{
  Cabin *cab = loco->Cab();
  UINT Trig;
  if (SwitchID == 45) {
    SwitchID = 6;
  }

  switch (SwitchID) {
  case 0:
    loco->PostTriggerBoth(16);
    break;
  case 1:
    if (cab->Switch(0)) {
      return false;
    }
    loco->PostTriggerCab(15);
    break;
  case 4:
    if (SetState < 4 && cab->Switch(4) >= 4) {
      loco->PostTriggerCab(116);
    }
    break;
  case 7:
    if (SetState == 1) {
      Trig = 8;
    }
    else {
      Trig = 9;
    }
    loco->PostTriggerBoth(Trig);
    break;
  case 6:
    if (SetState == 1) {
      loco->PostTriggerBoth(10);
    }
    break;
  };

  if (SwitchID == 2 || SwitchID == 3 || SwitchID == 4) {
    loco->PostTriggerCab(18);
  }
  else if ((SwitchID >= 9 && SwitchID <= 14) || SwitchID == 17 ||
           (SwitchID >= 19 && SwitchID <= 23) || SwitchID == 26) {
    loco->PostTriggerCab(102);
  }
  else if (SwitchID == 15 || SwitchID == 16 || SwitchID == 18 ||
           SwitchID == 24 || SwitchID == 25 ||
           (SwitchID >= 27 && SwitchID <= 31)) {
    loco->PostTriggerCab(37);
  }
  else if (SwitchID == 33) {
    loco->PostTriggerCab(105);
  };

  return true;
};

extern "C" void __export Switched(const DieselLocomotive *loco,
                                  DieselEngine *eng, unsigned int SwitchID,
                                  unsigned int PrevState)
{
  Cabin *cab = loco->Cab();
  FreeAnimation *anim;
  ULONG &Flags = *(ULONG *) &eng->var[0];
  int n, n1;

  if (SwitchID == (UINT) sw::SW_P_SAND_44) {
    SwitchID = (UINT) sw::SW_SAND_8;
  }

  if (SwitchID == (UINT) sw::C396_3) {
    SwitchID = (UINT) sw::C254_2;
  }

  switch (SwitchID) {
  case 0:
    eng->ThrottlePosition = cab->Switch((UINT) sw::C_MAIN_0);
    break;
  case 1:
    if (!cab->Switch((UINT) sw::C_REV_1)) {
      break;
    }
    eng->Reverse = cab->Switch((UINT) sw::C_REV_1) - 2;
    // if(eng->Reverse)
    // if(loco->Flags&1)
    // eng->Reverse=-eng->Reverse;
    break;
  case 2:
    n = cab->Switch(2);
    n1 = cab->Switch(3);
    if (n1 > n) {
      n = n1;
    }
    if (n < 2) {
      eng->IndependentBrakeValue = 0.0;
    }
    else {
      eng->IndependentBrakeValue = 1.0 * (n - 1);
    }
    break;
  case 4:
    switch (cab->Switch(4)) {
    case 0:
      loco->PostTriggerCab(113);
      break;
    case 1:
      if (loco->BrakeCylinderPressure && PrevState != 0) {
        loco->PostTriggerCab(113);
      }
      else {
        loco->PostTriggerCab(114);
      };
      break;
    case 3:
      if (PrevState == 4) {
        loco->PostTriggerCab(114);
      }
      break;
    case 4:
      if (PrevState != 5) {
        loco->PostTriggerCab(115);
      }
      break;
    };
    break;
  case 8:
    if (cab->Switch(8) || cab->Switch(44)) {
      eng->Sanding = 1;
      loco->PostTriggerBoth(111);
    }
    else {
      eng->Sanding = 0;
      loco->PostTriggerBoth(112);
    };
    break;
  case 9:
    if (cab->Switch(9)) {
      loco->PostTriggerCab(100);
    }
    else {
      loco->PostTriggerCab(101);
    };
    break;
  case 10:
    SwitchLights(loco, cab->Switch(10) + 19);
    break;
  case 13:
    SwitchLights(loco, cab->Switch(13) + 1);
    break;
  case 14:
    SwitchLights(loco, cab->Switch(14) + 4);
    break;
  case 15:
    if (cab->Switch(16)) {
      break;
    }
    if (cab->Switch(15)) {
      SwitchLights(loco, 7);
    }
    else {
      SwitchLights(loco, 8);
    }
    break;
  case 16:
    if (cab->Switch(16)) {
      SwitchLights(loco, 9);
    }
    else {
      Switched(loco, eng, 15, 0);
    }
    break;
  case 17:
    if (eng->DieselOn == 1) {
      break;
    }
    if (cab->Switch((UINT) sw::SW_START_17)) {
      if (cab->Switch((UINT) sw::SW_STOP_26)) {
        if (eng->var[9] > 95.0) {
          break;
        }
        eng->DieselOn = 2;
        loco->PostTriggerBoth(103);
      };
    }
    else {
      /*eng->DieselOn=0;
      if(loco->sound)
       loco->sound->PostTrigger(104);
      if(eng->sound)
       eng->sound->PostTrigger(104);*/
    };
    break;
  case 19:
    if (!PrevState) {
      anim = loco->FindAnim(L"wiper1");
      if (anim) {
        anim->Flags |= 1;
      }
      anim = loco->FindAnim(L"wiper2");
      if (anim) {
        anim->Flags |= 1;
      }
      anim = loco->FindAnim(L"wiper3");
      if (anim) {
        anim->Flags |= 1;
      }
      anim = loco->FindAnim(L"wiper4");
      if (anim) {
        anim->Flags |= 1;
      }
      anim = cab->FindAnim(L"wiper1");
      if (anim) {
        anim->Flags |= 1;
      }
      anim = cab->FindAnim(L"wiper2");
      if (anim) {
        anim->Flags |= 1;
      }
      anim = cab->FindAnim(L"wiper3");
      if (anim) {
        anim->Flags |= 1;
      }
      anim = cab->FindAnim(L"wiper4");
      if (anim) {
        anim->Flags |= 1;
      }
    }
    else if (!cab->Switch(19)) {
      anim = loco->FindAnim(L"wiper1");
      if (anim) {
        anim->Flags &= ~1;
      }
      anim = loco->FindAnim(L"wiper2");
      if (anim) {
        anim->Flags &= ~1;
      }
      anim = loco->FindAnim(L"wiper3");
      if (anim) {
        anim->Flags &= ~1;
      }
      anim = loco->FindAnim(L"wiper4");
      if (anim) {
        anim->Flags &= ~1;
      }
      anim = cab->FindAnim(L"wiper1");
      if (anim) {
        anim->Flags &= ~1;
      }
      anim = cab->FindAnim(L"wiper2");
      if (anim) {
        anim->Flags &= ~1;
      }
      anim = cab->FindAnim(L"wiper3");
      if (anim) {
        anim->Flags &= ~1;
      }
      anim = cab->FindAnim(L"wiper4");
      if (anim) {
        anim->Flags &= ~1;
      }
    };
    break;
  case 20:
    SwitchLights(loco, cab->Switch(20) + 23);
    break;
  case 21:
    SwitchLights(loco, cab->Switch(21) + 21);
    break;
  case 22:
    SwitchLights(loco, cab->Switch(22) + 10);
    break;
  case 23:
    SwitchLights(loco, cab->Switch(23) + 13);
    break;
  case 24:
    if (cab->Switch(25)) {
      break;
    }
    if (cab->Switch(24)) {
      SwitchLights(loco, 16);
    }
    else {
      SwitchLights(loco, 17);
    }
    break;
  case 25:
    if (cab->Switch(25)) {
      SwitchLights(loco, 18);
    }
    else {
      Switched(loco, eng, 24, 0);
    }
    break;
  case 26:
    if (!cab->Switch(26)) {
      if (eng->DieselOn == 2) {
        loco->PostTriggerBoth(104);
      };
      eng->DieselOn = 0;
    };
    break;
  case 29:
  case 37:
    // KNAS2
    if (cab->Switch(29) || cab->Switch(37)) {
      if (!PrevState) {
        loco->LockCoupling(false, true);
        loco->DetachCoupling(false, true);
      };
    }
    else {
      loco->LockCoupling(false, false);
      loco->DetachCoupling(false, false);
    };
    break;
  case 30:
  case 38:
    // KNAS1
    if (cab->Switch(30) || cab->Switch(38)) {
      if (!PrevState) {
        loco->LockCoupling(true, true);
        loco->DetachCoupling(true, true);
      };
    }
    else {
      loco->LockCoupling(true, false);
      loco->DetachCoupling(true, false);
    };
    break;
  case 33:
    eng->var[5] = 0.0;
    Flags &= ~4;
    break;
  };
};

extern "C" void __export Run(DieselEngine *eng, const DieselLocomotive *loco,
                             unsigned long State, float time,
                             float AirTemperature)
{
  Cabin *cab = loco->Cab();
  ULONG &Flags = *(ULONG *) &eng->var[0];
  float InternalPowerUsage = 0.0;
  float Current = 0.0;
  FreeAnimation *anim;

  // Diesel power
  if (eng->DieselOn == 2) {
    if (eng->Power < 159.0) {
      eng->Power += 30.0 * time;
    }
    if (loco->FuelAmount < 0.1) {
      if (eng->Power > 100.0) {
        eng->DieselOn = 0.0;
        eng->Power = 100.0;
      };
    };
  }
  else if (eng->DieselOn == 1) {
    float SetPower = 463.4 + eng->ThrottlePosition * 66.25;
    if (SetPower > eng->Power) {
      eng->Power += 50.0 * time;
      if (eng->Power > SetPower) {
        eng->Power = SetPower;
      }
    }
    else {
      eng->Power -= 50.0 * time;
      if (eng->Power < SetPower) {
        eng->Power = SetPower;
      }
    };
  }
  else if (!eng->DieselOn) {
    if (eng->Power > 10.0) {
      eng->Power -= eng->Power * 0.2 * time;
    }
    else {
      eng->Power = 0.0;
    };
  };
  // Fuel consumption
  eng->FuelConsuming = 0.0;
  if (eng->DieselOn == 2) {
    eng->FuelConsuming = eng->Power / 159.0;
    if (eng->FuelConsuming > 1.0) {
      eng->FuelConsuming =
          (0.3 * eng->Power / 993.0) + 0.4 * (2.0 - eng->FuelConsuming);
    }
    else {
      eng->FuelConsuming = 0.4 * eng->FuelConsuming;
    }
  }
  else if (eng->DieselOn == 1) {
    if (loco->FuelAmount < 0.1) {
      eng->DieselOn = 0;
      eng->Power = 0.0;
    }
    else {
      eng->FuelConsuming = 0.3 * (eng->Power - 159.0) / 993.0;
    }
  };
  // Water temperature
  float PowerToBalance = 8.575 * eng->var[9];
  float VelLeak = 1.0 + fabs(loco->Velocity) / 30.0;
  if (!eng->DieselOn) {
    VelLeak *= 0.2;
  }
  if (eng->Power > PowerToBalance) {
    eng->var[9] += time * (eng->Power - PowerToBalance) / (2850.0 * VelLeak);
  }
  else {
    eng->var[9] += time * (eng->Power - PowerToBalance) / (1475.0 / VelLeak);
  };
  if (eng->var[9] < 20.0) {
    eng->var[9] = 20.0;
  }
  if (eng->var[9] > 110.0) {
    eng->DieselOn = 0;
    Flags |= 8;
  };

  // Compressor
  eng->MainResRate = -0.001;
  if (eng->DieselOn == 1) {
    if (loco->MainResPressure < 6.0) {
      if (loco->IsSMSTriggerOnEng(107) <= 0) {
        loco->PostTriggerBoth(107);
      }
      Flags |= 1;
    }
    else if (loco->MainResPressure > 9.0) {
      if (loco->IsSMSTriggerOnEng(107) == 1) {
        loco->PostTriggerBoth(108);
      }
      Flags &= ~1;
    };
    if (Flags & 1) {
      eng->MainResRate = 0.025 * (11.0 - loco->MainResPressure);
      InternalPowerUsage += 30.0;
    };
  }
  else if (Flags & 1) {
    loco->PostTriggerBoth(108);
    Flags &= ~1;
  };

  // Traction and diesel RPM
  eng->Force = 0.0;
  if (!eng->Reverse) {
    eng->RPM = eng->Power * 0.756;
  }
  else {
    if (eng->DieselOn && eng->ThrottlePosition) {
      float VelMin = -3.0 + eng->ThrottlePosition * 0.225,
            Vel = loco->Velocity * eng->Reverse;
      float q = Vel - VelMin;
      float ggc = 0.0, ShuntQ = 1.0, ShuntQ1 = 1.0;
      if (q > 2.0 + eng->ThrottlePosition * 3.16) {
        ggc = q - 2.0 - eng->ThrottlePosition * 3.16;
        if (eng->ThrottlePosition == 4) {
          ggc -= 1.2;
        }
        else if (eng->ThrottlePosition == 5) {
          ggc -= 2.3;
        }
        else if (eng->ThrottlePosition == 6) {
          ggc -= 0.4;
        };
        if (ggc > 0.0) {
          ggc *= 0.6;
          ggc *= ggc;
        }
        else {
          ggc = 0.0;
        }
      };
      q *= 10.0;
      if (q < 1.0) {
        q = 1.0;
      }
      if (eng->ThrottlePosition > 4) {
        q *= 0.92;
      }
      if (eng->ThrottlePosition > 5) {
        q *= 0.95;
      }
      if (eng->ThrottlePosition > 6) {
        q *= 0.93;
      }
      if (eng->ThrottlePosition > 7) {
        q *= 0.87;
      }

      // ��
      if (Vel > 4.75) {
        Flags |= 32;
        if (Vel > 9.50) {
          Flags |= 64;
        }
        else if (Vel < 8.05) {
          Flags &= ~64;
        }
      }
      else if (Vel < 4.16) {
        Flags &= ~96;
      }
      if (Flags & 32) {
        ShuntQ1 = 0.95;
        ShuntQ = 1.15 + (8.0 - eng->ThrottlePosition) * 0.15;
      };
      if (Flags & 64) {
        ShuntQ1 = 0.84;
        ShuntQ = 1.58 + (8.0 - eng->ThrottlePosition) * 0.4;
      };

      Current = 0.207 * eng->Power * ShuntQ * eng->ThrottlePosition /
                pow(q, 1.85 - eng->ThrottlePosition * 0.038 * ShuntQ1);
      if (Current < ggc) {
        Current = 0.0;
      }
      else {
        Current -= ggc;
      }
      eng->RPM =
          (eng->Power - InternalPowerUsage) * 0.756 * (1.0 - Current / 5.5);
      if (eng->RPM < 0.0) {
        eng->RPM = 0.0;
      }
      if (eng->RPM > eng->Power * 0.756) {
        eng->RPM = eng->Power * 0.756;
      }
      eng->Force = eng->Reverse * Current * 102000.0;

      if (eng->RPM < 150.0) {
        eng->DieselOn = 0;
      }
    }
    else {
      eng->RPM = eng->Power * 0.756;
    };
  };

  if (eng->DieselOn == 2) {
    if (eng->RPM >= 120.0) {
      eng->DieselOn = 1;
      Flags |= 16;
      Flags &= ~8;
      eng->var[11] = 0.0;
    };
  }

  // Smoke
  if (!eng->DieselOn) {
    Exhaust(loco, 0, 0.0, 0.0, 0.0, 0, 0);
  }
  else if (Flags & 16) {
    eng->var[11] += time;
    if (eng->var[11] > 12.0) {
      Flags &= ~16;
    }
    Exhaust(loco, 0, 1.0, eng->FuelConsuming * 60, eng->FuelConsuming * 30.0,
            0xEE9090AA, 2.4);
  }
  else {
    Exhaust(loco, 0, 0.2 + eng->RPM / 400.0, eng->FuelConsuming * 8.0,
            eng->FuelConsuming * 10.0, 0xEE505050, 1.0);
  };

  // Handbrake
  eng->HandbrakePercent = cab->GetSwitchFrame(5) * 100.0;

  // Loco brake
  if (eng->IndependentBrakeValue > loco->MainResPressure) {
    eng->IndependentBrakeValue = loco->MainResPressure;
  }
  if (eng->IndependentBrakeValue > loco->IndependentBrakePressure) {
    eng->MainResRate -= 0.02;
  }
  if (!cab->Switch(2)) {
    if (loco->BrakeCylinderPressure > 0.0) {
      eng->EngineFlags |= 1;
    }
  }
  else {
    eng->EngineFlags &= ~1;
  };

  eng->TrainPipeRate = 0.0;
  if (loco->LocoFlags & 1) {
    // Train brake
    switch (cab->Switch(4)) {
    case 0:
      if (eng->var[5] < 45.0) {
        if (!cab->SwitchSet(4)) {
          eng->UR += BRAKE_UR_RATE_CHARGE * time;
        }
        if (eng->UR > loco->MainResPressure) {
          eng->UR = loco->MainResPressure;
        }
        if (loco->TrainPipePressure < eng->UR) {
          eng->TrainPipeRate =
              (eng->UR - loco->TrainPipePressure) / BRAKE_PIPE_RATE_CHARGE;
        }
      };
      break;
    case 1:
      if (eng->var[5] < 45.0) {
        if (eng->UR < 5.2) {
          float rate = (loco->MainResPressure - eng->UR) * 2.0;
          if (rate < 0.0) {
            rate = 0.0;
          }
          if (rate > BRAKE_UR_RATE_CHARGE) {
            rate = BRAKE_UR_RATE_CHARGE;
          }
          eng->UR += rate * time;
        }
        else if (loco->BrakeCylinderPressure > 0.0 &&
                 (eng->UR - loco->TrainPipePressure) < 0.1) {
          eng->UR += 0.15 * time;
        }
        if (eng->UR > loco->MainResPressure) {
          eng->UR = loco->MainResPressure;
        }
        if (eng->UR > loco->TrainPipePressure) {
          eng->UR -= 0.003 * time;
        }
        if (loco->TrainPipePressure < eng->UR - 0.01) {
          eng->TrainPipeRate =
              (eng->UR - loco->TrainPipePressure) / BRAKE_PIPE_RATE_CHARGE;
        }
        else if (loco->TrainPipePressure > eng->UR) {
          eng->TrainPipeRate = (eng->UR - loco->TrainPipePressure);
          if (eng->TrainPipeRate < -BRAKE_PIPE_RATE) {
            eng->TrainPipeRate = -BRAKE_PIPE_RATE;
          }
        };
      };
      break;
    case 2:
      if (eng->UR > loco->MainResPressure) {
        eng->UR = loco->MainResPressure;
      }
      if (loco->TrainPipePressure > eng->UR) {
        eng->TrainPipeRate = eng->UR - loco->TrainPipePressure;
      }
      if (eng->TrainPipeRate < -BRAKE_PIPE_RATE) {
        eng->TrainPipeRate = -BRAKE_PIPE_RATE;
      }
      else if (eng->TrainPipeRate > PIPE_DISCHARGE_SLOW) {
        eng->TrainPipeRate = PIPE_DISCHARGE_SLOW;
      }
      break;
    case 3:
      if (eng->UR > loco->MainResPressure) {
        eng->UR = loco->MainResPressure;
      }
      if (loco->TrainPipePressure > eng->UR) {
        eng->TrainPipeRate = eng->UR - loco->TrainPipePressure;
      }
      else if (eng->UR - loco->TrainPipePressure > 0.1) {
        eng->TrainPipeRate = 0.05;
      }
      if (eng->TrainPipeRate < -BRAKE_PIPE_RATE) {
        eng->TrainPipeRate = -BRAKE_PIPE_RATE;
      }
      break;
    case 4:
      if (cab->SwitchSet(4) < 4) {
        break;
      }
      eng->UR += (BRAKE_TP_DISCHARGE_RATE * 1.2) * time;
      if (eng->UR > loco->MainResPressure) {
        eng->UR = loco->MainResPressure;
      }
      if (eng->UR < 0) {
        eng->UR = 0;
      }
      eng->TrainPipeRate = BRAKE_TP_DISCHARGE_RATE;
      if (loco->TrainPipePressure < 0.4 && loco->IsSMSTriggerOnCab(115) != 0) {
        loco->PostTriggerCab(116);
      }
      break;
    case 5:
      eng->UR += BRAKE_PIPE_EMERGENCY * 1.2 * time;
      if (eng->UR > loco->MainResPressure) {
        eng->UR = loco->MainResPressure;
      }
      if (eng->UR < 0) {
        eng->UR = 0;
      }
      eng->TrainPipeRate = BRAKE_PIPE_EMERGENCY;
      if ((loco->TrainPipePressure < 0.4) &&
          loco->IsSMSTriggerOnCab(115) != 0) {
        loco->PostTriggerCab(116);
      }
      break;
    };

    // EPK
    if (!cab->Switch(32) && (loco->Velocity > 0.3 || loco->Velocity < -0.3) &&
        eng->Reverse) {
      bool SoundOn = Flags & 2;
      UINT Aspect = cab->Signal.Aspect[0];
      if (Aspect != unsigned(eng->var[8])) {
        if (Aspect < SIGASP_CLEAR_2 && Aspect < unsigned(eng->var[8])) {
          if (Aspect == SIGASP_STOP_AND_PROCEED ||
              Aspect == SIGASP_RESTRICTING) {
            eng->var[5] = 35.1;
          }
          else {
            eng->var[5] = 30.0;
          }
          Flags |= 4;
        }
        else {
          loco->PostTriggerCab(117);
        };
      };
      if (cab->Signal.Aspect[0] < SIGASP_APPROACH_1) {
        Flags |= 4;
      };
      if (Flags & 4) {
        eng->var[5] += time;
      }
      if (eng->var[5] > 35.0) {
        Flags |= 2;
        if (!SoundOn) {
          loco->PostTriggerCab(109);
        }
      }
      else if (SoundOn) {
        loco->PostTriggerCab(110);
        Flags &= ~2;
        SoundOn = false;
      };
      if (eng->var[5] > 45.0) {
        // eng->TrainPipeRate=BRAKE_PIPE_EMERGENCY;
      };
      eng->var[8] = cab->Signal.Aspect[0];
    }
    else {
      if (Flags & 6) {
        loco->PostTriggerCab(110);
        Flags &= ~6;
      };
      eng->var[5] = 0.0;
    };
  };

  float DVol, DFreq;
  if (eng->Power >= 463.4) {
    DVol = 0.05 + (eng->Power - 463.4) / 490.0;
  }
  else {
    DVol = 0.05 * eng->Power / 463.4;
  }
  if (eng->RPM >= 350.0) {
    DFreq = 0.05 + (eng->RPM - 350.0) / 400.0;
  }
  else {
    DFreq = 0.05 * eng->RPM / 350.0;
  }
  SMSObject *soundCab = loco->SoundCab(), *soundEng = loco->SoundEng();
  if (soundCab) {
    soundCab->Var1[0] = DFreq;
    soundCab->Var2[0] = DVol;
  };
  if (soundEng) {
    soundEng->Var1[0] = DFreq;
    soundEng->Var2[0] = DVol;
    soundEng->Var3[0] = Current / 3.5;
  };
  anim = loco->FindAnim(L"ROD");
  if (anim) {
    if (eng->Power < 10.0) {
      anim->Flags &= ~1;
    }
    else {
      anim->Flags |= 1;
      anim->Speed = 5.0 * eng->Power / 993.0;
    };
  };

  if ((State >> 8) & 1) {
    cab->SetDisplayValue(0,
                         loco->Velocity > 0 ? loco->Velocity : -loco->Velocity);
    cab->SetDisplayValue(19,
                         loco->Velocity > 0 ? loco->Velocity : -loco->Velocity);
    cab->SetDisplayValue(1, loco->MainResPressure);
    cab->SetDisplayValue(2, loco->TrainPipePressure);
    cab->SetDisplayValue(3, eng->UR);
    float BC = loco->BrakeCylinderPressure > loco->IndependentBrakePressure
                   ? loco->BrakeCylinderPressure
                   : loco->IndependentBrakePressure;
    cab->SetDisplayValue(4, BC);
    cab->SetDisplayValue(5, Current);
    cab->SetDisplayValue(6, eng->RPM);
    cab->SetDisplayValue(7, BC);
    cab->SetDisplayValue(8, Current);
    switch (eng->DieselOn) {
    case 1:
      cab->SetDisplayValue(9, 10.0);
      cab->SetDisplayValue(10, 10.0);
      break;
    case 2:
      cab->SetDisplayValue(9, 10.0 * eng->RPM / 120.0);
      cab->SetDisplayValue(10, 10.0 * eng->Power / 159.0);
      break;
    default:
      cab->SetDisplayValue(9, 0.0);
      cab->SetDisplayValue(10, 0.0);
      break;
    };
    cab->SetDisplayValue(11, eng->var[9]);
    cab->SetDisplayState(12, eng->var[5] > 30.0 ? 1 : 0);
    cab->SetDisplayState(13, eng->var[9] > 100.0 ? 1 : 0);
    cab->SetDisplayState(14, (Flags & 8) ? 1 : 0);

    cab->SetDisplayState(16, eng->Wheelslip ? 1 : 0);

    eng->ALSNOn = 0;
    if (!cab->Switch(32)) {
      eng->ALSNOn = 1;
    }
    if (cab->Switch(28)) {
      eng->ALSNOn = 0xFFFF;
    }
  };
};
