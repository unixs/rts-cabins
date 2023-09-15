#include <cabin_context.h>

#define LOCOMOTIVE_CLASS_NAME "Locomotive"
#define DIESEL_LOCOMOTIVE_CLASS_NAME "DieselLocomotive"
#define CABIN_CLASS_NAME "Cabin"

#ifdef __cpusplus
  extern "C" {
#endif

// struct RClass*
// define_locomotive_cabin_class(CabinContext_t *ctxt);

// struct RClass*
// define_diesel_locomotive_cabin_class(CabinContext_t *ctxt);

void
define_cabin_interface(ctxt);

#ifdef __cpusplus
  }
#endif
