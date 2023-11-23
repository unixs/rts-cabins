
/**
  # Интерфейс 3D модели
 **/
namespace model {

  
  /**
  ## Переключатели.
  **/
  enum class sw : unsigned short {
    
    /**
    ### Тяга
    Type: Мультипереключатель
    Name: C_MAIN
    Flags: CONTROLLERY
    **/
    C_MAIN_0 = 0,

    /**
    ### Реверс
    Type: Мультипереключатель
    Name: C_REV
    Flags: KEY, CONTROLLERY
    **/
    C_REV_1 = 1,

    /**
    ### Тормоз локомотива
    Type: Мультипереключатель
    Name: C254
    Flags: CONTROLLERY, CHECKDISTANCEONPRESS
    **/
    C254_2 = 2,

    /**
    ### Тормоз локомотива
    Type: Мультипереключатель
    Name: C396
    Flags: CONTROLLERY, CHECKDISTANCEONPRESS
    **/
    C396_3 = 3,

    /**
    ### Тормоз поезда
    Type: Мультипереключатель
    Name: C395
    Flags: CONTROLLERY
    **/
    C395_4 = 4,

    /**
    ### Ручной тормоз
    Type: Выключатель/тумблер
    Name: C_HANDBR
    Flags: CONTROLLERX, PRECISE
    **/
    C_HANDBR_5 = 5,

    /**
    ### Свисток
    Type: Кнопка
    Name: SW_SVIST
    Flags: NONFIXED
    **/
    SW_SVIST_6 = 6,

    /**
    ### Тифон
    Type: Кнопка
    Name: SW_TIFON
    Flags: NONFIXED
    **/
    SW_TIFON_7 = 7,

    /**
    ### Песок
    Type: Выключатель/тумблер
    Name: SW_SAND
    Flags: 
    **/
    SW_SAND_8 = 8,

    /**
    ### Радиостанция
    Type: Выключатель/тумблер
    Name: SW_RADIO
    Flags: 
    **/
    SW_RADIO_9 = 9,

    /**
    ### Освещение тележек и капота
    Type: Выключатель/тумблер
    Name: SW_VTK
    Flags: 
    **/
    SW_VTK_10 = 10,

    /**
    ### Освещение номера тепловоза
    Type: Выключатель/тумблер
    Name: SW_VN
    Flags: 
    **/
    SW_VN_11 = 11,

    /**
    ### Освещение расписания
    Type: Выключатель/тумблер
    Name: SW_VRD
    Flags: 
    **/
    SW_VRD_12 = 12,

    /**
    ### Передний левый буферный фонарь
    Type: Мультипереключатель
    Name: SW_VBLP
    Flags: CONTROLLERX
    **/
    SW_VBLP_13 = 13,

    /**
    ### Передний правый буферный фонарь
    Type: Мультипереключатель
    Name: SW_VBFP
    Flags: CONTROLLERX
    **/
    SW_VBFP_14 = 14,

    /**
    ### Передний прожектор: тускло
    Type: Выключатель/тумблер
    Name: SW_PR1
    Flags: 
    **/
    SW_PR1_15 = 15,

    /**
    ### Передний прожектор: ярко
    Type: Выключатель/тумблер
    Name: SW_PR2
    Flags: 
    **/
    SW_PR2_16 = 16,

    /**
    ### Пуск дизеля
    Type: Кнопка
    Name: SW_START
    Flags: NONFIXED
    **/
    SW_START_17 = 17,

    /**
    ### Вентилятор кабины машиниста
    Type: Выключатель/тумблер
    Name: SW_VMVO
    Flags: 
    **/
    SW_VMVO_18 = 18,

    /**
    ### Калорифер
    Type: Мультипереключатель
    Name: SW_VOK
    Flags: 
    **/
    SW_VOK_19 = 19,

    /**
    ### Освещение приборов
    Type: Мультипереключатель
    Name: SW_PVIP
    Flags: CONTROLLERX
    **/
    SW_PVIP_20 = 20,

    /**
    ### Освещение кабины
    Type: Выключатель/тумблер
    Name: SW_VK
    Flags: 
    **/
    SW_VK_21 = 21,

    /**
    ### Задний левый буферный фонарь
    Type: Мультипереключатель
    Name: SW_VBLZ
    Flags: CONTROLLERX
    **/
    SW_VBLZ_22 = 22,

