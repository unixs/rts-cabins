#pragma once

#include <winsock2.h>
#include <windows.h>

#define __export __declspec(dllexport)
#define __import __declspec(dllimport)

#define Run _Run
#define Switched _Switched
#define InitRTSLibrary _InitRTSLibrary
#define Init _Init
#define DLLVersion _DLLVersion
#define CanSwitch _CanSwitch
#define CanWorkWith _CanWorkWith
#define ChangeLoco _ChangeLoco
