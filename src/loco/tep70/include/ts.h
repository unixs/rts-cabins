#include <windows.h>

#define TS_VERSION 104

#define MAXSOUNDQUEUE 96
#define MAXMSGQUEUE 16

#define SIGASP_STOP 0
#define SIGASP_STOP_AND_PROCEED 1
#define SIGASP_RESTRICTING 2
#define SIGASP_APPROACH_1 3
#define SIGASP_APPROACH_2 4
#define SIGASP_APPROACH_3 5
#define SIGASP_CLEAR_1 6
#define SIGASP_CLEAR_2 7
#define SIGASP_BLOCK_OBSTRUCTED 8
#define SIGASP_FAILED 9

#define GM_DOOR_OPEN 1
#define GM_DOOR_CLOSE 2
#define GM_DOOR_UNLOCK 3
#define GM_DOOR_LOCK 4
#define GM_SMS_POST 5
#define GM_LIGHT_ON 7
#define GM_LIGHT_OFF 8
#define GM_LIGHT_ENABLE 9
#define GM_LIGHT_DISABLE 10
#define GM_TEX_CHANGE 11
#define GM_TEX_REVERT 12
#define GMM_BOX 1
#define GMM_HINT 2
#define GMM_POST 3
#define GM_MSG_POST 14

#define CT_FRAME 0
#define CT_ARROW 1
#define CT_LINK 2
#define CT_LABEL 3
#define CT_BAR 4
#define CT_GRID 5

// Wagon classes
#define WCL_WAGON 0
#define WCL_LOCOEL 1
#define WCL_LOCODS 2
#define WCL_LOCOST 3

#define RTSOAL_LOCO 1
#define RTSOAL_CABIN 2
#define RTSOAL_SALON 3
#define RTSOAL_AUXLIB 4

typedef enum {
  RTSOT_Switch = 1,
  RTSOT_Display = 2,
  RTSOT_Loco = 3,
  RTSOT_Door = 4,
  RTSOT_Area = 5,
  RTSOT_Window = 6,
  RTSOT_Cabin = 7,
  RTSOT_Cls = 8,
  RTSOT_ClsSub = 9,
  RTSOT_Scr = 10,
  RTSOT_ScrSub = 11,
  RTSOT_Engine = 12,
  RTSOT_Exhaust = 13,
  RTSOT_FreeAnim = 14,
  RTSOT_IntLight = 15,
  RTSOT_Light = 16,
  RTSOT_Sound = 17,
  RTSOT_TexChng = 18,
  RTSOT_EngExtParam = 19,
  RTSOT_SlaveLoco = 20,
  RTSOT_Wagon = 21,
  RTSOT_AuxLib = 22,
  RTSOT_SignalsInfo = 23,
  RTSOT_Chair = 24,
  RTSOT_Seat = 25
} RTSObjType;

struct Wagon;
struct Locomotive;
struct Cabin;
struct AnimNode;
struct Engine;
struct ElectricEngine;
struct DieselEngine;
struct SMSObject;
struct TrackItemsItem;

typedef int (*LPRTS_GETINT)(const Locomotive *loco, UINT Code, int Index);
typedef void *(*LPRTS_GETOBJ)(void *DLL, const void *obj, short ActLoc,
                              RTSObjType Code, int Index, int SubIndex);
typedef void *(*LPRTS_GETOBJBYNAME)(void *DLL, const void *obj, short ActLoc,
                                    RTSObjType Code, const wchar_t *Name,
                                    int SubIndex);
typedef void *(*LPRTS_GETOBJLOCO)(void *DLL, const Locomotive *loco,
                                  RTSObjType Code, int Index, int SubIndex);
typedef void *(*LPRTS_GETOBJBYNAMELOCO)(void *DLL, const Locomotive *loco,
                                        RTSObjType Code, const wchar_t *Name,
                                        int SubIndex);
typedef void *(*LPRTS_GETOBJCAB)(void *DLL, const Cabin *cab, RTSObjType Code,
                                 int Index, int SubIndex);
typedef void *(*LPRTS_GETOBJBYNAMECAB)(void *DLL, const Cabin *cab,
                                       RTSObjType Code, const wchar_t *Name,
                                       int SubIndex);
typedef int (*LPRTS_GETTRITEMS)(void *DLL, const Locomotive *loco, UINT Code,
                                float Distance, TrackItemsItem *&items,
                                UINT &Count);
typedef int (*LPRTS_GETNAMEDINT)(const void *obj, UINT Code, wchar_t *Name);
typedef int (*LPRTS_GETSNDTRON)(const SMSObject *sound, USHORT TriggerCode);

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

struct Object {
  USHORT UID;
  void *tile;
  void *objX;
  void *Composition;
  void *Reserved1, *Reserved2;
  char Sort, Draw;
  void *shape;
  void *mesh;
  void *Attach[2];
  float Coord[3];
  ULONG Flags, CollideFlags, CollideFunction;
  float QDirection[4];
  ULONG VbID;
  UCHAR DetailLevel;
  UCHAR ObjType;
  UINT Idx;
  float Elevation, Distance;
  void *CurLOD;
  float Volume[4];
  AnimNode *anim;
  void *modelX;
};

struct DLLInterfaceObject {
private:
  void *adaptLink;
  UINT adaptStatus;
  void *adapters;
};

struct TrackPDP {
  short TileX, TileZ;
  float X, Y, Z;
  UINT a1, a2;
  void *Node;
  UINT SubIDX;
  float NodeOff, NodeLen, NodeOffHigh;
  float Radius;
  float Direction[3];
  bool Reversed;
};

struct TrackTDP {
  void *ds;
  Wagon *wag;
  TrackPDP *pos;
  void *Node;
  TrackTDP *next, *prev;
  float Time, Distance;
};

struct EngineParam {
  wchar_t *name;
  float Value;
  wchar_t *str;
};

wchar_t _RTS_ParamBuf[128];

struct AuxLibrary : public DLLInterfaceObject {
  void *lib;
#ifdef RTS_NODIRECTOBJLINKS
  void *loco;
  float *var;
  USHORT NumParams;
  UINT StackSize;
  void *Params;
  void *sound;
#else
  Locomotive *loco;
  float *var;
  USHORT NumParams;
  UINT StackSize;
  EngineParam *Params;
  SMSObject *sound;
#endif
  void *soundObj;
  wchar_t *Name;
  unsigned long LibFlags;
  /*
  1bite
   1bit - after main call
  */

