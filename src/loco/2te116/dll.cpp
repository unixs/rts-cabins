#include <common.hpp>
#include <cab.hpp>
#include <light.hpp>
#include <dizel.hpp>
#include <state.hpp>

using namespace model;


EMPTY_ENTRYPOINT

//-----{ STATE }----------------------------------------------------------------

static DieselState *state;


//-----{ INIT }-----------------------------------------------------------------

INIT { return true; }


//-----{ SWITCHED }-------------------------------------------------------------

SWITCHED
{
  // Вызываем основные ветки
  CALL_SW(aux_light_branch);
  CALL_SW(aux_dizel_start_branch);
}


//-----{ RUN }------------------------------------------------------------------

RUN
{
  // noop
}


//-----{ CAN_SWITCH }-----------------------------------------------------------

CAN_SWITCH { return true; }


//-----{ CHANGE_LOCO }----------------------------------------------------------

CHANGE_LOCO
{
  // noop
}


//-----{ CAN_WORK_WITH }--------------------------------------------------------

CAN_WORK_WITH { return true; }
