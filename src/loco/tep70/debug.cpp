#include <debug.hpp>
#include <model.h>
#include <ts_fix.h>


static char *var_mapping[VAR_SIZE];

const char *
get_var_mapping()
{

  var_mapping[11] = "dizel_oil_timer";
  var_mapping[12] = "dizel_start_timer";

  return (const char *) var_mapping;
}

void
after_run(DieselEngine *eng, const DieselLocomotive *loco, unsigned long State,
          float time, float AirTemperature)
{
}