  void *ChangeLoco, *LostMaster;
  void *ALSN;
  void *SpeedLim;
  void *InitLoco, *Run;
  void *CanSwitch, *Switched;

  inline float GetParameter(wchar_t *name, float Default) const {
    EngineParam *p = (EngineParam *)RTSGetObjectByName(
        DLLHandle, this, RTSOAL_AUXLIB, RTSOT_EngExtParam, name, -1);
    if (p)
      return p->Value;
    return Default;
  };

  inline wchar_t *GetParameterAsString(wchar_t *name,
                                       const wchar_t *Default) const {
    EngineParam *p = (EngineParam *)RTSGetObjectByName(
        DLLHandle, this, RTSOAL_AUXLIB, RTSOT_EngExtParam, name, -1);
    if (p) {
      if (p->str)
        return p->str;
#ifdef __STDIO_H
      swprintf(_RTS_ParamBuf, L"%.03f", p->Value);
      return _RTS_ParamBuf;
#endif
    };
    return (wchar_t *)Default;
  };

  inline SMSObject *Sound() const {
    return (SMSObject *)RTSGetObject(DLLHandle, this, RTSOAL_AUXLIB,
                                     RTSOT_Sound, -1, -1);
  };

  inline const Locomotive *Loco() const {
    return (Locomotive *)RTSGetObject(DLLHandle, this, RTSOAL_AUXLIB,
                                      RTSOT_Loco, -1, -1);
  };

  inline bool PostTrigger(USHORT TrigID) const;
};

#ifndef RTS_NODIRECTOBJLINKS
struct AuxLibStack {
  AuxLibrary *LibObjs;
  UINT NumLibraries;
};
#endif

struct ActivatorObject {
  Wagon *Parent;
  AnimNode *AnimPart;
  wchar_t *name, *hint;
  float Pos[4];
  unsigned char Type;
  short ParentObj, Location;
  float AnimSpeed;
  UINT State, SetState;
};

struct ActDoor : public ActivatorObject {
  unsigned long flags;
  /*
   1bit - Has Trajectory
   2bit - Has Area
   3bit - can be opened
  */
  unsigned int GlobalID;
  short Connects[4];
  UINT NumTrajPoints;
  float *Trajectory;
  float DoorArea[6];
  float AnimTime, Soundproof[2];
  AnimNode *OutNode;
  short SMSTrigger[2];
};

struct ActArea : public ActivatorObject {
  unsigned long flags, ID;
  /*
   1bit -
   2bit - area in sight
  */
  UINT NumChild;
  AnimNode **child;
};

struct ActSwitch : public ActivatorObject {
  unsigned int NumStates, InitialState, NumHints, FixedState;
  unsigned long Flags;
  /*
   1bite
   1bit - ControllerX
   2bit - Key
   3bit - Non-fixed
   4bit - is assigned key pressed(for non-fixed)
   5bit - goes down(for fixed)
   6bit - ControllerY
   7bit - Precise
   8bit - Overscale

   2bite
   1bit - Display Is Of Arrow Type
   2bit - Display is Of Lamp Type
   3bit - Display Is Of Display Type
   4bit - Display is Of Screen Type

   3bite
   1bit - Order looped
   2bit - disabled
   3bit - check distance on key / sequence display
   4bit - stretch UV
   5bit - first key pressed
  */
  unsigned char Key[4];

  /*
  2&4bite
  1bit - Shift state
  2bit - Ctrl state
  3bit - Alt state
  */
  float AnimTime, *AnimScale, CurrentFrame;
  float precdX, precdY;
  unsigned long KeyPressed;
  void *hints;
};

struct ActDisplay : public ActivatorObject {
  float ValuesRange[4], Granularity, Fade[4];
  unsigned long Flags; // same as ActSwitch
  int ShowHint;
  UINT NumHints;
  void *hints;

  float Value;
};

struct ActWindow : public ActivatorObject {
  float *Planes;
  UINT NumPlanes;
  bool CanBeOpened;
  float HeadOutPos[3];
  float AnimTime;
  AnimNode *OutNode;
  void *in;
  short SMSTrigger[2];
};

struct ActChair : public ActivatorObject {
  ActWindow *HeadOut;
  bool HasHeadOut;
  float Direction[3];
  float Pos1[3], Pos2[3], Pos3[3];
  /*
   ActivatorObject::State for chair:

   1bite
    1bit - is player standing
    2bit - is player in headout
  */
};

struct ActSeat : public ActivatorObject {
  float Pos1[3], Pos2[3], Area[4];
  unsigned long Flags;
  ActWindow *HeadOut;
  /*
   1bit - has area
   2bit - attached to window
   3bit - is player in headout
  */
};

struct FreeAnimation {
  wchar_t *name;
  unsigned int NumNodes, NumKeyFrames, AnimateTo;
  void **nodes;
  unsigned long Flags;
  /*
   1bit - running
   2bit - continuous
   3bit - loop

   2bite

   1bit - goes down

  */
  float AnimTime, *AnimScale, Speed, SpeedQ, MaxSpeed;
  wchar_t **nodeNames;

  inline void Switch(bool On) {
    if (On)
      this->Flags |= 1;
    else
      this->Flags &= ~1;
  };
};

struct TexChange {
  UINT TexID, GlobalID;
  unsigned short State, SetState;
  wchar_t *old, *name;
  UINT Change;
};

struct CloseUpSubObject {
  UINT ID, Type, Shader;
  Wagon *Parent;
  ULONG Flags, AnimFlags;
  wchar_t *hint;
  float Area[4], UV[4], Act[4], Pt[8], Rotate[3];
  float AnimTime, *AnimScale, AnimSpeed, Frame, Value, Fade[4];
  int CurrentTex, State, SetState;
  unsigned long Colour;
  UINT NumTex, NumFrames;
  void *Tex;
  void *Frames;
  CloseUpSubObject *References, *BelongsToList;
  UINT ParentSub, ParentListCount;
};

struct CloseUpScene : public ActivatorObject {
  UINT CurrentBackground;
  UINT NumBack, Shader;
  void *Backs;
  float *UVs;
  UINT NumSub;
  CloseUpSubObject *Obj;
  UINT sPrev;
  void *Adj[4];
  bool Transparent;
  float CameraPos[3], CameraDir[4], CameraFOV;
  ULONG Colour;
};

