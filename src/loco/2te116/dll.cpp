#define DIESEL_LOCO

#include <common.hpp>

#include <cab.hpp>

using namespace model;


EMPTY_ENTRYPOINT


//-----{ INIT }-----------------------------------------------------------------

INIT { return true; }


//-----{ SWITCHED }-------------------------------------------------------------

SWITCHED
{
  CABIN;
  // АБ, ДИзель, топливный насос автомат, топливный насос тумблер 1 секции, пуск
  // дизеля
  if (SW(sw::AB_64) && SW(sw::diz_52) && SW(sw::tn1_7) && SW(sw::PD1_33)) {
    DI_ON(disp::sn_17);
    loco->PostTriggerCab(103);
  }
  else {
    DI_ON(disp::sn2_18);
  }

  DI_STATE(disp::ohla_19, 1);
}


//-----{ RUN }------------------------------------------------------------------

RUN {}


//-----{ CAN_SWITCH }-----------------------------------------------------------

CAN_SWITCH { return true; }


//-----{ CHANGE_LOCO }----------------------------------------------------------

CHANGE_LOCO {}


//-----{ CAN_WORK_WITH }--------------------------------------------------------

CAN_WORK_WITH { return true; }
