#pragma once

#include <ts_fix.h>

#ifdef DIESEL
#  define ENGINE_TYPE DieselEngine
#  define LOCO_TYPE DieselLocomotive
#else
#  define ENGINE_TYPE ElectricEngine
#  define LOCO_TYPE ElectricLocomotive
#endif

/**
 * #### Извлечение кабины в текущий контекст
 */
#define CABIN Cabin *cab = loco->Cab()

/**
 * #### Запрос состояния переключателя
 */
#define SW(id) (cab->Switch((UINT) (id)))

/**
 * #### Установка состояния индикатора
 */
#define DI_STATE(id, state) (cab->SetDisplayState((UINT) id, (UINT) state))

/**
 * #### Включение индикатора
 */
#define DI_ON(id) DI_STATE(id, true)

/**
 * #### Выключение индикатора
 */
#define DI_OFF(id) DI_STATE(id, false)

/**
 * #### Установка значения индикатора
 */
#define DI_VAL(id, val) (cab->SetDisplayValue((UINT) id, val))

/**
 * #### Вводит переменную *ctxt* извлекая из `eng->var[]` указатель
 */
#define CONTEXT(T)                                                             \
  auto ctxt = static_cast<T *>(restore_context_ptr(&eng->var[CONTEXT_CELL]));

#define CAB_CONTEXT(T)                                                         \
  CABIN;                                                                       \
  CONTEXT(T)

/**
 * Пустая точка входа в dll
 */
#define EMPTY_ENTRYPOINT                                                       \
  int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason,              \
                           void *lpReserved)                                   \
  {                                                                            \
    return 1;                                                                  \
  }

/**
 * Ф-ция API RTS
 */
#define RUN                                                                    \
  extern "C" void __export Run(ENGINE_TYPE *eng, const LOCO_TYPE *loco,        \
                               unsigned long State, float time,                \
                               float AirTemperature)

/**
 * Ф-ция API RTS
 */
#define CAN_SWITCH                                                             \
  extern "C" bool __export CanSwitch(const LOCO_TYPE *loco, ENGINE_TYPE *eng,  \
                                     unsigned int switch_id,                   \
                                     unsigned int new_state)

/**
 * Ф-ция API RTS
 */
#define SWITCHED                                                               \
  extern "C" void __export Switched(const LOCO_TYPE *loco, ENGINE_TYPE *eng,   \
                                    unsigned int switch_id,                    \
                                    unsigned int prev_state)

/**
 * Ф-ция API RTS
 */
#define INIT                                                                   \
  extern "C" bool __export Init(ENGINE_TYPE *eng, LOCO_TYPE *loco,             \
                                unsigned long State, float time,               \
                                float AirTemperature)

/**
 * Ф-ция API RTS
 */
#define CHANGE_LOCO                                                            \
  extern "C" void __export ChangeLoco(                                         \
      Locomotive *next, const Locomotive *prev, unsigned long state)

/**
 * Ф-ция API RTS
 */
#define CAN_WORK_WITH                                                          \
  extern "C" bool __export CanWorkWith(const Locomotive *loco,                 \
                                       const wchar_t *type)

#define DEF_BRANCH(func)                                                       \
  void func##_branch(const LOCO_TYPE *loco, ENGINE_TYPE *eng,                  \
                     unsigned int switch_id, unsigned int prev_state)

#define DEF_NODE(func)                                                         \
  void func##_node(const LOCO_TYPE *loco, ENGINE_TYPE *eng,                    \
                   unsigned int switch_id, unsigned int prev_state)

#define DEF_SWITCH(id, func, block)                                            \
  void func##_switch(const LOCO_TYPE *loco, ENGINE_TYPE *eng,                  \
                     unsigned int switch_id, unsigned int prev_state)          \
  {                                                                            \
    if (switch_id != (UINT) id) {                                              \
      return;                                                                  \
    }                                                                          \
    block                                                                      \
  }

/**
 * Вызов ф-ций ветки эл-ой схемы начиная с заданной
 */
#define CALL_SW(func) func(loco, eng, switch_id, prev_state)

#define CASE_SW(sw) case (UINT) sw

/**
 * Подстановка выключателя к обработчику
 */
#define CASE_BRANCH(sw, func)                                                  \
  CASE_SW(sw) : { CALL_SW(func); }                                             \
  break;

/**
 * Главное предусловие
 */
#define MAIN_PCOND(condition) auto main_pcond = (condition)

#define CHAIN_MAIN_PCOND(condition) main_pcond = main_pcond && (condition)

/**
 * Главный условный блок ветки
 */
#define SWITCH_BLOCK(sw, on, off)                                              \
  if (main_pcond && SW(sw))                                                    \
  on else off

/**
 * Главный условный блок ветки
 */
#define COND_BLOCK(cond, on, off)                                              \
  if (main_pcond && (cond))                                                    \
  on else off