struct ActScreen {
  float Pos[4], Norm[3], Pivot[3], Up[3], Width, Height;
  unsigned int NumSub;
  CloseUpSubObject *Obj;
  ActScreen *ReferenceScr;
  CloseUpScene *ReferenceScn;
};

//---------------Train data------------------------

struct RTSSignalData {
  short Tile[2];
  float Pos[3];
  wchar_t *Name;
};

struct SignalsInfo {
  float Distance;
  UINT Aspect[4], Flags;
  /*
  Flags
   1bite
    1bit - has normal fn
    2bit - has distance fn
    3bit - has shunt fn
    4bir - has info fn
  */
  float SpeedLimit;
  RTSSignalData *SignalInfo;
};

struct LightObj {
  unsigned long Flags, Type;
  /*
  Flags
   1bite
    1bit - LightOn
    2bit - FadingOut
    3bit - FadingIn
    4bit - TurnOn
    5bit - Reversed
  */
  unsigned long Colour;
  float Position[3];
  float Dir[4];
  float UV[4];
  float Vol[4], Vol1[4];
  float Radius, Phase;
  float FadeIn, FadeOut;
  float Attenuation[4], ArrayStride[4], SourceRadius, ArrayItemLength;
  UINT ArraySize;
  float SpotExp;
  void *parent;
  void *light;
  void *next;
};

struct InternalLight {
  unsigned long Flags;
  AnimNode *obj;
  float Position[3], Points[3], Radius[3], Fade[4], SpotExp, SpotGen;
  unsigned long Colour, ProjSize;
  void *light;
  unsigned int State, GlobalID;
  float AutoOnWorldLit, Attenuation[4], ArrayStride[4], ArrayItemLength,
      SourceRadius;
  UINT ArraySize;
};

struct Light {
  unsigned long Colour;
  float Duration;
  float X, Y, Z;
  float Pos[3];
  float Azimuth[3];
  float Transition;
  float Radius, Elevation[3], Angle;
  bool On;
};

struct ExhaustContr {
  float Rate, Magnitude, Dispertion, Mass;
  unsigned long Colour;
};

struct Wagon : public DLLInterfaceObject {
  unsigned char IsLocomotive, PantoRaised, Coupling;
  unsigned long UID;
  void *TrainIn;
  float Durability;
  unsigned long Flags, Flags1;
  /*
  Flags
   1bite
    1bit - Flipped
    2bit - In sight
    3bit - Player in
    4bit - sounds loaded for player train
    5bit - loaded void sounds

   2bite
    1,2bit - train pipe(front/rear) disconnected
    3,4bit - 2nd train pipe disconnected
    5,6bit - ep_brake disconnected
    7,8bit - end valves closed(front/rear)

   3bite == WagonData::Cables

   4bite
    1,2bit - front/rear bogie fastened
  Coupl
   1bite
    1,2bit - coupling(front/rear) locked
    3,4bit - coupling(front/rear) detached
  */
  float Mass;
  UINT PassengersAboard;
  float BrakeForce, CylinderPressure, IndependentBrakePressure,
      AuxiliaryPressure, EPTvalue, PTValue;
  float Velocity, Acceleration, Resistance, Slope, Force;
  double ZOrd;
  float BrakeCylinderPressure, TrainPipePressure, TrainPipeRate,
      ChargingPipePressure, HandbrakeValue;
  float Osc[8];
  Object *obj;
  TrackPDP TrPos[2];
  TrackTDP TrPosT;
  void *wag;

  USHORT NumDoors, NumLadders, NumAnim, NumLedges, NumPlanes, NumFrAnims;
#ifdef RTS_NODIRECTOBJLINKS
  void *Doors;
  void *Ladders, *Ledges, *Planes;
  void *AnimParts;
  UINT NumBogies;
  void *Bogies;
  void *Wheels;
  void *Anims;
  void *lights;
  void *FrAnim;
  void *Int;
  void *sound;
#else
  ActDoor *Doors;
  void *Ladders, *Ledges, *Planes;
  AnimNode *AnimParts;
  UINT NumBogies;
  void *Bogies;
  void *Wheels;
  FreeAnimation *Anims;
  LightObj *lights;
  void *FrAnim;
  void *Int;
  SMSObject *sound;
#endif
  void *soundobj;
  void *WagonObjs;
};

struct Cabin : public DLLInterfaceObject {
  Wagon *Parent;
  AnimNode *nodes;
  void *shape;
  UINT NumSwitches, NumDisplays, NumAnim, NumSwDecor;
  UINT SignalBlockCheckAhead, SignalNumLights, SignalNumAspects, SignalScripted;
  AnimNode **Signals;
  unsigned int *SignalAspects, SignalAspects1;
  UINT NumAreas, NumPlanes, NumDoors, NumWindows, NumChairs, NumTexChanges,
      NumLights, NumScenes, NumSeats, NumLedges;
  SignalsInfo Signal;
  unsigned long Flags;

#ifdef RTS_NODIRECTOBJLINKS
  void *Switches, *SwitchesDecor;
  void *Displays;
  void *Anims;
  void *areas;
  float *Planes;
  int *PlaneParent;
  void *Doors;
  void *Windows;
  void *Chairs;
  void *Seats;
  void *Tex;
  void *Light;
  void *Cls;
  void *Ledges;

  void *PlayerInChair;
#else
  ActSwitch *Switches, *SwitchesDecor;
  ActDisplay *Displays;
  FreeAnimation *Anims;
  ActArea *areas;
  float *Planes;
  int *PlaneParent;
  ActDoor *Doors;
  ActWindow *Windows;
  ActChair *Chairs;
  void *Seats;
  TexChange *Tex;
  InternalLight *Light;
  CloseUpScene *Cls;
  void *Ledges;

  ActChair *PlayerInChair;
#endif
  Object obj;

  inline int Switch(UINT ID) {
    ActSwitch *sw =
        (ActSwitch *)RTSGetCabObject(DLLHandle, this, RTSOT_Switch, ID, -1);
    if (!sw)
      return -1;
    return sw->State;
  };

