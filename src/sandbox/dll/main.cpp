#include <windows.h>
#include <cstdio>
#include <dll.hpp>

#define DLL_NAME "libsomefunc.dll"

// static float var[10];

HINSTANCE mylib;

int
main(int argc, char *argv[])
{
  printf("%s", argv[1]);

  mylib = LoadLibrary(TEXT(DLL_NAME));

  if (mylib != NULL) {
    printf("Dll has been loaded\n");

    dll_callback callback = (dll_callback) GetProcAddress(mylib, "dll_func");

    if (NULL != callback) {
      callback();
    }

    FreeLibrary(mylib);
  }
}
