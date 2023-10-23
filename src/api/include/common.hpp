#pragma once

#include <ts_fix.h>

/**
 * Ячейка массива var где начинается указатель на контекст используемая по
 * умолчанию
 */
#define DEFAULT_CONTEXT_CELL 1

/**
 * Ячейка `eng->var` в которой будет читаться указатель на контекст
 */
#ifndef CONTEXT_CELL
#  define CONTEXT_CELL DEFAULT_CONTEXT_CELL
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