  inline int SwitchSet(UINT ID) {
    ActSwitch *sw =
        (ActSwitch *)RTSGetCabObject(DLLHandle, this, RTSOT_Switch, ID, -1);
    if (!sw)
      return -1;
    return sw->SetState;
  };

  int SwitchSub(UINT ID) {
    CloseUpSubObject *sw = (CloseUpSubObject *)RTSGetCabObject(
        DLLHandle, this, RTSOT_ClsSub, ID, -1);
    if (!sw)
      return -1;
    return sw->State;
  };

  inline int SwitchSub(UINT sceneID, UINT objID) {
    CloseUpSubObject *sw = (CloseUpSubObject *)RTSGetCabObject(
        DLLHandle, this, RTSOT_ClsSub, sceneID, objID);
    if (!sw)
      return -1;
    return sw->State;
  };

  inline void SetSwitch(UINT ID, UINT State, bool SetBoth) {
    ActSwitch *sw =
        (ActSwitch *)RTSGetCabObject(DLLHandle, this, RTSOT_Switch, ID, -1);
    if (sw) {
      sw->SetState = State;
      if (SetBoth)
        sw->State = State;
    };
  };

  inline void SetSwitchFixedState(UINT ID, UINT FixedState, bool Set) {
    ActSwitch *sw =
        (ActSwitch *)RTSGetCabObject(DLLHandle, this, RTSOT_Switch, ID, -1);
    if (sw) {
      sw->FixedState = FixedState;
      if (Set)
        sw->SetState = FixedState;
    };
  };

  inline void SetSwitch(UINT sceneID, UINT objID, float Value, bool SetBoth) {
    CloseUpSubObject *o = (CloseUpSubObject *)RTSGetCabObject(
        DLLHandle, this, RTSOT_ClsSub, sceneID, objID);
    if (o) {
      if (o->Type == 1) {
        o->Value = Value;
      } else {
        o->SetState = Value;
        if (SetBoth)
          o->State = Value;
      };
    };
  };

  inline float GetSwitchFrame(UINT SwitchID) {
    ActSwitch *sw = (ActSwitch *)RTSGetCabObject(DLLHandle, this, RTSOT_Switch,
                                                 SwitchID, -1);
    if (sw) {
      if (sw->Flags & 64)
        return sw->CurrentFrame;
      else
        return sw->State;
    };
    return 0.0;
  };

  inline void SetDisplayValue(UINT displayID, float Value) {
    ActDisplay *dpl = (ActDisplay *)RTSGetCabObject(
        DLLHandle, this, RTSOT_Display, displayID, -1);
    if (dpl)
      dpl->Value = Value;
  };

  inline void SetDisplayState(UINT displayID, UINT State) {
    ActDisplay *dpl = (ActDisplay *)RTSGetCabObject(
        DLLHandle, this, RTSOT_Display, displayID, -1);
    if (dpl)
      dpl->State = State;
  };

  inline float DisplayValue(UINT displayID) {
    ActDisplay *dpl = (ActDisplay *)RTSGetCabObject(
        DLLHandle, this, RTSOT_Display, displayID, -1);
    if (dpl)
      return dpl->Value;
    return 0.0;
  };

  inline float DisplayState(UINT displayID) {
    ActDisplay *dpl = (ActDisplay *)RTSGetCabObject(
        DLLHandle, this, RTSOT_Display, displayID, -1);
    if (dpl)
      return dpl->State;
    return 0;
  };

  inline void SetHint(UINT displayID, int ID) {
    ActDisplay *dpl = (ActDisplay *)RTSGetCabObject(
        DLLHandle, this, RTSOT_Display, displayID, -1);
    if (dpl)
      dpl->ShowHint = ID;
  };

  inline bool IsDoorOpened(UINT ID) {
    ActDoor *door =
        (ActDoor *)RTSGetCabObject(DLLHandle, this, RTSOT_Door, ID, -1);
    if (door)
      return door->State;
    return false;
  };

  inline void SwitchLight(UINT ID, UINT On) {
    InternalLight *lgt = (InternalLight *)RTSGetCabObject(
        DLLHandle, this, RTSOT_IntLight, ID, -1);
    if (lgt)
      lgt->State = On;
  };

  inline void SetLightColour(UINT ID, ULONG Colour) {
    InternalLight *lgt = (InternalLight *)RTSGetCabObject(
        DLLHandle, this, RTSOT_IntLight, ID, -1);
    if (lgt)
      lgt->Colour = Colour;
  };

  inline void SetLightState(UINT ID, UINT State, ULONG Colour, float SpotExp,
                            float RadiusX = -1.0, float RadiusZ = -1.0) {
    InternalLight *lgt = (InternalLight *)RTSGetCabObject(
        DLLHandle, this, RTSOT_IntLight, ID, -1);
    if (lgt) {
      lgt->State = State;
      if (Colour)
        lgt->Colour = Colour;
      if (SpotExp >= 0.0)
        lgt->SpotExp = SpotExp;
      if (RadiusX > 0.0)
        lgt->Radius[0] = RadiusX;
      if (RadiusZ > 0.0)
        lgt->Radius[1] = RadiusZ;
    };
  };

  inline unsigned int IsLightOn(UINT ID) {
    InternalLight *lgt = (InternalLight *)RTSGetCabObject(
        DLLHandle, this, RTSOT_IntLight, ID, -1);
    if (lgt)
      return lgt->State;
    return 0;
  };

  inline int ScreenState(UINT DisplayID, UINT SubID) {
    CloseUpSubObject *sw = (CloseUpSubObject *)RTSGetCabObject(
        DLLHandle, this, RTSOT_ScrSub, DisplayID, SubID);
    if (sw)
      return sw->State;
    return 0;
  };

  inline void SetScreenState(UINT DisplayID, UINT SubID, int State) {
    CloseUpSubObject *sw = (CloseUpSubObject *)RTSGetCabObject(
        DLLHandle, this, RTSOT_ScrSub, DisplayID, SubID);
    if (sw)
      sw->SetState = State;
  };

  inline void SetScreenLabel(UINT DisplayID, UINT SubID, wchar_t *text) {
    CloseUpSubObject *sw = (CloseUpSubObject *)RTSGetCabObject(
        DLLHandle, this, RTSOT_ScrSub, DisplayID, SubID);
    if (sw)
      if (sw->Type == CT_LABEL && sw->hint) {
        if (text)
          lstrcpynW(sw->hint, text, sw->Pt[1]);
        else
          sw->hint[0] = 0;
      };
  };

