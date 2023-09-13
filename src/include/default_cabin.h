#include <cabin_context.h>

#define DEFAULT_CABIN_CLASS_NAME "DefaultCabin"

#ifdef __cpusplus
  extern "C" {
#endif

struct RClass*
define_default_cabin_class(CabinContext_t *ctxt);

#ifdef __cpusplus
  }
#endif
