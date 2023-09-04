/**
 * Извлечение кабины в текущий контекст
 */
#define CABIN Cabin *cab = loco->Cab()

/**
 * Запрос состояния переключателя
 */
#define SW(id) (cab->Switch(id))

/**
 * Установка состояния индикатора
 */
#define DI_STATE(id, state) (cab->SetDisplayState(id, state))

/**
 * Включение индикатора
 */
#define DI_ON(id) DI_STATE(id, true)

/**
 * Выключение индикатора
 */
#define DI_OFF(id) DI_STATE(id, false)
