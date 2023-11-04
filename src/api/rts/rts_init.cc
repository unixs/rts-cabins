#include <ts_init.hpp>

LPRTS_GETINT RTSGetInteger = NULL, RTSSetIntegerG = NULL;
LPRTS_GETOBJ RTSGetObject = NULL;
LPRTS_GETOBJBYNAME RTSGetObjectByName = NULL;
LPRTS_GETOBJLOCO RTSGetLocoObject = NULL;
LPRTS_GETOBJBYNAMELOCO RTSGetLocoObjectByName = NULL;
LPRTS_GETOBJCAB RTSGetCabObject = NULL;
LPRTS_GETOBJBYNAMECAB RTSGetCabObjectByName = NULL;
LPRTS_GETTRITEMS RTSGetTrackItems = NULL;
LPRTS_GETNAMEDINT RTSGetNamedInteger = NULL;
LPRTS_GETSNDTRON RTSIsSMSTriggerOn = NULL;
void *DLLHandle = NULL;
wchar_t _RTS_ParamBuf[RTS_EXTRA_PARAM_BUF_SIZE];

void
Exhaust(const DieselLocomotive *loco, USHORT ID, float Rate, float Magnitude,
        float Dispertion, ULONG Colour, float Mass)
{
  ExhaustContr *exh =
      (ExhaustContr *) RTSGetLocoObject(DLLHandle, loco, RTSOT_Exhaust, ID, -1);
  if (exh) {
    if (Rate >= 0.0) {
      exh->Rate = Rate;
    }
    if (Magnitude >= 0.0) {
      exh->Magnitude = Magnitude;
    }
    if (Dispertion >= 0.0) {
      exh->Dispertion = Dispertion;
    }
    if (Colour) {
      exh->Colour = Colour;
    }
    if (Mass > 0.0) {
      exh->Mass = Mass;
    }
  };
};

float
GetLimit(float &l1, float &l2, float l3)
{
  float l;
  l = l1;
  if (l < 0.0 || (l2 < l && l2 >= 0.0)) {
    l = l2;
  }
  if (l < 0.0 || (l3 < l && l3 >= 0.0)) {
    l = l3;
  }
  return l;
};

bool __export
InitRTSLibrary(HINSTANCE Module, void *DLL)
{
  DLLHandle = DLL;
  RTSGetInteger = (LPRTS_GETINT) GetProcAddress(Module, "_RTSGetInteger");
  RTSSetIntegerG = (LPRTS_GETINT) GetProcAddress(Module, "_RTSSetIntegerG");
  RTSGetObject = (LPRTS_GETOBJ) GetProcAddress(Module, "_RTSGetObject");
  RTSGetObjectByName =
      (LPRTS_GETOBJBYNAME) GetProcAddress(Module, "_RTSGetObjectByName");
  RTSGetLocoObject =
      (LPRTS_GETOBJLOCO) GetProcAddress(Module, "_RTSGetLocoObject");
  RTSGetLocoObjectByName = (LPRTS_GETOBJBYNAMELOCO) GetProcAddress(
      Module, "_RTSGetLocoObjectByName");
  RTSGetCabObject =
      (LPRTS_GETOBJCAB) GetProcAddress(Module, "_RTSGetCabObject");
  RTSGetCabObjectByName =
      (LPRTS_GETOBJBYNAMECAB) GetProcAddress(Module, "_RTSGetCabObjectByName");
  RTSGetTrackItems =
      (LPRTS_GETTRITEMS) GetProcAddress(Module, "_RTSGetTrackItems");
  RTSGetNamedInteger =
      (LPRTS_GETNAMEDINT) GetProcAddress(Module, "_RTSGetNamedInteger");
  RTSIsSMSTriggerOn =
      (LPRTS_GETSNDTRON) GetProcAddress(Module, "_RTSIsSMSTriggerOn");
  if (!RTSGetInteger || !RTSGetObject || !RTSGetObjectByName ||
      !RTSGetLocoObject || !RTSGetLocoObjectByName || !RTSGetCabObject ||
      !RTSGetCabObjectByName || !RTSSetIntegerG) {
    return false;
  }
  return true;
};

unsigned long __export
DLLVersion(unsigned int Parameter)
{
  switch (Parameter) {
    case DLLV_VERSION:
      return TS_VERSION;
    case DLLV_SWITCH:
      return sizeof(ActSwitch);
    case DLLV_DISPLAY:
      return sizeof(ActDisplay);
    case DLLV_SCREEN:
      return sizeof(ActScreen);
    case DLLV_LOCO:
      return sizeof(Locomotive);
    case DLLV_LOCOE:
      return sizeof(ElectricLocomotive);
    case DLLV_LOCOD:
      return sizeof(DieselLocomotive);
    case DLLV_ENGINE:
      return sizeof(Engine);
    case DLLV_ENGINEE:
      return sizeof(ElectricEngine);
    case DLLV_ENGINED:
      return sizeof(DieselEngine);
    case DLLV_LIGHT:
      return sizeof(LightObj);
    case DLLV_CABIN:
      return sizeof(Cabin);
    case DLLV_INTLIGHT:
      return sizeof(InternalLight);
    case DLLV_CLSSUB:
      return sizeof(CloseUpSubObject);
    case DLLV_OBJECT:
      return sizeof(Object);
    case DLLV_WAGON:
      return sizeof(Wagon);
    case DLLV_ACTIVATOR:
      return sizeof(ActivatorObject);
    case DLLV_TRACKITEM:
      return sizeof(TrackItem);
    case DLLV_TRACKITEMITEM:
      return sizeof(TrackItemsItem);

    case DLLV_ADAPTER_COMPLIANCE:
#ifdef RTS_ADAPTER_COMPLIANCE
      return RTS_ADAPTER_COMPLIANCE;
#else
      return 0;
#endif
    case DLLV_STACKSIZE:
#ifdef RTS_STACKSIZE
      return RTS_STACKSIZE;
#else
      return 0;
#endif
  };
  return 0;
};