  inline void SetScreenValue(UINT DisplayID, UINT SubID, float Value) {
    CloseUpSubObject *sw = (CloseUpSubObject *)RTSGetCabObject(
        DLLHandle, this, RTSOT_ScrSub, DisplayID, SubID);
    if (sw)
      sw->Value = Value;
  };

  inline float ScreenValue(UINT DisplayID, UINT SubID) {
    CloseUpSubObject *sw = (CloseUpSubObject *)RTSGetCabObject(
        DLLHandle, this, RTSOT_ScrSub, DisplayID, SubID);
    if (sw)
      return sw->Value;
    return -1.0;
  };

  inline void SetScreenArea(UINT DisplayID, UINT SubID, float *area,
                            UINT Flags) {
    CloseUpSubObject *sw = (CloseUpSubObject *)RTSGetCabObject(
        DLLHandle, this, RTSOT_ScrSub, DisplayID, SubID);
    if (sw) {
      if (Flags & 1)
        sw->Area[0] = area[0];
      if (Flags & 2)
        sw->Area[1] = area[1];
      if (Flags & 4)
        sw->Area[2] = area[2];
      if (Flags & 8)
        sw->Area[3] = area[3];
    };
  };

  inline void SetScreenGridState(UINT DisplayID, UINT SubID, int Row, int Col,
                                 int State) {
    CloseUpSubObject *sw = (CloseUpSubObject *)RTSGetCabObject(
        DLLHandle, this, RTSOT_ScrSub, DisplayID, SubID);
    if (sw) {
      if (sw->Type == CT_GRID) {
        if (State > 0)
          sw->SetState |= 1 << (Row * int(sw->Pt[2]) + Col);
        else
          sw->SetState &= ~(1 << (Row * int(sw->Pt[2]) + Col));
      };
    };
  };

  inline void ChangeTexture(UINT TexChangeID, UINT State) {
    TexChange *chng = (TexChange *)RTSGetCabObject(
        DLLHandle, this, RTSOT_TexChng, TexChangeID, -1);
    if (chng)
      chng->SetState = State;
  };

  inline void SetScreenFade(UINT DisplayID, UINT SubID, float Fade,
                            float Blink) {
    CloseUpSubObject *sw = (CloseUpSubObject *)RTSGetCabObject(
        DLLHandle, this, RTSOT_ScrSub, DisplayID, SubID);
    if (sw) {
      if (Fade >= 0.0)
        sw->Fade[1] = Fade;
      if (Blink >= 0.0)
        sw->Fade[2] = Blink;
    };
  };

  inline void SetDisplayFade(UINT displayID, float Fade, float Blink) {
    ActDisplay *dpl = (ActDisplay *)RTSGetCabObject(
        DLLHandle, this, RTSOT_Display, displayID, -1);
    if (dpl) {
      if (Fade >= 0.0)
        dpl->Fade[1] = Fade;
      if (Blink >= 0.0)
        dpl->Fade[2] = Blink;
    };
  };

  inline FreeAnimation *FindAnim(wchar_t *name) const {
    return (FreeAnimation *)RTSGetCabObjectByName(DLLHandle, this,
                                                  RTSOT_FreeAnim, name, -1);
  };

  inline ActDoor *Door(UINT ID) const {
    return (ActDoor *)RTSGetCabObject(DLLHandle, this, RTSOT_Door, ID, -1);
  };

  inline TexChange *TextureChange(UINT TexChangeID) {
    return (TexChange *)RTSGetCabObject(DLLHandle, this, RTSOT_TexChng,
                                        TexChangeID, -1);
  };

  inline InternalLight *LightInt(UINT LightID) {
    return (InternalLight *)RTSGetCabObject(DLLHandle, this, RTSOT_IntLight,
                                            LightID, -1);
  };

  inline ActChair *Chair(UINT ID) const {
    return (ActChair *)RTSGetCabObject(DLLHandle, this, RTSOT_Chair, ID, -1);
  };
  inline ActSeat *Seat(UINT ID) const {
    return (ActSeat *)RTSGetCabObject(DLLHandle, this, RTSOT_Seat, ID, -1);
  };
  inline ActChair *Chair(wchar_t *Name) const {
    return (ActChair *)RTSGetCabObjectByName(DLLHandle, this, RTSOT_Chair, Name,
                                             -1);
  };
  inline ActSeat *Seat(wchar_t *Name) const {
    return (ActSeat *)RTSGetCabObjectByName(DLLHandle, this, RTSOT_Seat, Name,
                                            -1);
  };
};

struct Locomotive : public Wagon {
  unsigned long LocoFlags;
  /*
   1bite
    1bit - Master locomotive
    2bit - direction flipped
    3bit - in player's join
    4bit - cold
    5bit - has cabin
    6bit - script loaded
    7bit - cabin loaded for player
    8bit - AI-controlled

   2bite
    1bit - sanding applied
    2bit - pantograph overburnt
  */
  UINT NumEngines, NumSlaves, NumAxles;
  float MainResPressure;
  float SandLeft, LastSanding, PantoBurnTimer;

#ifdef RTS_NODIRECTOBJLINKS
  void *cab;
  UINT LibParam, StackSize;
  void *Slaves;
  void **FirstInGroup, **LastInGroup;
  void *locoA;
#else
  Cabin *cab;
  UINT LibParam, StackSize;
  Locomotive **Slaves;
  Wagon **FirstInGroup, **LastInGroup;
  Engine *locoA;
#endif
  void *AI;

  void *CanWorkWith;
  void *ChangeLoco, *LostSlave;
  void *ALSN;
  void *SpeedLim;
  void *LibModule;
#ifdef RTS_NODIRECTOBJLINKS
  void *AuxLibs;
#else
  AuxLibStack *AuxLibs;
#endif

  inline void SwitchLight(USHORT ID, bool TurnOn, float Radius = 0.0,
                          unsigned long Colour = 0) const;
  inline void ReverseLight(USHORT ID, bool Reversed);
  inline bool IsLightOn(USHORT ID) const;
  inline bool PostTriggerBoth(USHORT N) const;
  inline bool PostTriggerCab(USHORT N) const;
  inline bool PostTriggerEng(USHORT N) const;
  inline void LockCoupling(bool Front, bool Locked) const;
  inline void DetachCoupling(bool Front, bool Detached) const;