    /**
    ### Задний правый буферный фонарь
    Type: Мультипереключатель
    Name: SW_VBFZ
    Flags: CONTROLLERX
    **/
    SW_VBFZ_23 = 23,

    /**
    ### Задний прожектор: тускло
    Type: Выключатель/тумблер
    Name: SW_PR3
    Flags: 
    **/
    SW_PR3_24 = 24,

    /**
    ### Задний прожектор: ярко
    Type: Выключатель/тумблер
    Name: SW_PR4
    Flags: 
    **/
    SW_PR4_25 = 25,

    /**
    ### Остановка дизеля
    Type: Выключатель/тумблер
    Name: SW_STOP
    Flags: CONTROLLERX
    **/
    SW_STOP_26 = 26,

    /**
    ### Обслуживание одним лицом
    Type: Выключатель/тумблер
    Name: SW_OOL
    Flags: 
    **/
    SW_OOL_27 = 27,

    /**
    ### Проверка АЛСН
    Type: Выключатель/тумблер
    Name: SW_TESTLS
    Flags: 
    **/
    SW_TESTLS_28 = 28,

    /**
    ### КНАС2
    Type: Выключатель/тумблер
    Name: SW_KNAS2
    Flags: 
    **/
    SW_KNAS2_29 = 29,

    /**
    ### КНАС1
    Type: Выключатель/тумблер
    Name: SW_KNAS1
    Flags: 
    **/
    SW_KNAS1_30 = 30,

    /**
    ### Проверка звукового сигнала
    Type: Выключатель/тумблер
    Name: SW_KNZS
    Flags: 
    **/
    SW_KNZS_31 = 31,

    /**
    ### Выключатель АЛСН
    Type: Выключатель/тумблер
    Name: SW_ALSN
    Flags: 
    **/
    SW_ALSN_32 = 32,

    /**
    ### РБ
    Type: Кнопка
    Name: SW_RB
    Flags: NONFIXED
    **/
    SW_RB_33 = 33,

    /**
    ### UNNAMED
    Type: Выключатель/тумблер
    Name: SW_A1
    Flags: 
    **/
    SW_A1_34 = 34,

    /**
    ### UNNAMED
    Type: Выключатель/тумблер
    Name: SW_A2
    Flags: 
    **/
    SW_A2_35 = 35,

    /**
    ### UNNAMED
    Type: Выключатель/тумблер
    Name: SW_A3
    Flags: 
    **/
    SW_A3_36 = 36,

    /**
    ### КНАС2
    Type: Кнопка
    Name: SW_KNAS2b
    Flags: NONFIXED
    **/
    SW_KNAS2b_37 = 37,

    /**
    ### КНАС1
    Type: Кнопка
    Name: SW_KNAS1b
    Flags: NONFIXED
    **/
    SW_KNAS1b_38 = 38,

    /**
    ### Тяга больше/меньше
    Type: Кнопка
    Name: SW_P_THR
    Flags: NONFIXED, CONTROLLERY
    **/
    SW_P_THR_39 = 39,

    /**
    ### Торможение/отпуск
    Type: Кнопка
    Name: SW_P_BR
    Flags: NONFIXED, CONTROLLERY
    **/
    SW_P_BR_40 = 40,

    /**
    ### Реверс вперёд/назад
    Type: Мультипереключатель
    Name: SW_P_REV
    Flags: CONTROLLERY
    **/
    SW_P_REV_41 = 41,

    /**
    ### Автоматический сброс
    Type: Кнопка
    Name: SW_P_SBR
    Flags: NONFIXED
    **/
    SW_P_SBR_42 = 42,

    /**
    ### Стоп
    Type: Выключатель/тумблер
    Name: SW_P_STOP
    Flags: 
    **/
    SW_P_STOP_43 = 43,

    /**
    ### Песок
    Type: Выключатель/тумблер
    Name: SW_P_SAND
    Flags: 
    **/
    SW_P_SAND_44 = 44,

    /**
    ### Свисток
    Type: Кнопка
    Name: SW_P_SV
    Flags: NONFIXED
    **/
    SW_P_SV_45 = 45,

  };
  
  /**
  ## Указатели.
  **/
  enum class disp : unsigned short {
    
