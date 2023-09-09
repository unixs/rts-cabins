#include <uv.h>

typedef void (* timer_callback)(uv_timer_t *timer);

/**
 * Содержит главный цикл событий кабины
 */
class MainLoop {
  /**
   * Задержка между итерациями цикла
   */
  const float delay;

  /**
   * Указатель на экземпляр цикла
   */
  uv_loop_t *loop;

  /**
   * Полное время прошедшее с момента загрузки кабины
   */
  float time;

  /**
   * Время прошедшее с момента последнего запуска цикла
   */
  float step_time;

public:
  MainLoop(const float delay);
  ~MainLoop();

  /**
   * Выполняет итерацию цикла событий с учётом задержки
   * для сокращения влияния на FPS
   */
  void
  run(const float frame_time);

  /**
   * Возвращает указатель на экземпляр цикла
   */
  uv_loop_t*
  get_loop();

  /**
   * Возвращает сырое время прошедшее с момента загрузки кабины
   *
   * Время имеет некоторую погрешность из-за того, что считается не на каждом
   * кадре.
   */
  float
  cabin_time_raw();

  /**
   * Возвращает округлённое время в секундах прошедшее с момента загрузки кабины
   */
  unsigned long
  cabin_time();

  void
  setInterval();

  //void
  //clearInterval();
};