  inline float GetParameter(wchar_t *name, float Default = 0.0) const;
  inline wchar_t *GetParameterAsString(wchar_t *name,
                                       const wchar_t *Default) const;
  inline FreeAnimation *FindAnim(wchar_t *name) const;
  inline SMSObject *SoundEng() const;
  inline SMSObject *SoundCab() const;
  inline Cabin *Cab() const;
  inline Engine *Eng() const;
  inline Locomotive *SlaveLoco(UINT N) const;
  inline ActDoor *Door(UINT ID) const;
  inline int GetTrackItems(UINT Code, float Distance, TrackItemsItem *&res,
                           UINT &Count) const;
  inline AuxLibrary *GetAuxLibrary(wchar_t *Name) const;
  inline int IsSMSTriggerOnEng(USHORT Code) const;
  inline int IsSMSTriggerOnCab(USHORT Code) const;
};

struct ElectricLocomotive : public Locomotive {
  void *eng;
#ifdef RTS_NODIRECTOBJLINKS
  void *loco;
#else
  ElectricEngine *loco;
#endif
  void *InitLoco, *Run;
  void *CanSwitch, *Switched;

  float LineVoltage, LineFreq, LineCurrent;
  void *Line;
};

struct DieselLocomotive : public Locomotive {
  void *eng;
#ifdef RTS_NODIRECTOBJLINKS
  void *loco;
#else
  DieselEngine *loco;
#endif
  void *InitLoco, *Run;
  void *CanSwitch, *Switched;

  float FuelAmount;

  USHORT NumEx;
  void *Ex;
};

struct Engine : public DLLInterfaceObject {
#ifdef RTS_NODIRECTOBJLINKS
  void *cab;
  void *sound;
  float *var;
  void *Parameters;
#else
  Cabin *cab;
  SMSObject *sound;
  float *var;
  EngineParam *Parameters;
#endif

  float Power, Force, BrakeForce;
  float *EngineVoltage, *EngineCurrent, *EngineForce;
  float IndependentBrakeValue, TrainPipeRate, AuxilaryRate, MainResRate,
      ChargingRate, HandbrakePercent, DynamicBrakePercent, EPTvalue, UR;
  float ExternalPowerSource, ExternalPowerSourceVoltage;
  double BatteryCharge;
  unsigned short BrakeSystemsEngaged, ALSNOn, Sanding, NumLights, NumParameters;
  /*
   BrakeSystems
   1bit - pneumatic(single_pipe)
   2bit - electro-pneumatic
   3bit - twin pipe
   4bit - vacuum pipe
  */
  unsigned long EngineFlags, Flags, Flags2;
  /*
  EngineFlags
   1bite
    1bit - release train brake
    2bit - release independent brake
  */
  int Reverse;
  unsigned int Wheelslip;
  unsigned int ThrottlePosition;
  float CurrentMilepost;
  unsigned short GlobalMsg[MAXMSGQUEUE * 2];

  bool PostGlobalMessage(short Action, short ID) {
    short i = 0;
    while (i < MAXMSGQUEUE && this->GlobalMsg[i * 2])
      i++;
    if (i == MAXMSGQUEUE)
      return false;
    i *= 2;
    this->GlobalMsg[i] = Action;
    this->GlobalMsg[++i] = ID;
    return true;
  };

  bool ShowMessage(short Type, wchar_t *text) {
    if (!text || Type < 1 || Type > 3)
      return false;
    short i = 0;
    while (i < MAXMSGQUEUE && this->GlobalMsg[i * 2])
      i++;
    // Possible issue with over-64 bit addressation
    if (i >= MAXMSGQUEUE - 3)
      return false;
    i *= 2;
    wchar_t *&m = *(wchar_t **)(&this->GlobalMsg[i + 2]);
    this->GlobalMsg[i] = GM_MSG_POST;
    this->GlobalMsg[++i] = Type;
    m = text;
    return true;
  };
};

struct ElectricEngine : public Engine {
  unsigned char Panto, MainSwitch;
  float PowerConsuming;
};

struct DieselEngine : public Engine {
  unsigned char DieselOn;
  float FuelConsuming, RPM;
  void *Ex;
};

#define TIT_UNK 0
#define TIT_SIG 1
#define TIT_SPEED 2
#define TIT_PLATF 3
#define TIT_SIDING 4
#define TIT_LEVELCR 5
#define TIT_CROSS 6
#define TIT_PICKUP 7
#define TIT_CARSPWN 8

struct TrackItem {
  UINT Type, ID;
  float SNodeOff;
  unsigned long SDataFlags;
  /*
   1bite
    1bit - for level crossings - opened
  */
  float PDataX, PDataZ;
  short PDataTileX, PDataTileZ;
  float RDataX, RDataY, RDataZ;
  short RTileX, RTileZ;
};

struct SpeedPostItem : public TrackItem {
  UINT Flags;
  /*
   1bite
    1bit - resume speed
    2bit - speedpost
    4bit - milepost with speed limit
    5bit - show numbers
    6bit - set speed for passenger
    7bit - set speed for freight
    8bit - set speed for all
   2bite
    1bit - MPH
    2bit - show dot
  */
  float Value, Off, KM;
  int Number;
};

struct PlatformItem : public TrackItem {
  unsigned long TrItemFlags, TrItemConj;
  wchar_t *PlatformName, *StationName;
  UINT MinWaitTime, Passengers;
  void *pl;
  void *at;
};

struct CrossoverItem : public TrackItem {
  UINT Conj, SectionIDX;
};

struct LevelCrItem : public TrackItem {
  float Time, Distance;
};

struct PickupItem : public TrackItem {
  float Amount;
  unsigned long PickupFlags;
  void *at;
};

struct TrackItemsItem {
  float Distance, Z;
  USHORT Pos;
  TrackItem *obj;
};

