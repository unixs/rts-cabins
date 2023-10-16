#include <uv.h>
#include <context.hpp>

typedef struct {
  uv_timer_t *svistok_timer = nullptr;
  bool svist_is_on = false;
} Tep70State;


class Tep70Context : public Context {
  Tep70State *_state;

public:
  Tep70Context();

  ~Tep70Context();

  Tep70State *
  state();
};
