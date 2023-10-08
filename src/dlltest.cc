#include <windows.h>
#include <cstdio>

#define DLL_NAME "libtep70.dll"

int main(int argc, char *argv[]) {
  // printf("%s", argv[1]);

  HINSTANCE tep70 = LoadLibrary(TEXT(DLL_NAME));

  if (tep70 != NULL) {
    // ProcAdd = (MYPROC) GetProcAddress(hinstLib, "myPuts");

    // If the function address is valid, call the function.

    // if (NULL != ProcAdd) {
    //    fRunTimeLinkSuccess = TRUE;
    //    (ProcAdd) (L"Message sent to the DLL function\n");
    // }
    // Free the DLL module.

    printf("Dll has been loaded\n");

    // FreeLibrary(tep70);
  }

  system("PAUSE");

  return 0;
}