inline void Exhaust(const DieselLocomotive *loco, USHORT ID, float Rate,
                    float Magnitude, float Dispertion, ULONG Colour,
                    float Mass) {
  ExhaustContr *exh =
      (ExhaustContr *)RTSGetLocoObject(DLLHandle, loco, RTSOT_Exhaust, ID, -1);
  if (exh) {
    if (Rate >= 0.0)
      exh->Rate = Rate;
    if (Magnitude >= 0.0)
      exh->Magnitude = Magnitude;
    if (Dispertion >= 0.0)
      exh->Dispertion = Dispertion;
    if (Colour)
      exh->Colour = Colour;
    if (Mass > 0.0)
      exh->Mass = Mass;
  };
};

inline void Locomotive::SwitchLight(USHORT ID, bool TurnOn, float Radius,
                                    unsigned long Colour) const {
  LightObj *lgt =
      (LightObj *)RTSGetLocoObject(DLLHandle, this, RTSOT_Light, ID, -1);
  if (lgt) {
    if (TurnOn)
      lgt->Flags |= 8;
    else
      lgt->Flags &= ~8;
    if (Radius > 0.0)
      lgt->Radius = Radius;
    if (Colour)
      lgt->Colour = Colour;
    // this->lights[ID].Colour=(Colour&0xFF00FF00)|((Colour&0xFF0000)>>16)|((Colour&0xFF)<<16);
  };
};

inline void Locomotive::ReverseLight(USHORT ID, bool Reversed) {
  LightObj *lgt =
      (LightObj *)RTSGetLocoObject(DLLHandle, this, RTSOT_Light, ID, -1);
  if (lgt) {
    if (Reversed)
      lgt->Flags |= 16;
    else
      lgt->Flags &= ~16;
  };
};

inline bool Locomotive::IsLightOn(USHORT ID) const {
  LightObj *lgt =
      (LightObj *)RTSGetLocoObject(DLLHandle, this, RTSOT_Light, ID, -1);
  if (lgt)
    return lgt->Flags & 8;
  return false;
};

inline void Locomotive::LockCoupling(bool Front, bool Locked) const {
  unsigned char b, *coupl = (unsigned char *)&this->Coupling;
  if (Front)
    b = 1;
  else
    b = 2;
  if (Locked)
    *coupl |= b;
  else
    *coupl &= ~b;
};

inline void Locomotive::DetachCoupling(bool Front, bool Detached) const {
  unsigned char b, *coupl = (unsigned char *)&this->Coupling;
  if (Front)
    b = 4;
  else
    b = 8;
  if (Detached)
    *coupl |= b;
  else
    *coupl &= ~b;
};

inline Cabin *Locomotive::Cab() const {
  return (Cabin *)RTSGetLocoObject(DLLHandle, this, RTSOT_Cabin, 0, -1);
};

inline Engine *Locomotive::Eng() const {
  return (Engine *)RTSGetLocoObject(DLLHandle, this, RTSOT_Engine, 0, -1);
};

inline Locomotive *Locomotive::SlaveLoco(UINT N) const {
  return (Locomotive *)RTSGetLocoObject(DLLHandle, this, RTSOT_SlaveLoco, N,
                                        -1);
};

inline ActDoor *Locomotive::Door(UINT ID) const {
  return (ActDoor *)RTSGetLocoObject(DLLHandle, this, RTSOT_Door, ID, -1);
};

inline int Locomotive::GetTrackItems(UINT Code, float Distance,
                                     TrackItemsItem *&items,
                                     UINT &Count) const {
  if (RTSGetTrackItems)
    return RTSGetTrackItems(DLLHandle, this, Code, Distance, items, Count);
  Count = 0;
  return 0;
};

inline AuxLibrary *Locomotive::GetAuxLibrary(wchar_t *Name) const {
  return (AuxLibrary *)RTSGetLocoObjectByName(DLLHandle, this, RTSOT_AuxLib,
                                              Name, -1);
};

struct SMSObject {
  void *sms;
  unsigned long Flags;
  /*
   1bit - has discrete triggers
   2bit - is On
   3bit - is starting
  */
  unsigned short Queue[MAXSOUNDQUEUE], QueuePos;
  float Speed[2], Var1[2], Var2[2], Var3[2], Var4[2], Var5[2], Var6[2], Var7[2],
      Var8[2], Distance[2], Trav[2], Accel[2], Radius[2];
  float Volume;
  void *Streams;
  unsigned long LocoFlags, TriggersProcessed, StepCount;
  void *PairedFlags;

  bool PostTrigger(UINT TriggerID) {
    if (!TriggerID)
      return false;
    USHORT idx = this->QueuePos;
    while (idx < MAXSOUNDQUEUE) {
      if (!this->Queue[idx]) {
        this->Queue[idx] = TriggerID;
        return true;
      };
      idx++;
    };
    if (idx == MAXSOUNDQUEUE) {
      idx = 0;
      while (idx < this->QueuePos) {
        if (!this->Queue[idx]) {
          this->Queue[idx] = TriggerID;
          return true;
        };
        idx++;
      };
    };
    return false;
  };

  inline unsigned short GetNamedTrigger(wchar_t *Name) const;
  inline int IsTriggerOn(unsigned short Code) const;
};

inline bool Locomotive::PostTriggerBoth(USHORT N) const {
  bool res = true;
  SMSObject *soundExt, *soundCab;
  soundExt = (SMSObject *)RTSGetLocoObject(DLLHandle, this, RTSOT_Sound, 0, -1);
  soundCab = (SMSObject *)RTSGetLocoObject(DLLHandle, this, RTSOT_Sound, 1, -1);
  if (soundExt)
    res = soundExt->PostTrigger(N);
  if (soundCab)
    res = soundCab->PostTrigger(N) && res;
  return res;
};

inline bool Locomotive::PostTriggerCab(USHORT N) const {
  SMSObject *soundCab =
      (SMSObject *)RTSGetLocoObject(DLLHandle, this, RTSOT_Sound, 1, -1);
  if (soundCab)
    return soundCab->PostTrigger(N);
  return true;
};

inline bool Locomotive::PostTriggerEng(USHORT N) const {
  bool res = true;
  SMSObject *soundExt =
      (SMSObject *)RTSGetLocoObject(DLLHandle, this, RTSOT_Sound, 0, -1);
  if (soundExt)
    res = soundExt->PostTrigger(N);
  return res;
};

inline SMSObject *Locomotive::SoundEng() const {
  return (SMSObject *)RTSGetLocoObject(DLLHandle, this, RTSOT_Sound, 0, -1);
};

