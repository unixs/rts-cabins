#include <tep70.hpp>

#define DLL_NAME "libtep70.dll"

static float var[10];

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

  init_pool();

  auto ctxt = init_context();

  uv_sleep(3000);

  void **ptra = (void **) var;
  for (size_t i = 0; i < 7; i++) {
    printf("PTRA: %p - %p\n", ptra, *ptra);
    ptra++;
  }

  printf("SAVE\n");
  printf("Address: %p\n", (void *) ctxt);
  uv_sleep(1000);

  save_context_ptr(&ctxt, var, 5);

  ptra = (void **) var;
  for (size_t i = 0; i < 7; i++) {
    printf("PTRA: %p - %p\n", ptra, *ptra);
    ptra++;
  }

  uv_sleep(1000);

  printf("RESTORE\n");
  uv_sleep(1000);

  Context *ctxt2 = restore_context_ptr(var);

  printf("Restored address: %p\n", (void *) ctxt2);
  uv_sleep(1000);

  printf("RUN\n");
  uv_sleep(1000);

  ctxt->run(0.05);

  printf("EXIT\n");
  system("PAUSE");
  return 0;
}
