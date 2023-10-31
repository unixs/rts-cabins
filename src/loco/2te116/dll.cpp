#define DIESEL

#include <common.hpp>

#include <cab.hpp>

using namespace model;


EMPTY_ENTRYPOINT

//-----{ INIT }-----------------------------------------------------------------

INIT { return true; }


//-----{ STATE }----------------------------------------------------------------

class DieselState {
public:
};

static DieselState *state;


//-----{ BRANCHES }-------------------------------------------------------------

#define LIGHT_PCOND auto pcond = SW(sw::AB_64) && SW(sw::AZVOS_77)

DEF_BRANCH(dizel_light)
{
  CABIN;

  LIGHT_PCOND;

  SWITCH_BLOCK(sw::osdp_74,
               {
                   // Включаем что-то
               },
               {
                   // Выключаем что-то
               });

  // Нету дочерних веток
}

DEF_BRANCH(vvk_light)
{
  CABIN;

  LIGHT_PCOND;

  if (pcond && SW(sw::osvvk_75)) {
    // Включаем что-то
  }
  else {
    // Выключаем что-то
  }

  // Нету дочерних веток
}

DEF_BRANCH(cabin_light)
{
  CABIN;

  LIGHT_PCOND;

  if (pcond && SW(sw::oscab_30)) {
    // Включаем что-то
  }
  else {
    // Выключаем что-то
  }

  // Нету дочерних веток
}

DEF_BRANCH(pult_light)
{
  CABIN;

  LIGHT_PCOND;

  if (pcond && SW(sw::ospult_28)) {
    // Включаем что-то
  }
  else {
    // Выключаем что-то
  }

  // Нету дочерних веток
}

DEF_BRANCH(tambur_light)
{
  CABIN;

  LIGHT_PCOND;

  if (pcond && SW(sw::osv_71)) {
    // Включаем что-то
  }
  else {
    // Выключаем что-то
  }

  // Нету дочерних веток
}

DEF_BRANCH(podkuzov_light)
{
  CABIN;

  LIGHT_PCOND;

  if (pcond && SW(sw::ospod_73)) {
    // Включаем что-то
  }
  else {
    // Выключаем что-то
  }

  // Нету дочерних веток
}

DEF_BRANCH(sl2m_light)
{
  CABIN;

  LIGHT_PCOND;

  if (pcond && SW(sw::osskor_80)) {
    // Включаем что-то
  }
  else {
    // Выключаем что-то
  }

  // Нету дочерних веток
}

/**
 * Отдельные ветви схемы освещения
 */
DEF_BRANCH(light)
{
  CALL_BRANCH(pult_light_branch);
  CALL_BRANCH(cabin_light_branch);
  CALL_BRANCH(tambur_light_branch);
  CALL_BRANCH(podkuzov_light_branch);
  CALL_BRANCH(dizel_light_branch);
  CALL_BRANCH(vvk_light_branch);
  CALL_BRANCH(sl2m_light_branch);
}

/**
 * Начало схемы освещения
 */
DEF_BRANCH(light_root)
{
  switch (switch_id) {
    CASE_BRANCH(sw::ospult_28, pult_light_branch);
    CASE_BRANCH(sw::oscab_30, cabin_light_branch);
    CASE_BRANCH(sw::osv_71, tambur_light_branch);
    CASE_BRANCH(sw::ospod_73, podkuzov_light_branch);
    CASE_BRANCH(sw::osdp_74, dizel_light_branch);
    CASE_BRANCH(sw::osvvk_75, vvk_light_branch);
    CASE_BRANCH(sw::osskor_80, sl2m_light_branch);


    case (UINT) sw::AZVOS_77:
    case (UINT) sw::AB_64:
      CALL_BRANCH(light_branch);
      break;
  }
}


//-----{ SWITCHED }-------------------------------------------------------------

SWITCHED
{
  // Вызываем основные ветки
  CALL_BRANCH(light_root_branch);
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