    /**
    ### Скорость
    Type: ARROW
    Name: `D_SKOR`
        #### Values:
        MIN: `0.0`
        MAX: `41.7`
        ZERO: `14.45`
    **/
    D_SKOR_0 = 0,

    /**
    ### Главный резервуар
    Type: ARROW
    Name: `D_GR`
        #### Values:
        MIN: `0.0`
        MAX: `15.0`
        ZERO: `5.0`
    **/
    D_GR_1 = 1,

    /**
    ### Тормозная магистраль
    Type: ARROW
    Name: `D_TM`
        #### Values:
        MIN: `0.0`
        MAX: `15.0`
        ZERO: `5.0`
    **/
    D_TM_2 = 2,

    /**
    ### Уравнительный резервуар
    Type: ARROW
    Name: `D_UR`
        #### Values:
        MIN: `0.0`
        MAX: `15.0`
        ZERO: `3.0`
    **/
    D_UR_3 = 3,

    /**
    ### Тормозной цилиндр
    Type: ARROW
    Name: `D_BC`
        #### Values:
        MIN: `0.0`
        MAX: `15.0`
        ZERO: `1.8`
    **/
    D_BC_4 = 4,

    /**
    ### Ток нагрузки ГГ
    Type: ARROW
    Name: `D_GG`
        #### Values:
        MIN: `0.0`
        MAX: `4.0`
        ZERO: `4.0`
    **/
    D_GG_5 = 5,

    /**
    ### Обороты дизеля
    Type: ARROW
    Name: `D_RPM`
        #### Values:
        MIN: `0.0`
        MAX: `800.0`
        ZERO: `800.0`
    **/
    D_RPM_6 = 6,

    /**
    ### Тормозной цилиндр
    Type: ARROW
    Name: `D_BCb`
        #### Values:
        MIN: `0.0`
        MAX: `15.0`
        ZERO: `1.8`
    **/
    D_BCb_7 = 7,

    /**
    ### Ток нагрузки ГГ
    Type: ARROW
    Name: `D_GGb`
        #### Values:
        MIN: `0.0`
        MAX: `4.0`
        ZERO: `4.0`
    **/
    D_GGb_8 = 8,

    /**
    ### Давление масла
    Type: ARROW
    Name: `D_POIL`
        #### Values:
        MIN: `0.0`
        MAX: `15.0`
        ZERO: `5.0`
    **/
    D_POIL_9 = 9,

    /**
    ### Давление топлива
    Type: ARROW
    Name: `D_PFUEL`
        #### Values:
        MIN: `0.0`
        MAX: `15.0`
        ZERO: `5.0`
    **/
    D_PFUEL_10 = 10,

    /**
    ### Температура воды
    Type: ARROW
    Name: `D_TWAT`
        #### Values:
        MIN: `0.0`
        MAX: `120.0`
        ZERO: `60.0`
    **/
    D_TWAT_11 = 11,

    /**
    ### ПСС
    Type: LAMP
    Name: `L_EPK`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    L_EPK_12 = 12,

    /**
    ### Пожар
    Type: LAMP
    Name: `L_FIRE`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    L_FIRE_13 = 13,

    /**
    ### Неисправность первого дизеля
    Type: LAMP
    Name: `L_DS1`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    L_DS1_14 = 14,

    /**
    ### Неисправность второго дизеля
    Type: LAMP
    Name: `L_DS2`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    L_DS2_15 = 15,

    /**
    ### Боксование
    Type: LAMP
    Name: `L_WS`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    L_WS_16 = 16,

    /**
    ### UNNAMED
    Type: LAMP
    Name: `L_LAMP1`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    L_LAMP1_17 = 17,

    /**
    ### UNNAMED
    Type: LAMP
    Name: `L_LAMP2`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    L_LAMP2_18 = 18,

    /**
    ### Скорость
    Type: ARROW
    Name: `D_SKOR1`
        #### Values:
        MIN: `0.0`
        MAX: `41.7`
        ZERO: `14.45`
    **/
    D_SKOR1_19 = 19,

  };
  
  /**
  ## Состояния приборов
  **/
  namespace st {
    