inline SMSObject *Locomotive::SoundCab() const {
  return (SMSObject *)RTSGetLocoObject(DLLHandle, this, RTSOT_Sound, 1, -1);
};

inline int Locomotive::IsSMSTriggerOnEng(USHORT Code) const {
  SMSObject *soundObj =
      (SMSObject *)RTSGetLocoObject(DLLHandle, this, RTSOT_Sound, 0, -1);
  if (soundObj)
    return soundObj->IsTriggerOn(Code);
  else
    return -5;
};

inline int Locomotive::IsSMSTriggerOnCab(USHORT Code) const {
  SMSObject *soundObj =
      (SMSObject *)RTSGetLocoObject(DLLHandle, this, RTSOT_Sound, 1, -1);
  if (soundObj)
    return soundObj->IsTriggerOn(Code);
  else
    return -5;
};

inline FreeAnimation *Locomotive::FindAnim(wchar_t *name) const {
  return (FreeAnimation *)RTSGetLocoObjectByName(DLLHandle, this,
                                                 RTSOT_FreeAnim, name, -1);
};

inline float Locomotive::GetParameter(wchar_t *name, float Default) const {
  EngineParam *p = (EngineParam *)RTSGetLocoObjectByName(
      DLLHandle, this, RTSOT_EngExtParam, name, -1);
  if (p)
    return p->Value;
  return Default;
};

inline wchar_t *Locomotive::GetParameterAsString(wchar_t *name,
                                                 const wchar_t *Default) const {
  EngineParam *p = (EngineParam *)RTSGetLocoObjectByName(
      DLLHandle, this, RTSOT_EngExtParam, name, -1);
  if (p) {
    if (p->str)
      return p->str;
#ifdef __STDIO_H
    swprintf(_RTS_ParamBuf, L"%.03f", p->Value);
    return _RTS_ParamBuf;
#endif
  };
  return (wchar_t *)Default;
};

inline bool AuxLibrary::PostTrigger(USHORT TrigID) const {
  if (this->sound)
    return this->sound->PostTrigger(TrigID);
  return true;
};

struct SpeedLimitDescr {
  float Limit, NextLimit, Distance;
};

float GetLimit(float &l1, float &l2, float l3 = -1.0) {
  float l;
  l = l1;
  if (l < 0.0 || (l2 < l && l2 >= 0.0))
    l = l2;
  if (l < 0.0 || (l3 < l && l3 >= 0.0))
    l = l3;
  return l;
};

#define DLLV_VERSION 1
#define DLLV_SWITCH 2
#define DLLV_DISPLAY 3
#define DLLV_SCREEN 4
#define DLLV_LOCO 5
#define DLLV_LOCOE 6
#define DLLV_LOCOD 7
#define DLLV_ENGINE 8
#define DLLV_ENGINEE 9
#define DLLV_ENGINED 10
#define DLLV_LIGHT 11
#define DLLV_CABIN 12
#define DLLV_INTLIGHT 13
#define DLLV_CLSSUB 14
#define DLLV_OBJECT 15
#define DLLV_WAGON 16
#define DLLV_ACTIVATOR 17
#define DLLV_ADAPTER_COMPLIANCE 18
#define DLLV_STACKSIZE 19
#define DLLV_TRACKITEM 20
#define DLLV_TRACKITEMITEM 21

// GetInteger Code
#define RTS_VAR_TIME 1
#define RTS_NUM_WAG 2
#define RTS_ISNIGHT 3
#define RTS_NUM_UNITS 4
#define RTS_TRIGGERID 5
#define RTS_TRAINDIR 6
#define RTS_TAPEROLL 7

#define RTSE_AHEAD -1
#define RTSE_BEHIND 1

#ifdef RTS_ADAPTER_COMPLY
#define RTS_ADAPTER_COMPLIANCE 39
#endif
#ifdef RTS_ADAPTER_COMPLIANCE039
#define RTS_ADAPTER_COMPLIANCE 39
#endif

inline unsigned short SMSObject::GetNamedTrigger(wchar_t *Name) const {
  return RTSGetNamedInteger(this->sms, RTS_TRIGGERID, Name);
};
inline int SMSObject::IsTriggerOn(unsigned short Code) const {
  if (!this || !this->PairedFlags || !RTSIsSMSTriggerOn)
    return -5;
  return RTSIsSMSTriggerOn(this, Code);
};

extern "C" bool __export InitRTSLibrary(HINSTANCE Module, void *DLL) {
  DLLHandle = DLL;
  RTSGetInteger = (LPRTS_GETINT)GetProcAddress(Module, "_RTSGetInteger");
  RTSSetIntegerG = (LPRTS_GETINT)GetProcAddress(Module, "_RTSSetIntegerG");
  RTSGetObject = (LPRTS_GETOBJ)GetProcAddress(Module, "_RTSGetObject");
  RTSGetObjectByName =
      (LPRTS_GETOBJBYNAME)GetProcAddress(Module, "_RTSGetObjectByName");
  RTSGetLocoObject =
      (LPRTS_GETOBJLOCO)GetProcAddress(Module, "_RTSGetLocoObject");
  RTSGetLocoObjectByName =
      (LPRTS_GETOBJBYNAMELOCO)GetProcAddress(Module, "_RTSGetLocoObjectByName");
  RTSGetCabObject = (LPRTS_GETOBJCAB)GetProcAddress(Module, "_RTSGetCabObject");
  RTSGetCabObjectByName =
      (LPRTS_GETOBJBYNAMECAB)GetProcAddress(Module, "_RTSGetCabObjectByName");
  RTSGetTrackItems =
      (LPRTS_GETTRITEMS)GetProcAddress(Module, "_RTSGetTrackItems");
  RTSGetNamedInteger =
      (LPRTS_GETNAMEDINT)GetProcAddress(Module, "_RTSGetNamedInteger");
  RTSIsSMSTriggerOn =
      (LPRTS_GETSNDTRON)GetProcAddress(Module, "_RTSIsSMSTriggerOn");
  if (!RTSGetInteger || !RTSGetObject || !RTSGetObjectByName ||
      !RTSGetLocoObject || !RTSGetLocoObjectByName || !RTSGetCabObject ||
      !RTSGetCabObjectByName || !RTSSetIntegerG)
    return false;
  return true;
};

extern "C" unsigned long __export DLLVersion(unsigned int Parameter) {
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
