#include <cstring>
#include <cmath>
#include <api_status.h>
#include <context.hpp>

/**
 * #### Сохраняет указатель контекста в "стеке" переменных кабины
 * Размер "стека" должен быть не менее 5и элементов т.к. они зарезервированы
 * для хранения указателя на контекст
 */
api_status
save_context_ptr(Context **ctxt_ptr, float dst[], const size_t arr_size);
/**
 * #### Восстанавливает указатель контекста из "стека" переменных модели
 */
api_status
restore_context_ptr(const float src[], Context **ptr_to_data_ptr);
