#include <context_pool.hpp>
#include <context.hpp>

#include <cstdio>
#include <list>

#define DEFAULT_GC_TIMEOUT 1000

#ifndef POOL_GC_TIMEOUT
#  define POOL_GC_TIMEOUT DEFAULT_GC_TIMEOUT
#endif


using namespace std;

/**
 * Поток сборщика мусора
 */
static uv_thread_t pool_thrd_id;

/**
 * Мьютекс структуры данных хранящей ссылки на все распределённые контексты
 */
static uv_mutex_t pool_lock;

/**
 * Структра данных для хранения всех выделенных контекстов
 */
static list<Context *> pool;

/**
 * #### Сборщик мусора
 * Выявляет контексты, которые больше не активны и освобождает их память
 * Здесь выполняется эвристический анализ основанный на допущениях и потому
 * подверженный неожиданным ошибкам
 */
static void
gc_run()
{
  // Try to destroy zombie cabins instances
  uv_mutex_lock(&pool_lock);

  printf("GC run\n");

  for (size_t i = 0; i < pool.size(); i++) {
    // TODO: implemnt me
    // try to remove
  }

  uv_mutex_unlock(&pool_lock);
}

/**
 * #### Основная ф-ция потока сборщика мосора
 * Через заданный промежуток времени проверяет все контексты на предмет наличия
 * зомби для сборки мусора
 */
static void
pool_worker(void *data)
{
  for (;;) {
    uv_sleep(POOL_GC_TIMEOUT);

    gc_run();
  }
}


/**
 * #### Инициализирует новый пулл контекстов и запускает поток сборщика мусора
 * Мусор это контексты, которые перестали участвовать в работе движка т.к.
 * локомотив для которого они были инициализированы больше не существует (зомби
 * - контекст)
 */
void
init_pool()
{
  uv_mutex_init(&pool_lock);

  uv_thread_create(&pool_thrd_id, pool_worker, NULL);
}

void
free_pool()
{
  // BUG: mem leak
}


Context *
create_context(Context *context)
{
  uv_mutex_lock(&pool_lock);

  pool.push_back(context);

  uv_mutex_unlock(&pool_lock);

  return context;
}