    /**
    #### Состояния переключателя
    ### Тяга
    Name: `C_MAIN`
    Default: `0`
    States:
    - `0` - [0]
    - `1` - [1]
    - `2` - [2]
    - `3` - [3]
    - `4` - [4]
    - `5` - [5]
    - `6` - [6]
    - `7` - [7]
    - `8` - [8]
    **/
    enum class C_MAIN : unsigned short {
      /**
      #### Тяга
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Тяга
      ### [0]
      **/
      ST_0 = 0,

      /**
      #### Тяга
      ### [1]
      **/
      ST_1 = 1,

      /**
      #### Тяга
      ### [2]
      **/
      ST_2 = 2,

      /**
      #### Тяга
      ### [3]
      **/
      ST_3 = 3,

      /**
      #### Тяга
      ### [4]
      **/
      ST_4 = 4,

      /**
      #### Тяга
      ### [5]
      **/
      ST_5 = 5,

      /**
      #### Тяга
      ### [6]
      **/
      ST_6 = 6,

      /**
      #### Тяга
      ### [7]
      **/
      ST_7 = 7,

      /**
      #### Тяга
      ### [8]
      **/
      ST_8 = 8,
    };
  
    /**
    #### Состояния переключателя
    ### Реверс
    Name: `C_REV`
    Default: `1`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    - `2` - UNNAMED
    **/
    enum class C_REV : unsigned short {
      /**
      #### Реверс
      ### Исходное состояние
      **/
      DEFAULT = 1,

      /**
      #### Реверс
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Реверс
      ### UNNAMED
      **/
      ST_1 = 1,

      /**
      #### Реверс
      ### UNNAMED
      **/
      ST_2 = 2,
    };
  
    /**
    #### Состояния переключателя
    ### Тормоз локомотива
    Name: `C254`
    Default: `1`
    States:
    - `0` - [отпуск]
    - `1` - [отпуск]
    - `2` - [1]
    - `3` - [2]
    - `4` - [3]
    - `5` - [4]
    **/
    enum class C254 : unsigned short {
      /**
      #### Тормоз локомотива
      ### Исходное состояние
      **/
      DEFAULT = 1,

      /**
      #### Тормоз локомотива
      ### [отпуск]
      **/
      ST_0 = 0,

      /**
      #### Тормоз локомотива
      ### [отпуск]
      **/
      ST_1 = 1,

      /**
      #### Тормоз локомотива
      ### [1]
      **/
      ST_2 = 2,

      /**
      #### Тормоз локомотива
      ### [2]
      **/
      ST_3 = 3,

      /**
      #### Тормоз локомотива
      ### [3]
      **/
      ST_4 = 4,

      /**
      #### Тормоз локомотива
      ### [4]
      **/
      ST_5 = 5,
    };
  
    /**
    #### Состояния переключателя
    ### Тормоз локомотива
    Name: `C396`
    Default: `1`
    States:
    - `0` - [отпуск]
    - `1` - [отпуск]
    - `2` - [1]
    - `3` - [2]
    - `4` - [3]
    - `5` - [4]
    **/
    enum class C396 : unsigned short {
      /**
      #### Тормоз локомотива
      ### Исходное состояние
      **/
      DEFAULT = 1,

      /**
      #### Тормоз локомотива
      ### [отпуск]
      **/
      ST_0 = 0,

      /**
      #### Тормоз локомотива
      ### [отпуск]
      **/
      ST_1 = 1,

      /**
      #### Тормоз локомотива
      ### [1]
      **/
      ST_2 = 2,

      /**
      #### Тормоз локомотива
      ### [2]
      **/
      ST_3 = 3,

      /**
      #### Тормоз локомотива
      ### [3]
      **/
      ST_4 = 4,

      /**
      #### Тормоз локомотива
      ### [4]
      **/
      ST_5 = 5,
    };
  
    /**
    #### Состояния переключателя
    ### Тормоз поезда
    Name: `C395`
    Default: `1`
    States:
    - `0` - [Отпуск]
    - `1` - [Поездное]
    - `2` - [Перекрыша без питания]
    - `3` - [Перекрыша]
    - `4` - [Торможение]
    - `5` - [Экстренное]
    **/
    enum class C395 : unsigned short {
      /**
      #### Тормоз поезда
      ### Исходное состояние
      **/
      DEFAULT = 1,

      /**
      #### Тормоз поезда
      ### [Отпуск]
      **/
      ST_0 = 0,

