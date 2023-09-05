#include <common.h>
#include <switches.h>
#include <model.h>

void
process_SW_EDT(unsigned int SwitchID, unsigned int PrevState,
                                  const ElectricLocomotive *loco,
                                  const ElectricEngine *eng) {
  CABIN;

  if (SW(SW_EDT_1) || SW(SW_EDT_2)) {
    DI_ON(DI_SBROS_1);
    DI_ON(DI_SBROS_2);
  } else {
    DI_OFF(DI_SBROS_1);
    DI_OFF(DI_SBROS_2);
  }
}
