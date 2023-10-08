#include <context_pool.h>
#include <cabin_context.h>

#include <cstdio>
#include <list>

#define DEFAULT_GC_TIMEOUT 1000

using namespace std;


static uv_thread_t pool_thrd_id;

static uv_mutex_t pool_lock;
static list<CabinContext *> pool;

static void
gc_run() {
  // Try to destroy zombie cabins instances
  uv_mutex_lock(&pool_lock);

  printf("GC run\n");

  for (size_t i = 0; i < pool.size(); i++) {
    // try to remove
  }

  uv_mutex_unlock(&pool_lock);
}

static void
pool_worker(void *data) {
  for(;;) {

    gc_run();

    uv_sleep(DEFAULT_GC_TIMEOUT);
  }
}

void
init_pool() {
  uv_mutex_init(&pool_lock);

  uv_thread_create(&pool_thrd_id, pool_worker, NULL);
}

void
free_pool() {
  // BUG: mem leek
}


CabinContext *
create_context() {
  uv_mutex_lock(&pool_lock);

  CabinContext *context = init_cabin_context();

  pool.push_back(context);

  uv_mutex_unlock(&pool_lock);

  return context;
}