      /**
      #### Тормоз поезда
      ### [Поездное]
      **/
      ST_1 = 1,

      /**
      #### Тормоз поезда
      ### [Перекрыша без питания]
      **/
      ST_2 = 2,

      /**
      #### Тормоз поезда
      ### [Перекрыша]
      **/
      ST_3 = 3,

      /**
      #### Тормоз поезда
      ### [Торможение]
      **/
      ST_4 = 4,

      /**
      #### Тормоз поезда
      ### [Экстренное]
      **/
      ST_5 = 5,
    };
  
    /**
    #### Состояния переключателя
    ### Ручной тормоз
    Name: `C_HANDBR`
    Default: `1`
    States:
    - `0` - [отпущен]
    - `1` - [закручен]
    **/
    enum class C_HANDBR : unsigned short {
      /**
      #### Ручной тормоз
      ### Исходное состояние
      **/
      DEFAULT = 1,

      /**
      #### Ручной тормоз
      ### [отпущен]
      **/
      ST_0 = 0,

      /**
      #### Ручной тормоз
      ### [закручен]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Свисток
    Name: `SW_SVIST`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SW_SVIST : unsigned short {
      /**
      #### Свисток
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Свисток
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Свисток
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Тифон
    Name: `SW_TIFON`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SW_TIFON : unsigned short {
      /**
      #### Тифон
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Тифон
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Тифон
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Песок
    Name: `SW_SAND`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SW_SAND : unsigned short {
      /**
      #### Песок
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Песок
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Песок
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Радиостанция
    Name: `SW_RADIO`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SW_RADIO : unsigned short {
      /**
      #### Радиостанция
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Радиостанция
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Радиостанция
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Освещение тележек и капота
    Name: `SW_VTK`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SW_VTK : unsigned short {
      /**
      #### Освещение тележек и капота
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Освещение тележек и капота
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Освещение тележек и капота
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Освещение номера тепловоза
    Name: `SW_VN`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SW_VN : unsigned short {
      /**
      #### Освещение номера тепловоза
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Освещение номера тепловоза
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Освещение номера тепловоза
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Освещение расписания
    Name: `SW_VRD`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SW_VRD : unsigned short {
      /**
      #### Освещение расписания
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Освещение расписания
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Освещение расписания
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Передний левый буферный фонарь
    Name: `SW_VBLP`
    Default: `1`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    - `2` - UNNAMED
    **/
    enum class SW_VBLP : unsigned short {
      /**
      #### Передний левый буферный фонарь
      ### Исходное состояние
      **/
      DEFAULT = 1,

      /**
      #### Передний левый буферный фонарь
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Передний левый буферный фонарь
      ### UNNAMED
      **/
      ST_1 = 1,

      /**
      #### Передний левый буферный фонарь
      ### UNNAMED
      **/
      ST_2 = 2,
    };
  
    /**
    #### Состояния переключателя
    ### Передний правый буферный фонарь
    Name: `SW_VBFP`
    Default: `1`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    - `2` - UNNAMED
    **/
    enum class SW_VBFP : unsigned short {
      /**
      #### Передний правый буферный фонарь
      ### Исходное состояние
      **/
      DEFAULT = 1,

      /**
      #### Передний правый буферный фонарь
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Передний правый буферный фонарь
      ### UNNAMED
      **/
      ST_1 = 1,

      /**
      #### Передний правый буферный фонарь
      ### UNNAMED
      **/
      ST_2 = 2,
    };
  
    /**
    #### Состояния переключателя
    ### Передний прожектор: тускло
    Name: `SW_PR1`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SW_PR1 : unsigned short {
      /**
      #### Передний прожектор: тускло
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Передний прожектор: тускло
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Передний прожектор: тускло
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Передний прожектор: ярко
    Name: `SW_PR2`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SW_PR2 : unsigned short {
      /**
      #### Передний прожектор: ярко
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Передний прожектор: ярко
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Передний прожектор: ярко
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Пуск дизеля
    Name: `SW_START`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SW_START : unsigned short {
      /**
      #### Пуск дизеля
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Пуск дизеля
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Пуск дизеля
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Вентилятор кабины машиниста
    Name: `SW_VMVO`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SW_VMVO : unsigned short {
      /**
      #### Вентилятор кабины машиниста
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Вентилятор кабины машиниста
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Вентилятор кабины машиниста
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Калорифер
    Name: `SW_VOK`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    - `2` - UNNAMED
    **/
    enum class SW_VOK : unsigned short {
      /**
      #### Калорифер
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Калорифер
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Калорифер
      ### UNNAMED
      **/
      ST_1 = 1,

