#define DIESEL

#include <common.hpp>

#include <cab.hpp>

using namespace model;


EMPTY_ENTRYPOINT
extern void (*signal(int, void (*)(int)))(int);

//-----{ INIT }-----------------------------------------------------------------

INIT { return true; }


//-----{ SWITCHED }-------------------------------------------------------------

class DieselState {
public:
  bool
  shema_power();

  void
  set_schema_power(bool);

  bool
  oil_pump();

  void
  set_oil_pump(bool);

  bool
  fuel_pump();

  void
  set_fuel_pump(bool);
};

static DieselState *state;

// Тут может быть макрос маппинга имени ф-ции на внутренний макрос
inline void
main_switch(BlackBox *state, const LOCO_TYPE *loco, const ENGINE_TYPE *eng)
{
  CABIN;

  // тут может быть макрос маппинга переключателя на метод
  if (SW(sw::tn1_7)) {
    state->set_schema_power(true);
  }
  else {
    state->set_schema_power(false);
  }

  // Тут запускаем ф-ции всех веток, которые содержат флаг в своих предусловиях
  // Флаг или выключатель
}

void
dizel_start_branch(DieselState *state, const LOCO_TYPE *loco,
                   const ENGINE_TYPE *eng)
{
  if ((state->shema_is_ready()) && SW(sw::tn1_7)) {
    return 1.;
  }
  else {
    .0;
  }
}

SWITCHED
{
  CABIN;
  /*
  // Главный рубильник АБ
  main_switch(state, loco, eng);

  // Ветка запуска дизеля
  dizel_start_branch(state, loco, eng);

  // Контроль пуска и глушения
  dizel_control(loco, eng);

  eng->var[3] = dizel_start_prep();*/
  /*
  АБ, ДИзель, топливный насос автомат, топливный насос тумблер 1 секции, пуск
  дизеля
  */
  // Предусловие
  if (SW(sw::PD1_33)) {
    // Условное действие
    DI_ON(disp::sn_17);
    loco->PostTriggerCab(103);
    // timer
    // pusk
    // kontrol
    // disel_on
    // AB zaradka
    // kopressor_start
  }
  // Отмена действия
  else {
    DI_ON(disp::sn2_18);
  }

  DI_ON(disp::ohla_19);
}


//-----{ RUN }------------------------------------------------------------------

float
someFunc();

RUN { check_rdtm(); }


//-----{ CAN_SWITCH }-----------------------------------------------------------

CAN_SWITCH { return true; }


//-----{ CHANGE_LOCO }----------------------------------------------------------

CHANGE_LOCO {}


//-----{ CAN_WORK_WITH }--------------------------------------------------------

CAN_WORK_WITH { return true; }
