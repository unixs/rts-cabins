
#pragma once
#include <cstddef>

using namespace std;

/**
 * # Кабина
 */
namespace cabin {
  
  /**
   * ## Интерфейс состояния кабины
   * Через методы этого класса получаем доступ к `eng->var`
   */
  class State {
  private:
    const size_t baseOffset = 0;
    const size_t pointerOffset = 10;
    const size_t innerOffset = 5;
    const size_t varOffset = baseOffset + pointerOffset + innerOffset;
    float *var = nullptr;

  public:
    /**
     * ### Суммарный размер стейта с учётом всех смещений и кол-ва ячеек
     */
    const size_t size = varOffset + 4;

    State() {
    }

    /**
     * ### Устанавливает указатель на оригинальный массив стэйта
     */
    inline void
    setVar(float *engVar) {
      var = engVar + varOffset;
    }

    // Определение доступа к элементам состояния
    

    /**
     * ### get: Таймер запуска дизеля
     */
    inline float
    get_dizel_start_time() {
      return (float) var[varOffset + 0];
    }
    
    /**
     * ### set: Таймер запуска дизеля
     */
    inline void
    set_dizel_start_time(float val) {
      var[varOffset + 0] = val;
    }
    

    /**
     * ### get: Таймер прокачки масла
     */
    inline int
    get_dizel_oil_time() {
      return (int) var[varOffset + 1];
    }
    
    /**
     * ### set: Таймер прокачки масла
     */
    inline void
    set_dizel_oil_time(int val) {
      var[varOffset + 1] = val;
    }
    

    /**
     * ### get: Мощность
     */
    inline bool
    get_power() {
      return (bool) var[varOffset + 2];
    }
    
    /**
     * ### set: Мощность
     */
    inline void
    set_power(bool val) {
      var[varOffset + 2] = val;
    }
    

    /**
     * ### get: Какой-то внутренний счётчик не раскрываемый для клиента
     */
    inline bool
    get_priv_counter() {
      return (bool) var[varOffset + 3];
    }
    
    /**
     * ### set: Какой-то внутренний счётчик не раскрываемый для клиента
     */
    inline void
    set_priv_counter(bool val) {
      var[varOffset + 3] = val;
    }
    
  };
  
    /**
     * ## Таймеры
     */
    namespace timers {
    
    };
  
}
  