      /**
      #### Калорифер
      ### UNNAMED
      **/
      ST_2 = 2,
    };
  
    /**
    #### Состояния переключателя
    ### Освещение приборов
    Name: `SW_PVIP`
    Default: `1`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    - `2` - UNNAMED
    **/
    enum class SW_PVIP : unsigned short {
      /**
      #### Освещение приборов
      ### Исходное состояние
      **/
      DEFAULT = 1,

      /**
      #### Освещение приборов
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Освещение приборов
      ### UNNAMED
      **/
      ST_1 = 1,

      /**
      #### Освещение приборов
      ### UNNAMED
      **/
      ST_2 = 2,
    };
  
    /**
    #### Состояния переключателя
    ### Освещение кабины
    Name: `SW_VK`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SW_VK : unsigned short {
      /**
      #### Освещение кабины
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Освещение кабины
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Освещение кабины
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Задний левый буферный фонарь
    Name: `SW_VBLZ`
    Default: `1`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    - `2` - UNNAMED
    **/
    enum class SW_VBLZ : unsigned short {
      /**
      #### Задний левый буферный фонарь
      ### Исходное состояние
      **/
      DEFAULT = 1,

      /**
      #### Задний левый буферный фонарь
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Задний левый буферный фонарь
      ### UNNAMED
      **/
      ST_1 = 1,

      /**
      #### Задний левый буферный фонарь
      ### UNNAMED
      **/
      ST_2 = 2,
    };
  
    /**
    #### Состояния переключателя
    ### Задний правый буферный фонарь
    Name: `SW_VBFZ`
    Default: `1`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    - `2` - UNNAMED
    **/
    enum class SW_VBFZ : unsigned short {
      /**
      #### Задний правый буферный фонарь
      ### Исходное состояние
      **/
      DEFAULT = 1,

      /**
      #### Задний правый буферный фонарь
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Задний правый буферный фонарь
      ### UNNAMED
      **/
      ST_1 = 1,

      /**
      #### Задний правый буферный фонарь
      ### UNNAMED
      **/
      ST_2 = 2,
    };
  
    /**
    #### Состояния переключателя
    ### Задний прожектор: тускло
    Name: `SW_PR3`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SW_PR3 : unsigned short {
      /**
      #### Задний прожектор: тускло
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Задний прожектор: тускло
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Задний прожектор: тускло
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Задний прожектор: ярко
    Name: `SW_PR4`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SW_PR4 : unsigned short {
      /**
      #### Задний прожектор: ярко
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Задний прожектор: ярко
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Задний прожектор: ярко
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Остановка дизеля
    Name: `SW_STOP`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SW_STOP : unsigned short {
      /**
      #### Остановка дизеля
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Остановка дизеля
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Остановка дизеля
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Обслуживание одним лицом
    Name: `SW_OOL`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SW_OOL : unsigned short {
      /**
      #### Обслуживание одним лицом
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Обслуживание одним лицом
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Обслуживание одним лицом
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Проверка АЛСН
    Name: `SW_TESTLS`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SW_TESTLS : unsigned short {
      /**
      #### Проверка АЛСН
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Проверка АЛСН
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Проверка АЛСН
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### КНАС2
    Name: `SW_KNAS2`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SW_KNAS2 : unsigned short {
      /**
      #### КНАС2
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### КНАС2
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### КНАС2
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### КНАС1
    Name: `SW_KNAS1`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SW_KNAS1 : unsigned short {
      /**
      #### КНАС1
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### КНАС1
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### КНАС1
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Проверка звукового сигнала
    Name: `SW_KNZS`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SW_KNZS : unsigned short {
      /**
      #### Проверка звукового сигнала
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Проверка звукового сигнала
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Проверка звукового сигнала
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Выключатель АЛСН
    Name: `SW_ALSN`
    Default: `1`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SW_ALSN : unsigned short {
      /**
      #### Выключатель АЛСН
      ### Исходное состояние
      **/
      DEFAULT = 1,

