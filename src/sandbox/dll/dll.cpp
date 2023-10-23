#include <dll.hpp>
#include <cstdio>

BOOL WINAPI
DllMain(HINSTANCE hinstDLL, DWORD reason, LPVOID lpReserved)
{
  switch (reason) {
  case DLL_PROCESS_ATTACH:
    printf("ATTACH\n");
    break;

  case DLL_PROCESS_DETACH:
    printf("DETACH\n");
    break;
  }

  return TRUE; // Successful DLL_PROCESS_ATTACH.
}

__export void
dll_func()
{
  printf("DLL CALLBACK\n");
}
