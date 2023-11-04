#include <light.hpp>
#include <cab.hpp>

using namespace model;

/**
 * Корневые предусловия схемы освещения
 */
#define LIGHT_PCOND MAIN_PCOND(SW(sw::AB_64) && SW(sw::AZVOS_77))

static DEF_BRANCH(dizel_light)
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

static DEF_BRANCH(vvk_light)
{
  CABIN;

  LIGHT_PCOND;

  SWITCH_BLOCK(sw::osvvk_75,
               {
                   // Включаем что-то
               },
               {
                   // Выключаем что-то
               });

  // Нету дочерних веток
}

static DEF_BRANCH(cabin_light)
{
  CABIN;

  LIGHT_PCOND;

  SWITCH_BLOCK(sw::oscab_30,
               {
                   // Включаем что-то
               },
               {
                   // Выключаем что-то
               });

  // Нету дочерних веток
}

static DEF_BRANCH(pult_light)
{
  CABIN;

  LIGHT_PCOND;

  SWITCH_BLOCK(sw::ospult_28,
               {
                   // Включаем что-то
               },
               {
                   // Выключаем что-то
               });

  // Нету дочерних веток
}

static DEF_BRANCH(tambur_light)
{
  CABIN;

  LIGHT_PCOND;

  SWITCH_BLOCK(sw::osv_71,
               {
                   // Включаем что-то
               },
               {
                   // Выключаем что-то
               });

  // Нету дочерних веток
}

static DEF_BRANCH(podkuzov_light)
{
  CABIN;

  LIGHT_PCOND;

  SWITCH_BLOCK(sw::ospod_73,
               {
                   // Включаем что-то
               },
               {
                   // Выключаем что-то
               });

  // Нету дочерних веток
}

static DEF_BRANCH(sl2m_light)
{
  CABIN;

  LIGHT_PCOND;

  SWITCH_BLOCK(sw::osskor_80,
               {
                   // Включаем что-то
               },
               {
                   // Выключаем что-то
               });

  // Нету дочерних веток
}

/**
 * Отдельные ветви схемы освещения
 */
static DEF_NODE(light)
{
  CALL_SW(pult_light_branch);
  CALL_SW(cabin_light_branch);
  CALL_SW(tambur_light_branch);
  CALL_SW(podkuzov_light_branch);
  CALL_SW(dizel_light_branch);
  CALL_SW(vvk_light_branch);
  CALL_SW(sl2m_light_branch);
}


DEF_BRANCH(aux_light)
{
  switch (switch_id) {
    CASE_BRANCH(sw::ospult_28, pult_light_branch);
    CASE_BRANCH(sw::oscab_30, cabin_light_branch);
    CASE_BRANCH(sw::osv_71, tambur_light_branch);
    CASE_BRANCH(sw::ospod_73, podkuzov_light_branch);
    CASE_BRANCH(sw::osdp_74, dizel_light_branch);
    CASE_BRANCH(sw::osvvk_75, vvk_light_branch);
    CASE_BRANCH(sw::osskor_80, sl2m_light_branch);


    case (UINT) sw::AB_64:
    case (UINT) sw::AZVOS_77:
      CALL_SW(light_node);
      break;
  }
}