      /**
      #### Выключатель АЛСН
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Выключатель АЛСН
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### РБ
    Name: `SW_RB`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SW_RB : unsigned short {
      /**
      #### РБ
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### РБ
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### РБ
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### UNNAMED
    Name: `SW_A1`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SW_A1 : unsigned short {
      /**
      #### UNNAMED
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### UNNAMED
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### UNNAMED
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### UNNAMED
    Name: `SW_A2`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SW_A2 : unsigned short {
      /**
      #### UNNAMED
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### UNNAMED
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### UNNAMED
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### UNNAMED
    Name: `SW_A3`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SW_A3 : unsigned short {
      /**
      #### UNNAMED
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### UNNAMED
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### UNNAMED
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### КНАС2
    Name: `SW_KNAS2b`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SW_KNAS2b : unsigned short {
      /**
      #### КНАС2
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### КНАС2
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### КНАС2
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### КНАС1
    Name: `SW_KNAS1b`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SW_KNAS1b : unsigned short {
      /**
      #### КНАС1
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### КНАС1
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### КНАС1
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Тяга больше/меньше
    Name: `SW_P_THR`
    Default: `1`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    - `2` - UNNAMED
    **/
    enum class SW_P_THR : unsigned short {
      /**
      #### Тяга больше/меньше
      ### Исходное состояние
      **/
      DEFAULT = 1,

      /**
      #### Тяга больше/меньше
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Тяга больше/меньше
      ### UNNAMED
      **/
      ST_1 = 1,

      /**
      #### Тяга больше/меньше
      ### UNNAMED
      **/
      ST_2 = 2,
    };
  
    /**
    #### Состояния переключателя
    ### Торможение/отпуск
    Name: `SW_P_BR`
    Default: `1`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    - `2` - UNNAMED
    **/
    enum class SW_P_BR : unsigned short {
      /**
      #### Торможение/отпуск
      ### Исходное состояние
      **/
      DEFAULT = 1,

      /**
      #### Торможение/отпуск
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Торможение/отпуск
      ### UNNAMED
      **/
      ST_1 = 1,

      /**
      #### Торможение/отпуск
      ### UNNAMED
      **/
      ST_2 = 2,
    };
  
    /**
    #### Состояния переключателя
    ### Реверс вперёд/назад
    Name: `SW_P_REV`
    Default: `1`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    - `2` - UNNAMED
    **/
    enum class SW_P_REV : unsigned short {
      /**
      #### Реверс вперёд/назад
      ### Исходное состояние
      **/
      DEFAULT = 1,

      /**
      #### Реверс вперёд/назад
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Реверс вперёд/назад
      ### UNNAMED
      **/
      ST_1 = 1,

      /**
      #### Реверс вперёд/назад
      ### UNNAMED
      **/
      ST_2 = 2,
    };
  
    /**
    #### Состояния переключателя
    ### Автоматический сброс
    Name: `SW_P_SBR`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SW_P_SBR : unsigned short {
      /**
      #### Автоматический сброс
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Автоматический сброс
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Автоматический сброс
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Стоп
    Name: `SW_P_STOP`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SW_P_STOP : unsigned short {
      /**
      #### Стоп
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Стоп
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Стоп
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Песок
    Name: `SW_P_SAND`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SW_P_SAND : unsigned short {
      /**
      #### Песок
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Песок
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Песок
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Свисток
    Name: `SW_P_SV`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SW_P_SV : unsigned short {
      /**
      #### Свисток
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Свисток
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Свисток
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
  };
  



  /**
    ## Источники света
   **/
  enum class lights : unsigned short {
    
    /**
    #### Источник света
    ### UNNAMED
    **/
    _0 = 0,

    /**
    #### Источник света
    ### UNNAMED
    **/
    _1 = 1,

  };

  /**
    ## Анимации
   **/
  enum class anims : unsigned short {
  
    /**
    #### Анимация
    ### WIPER1
    **/
    WIPER1_0 = 0,

    /**
    #### Анимация
    ### WIPER2
    **/
    WIPER2_1 = 1,

    /**
    #### Анимация
    ### WIPER3
    **/
    WIPER3_2 = 2,

    /**
    #### Анимация
    ### WIPER4
    **/
    WIPER4_3 = 3,

  };
};

  