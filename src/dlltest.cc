#include <windows.h>
#include <cstdio>
#include <cstring>

#define DLL_NAME "libtep70.dll"

int
main(int argc, char *argv[])
{
  // printf("%s", argv[1]);

  // HINSTANCE tep70 = LoadLibrary(TEXT(DLL_NAME));

  // if (tep70 != NULL) {
  //  ProcAdd = (MYPROC) GetProcAddress(hinstLib, "myPuts");

  // If the function address is valid, call the function.

  // if (NULL != ProcAdd) {
  //    fRunTimeLinkSuccess = TRUE;
  //    (ProcAdd) (L"Message sent to the DLL function\n");
  // }
  // Free the DLL module.

  //  printf("Dll has been loaded\n");

  // FreeLibrary(tep70);
  //}

  char str[] = "some string.";
  char *str_ptr;
  float arr[] = {.1, .2, .3};

  printf("direct\n");
  memcpy(arr, &str, sizeof(void *));
  printf("back\n");
  memcpy(&str_ptr, arr, sizeof(void *));

  printf("%s\n", str_ptr);

  system("PAUSE");

  return 0;
}
