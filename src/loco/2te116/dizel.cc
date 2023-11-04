#include <dizel.hpp>
#include <cab.hpp>

using namespace model;

/**
 * Корневые предусловия схемы пуска
 */
#define DIZEL_START_ROOT_PCOND MAIN_PCOND(SW(sw::AB_64) && SW(sw::diz_52))

/**
 * Кнопка пуска дизеля 1 секции
 */
static DEF_BRANCH(start_btn_1)
{
  CABIN;

  DIZEL_START_ROOT_PCOND;
  CHAIN_MAIN_PCOND(SW(sw::tn1_7));

  SWITCH_BLOCK(sw::PD1_33,
               {
                   // Включаем топливный насос
               },
               {
                   // Выключаем топливный насос
               })
}

/**
 * Тумблер ТН первой секции
 */
static DEF_BRANCH(fuel_pump_1)
{
  CABIN;

  DIZEL_START_ROOT_PCOND;

  SWITCH_BLOCK(sw::tn1_7,
               {
                   // Включаем топливный насос
               },
               {
                   // Выключаем топливный насос
               });

  CALL_SW(start_btn_1_branch);
}

static DEF_BRANCH(oil_pump)
{
  CABIN;

  DIZEL_START_ROOT_PCOND;
  CHAIN_MAIN_PCOND(SW(sw::tn1_7));

  COND_BLOCK(SW(sw::PD1_33),
             {
                 // Включаем топливный насос
             },
             {
                 // Выключаем топливный насос
             })
}

static DEF_NODE(dizel_start)
{
  // Тут ветви пуска дизеля
  CALL_SW(fuel_pump_1_branch);
}

DEF_BRANCH(aux_dizel_start)
{
  // NOTE: Цепи пуска дизеля

  switch (switch_id) {
    CASE_BRANCH(sw::tn1_7, fuel_pump_1_branch);
    CASE_BRANCH(sw::PD1_33, start_btn_1_branch);

    case (UINT) sw::AB_64:
    case (UINT) sw::diz_52:
      CALL_SW(dizel_start_node);
      break;
  }
}
