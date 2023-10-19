
/**
  # Интерфейс 3D модели
 **/
namespace model {

  
  /**
  ## Переключатели.
  **/
  enum class sw : unsigned short {
    
    /**
    ### Тормоз поезда
    Type: Мультипереключатель
    Name: R3951
    Flags: CONTROLLERY, CHECKDISTANCEONPRESS
    **/
    R3951_0 = 0,

    /**
    ### Тормоз локомотива
    Type: Мультипереключатель
    Name: R2541
    Flags: CONTROLLERY, CHECKDISTANCEONPRESS
    **/
    R2541_1 = 1,

    /**
    ### Реверс
    Type: Мультипереключатель
    Name: REV1
    Flags: CONTROLLERY, CHECKDISTANCEONPRESS, KEY
    **/
    REV1_2 = 2,

    /**
    ### Контроллер
    Type: Мультипереключатель
    Name: KONT1
    Flags: CONTROLLERX, CHECKDISTANCEONPRESS
    **/
    KONT1_3 = 3,

    /**
    ### Задатчик тормозного усилия ЭДТ
    Type: Мультипереключатель
    Name: ZAD1
    Flags: CONTROLLERX, CHECKDISTANCEONPRESS
    **/
    ZAD1_4 = 4,

    /**
    ### Блокировка тормозов усл. 367
    Type: Выключатель/тумблер
    Name: R3671
    Flags: CHECKDISTANCEONPRESS, KEY
    **/
    R3671_6 = 6,

    /**
    ### Редуктор зарядного давления
    Type: Мультипереключатель
    Name: RED1
    Flags: CHECKDISTANCEONPRESS, CONTROLLERX
    **/
    RED1_7 = 7,

    /**
    ### Ключ ЭПК
    Type: Выключатель/тумблер
    Name: EPK1
    Flags: CHECKDISTANCEONPRESS
    **/
    EPK1_8 = 8,

    /**
    ### Прожектор яркий
    Type: Выключатель/тумблер
    Name: AZV11
    Flags: CHECKDISTANCEONPRESS
    **/
    AZV11_9 = 9,

    /**
    ### Прожектор тускло
    Type: Выключатель/тумблер
    Name: AZV21
    Flags: CHECKDISTANCEONPRESS
    **/
    AZV21_10 = 10,

    /**
    ### Питание ЭПТ
    Type: Выключатель/тумблер
    Name: AZV31
    Flags: CHECKDISTANCEONPRESS
    **/
    AZV31_11 = 11,

    /**
    ### ЭПТ
    Type: Выключатель/тумблер
    Name: AZV41
    Flags: CHECKDISTANCEONPRESS
    **/
    AZV41_12 = 12,

    /**
    ### Электрический тормоз
    Type: Выключатель/тумблер
    Name: AZV51
    Flags: CHECKDISTANCEONPRESS
    **/
    AZV51_13 = 13,

    /**
    ### Топливный насос ведомого тепловоза
    Type: Выключатель/тумблер
    Name: AZV61
    Flags: CHECKDISTANCEONPRESS
    **/
    AZV61_14 = 14,

    /**
    ### Топливный насос ведущего тепловоза
    Type: Выключатель/тумблер
    Name: AZV71
    Flags: CHECKDISTANCEONPRESS
    **/
    AZV71_15 = 15,

    /**
    ### Управление тепловозом
    Type: Выключатель/тумблер
    Name: AZV81
    Flags: CHECKDISTANCEONPRESS
    **/
    AZV81_16 = 16,

    /**
    ### Управление общее
    Type: Выключатель/тумблер
    Name: AZV91
    Flags: CHECKDISTANCEONPRESS
    **/
    AZV91_17 = 17,

    /**
    ### Освещение пульта
    Type: Выключатель/тумблер
    Name: AZV101
    Flags: CHECKDISTANCEONPRESS
    **/
    AZV101_18 = 18,

    /**
    ### Освещение кабины
    Type: Выключатель/тумблер
    Name: AZV111
    Flags: CHECKDISTANCEONPRESS
    **/
    AZV111_19 = 19,

    /**
    ### Вентиляция
    Type: Выключатель/тумблер
    Name: AZV121
    Flags: CHECKDISTANCEONPRESS
    **/
    AZV121_20 = 20,

    /**
    ### Жалюзи масло
    Type: Выключатель/тумблер
    Name: TB11
    Flags: CHECKDISTANCEONPRESS
    **/
    TB11_21 = 21,

    /**
    ### Жалюзи вода
    Type: Выключатель/тумблер
    Name: TB21
    Flags: CHECKDISTANCEONPRESS
    **/
    TB21_22 = 22,

    /**
    ### ОП II ступень
    Type: Выключатель/тумблер
    Name: TB31
    Flags: CHECKDISTANCEONPRESS
    **/
    TB31_23 = 23,

    /**
    ### ОП I ступень
    Type: Выключатель/тумблер
    Name: TB41
    Flags: CHECKDISTANCEONPRESS
    **/
    TB41_24 = 24,

    /**
    ### Освещение приборов
    Type: Выключатель/тумблер
    Name: TB51
    Flags: CHECKDISTANCEONPRESS
    **/
    TB51_25 = 25,

    /**
    ### Освещение кабины
    Type: Выключатель/тумблер
    Name: TB61
    Flags: CHECKDISTANCEONPRESS
    **/
    TB61_26 = 26,

    /**
    ### Освещение расписания
    Type: Выключатель/тумблер
    Name: TB71
    Flags: CHECKDISTANCEONPRESS
    **/
    TB71_27 = 27,

    /**
    ### Электрикалорифер
    Type: Выключатель/тумблер
    Name: TB81
    Flags: CHECKDISTANCEONPRESS
    **/
    TB81_28 = 28,

    /**
    ### Радиостанция
    Type: Выключатель/тумблер
    Name: TB101
    Flags: CHECKDISTANCEONPRESS
    **/
    TB101_29 = 29,

    /**
    ### Манометры и термометры
    Type: Выключатель/тумблер
    Name: TB111
    Flags: CHECKDISTANCEONPRESS
    **/
    TB111_30 = 30,

    /**
    ### АЛСН
    Type: Выключатель/тумблер
    Name: TB121
    Flags: CHECKDISTANCEONPRESS
    **/
    TB121_31 = 31,

    /**
    ### Частота АСЛН
    Type: Выключатель/тумблер
    Name: TB131
    Flags: CHECKDISTANCEONPRESS
    **/
    TB131_32 = 32,

    /**
    ### Омыв окон
    Type: Выключатель/тумблер
    Name: TB141
    Flags: CHECKDISTANCEONPRESS
    **/
    TB141_33 = 33,

    /**
    ### Стеклоочиститель
    Type: Выключатель/тумблер
    Name: TB151
    Flags: CHECKDISTANCEONPRESS
    **/
    TB151_34 = 34,

    /**
    ### Вызов помощника
    Type: Кнопка
    Name: BTN41
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    BTN41_35 = 35,

    /**
    ### Отпуск тормозов локомотива
    Type: Кнопка
    Name: BTN51
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    BTN51_36 = 36,

    /**
    ### Свисток
    Type: Кнопка
    Name: BTN11
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    BTN11_37 = 37,

    /**
    ### Тифон
    Type: Кнопка
    Name: BTN21
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    BTN21_38 = 38,

    /**
    ### Песок
    Type: Кнопка
    Name: BTN31
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    BTN31_39 = 39,

    /**
    ### Рукоятка бдительности
    Type: Кнопка
    Name: RB1
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    RB1_40 = 40,

    /**
    ### Пуск дизеля ведущего тепловоза
    Type: Кнопка
    Name: BTN81
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    BTN81_41 = 41,

    /**
    ### Пуск дизеля ведомого тепловоза
    Type: Кнопка
    Name: BTN71
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    BTN71_42 = 42,

    /**
    ### Проверка ЭТ
    Type: Кнопка
    Name: BTN91
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    BTN91_43 = 43,

    /**
    ### ВК
    Type: Кнопка
    Name: BTN101
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    BTN101_44 = 44,

    /**
    ### Проверка АЛСН
    Type: Кнопка
    Name: BTN111
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    BTN111_45 = 45,

    /**
    ### Левый БФ
    Type: Мультипереключатель
    Name: TBP71
    Flags: CHECKDISTANCEONPRESS, CONTROLLERY
    **/
    TBP71_46 = 46,

    /**
    ### Правый БФ
    Type: Мультипереключатель
    Name: TBP61
    Flags: CHECKDISTANCEONPRESS, CONTROLLERY
    **/
    TBP61_47 = 47,

    /**
    ### Номерные знаки
    Type: Выключатель/тумблер
    Name: TBP51
    Flags: CHECKDISTANCEONPRESS
    **/
    TBP51_48 = 48,

    /**
    ### Освещение пульта
    Type: Выключатель/тумблер
    Name: TBP41
    Flags: CHECKDISTANCEONPRESS
    **/
    TBP41_49 = 49,

    /**
    ### Освещение резервное
    Type: Выключатель/тумблер
    Name: TBP31
    Flags: CHECKDISTANCEONPRESS
    **/
    TBP31_50 = 50,

    /**
    ### Калориферы
    Type: Выключатель/тумблер
    Name: TBP21
    Flags: CHECKDISTANCEONPRESS
    **/
    TBP21_51 = 51,

    /**
    ### Вентиляторы
    Type: Выключатель/тумблер
    Name: TBP11
    Flags: CHECKDISTANCEONPRESS
    **/
    TBP11_52 = 52,

    /**
    ### Вольтметр
    Type: Выключатель/тумблер
    Name: TBP81
    Flags: CHECKDISTANCEONPRESS
    **/
    TBP81_53 = 53,

    /**
    ### Тифон
    Type: Кнопка
    Name: BTNP21
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    BTNP21_54 = 54,

    /**
    ### Свисток
    Type: Кнопка
    Name: BTNP11
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    BTNP11_55 = 55,

    /**
    ### Комбинированный кран усл. 103
    Type: Мультипереключатель
    Name: KK1
    Flags: CONTROLLERX
    **/
    KK1_56 = 56,

    /**
    ### Маневры
    Type: Кнопка
    Name: BTN121
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    BTN121_57 = 57,

    /**
    ### Свисток
    Type: Кнопка
    Name: BTN131
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    BTN131_58 = 58,

    /**
    ### РБС
    Type: Кнопка
    Name: RBS1
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    RBS1_59 = 59,

    /**
    ### РБП
    Type: Кнопка
    Name: RBP1
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    RBP1_60 = 60,

    /**
    ### Вызов ДСП
    Type: Кнопка
    Name: DSP1
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    DSP1_61 = 61,

    /**
    ### Вызов ДНЦ
    Type: Кнопка
    Name: DNC1
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    DNC1_62 = 62,

    /**
    ### Подсветка
    Type: Кнопка
    Name: PODSV1
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    PODSV1_63 = 63,

    /**
    ### Питание радиостанции
    Type: Кнопка
    Name: PIT1
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    PIT1_64 = 64,

    /**
    ### Ручной тормоз
    Type: Мультипереключатель
    Name: RT1
    Flags: CHECKDISTANCEONPRESS, CONTROLLERX, PRECISE
    **/
    RT1_65 = 65,

    /**
    ### Завод часов
    Type: Выключатель/тумблер
    Name: SLZAVOD1
    Flags: CHECKDISTANCEONPRESS
    **/
    SLZAVOD1_66 = 66,

    /**
    ### Тормоз поезда
    Type: Мультипереключатель
    Name: R395
    Flags: CONTROLLERY, CHECKDISTANCEONPRESS
    **/
    R395_100 = 100,

    /**
    ### Тормоз локомотива
    Type: Мультипереключатель
    Name: R254
    Flags: CONTROLLERY, CHECKDISTANCEONPRESS
    **/
    R254_101 = 101,

    /**
    ### Реверс
    Type: Мультипереключатель
    Name: REV
    Flags: CONTROLLERY, CHECKDISTANCEONPRESS, KEY
    **/
    REV_102 = 102,

    /**
    ### Контроллер
    Type: Мультипереключатель
    Name: KONT
    Flags: CONTROLLERX, CHECKDISTANCEONPRESS
    **/
    KONT_103 = 103,

    /**
    ### Задатчик тормозного усилия ЭДТ
    Type: Мультипереключатель
    Name: ZAD
    Flags: CONTROLLERX, CHECKDISTANCEONPRESS
    **/
    ZAD_104 = 104,

    /**
    ### Блокировка тормозов усл. 367
    Type: Выключатель/тумблер
    Name: R367
    Flags: CHECKDISTANCEONPRESS, KEY
    **/
    R367_106 = 106,

    /**
    ### Редуктор зарядного давления
    Type: Мультипереключатель
    Name: RED
    Flags: CHECKDISTANCEONPRESS, CONTROLLERX
    **/
    RED_107 = 107,

    /**
    ### Ключ ЭПК
    Type: Выключатель/тумблер
    Name: EPK
    Flags: CHECKDISTANCEONPRESS
    **/
    EPK_108 = 108,

    /**
    ### Прожектор яркий
    Type: Выключатель/тумблер
    Name: AZV1
    Flags: CHECKDISTANCEONPRESS
    **/
    AZV1_109 = 109,

    /**
    ### Прожектор тускло
    Type: Выключатель/тумблер
    Name: AZV2
    Flags: CHECKDISTANCEONPRESS
    **/
    AZV2_110 = 110,

    /**
    ### Питание ЭПТ
    Type: Выключатель/тумблер
    Name: AZV3
    Flags: CHECKDISTANCEONPRESS
    **/
    AZV3_111 = 111,

    /**
    ### ЭПТ
    Type: Выключатель/тумблер
    Name: AZV4
    Flags: CHECKDISTANCEONPRESS
    **/
    AZV4_112 = 112,

    /**
    ### Электрический тормоз
    Type: Выключатель/тумблер
    Name: AZV5
    Flags: CHECKDISTANCEONPRESS
    **/
    AZV5_113 = 113,

    /**
    ### Топливный насос ведомого тепловоза
    Type: Выключатель/тумблер
    Name: AZV6
    Flags: CHECKDISTANCEONPRESS
    **/
    AZV6_114 = 114,

    /**
    ### Топливный насос ведущего тепловоза
    Type: Выключатель/тумблер
    Name: AZV7
    Flags: CHECKDISTANCEONPRESS
    **/
    AZV7_115 = 115,

    /**
    ### Управление тепловозом
    Type: Выключатель/тумблер
    Name: AZV8
    Flags: CHECKDISTANCEONPRESS
    **/
    AZV8_116 = 116,

    /**
    ### Управление общее
    Type: Выключатель/тумблер
    Name: AZV9
    Flags: CHECKDISTANCEONPRESS
    **/
    AZV9_117 = 117,

    /**
    ### Освещение пульта
    Type: Выключатель/тумблер
    Name: AZV10
    Flags: CHECKDISTANCEONPRESS
    **/
    AZV10_118 = 118,

    /**
    ### Освещение кабины
    Type: Выключатель/тумблер
    Name: AZV011
    Flags: CHECKDISTANCEONPRESS
    **/
    AZV011_119 = 119,

    /**
    ### Вентиляция
    Type: Выключатель/тумблер
    Name: AZV12
    Flags: CHECKDISTANCEONPRESS
    **/
    AZV12_120 = 120,

    /**
    ### Жалюзи масло
    Type: Выключатель/тумблер
    Name: TB1
    Flags: CHECKDISTANCEONPRESS
    **/
    TB1_121 = 121,

    /**
    ### Жалюзи вода
    Type: Выключатель/тумблер
    Name: TB2
    Flags: CHECKDISTANCEONPRESS
    **/
    TB2_122 = 122,

    /**
    ### ОП II ступень
    Type: Выключатель/тумблер
    Name: TB3
    Flags: CHECKDISTANCEONPRESS
    **/
    TB3_123 = 123,

    /**
    ### ОП I ступень
    Type: Выключатель/тумблер
    Name: TB4
    Flags: CHECKDISTANCEONPRESS
    **/
    TB4_124 = 124,

    /**
    ### Освещение приборов
    Type: Выключатель/тумблер
    Name: TB5
    Flags: CHECKDISTANCEONPRESS
    **/
    TB5_125 = 125,

    /**
    ### Освещение кабины
    Type: Выключатель/тумблер
    Name: TB6
    Flags: CHECKDISTANCEONPRESS
    **/
    TB6_126 = 126,

    /**
    ### Освещение расписания
    Type: Выключатель/тумблер
    Name: TB7
    Flags: CHECKDISTANCEONPRESS
    **/
    TB7_127 = 127,

    /**
    ### Электрикалорифер
    Type: Выключатель/тумблер
    Name: TB8
    Flags: CHECKDISTANCEONPRESS
    **/
    TB8_128 = 128,

    /**
    ### Радиостанция
    Type: Выключатель/тумблер
    Name: TB10
    Flags: CHECKDISTANCEONPRESS
    **/
    TB10_129 = 129,

    /**
    ### Манометры и термометры
    Type: Выключатель/тумблер
    Name: TB011
    Flags: CHECKDISTANCEONPRESS
    **/
    TB011_130 = 130,

    /**
    ### АЛСН
    Type: Выключатель/тумблер
    Name: TB12
    Flags: CHECKDISTANCEONPRESS
    **/
    TB12_131 = 131,

    /**
    ### Частота АСЛН
    Type: Выключатель/тумблер
    Name: TB13
    Flags: CHECKDISTANCEONPRESS
    **/
    TB13_132 = 132,

    /**
    ### Омыв окон
    Type: Выключатель/тумблер
    Name: TB14
    Flags: CHECKDISTANCEONPRESS
    **/
    TB14_133 = 133,

    /**
    ### Стеклоочиститель
    Type: Выключатель/тумблер
    Name: TB15
    Flags: CHECKDISTANCEONPRESS
    **/
    TB15_134 = 134,

    /**
    ### Вызов помощника
    Type: Кнопка
    Name: BTN4
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    BTN4_135 = 135,

    /**
    ### Отпуск тормозов локомотива
    Type: Кнопка
    Name: BTN5
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    BTN5_136 = 136,

    /**
    ### Свисток
    Type: Кнопка
    Name: BTN1
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    BTN1_137 = 137,

    /**
    ### Тифон
    Type: Кнопка
    Name: BTN2
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    BTN2_138 = 138,

    /**
    ### Песок
    Type: Кнопка
    Name: BTN3
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    BTN3_139 = 139,

    /**
    ### Рукоятка бдительности
    Type: Кнопка
    Name: RB
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    RB_140 = 140,

    /**
    ### Пуск дизеля ведущего тепловоза
    Type: Кнопка
    Name: BTN8
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    BTN8_141 = 141,

    /**
    ### Пуск дизеля ведомого тепловоза
    Type: Кнопка
    Name: BTN7
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    BTN7_142 = 142,

    /**
    ### Проверка ЭТ
    Type: Кнопка
    Name: BTN9
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    BTN9_143 = 143,

    /**
    ### ВК
    Type: Кнопка
    Name: BTN10
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    BTN10_144 = 144,

    /**
    ### Проверка АЛСН
    Type: Кнопка
    Name: BTN011
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    BTN011_145 = 145,

    /**
    ### Левый БФ
    Type: Мультипереключатель
    Name: TBP7
    Flags: CHECKDISTANCEONPRESS, CONTROLLERY
    **/
    TBP7_146 = 146,

    /**
    ### Правый БФ
    Type: Мультипереключатель
    Name: TBP6
    Flags: CHECKDISTANCEONPRESS, CONTROLLERY
    **/
    TBP6_147 = 147,

    /**
    ### Номерные знаки
    Type: Выключатель/тумблер
    Name: TBP5
    Flags: CHECKDISTANCEONPRESS
    **/
    TBP5_148 = 148,

    /**
    ### Освещение пульта
    Type: Выключатель/тумблер
    Name: TBP4
    Flags: CHECKDISTANCEONPRESS
    **/
    TBP4_149 = 149,

    /**
    ### Освещение резервное
    Type: Выключатель/тумблер
    Name: TBP3
    Flags: CHECKDISTANCEONPRESS
    **/
    TBP3_150 = 150,

    /**
    ### Калориферы
    Type: Выключатель/тумблер
    Name: TBP2
    Flags: CHECKDISTANCEONPRESS
    **/
    TBP2_151 = 151,

    /**
    ### Вентиляторы
    Type: Выключатель/тумблер
    Name: TBP1
    Flags: CHECKDISTANCEONPRESS
    **/
    TBP1_152 = 152,

    /**
    ### Вольтметр
    Type: Выключатель/тумблер
    Name: TBP8
    Flags: CHECKDISTANCEONPRESS
    **/
    TBP8_153 = 153,

    /**
    ### Тифон
    Type: Кнопка
    Name: BTNP2
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    BTNP2_154 = 154,

    /**
    ### Свисток
    Type: Кнопка
    Name: BTNP1
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    BTNP1_155 = 155,

    /**
    ### Комбинированный кран усл. 103
    Type: Мультипереключатель
    Name: KK
    Flags: CONTROLLERX
    **/
    KK_156 = 156,

    /**
    ### Маневры
    Type: Кнопка
    Name: BTN12
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    BTN12_157 = 157,

    /**
    ### Свисток
    Type: Кнопка
    Name: BTN13
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    BTN13_158 = 158,

    /**
    ### РБС
    Type: Кнопка
    Name: RBS
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    RBS_159 = 159,

    /**
    ### РБП
    Type: Кнопка
    Name: RBP
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    RBP_160 = 160,

    /**
    ### Вызов ДСП
    Type: Кнопка
    Name: DSP
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    DSP_161 = 161,

    /**
    ### Вызов ДНЦ
    Type: Кнопка
    Name: DNC
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    DNC_162 = 162,

    /**
    ### Подсветка
    Type: Кнопка
    Name: PODSV
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    PODSV_163 = 163,

    /**
    ### Питание радиостанции
    Type: Кнопка
    Name: PIT
    Flags: CHECKDISTANCEONPRESS, NONFIXED
    **/
    PIT_164 = 164,

    /**
    ### Ручной тормоз
    Type: Мультипереключатель
    Name: RT
    Flags: CHECKDISTANCEONPRESS, CONTROLLERX, PRECISE
    **/
    RT_165 = 165,

    /**
    ### Завод часов
    Type: Выключатель/тумблер
    Name: SLZAVOD
    Flags: CHECKDISTANCEONPRESS
    **/
    SLZAVOD_166 = 166,

    /**
    ### UNNAMED
    Type: Выключатель/тумблер
    Name: STOR_1
    Flags: PRECISE, CONTROLLERY, CHECKDISTANCEONPRESS
    **/
    STOR_1_168 = 168,

    /**
    ### UNNAMED
    Type: Выключатель/тумблер
    Name: STOR_2
    Flags: PRECISE, CONTROLLERY, CHECKDISTANCEONPRESS
    **/
    STOR_2_169 = 169,

    /**
    ### UNNAMED
    Type: Выключатель/тумблер
    Name: STOR_3
    Flags: PRECISE, CONTROLLERY, CHECKDISTANCEONPRESS
    **/
    STOR_3_170 = 170,

    /**
    ### UNNAMED
    Type: Выключатель/тумблер
    Name: STOR_11
    Flags: PRECISE, CONTROLLERY, CHECKDISTANCEONPRESS
    **/
    STOR_11_171 = 171,

    /**
    ### UNNAMED
    Type: Выключатель/тумблер
    Name: STOR_22
    Flags: PRECISE, CONTROLLERY, CHECKDISTANCEONPRESS
    **/
    STOR_22_172 = 172,

    /**
    ### UNNAMED
    Type: Выключатель/тумблер
    Name: STOR_33
    Flags: PRECISE, CONTROLLERY, CHECKDISTANCEONPRESS
    **/
    STOR_33_173 = 173,

    /**
    ### Шкаф
    Type: Выключатель/тумблер
    Name: DOOR_F
    Flags: CHECKDISTANCEONPRESS
    **/
    DOOR_F_200 = 200,

    /**
    ### Переключение кабины
    Type: Выключатель/тумблер
    Name: RC1
    Flags: CHECKDISTANCEONPRESS
    **/
    RC1_201 = 201,

    /**
    ### Переключение кабины
    Type: Выключатель/тумблер
    Name: RC2
    Flags: CHECKDISTANCEONPRESS
    **/
    RC2_202 = 202,

    /**
    ### Питание топливного насоса
    Type: Выключатель/тумблер
    Name: TBM6
    Flags: CHECKDISTANCEONPRESS
    **/
    TBM6_203 = 203,

    /**
    ### Отключение 1 ТЭД
    Type: Выключатель/тумблер
    Name: OM1
    Flags: CHECKDISTANCEONPRESS
    **/
    OM1_204 = 204,

    /**
    ### Отключение 2 ТЭД
    Type: Выключатель/тумблер
    Name: OM2
    Flags: CHECKDISTANCEONPRESS
    **/
    OM2_205 = 205,

    /**
    ### Отключение 3 ТЭД
    Type: Выключатель/тумблер
    Name: OM3
    Flags: CHECKDISTANCEONPRESS
    **/
    OM3_206 = 206,

    /**
    ### Отключение 4 ТЭД
    Type: Выключатель/тумблер
    Name: OM4
    Flags: CHECKDISTANCEONPRESS
    **/
    OM4_207 = 207,

    /**
    ### Отключение 5 ТЭД
    Type: Выключатель/тумблер
    Name: OM5
    Flags: CHECKDISTANCEONPRESS
    **/
    OM5_208 = 208,

    /**
    ### Отключение 6 ТЭД
    Type: Выключатель/тумблер
    Name: OM6
    Flags: CHECKDISTANCEONPRESS
    **/
    OM6_209 = 209,

    /**
    ### АЗВ освещение дизельного
    Type: Выключатель/тумблер
    Name: AZVM1
    Flags: CHECKDISTANCEONPRESS
    **/
    AZVM1_210 = 210,

    /**
    ### АЗВ резервное освещение дизельного
    Type: Выключатель/тумблер
    Name: AZVM2
    Flags: CHECKDISTANCEONPRESS
    **/
    AZVM2_211 = 211,

    /**
    ### АЗВ освещение подкузовное
    Type: Выключатель/тумблер
    Name: AZVM3
    Flags: CHECKDISTANCEONPRESS
    **/
    AZVM3_212 = 212,

    /**
    ### АЗВ освещение ВВК
    Type: Выключатель/тумблер
    Name: AZVM4
    Flags: CHECKDISTANCEONPRESS
    **/
    AZVM4_213 = 213,

    /**
    ### АЗВ питание розеток
    Type: Выключатель/тумблер
    Name: AZVM5
    Flags: CHECKDISTANCEONPRESS
    **/
    AZVM5_214 = 214,

    /**
    ### АЗВ питание автостопа
    Type: Выключатель/тумблер
    Name: AZVM6
    Flags: CHECKDISTANCEONPRESS
    **/
    AZVM6_215 = 215,

    /**
    ### АЗВ питание автостопа
    Type: Выключатель/тумблер
    Name: AZVM7
    Flags: CHECKDISTANCEONPRESS
    **/
    AZVM7_216 = 216,

    /**
    ### АЗВ пожарная сигнализация
    Type: Выключатель/тумблер
    Name: AZVM8
    Flags: CHECKDISTANCEONPRESS
    **/
    AZVM8_217 = 217,

    /**
    ### АЗВ буферные фонари
    Type: Выключатель/тумблер
    Name: AZVM9
    Flags: CHECKDISTANCEONPRESS
    **/
    AZVM9_218 = 218,

    /**
    ### АЗВ питание розеток
    Type: Выключатель/тумблер
    Name: AZVM10
    Flags: CHECKDISTANCEONPRESS
    **/
    AZVM10_219 = 219,

    /**
    ### АЗВ вспомогательные цепи
    Type: Выключатель/тумблер
    Name: AZVM11
    Flags: CHECKDISTANCEONPRESS
    **/
    AZVM11_220 = 220,

    /**
    ### АЗВ компрессор
    Type: Выключатель/тумблер
    Name: AZVM12
    Flags: CHECKDISTANCEONPRESS
    **/
    AZVM12_221 = 221,

    /**
    ### АЗВ топливный насос
    Type: Выключатель/тумблер
    Name: AZVM13
    Flags: CHECKDISTANCEONPRESS
    **/
    AZVM13_222 = 222,

    /**
    ### АЗВ калорифер
    Type: Выключатель/тумблер
    Name: AZVM14
    Flags: CHECKDISTANCEONPRESS
    **/
    AZVM14_223 = 223,

    /**
    ### Резервное питание насоса
    Type: Выключатель/тумблер
    Name: TBM1
    Flags: CHECKDISTANCEONPRESS
    **/
    TBM1_224 = 224,

    /**
    ### Автостоп
    Type: Выключатель/тумблер
    Name: TBM2
    Flags: CHECKDISTANCEONPRESS
    **/
    TBM2_225 = 225,

    /**
    ### Шунтировка
    Type: Выключатель/тумблер
    Name: TBM3
    Flags: CHECKDISTANCEONPRESS
    **/
    TBM3_226 = 226,

    /**
    ### Электродинамический тормоз
    Type: Выключатель/тумблер
    Name: TBM4
    Flags: CHECKDISTANCEONPRESS
    **/
    TBM4_227 = 227,

    /**
    ### Ручная прокачка масла
    Type: Выключатель/тумблер
    Name: TBM5
    Flags: CHECKDISTANCEONPRESS
    **/
    TBM5_228 = 228,

    /**
    ### Батарея 1
    Type: Выключатель/тумблер
    Name: RUB_AB1
    Flags: CHECKDISTANCEONPRESS
    **/
    RUB_AB1_229 = 229,

    /**
    ### Батарея 2
    Type: Выключатель/тумблер
    Name: RUB_AB2
    Flags: CHECKDISTANCEONPRESS
    **/
    RUB_AB2_230 = 230,

    /**
    ### UNNAMED
    Type: Выключатель/тумблер
    Name: KR1
    Flags: CHECKDISTANCEONPRESS
    **/
    KR1_233 = 233,

    /**
    ### UNNAMED
    Type: Выключатель/тумблер
    Name: KR2
    Flags: CHECKDISTANCEONPRESS
    **/
    KR2_234 = 234,

    /**
    ### UNNAMED
    Type: Выключатель/тумблер
    Name: KR3
    Flags: CHECKDISTANCEONPRESS
    **/
    KR3_235 = 235,

    /**
    ### UNNAMED
    Type: Выключатель/тумблер
    Name: KR4
    Flags: CHECKDISTANCEONPRESS
    **/
    KR4_236 = 236,

  };
  
  /**
  ## Указатели.
  **/
  enum class disp : unsigned short {
    
    /**
    ### Вольтметр
    Type: ARROW
    Name: `ARR141`
        #### Values:
        MIN: `0.0`
        MAX: `150.0`
        ZERO: `0.0`
    **/
    ARR141_0 = 0,

    /**
    ### Амперметр АКБ
    Type: ARROW
    Name: `ARR151`
        #### Values:
        MIN: `-150.0`
        MAX: `150.0`
        ZERO: `-150.0`
    **/
    ARR151_1 = 1,

    /**
    ### Напряжение генератора
    Type: ARROW
    Name: `ARR161`
        #### Values:
        MIN: `0.0`
        MAX: `1000.0`
        ZERO: `0.0`
    **/
    ARR161_2 = 2,

    /**
    ### Индикатор
    Type: ARROW
    Name: `ARR171`
        #### Values:
        MIN: `0.0`
        MAX: `10.0`
        ZERO: `0.0`
    **/
    ARR171_3 = 3,

    /**
    ### Ток якоря Тяга
    Type: ARROW
    Name: `ARR51`
        #### Values:
        MIN: `0.0`
        MAX: `10.0`
        ZERO: `0.0`
    **/
    ARR51_4 = 4,

    /**
    ### Ток якоря ЭДТ
    Type: ARROW
    Name: `ARR61`
        #### Values:
        MIN: `0.0`
        MAX: `10.0`
        ZERO: `0.0`
    **/
    ARR61_5 = 5,

    /**
    ### Заданная скорость
    Type: ARROW
    Name: `ARR71`
        #### Values:
        MIN: `0.0`
        MAX: `150.0`
        ZERO: `0.0`
    **/
    ARR71_6 = 6,

    /**
    ### Давление ТЦ
    Type: ARROW
    Name: `ARR81`
        #### Values:
        MIN: `0.0`
        MAX: `16.2`
        ZERO: `0.0`
    **/
    ARR81_7 = 7,

    /**
    ### Давление ТМ
    Type: ARROW
    Name: `ARR101`
        #### Values:
        MIN: `0.0`
        MAX: `16.0`
        ZERO: `0.0`
    **/
    ARR101_8 = 8,

    /**
    ### Давление ГР
    Type: ARROW
    Name: `ARR91`
        #### Values:
        MIN: `0.0`
        MAX: `16.0`
        ZERO: `0.0`
    **/
    ARR91_9 = 9,

    /**
    ### Давление УР
    Type: ARROW
    Name: `ARR111`
        #### Values:
        MIN: `0.0`
        MAX: `10.0`
        ZERO: `0.0`
    **/
    ARR111_10 = 10,

    /**
    ### Скорость
    Type: ARROW
    Name: `ARR01`
        #### Values:
        MIN: `0.0`
        MAX: `62.50`
        ZERO: `0.0`
    **/
    ARR01_11 = 11,

    /**
    ### Часы
    Type: ARROW
    Name: `ARR121`
        #### Values:
        MIN: `0.0`
        MAX: `24.00`
        ZERO: `0.0`
    **/
    ARR121_12 = 12,

    /**
    ### Минуты
    Type: ARROW
    Name: `ARR131`
        #### Values:
        MIN: `0.0`
        MAX: `60.00`
        ZERO: `0.0`
    **/
    ARR131_13 = 13,

    /**
    ### Температура воды
    Type: ARROW
    Name: `ARR011`
        #### Values:
        MIN: `0.0`
        MAX: `127.0`
        ZERO: `0.0`
    **/
    ARR011_14 = 14,

    /**
    ### Температура масла
    Type: ARROW
    Name: `ARR21`
        #### Values:
        MIN: `0.0`
        MAX: `127.0`
        ZERO: `0.0`
    **/
    ARR21_15 = 15,

    /**
    ### Давление топлива
    Type: ARROW
    Name: `ARR31`
        #### Values:
        MIN: `0.0`
        MAX: `15.8`
        ZERO: `0.0`
    **/
    ARR31_16 = 16,

    /**
    ### Давление масла
    Type: ARROW
    Name: `ARR41`
        #### Values:
        MIN: `0.0`
        MAX: `15.8`
        ZERO: `0.0`
    **/
    ARR41_17 = 17,

    /**
    ### Сброс нагрузки
    Type: LAMP
    Name: `LAMP011`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMP011_20 = 20,

    /**
    ### Жалюзи ЭТ открыты
    Type: LAMP
    Name: `LAMP21`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMP21_21 = 21,

    /**
    ### Температура воды и масла
    Type: LAMP
    Name: `LAMP31`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMP31_22 = 22,

    /**
    ### Жалюзи ЭТ открыты
    Type: LAMP
    Name: `LAMP41`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMP41_23 = 23,

    /**
    ### Давление масла
    Type: LAMP
    Name: `LAMP51`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMP51_24 = 24,

    /**
    ### Нет зарядки батареи
    Type: LAMP
    Name: `LAMP61`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMP61_25 = 25,

    /**
    ### ЭДТ I тепловоза
    Type: LAMP
    Name: `LAMP71`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMP71_26 = 26,

    /**
    ### ЭДТ II тепловоза
    Type: LAMP
    Name: `LAMP81`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMP81_27 = 27,

    /**
    ### О
    Type: LAMP
    Name: `LAMP111`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMP111_28 = 28,

    /**
    ### П
    Type: LAMP
    Name: `LAMP101`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMP101_29 = 29,

    /**
    ### Т
    Type: LAMP
    Name: `LAMP91`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMP91_30 = 30,

    /**
    ### Резервный топливный насос
    Type: LAMP
    Name: `LAMPP11`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMPP11_31 = 31,

    /**
    ### Нагружение на тормозные резисторы
    Type: LAMP
    Name: `LAMPP21`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMPP21_32 = 32,

    /**
    ### Пожар левой стороны ДП
    Type: LAMP
    Name: `LAMPP31`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMPP31_33 = 33,

    /**
    ### Пожар правой стороны ДП
    Type: LAMP
    Name: `LAMPP41`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMPP41_34 = 34,

    /**
    ### Перегрев электрического калорифера
    Type: LAMP
    Name: `LAMPP51`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMPP51_35 = 35,

    /**
    ### ПСС
    Type: LAMP
    Name: `PSS11`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    PSS11_36 = 36,

    /**
    ### Скатывание (H)
    Type: LAMP
    Name: `PSS21`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    PSS21_37 = 37,

    /**
    ### ПСС
    Type: LAMP
    Name: `PSS31`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    PSS31_38 = 38,

    /**
    ### UNNAMED
    Type: LAMP
    Name: `LAMPPO1`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMPPO1_39 = 39,

    /**
    ### Вольтметр
    Type: ARROW
    Name: `ARR14`
        #### Values:
        MIN: `0.0`
        MAX: `150.0`
        ZERO: `0.0`
    **/
    ARR14_100 = 100,

    /**
    ### Амперметр АКБ
    Type: ARROW
    Name: `ARR15`
        #### Values:
        MIN: `-150.0`
        MAX: `150.0`
        ZERO: `-150.0`
    **/
    ARR15_101 = 101,

    /**
    ### Напряжение генератора
    Type: ARROW
    Name: `ARR16`
        #### Values:
        MIN: `0.0`
        MAX: `1000.0`
        ZERO: `0.0`
    **/
    ARR16_102 = 102,

    /**
    ### Индикатор
    Type: ARROW
    Name: `ARR17`
        #### Values:
        MIN: `0.0`
        MAX: `10.0`
        ZERO: `0.0`
    **/
    ARR17_103 = 103,

    /**
    ### Ток якоря Тяга
    Type: ARROW
    Name: `ARR5`
        #### Values:
        MIN: `0.0`
        MAX: `10.0`
        ZERO: `0.0`
    **/
    ARR5_104 = 104,

    /**
    ### Ток якоря ЭДТ
    Type: ARROW
    Name: `ARR6`
        #### Values:
        MIN: `0.0`
        MAX: `10.0`
        ZERO: `0.0`
    **/
    ARR6_105 = 105,

    /**
    ### Заданная скорость
    Type: ARROW
    Name: `ARR7`
        #### Values:
        MIN: `0.0`
        MAX: `150.0`
        ZERO: `0.0`
    **/
    ARR7_106 = 106,

    /**
    ### Давление ТЦ
    Type: ARROW
    Name: `ARR8`
        #### Values:
        MIN: `0.0`
        MAX: `16.2`
        ZERO: `0.0`
    **/
    ARR8_107 = 107,

    /**
    ### Давление ТМ
    Type: ARROW
    Name: `ARR9`
        #### Values:
        MIN: `0.0`
        MAX: `16.0`
        ZERO: `0.0`
    **/
    ARR9_108 = 108,

    /**
    ### Давление ГР
    Type: ARROW
    Name: `ARR10`
        #### Values:
        MIN: `0.0`
        MAX: `16.0`
        ZERO: `0.0`
    **/
    ARR10_109 = 109,

    /**
    ### Давление УР
    Type: ARROW
    Name: `ARR11`
        #### Values:
        MIN: `0.0`
        MAX: `10.0`
        ZERO: `0.0`
    **/
    ARR11_110 = 110,

    /**
    ### Скорость
    Type: ARROW
    Name: `ARR0`
        #### Values:
        MIN: `0.0`
        MAX: `62.50`
        ZERO: `0.0`
    **/
    ARR0_111 = 111,

    /**
    ### Часы
    Type: ARROW
    Name: `ARR12`
        #### Values:
        MIN: `0.0`
        MAX: `24.00`
        ZERO: `0.0`
    **/
    ARR12_112 = 112,

    /**
    ### Минуты
    Type: ARROW
    Name: `ARR13`
        #### Values:
        MIN: `0.0`
        MAX: `60.00`
        ZERO: `0.0`
    **/
    ARR13_113 = 113,

    /**
    ### Температура воды
    Type: ARROW
    Name: `ARR1`
        #### Values:
        MIN: `0.0`
        MAX: `127.0`
        ZERO: `0.0`
    **/
    ARR1_114 = 114,

    /**
    ### Температура масла
    Type: ARROW
    Name: `ARR2`
        #### Values:
        MIN: `0.0`
        MAX: `127.0`
        ZERO: `0.0`
    **/
    ARR2_115 = 115,

    /**
    ### Давление топлива
    Type: ARROW
    Name: `ARR3`
        #### Values:
        MIN: `0.0`
        MAX: `15.8`
        ZERO: `0.0`
    **/
    ARR3_116 = 116,

    /**
    ### Давление масла
    Type: ARROW
    Name: `ARR4`
        #### Values:
        MIN: `0.0`
        MAX: `15.8`
        ZERO: `0.0`
    **/
    ARR4_117 = 117,

    /**
    ### Сброс нагрузки
    Type: LAMP
    Name: `LAMP1`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMP1_120 = 120,

    /**
    ### Жалюзи ЭТ открыты
    Type: LAMP
    Name: `LAMP2`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMP2_121 = 121,

    /**
    ### Температура воды и масла
    Type: LAMP
    Name: `LAMP3`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMP3_122 = 122,

    /**
    ### Жалюзи ЭТ открыты
    Type: LAMP
    Name: `LAMP4`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMP4_123 = 123,

    /**
    ### Давление масла
    Type: LAMP
    Name: `LAMP5`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMP5_124 = 124,

    /**
    ### Нет зарядки батареи
    Type: LAMP
    Name: `LAMP6`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMP6_125 = 125,

    /**
    ### ЭДТ I тепловоза
    Type: LAMP
    Name: `LAMP7`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMP7_126 = 126,

    /**
    ### ЭДТ II тепловоза
    Type: LAMP
    Name: `LAMP8`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMP8_127 = 127,

    /**
    ### О
    Type: LAMP
    Name: `LAMP11`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMP11_128 = 128,

    /**
    ### П
    Type: LAMP
    Name: `LAMP10`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMP10_129 = 129,

    /**
    ### Т
    Type: LAMP
    Name: `LAMP9`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMP9_130 = 130,

    /**
    ### Резервный топливный насос
    Type: LAMP
    Name: `LAMPP1`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMPP1_131 = 131,

    /**
    ### Нагружение на тормозные резисторы
    Type: LAMP
    Name: `LAMPP2`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMPP2_132 = 132,

    /**
    ### Пожар левой стороны ДП
    Type: LAMP
    Name: `LAMPP3`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMPP3_133 = 133,

    /**
    ### Пожар правой стороны ДП
    Type: LAMP
    Name: `LAMPP4`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMPP4_134 = 134,

    /**
    ### Перегрев электрического калорифера
    Type: LAMP
    Name: `LAMPP5`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMPP5_135 = 135,

    /**
    ### ПСС
    Type: LAMP
    Name: `PSS1`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    PSS1_136 = 136,

    /**
    ### Скатывание (H)
    Type: LAMP
    Name: `PSS2`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    PSS2_137 = 137,

    /**
    ### ПСС
    Type: LAMP
    Name: `PSS3`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    PSS3_138 = 138,

    /**
    ### UNNAMED
    Type: LAMP
    Name: `LAMPPO`
        #### Values:
        `0` - OFF
        `1` - ON
    **/
    LAMPPO_139 = 139,

    /**
    ### UNNAMED
    Type: SCREEN
    Name: `NUM1`
    **/
    NUM1_150 = 150,

    /**
    ### UNNAMED
    Type: SCREEN
    Name: `NUM2`
    **/
    NUM2_151 = 151,

    /**
    ### Давление масла до фильтра тонкой очистки
    Type: ARROW
    Name: `ARRM1`
        #### Values:
        MIN: `0.0`
        MAX: `16.0`
        ZERO: `0.0`
    **/
    ARRM1_162 = 162,

    /**
    ### Давление масла после фильтра тонкой очистки
    Type: ARROW
    Name: `ARRM2`
        #### Values:
        MIN: `0.0`
        MAX: `16.0`
        ZERO: `0.0`
    **/
    ARRM2_163 = 163,

    /**
    ### Давление топлива до фильтра тонкой очистки
    Type: ARROW
    Name: `ARRM3`
        #### Values:
        MIN: `0.0`
        MAX: `16.0`
        ZERO: `0.0`
    **/
    ARRM3_164 = 164,

    /**
    ### Давление топлива после фильтра тонкой очистки
    Type: ARROW
    Name: `ARRM4`
        #### Values:
        MIN: `0.0`
        MAX: `16.0`
        ZERO: `0.0`
    **/
    ARRM4_165 = 165,

    /**
    ### Наддув
    Type: ARROW
    Name: `ARRM5`
        #### Values:
        MIN: `0.0`
        MAX: `16.0`
        ZERO: `0.0`
    **/
    ARRM5_166 = 166,

    /**
    ### Давление в гидростатической системе
    Type: ARROW
    Name: `ARRM6`
        #### Values:
        MIN: `0.0`
        MAX: `16.0`
        ZERO: `0.0`
    **/
    ARRM6_167 = 167,

  };
  
  /**
  ## Состояния приборов
  **/
  namespace st {
    
    /**
    #### Состояния переключателя
    ### Тормоз поезда
    Name: `R3951`
    Default: `0`
    States:
    - `0` - [VI экстренное торм.]
    - `1` - [V торможение]
    - `2` - [Vэ торможение ЭПТ]
    - `3` - [IV перекрыша с пит.]
    - `4` - [III перекрыша без пит.]
    - `5` - [II поездное]
    - `6` - [I отпуск и зарядка]
    **/
    enum class R3951 : unsigned short {
      /**
      #### Тормоз поезда
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Тормоз поезда
      ### [VI экстренное торм.]
      **/
      ST_0 = 0,

      /**
      #### Тормоз поезда
      ### [V торможение]
      **/
      ST_1 = 1,

      /**
      #### Тормоз поезда
      ### [Vэ торможение ЭПТ]
      **/
      ST_2 = 2,

      /**
      #### Тормоз поезда
      ### [IV перекрыша с пит.]
      **/
      ST_3 = 3,

      /**
      #### Тормоз поезда
      ### [III перекрыша без пит.]
      **/
      ST_4 = 4,

      /**
      #### Тормоз поезда
      ### [II поездное]
      **/
      ST_5 = 5,

      /**
      #### Тормоз поезда
      ### [I отпуск и зарядка]
      **/
      ST_6 = 6,
    };
  
    /**
    #### Состояния переключателя
    ### Тормоз локомотива
    Name: `R2541`
    Default: `0`
    States:
    - `0` - [Торможение 4]
    - `1` - [Торможение 3]
    - `2` - [Торможение 2]
    - `3` - [Торможение 1]
    - `4` - [Поездное]
    - `5` - [Буфер]
    **/
    enum class R2541 : unsigned short {
      /**
      #### Тормоз локомотива
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Тормоз локомотива
      ### [Торможение 4]
      **/
      ST_0 = 0,

      /**
      #### Тормоз локомотива
      ### [Торможение 3]
      **/
      ST_1 = 1,

      /**
      #### Тормоз локомотива
      ### [Торможение 2]
      **/
      ST_2 = 2,

      /**
      #### Тормоз локомотива
      ### [Торможение 1]
      **/
      ST_3 = 3,

      /**
      #### Тормоз локомотива
      ### [Поездное]
      **/
      ST_4 = 4,

      /**
      #### Тормоз локомотива
      ### [Буфер]
      **/
      ST_5 = 5,
    };
  
    /**
    #### Состояния переключателя
    ### Реверс
    Name: `REV1`
    Default: `1`
    States:
    - `0` - [Назад]
    - `1` - [Нейтральный]
    - `2` - [Вперёд]
    **/
    enum class REV1 : unsigned short {
      /**
      #### Реверс
      ### Исходное состояние
      **/
      DEFAULT = 1,

      /**
      #### Реверс
      ### [Назад]
      **/
      ST_0 = 0,

      /**
      #### Реверс
      ### [Нейтральный]
      **/
      ST_1 = 1,

      /**
      #### Реверс
      ### [Вперёд]
      **/
      ST_2 = 2,
    };
  
    /**
    #### Состояния переключателя
    ### Контроллер
    Name: `KONT1`
    Default: `7`
    States:
    - `0` - [торм.6]
    - `1` - [торм.5]
    - `2` - [торм.4]
    - `3` - [торм.3]
    - `4` - [торм.2]
    - `5` - [торм.1]
    - `6` - [П]
    - `7` - [0]
    - `8` - [1]
    - `9` - [2]
    - `10` - [3]
    - `11` - [4]
    - `12` - [5]
    - `13` - [6]
    - `14` - [7]
    - `15` - [8]
    - `16` - [9]
    - `17` - [10]
    - `18` - [11]
    - `19` - [12]
    - `20` - [13]
    - `21` - [14]
    - `22` - [15]
    **/
    enum class KONT1 : unsigned short {
      /**
      #### Контроллер
      ### Исходное состояние
      **/
      DEFAULT = 7,

      /**
      #### Контроллер
      ### [торм.6]
      **/
      ST_0 = 0,

      /**
      #### Контроллер
      ### [торм.5]
      **/
      ST_1 = 1,

      /**
      #### Контроллер
      ### [торм.4]
      **/
      ST_2 = 2,

      /**
      #### Контроллер
      ### [торм.3]
      **/
      ST_3 = 3,

      /**
      #### Контроллер
      ### [торм.2]
      **/
      ST_4 = 4,

      /**
      #### Контроллер
      ### [торм.1]
      **/
      ST_5 = 5,

      /**
      #### Контроллер
      ### [П]
      **/
      ST_6 = 6,

      /**
      #### Контроллер
      ### [0]
      **/
      ST_7 = 7,

      /**
      #### Контроллер
      ### [1]
      **/
      ST_8 = 8,

      /**
      #### Контроллер
      ### [2]
      **/
      ST_9 = 9,

      /**
      #### Контроллер
      ### [3]
      **/
      ST_10 = 10,

      /**
      #### Контроллер
      ### [4]
      **/
      ST_11 = 11,

      /**
      #### Контроллер
      ### [5]
      **/
      ST_12 = 12,

      /**
      #### Контроллер
      ### [6]
      **/
      ST_13 = 13,

      /**
      #### Контроллер
      ### [7]
      **/
      ST_14 = 14,

      /**
      #### Контроллер
      ### [8]
      **/
      ST_15 = 15,

      /**
      #### Контроллер
      ### [9]
      **/
      ST_16 = 16,

      /**
      #### Контроллер
      ### [10]
      **/
      ST_17 = 17,

      /**
      #### Контроллер
      ### [11]
      **/
      ST_18 = 18,

      /**
      #### Контроллер
      ### [12]
      **/
      ST_19 = 19,

      /**
      #### Контроллер
      ### [13]
      **/
      ST_20 = 20,

      /**
      #### Контроллер
      ### [14]
      **/
      ST_21 = 21,

      /**
      #### Контроллер
      ### [15]
      **/
      ST_22 = 22,
    };
  
    /**
    #### Состояния переключателя
    ### Задатчик тормозного усилия ЭДТ
    Name: `ZAD1`
    Default: `11`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    - `2` - UNNAMED
    - `3` - UNNAMED
    - `4` - UNNAMED
    - `5` - UNNAMED
    - `6` - UNNAMED
    - `7` - UNNAMED
    - `8` - UNNAMED
    - `9` - UNNAMED
    - `10` - UNNAMED
    - `11` - UNNAMED
    **/
    enum class ZAD1 : unsigned short {
      /**
      #### Задатчик тормозного усилия ЭДТ
      ### Исходное состояние
      **/
      DEFAULT = 11,

      /**
      #### Задатчик тормозного усилия ЭДТ
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Задатчик тормозного усилия ЭДТ
      ### UNNAMED
      **/
      ST_1 = 1,

      /**
      #### Задатчик тормозного усилия ЭДТ
      ### UNNAMED
      **/
      ST_2 = 2,

      /**
      #### Задатчик тормозного усилия ЭДТ
      ### UNNAMED
      **/
      ST_3 = 3,

      /**
      #### Задатчик тормозного усилия ЭДТ
      ### UNNAMED
      **/
      ST_4 = 4,

      /**
      #### Задатчик тормозного усилия ЭДТ
      ### UNNAMED
      **/
      ST_5 = 5,

      /**
      #### Задатчик тормозного усилия ЭДТ
      ### UNNAMED
      **/
      ST_6 = 6,

      /**
      #### Задатчик тормозного усилия ЭДТ
      ### UNNAMED
      **/
      ST_7 = 7,

      /**
      #### Задатчик тормозного усилия ЭДТ
      ### UNNAMED
      **/
      ST_8 = 8,

      /**
      #### Задатчик тормозного усилия ЭДТ
      ### UNNAMED
      **/
      ST_9 = 9,

      /**
      #### Задатчик тормозного усилия ЭДТ
      ### UNNAMED
      **/
      ST_10 = 10,

      /**
      #### Задатчик тормозного усилия ЭДТ
      ### UNNAMED
      **/
      ST_11 = 11,
    };
  
    /**
    #### Состояния переключателя
    ### Блокировка тормозов усл. 367
    Name: `R3671`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class R3671 : unsigned short {
      /**
      #### Блокировка тормозов усл. 367
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Блокировка тормозов усл. 367
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Блокировка тормозов усл. 367
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Редуктор зарядного давления
    Name: `RED1`
    Default: `12`
    States:
    - `0` - [4.0]
    - `1` - [4.1]
    - `2` - [4.2]
    - `3` - [4.3]
    - `4` - [4.4]
    - `5` - [4.5]
    - `6` - [4.6]
    - `7` - [4.7]
    - `8` - [4.8]
    - `9` - [4.9]
    - `10` - [5.0]
    - `11` - [5.1]
    - `12` - [5.2]
    - `13` - [5.3]
    - `14` - [5.4]
    - `15` - [5.5]
    - `16` - [5.6]
    - `17` - [5.7]
    - `18` - [5.8]
    - `19` - [5.9]
    **/
    enum class RED1 : unsigned short {
      /**
      #### Редуктор зарядного давления
      ### Исходное состояние
      **/
      DEFAULT = 12,

      /**
      #### Редуктор зарядного давления
      ### [4.0]
      **/
      ST_0 = 0,

      /**
      #### Редуктор зарядного давления
      ### [4.1]
      **/
      ST_1 = 1,

      /**
      #### Редуктор зарядного давления
      ### [4.2]
      **/
      ST_2 = 2,

      /**
      #### Редуктор зарядного давления
      ### [4.3]
      **/
      ST_3 = 3,

      /**
      #### Редуктор зарядного давления
      ### [4.4]
      **/
      ST_4 = 4,

      /**
      #### Редуктор зарядного давления
      ### [4.5]
      **/
      ST_5 = 5,

      /**
      #### Редуктор зарядного давления
      ### [4.6]
      **/
      ST_6 = 6,

      /**
      #### Редуктор зарядного давления
      ### [4.7]
      **/
      ST_7 = 7,

      /**
      #### Редуктор зарядного давления
      ### [4.8]
      **/
      ST_8 = 8,

      /**
      #### Редуктор зарядного давления
      ### [4.9]
      **/
      ST_9 = 9,

      /**
      #### Редуктор зарядного давления
      ### [5.0]
      **/
      ST_10 = 10,

      /**
      #### Редуктор зарядного давления
      ### [5.1]
      **/
      ST_11 = 11,

      /**
      #### Редуктор зарядного давления
      ### [5.2]
      **/
      ST_12 = 12,

      /**
      #### Редуктор зарядного давления
      ### [5.3]
      **/
      ST_13 = 13,

      /**
      #### Редуктор зарядного давления
      ### [5.4]
      **/
      ST_14 = 14,

      /**
      #### Редуктор зарядного давления
      ### [5.5]
      **/
      ST_15 = 15,

      /**
      #### Редуктор зарядного давления
      ### [5.6]
      **/
      ST_16 = 16,

      /**
      #### Редуктор зарядного давления
      ### [5.7]
      **/
      ST_17 = 17,

      /**
      #### Редуктор зарядного давления
      ### [5.8]
      **/
      ST_18 = 18,

      /**
      #### Редуктор зарядного давления
      ### [5.9]
      **/
      ST_19 = 19,
    };
  
    /**
    #### Состояния переключателя
    ### Ключ ЭПК
    Name: `EPK1`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class EPK1 : unsigned short {
      /**
      #### Ключ ЭПК
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Ключ ЭПК
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Ключ ЭПК
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Прожектор яркий
    Name: `AZV11`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZV11 : unsigned short {
      /**
      #### Прожектор яркий
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Прожектор яркий
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Прожектор яркий
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Прожектор тускло
    Name: `AZV21`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZV21 : unsigned short {
      /**
      #### Прожектор тускло
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Прожектор тускло
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Прожектор тускло
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Питание ЭПТ
    Name: `AZV31`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZV31 : unsigned short {
      /**
      #### Питание ЭПТ
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Питание ЭПТ
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Питание ЭПТ
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### ЭПТ
    Name: `AZV41`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZV41 : unsigned short {
      /**
      #### ЭПТ
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### ЭПТ
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### ЭПТ
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Электрический тормоз
    Name: `AZV51`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZV51 : unsigned short {
      /**
      #### Электрический тормоз
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Электрический тормоз
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Электрический тормоз
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Топливный насос ведомого тепловоза
    Name: `AZV61`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZV61 : unsigned short {
      /**
      #### Топливный насос ведомого тепловоза
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Топливный насос ведомого тепловоза
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Топливный насос ведомого тепловоза
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Топливный насос ведущего тепловоза
    Name: `AZV71`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZV71 : unsigned short {
      /**
      #### Топливный насос ведущего тепловоза
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Топливный насос ведущего тепловоза
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Топливный насос ведущего тепловоза
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Управление тепловозом
    Name: `AZV81`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZV81 : unsigned short {
      /**
      #### Управление тепловозом
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Управление тепловозом
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Управление тепловозом
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Управление общее
    Name: `AZV91`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZV91 : unsigned short {
      /**
      #### Управление общее
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Управление общее
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Управление общее
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Освещение пульта
    Name: `AZV101`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZV101 : unsigned short {
      /**
      #### Освещение пульта
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Освещение пульта
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Освещение пульта
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Освещение кабины
    Name: `AZV111`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZV111 : unsigned short {
      /**
      #### Освещение кабины
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Освещение кабины
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Освещение кабины
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Вентиляция
    Name: `AZV121`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZV121 : unsigned short {
      /**
      #### Вентиляция
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Вентиляция
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Вентиляция
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Жалюзи масло
    Name: `TB11`
    Default: `0`
    States:
    - `0` - [Автомат]
    - `1` - [Ручное]
    **/
    enum class TB11 : unsigned short {
      /**
      #### Жалюзи масло
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Жалюзи масло
      ### [Автомат]
      **/
      ST_0 = 0,

      /**
      #### Жалюзи масло
      ### [Ручное]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Жалюзи вода
    Name: `TB21`
    Default: `0`
    States:
    - `0` - [Автомат]
    - `1` - [Ручное]
    **/
    enum class TB21 : unsigned short {
      /**
      #### Жалюзи вода
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Жалюзи вода
      ### [Автомат]
      **/
      ST_0 = 0,

      /**
      #### Жалюзи вода
      ### [Ручное]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### ОП II ступень
    Name: `TB31`
    Default: `0`
    States:
    - `0` - [Автомат]
    - `1` - [Ручное]
    **/
    enum class TB31 : unsigned short {
      /**
      #### ОП II ступень
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### ОП II ступень
      ### [Автомат]
      **/
      ST_0 = 0,

      /**
      #### ОП II ступень
      ### [Ручное]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### ОП I ступень
    Name: `TB41`
    Default: `0`
    States:
    - `0` - [Автомат]
    - `1` - [Ручное]
    **/
    enum class TB41 : unsigned short {
      /**
      #### ОП I ступень
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### ОП I ступень
      ### [Автомат]
      **/
      ST_0 = 0,

      /**
      #### ОП I ступень
      ### [Ручное]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Освещение приборов
    Name: `TB51`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class TB51 : unsigned short {
      /**
      #### Освещение приборов
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Освещение приборов
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Освещение приборов
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Освещение кабины
    Name: `TB61`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class TB61 : unsigned short {
      /**
      #### Освещение кабины
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Освещение кабины
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Освещение кабины
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Освещение расписания
    Name: `TB71`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class TB71 : unsigned short {
      /**
      #### Освещение расписания
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Освещение расписания
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Освещение расписания
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Электрикалорифер
    Name: `TB81`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class TB81 : unsigned short {
      /**
      #### Электрикалорифер
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Электрикалорифер
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Электрикалорифер
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Радиостанция
    Name: `TB101`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class TB101 : unsigned short {
      /**
      #### Радиостанция
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Радиостанция
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Радиостанция
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Манометры и термометры
    Name: `TB111`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class TB111 : unsigned short {
      /**
      #### Манометры и термометры
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Манометры и термометры
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Манометры и термометры
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### АЛСН
    Name: `TB121`
    Default: `1`
    States:
    - `0` - [Без АЛС]
    - `1` - [АЛС]
    **/
    enum class TB121 : unsigned short {
      /**
      #### АЛСН
      ### Исходное состояние
      **/
      DEFAULT = 1,

      /**
      #### АЛСН
      ### [Без АЛС]
      **/
      ST_0 = 0,

      /**
      #### АЛСН
      ### [АЛС]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Частота АСЛН
    Name: `TB131`
    Default: `0`
    States:
    - `0` - [25 Гц]
    - `1` - [50 Гц]
    **/
    enum class TB131 : unsigned short {
      /**
      #### Частота АСЛН
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Частота АСЛН
      ### [25 Гц]
      **/
      ST_0 = 0,

      /**
      #### Частота АСЛН
      ### [50 Гц]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Омыв окон
    Name: `TB141`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class TB141 : unsigned short {
      /**
      #### Омыв окон
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Омыв окон
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Омыв окон
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Стеклоочиститель
    Name: `TB151`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class TB151 : unsigned short {
      /**
      #### Стеклоочиститель
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Стеклоочиститель
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Стеклоочиститель
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Вызов помощника
    Name: `BTN41`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class BTN41 : unsigned short {
      /**
      #### Вызов помощника
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Вызов помощника
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Вызов помощника
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Отпуск тормозов локомотива
    Name: `BTN51`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class BTN51 : unsigned short {
      /**
      #### Отпуск тормозов локомотива
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Отпуск тормозов локомотива
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Отпуск тормозов локомотива
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Свисток
    Name: `BTN11`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class BTN11 : unsigned short {
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
    Name: `BTN21`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class BTN21 : unsigned short {
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
    Name: `BTN31`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class BTN31 : unsigned short {
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
    ### Рукоятка бдительности
    Name: `RB1`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class RB1 : unsigned short {
      /**
      #### Рукоятка бдительности
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Рукоятка бдительности
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Рукоятка бдительности
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Пуск дизеля ведущего тепловоза
    Name: `BTN81`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class BTN81 : unsigned short {
      /**
      #### Пуск дизеля ведущего тепловоза
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Пуск дизеля ведущего тепловоза
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Пуск дизеля ведущего тепловоза
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Пуск дизеля ведомого тепловоза
    Name: `BTN71`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class BTN71 : unsigned short {
      /**
      #### Пуск дизеля ведомого тепловоза
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Пуск дизеля ведомого тепловоза
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Пуск дизеля ведомого тепловоза
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Проверка ЭТ
    Name: `BTN91`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class BTN91 : unsigned short {
      /**
      #### Проверка ЭТ
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Проверка ЭТ
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Проверка ЭТ
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### ВК
    Name: `BTN101`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class BTN101 : unsigned short {
      /**
      #### ВК
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### ВК
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### ВК
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Проверка АЛСН
    Name: `BTN111`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class BTN111 : unsigned short {
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
    ### Левый БФ
    Name: `TBP71`
    Default: `1`
    States:
    - `0` - [Красный]
    - `1` - [Выкл.]
    - `2` - [Белый]
    **/
    enum class TBP71 : unsigned short {
      /**
      #### Левый БФ
      ### Исходное состояние
      **/
      DEFAULT = 1,

      /**
      #### Левый БФ
      ### [Красный]
      **/
      ST_0 = 0,

      /**
      #### Левый БФ
      ### [Выкл.]
      **/
      ST_1 = 1,

      /**
      #### Левый БФ
      ### [Белый]
      **/
      ST_2 = 2,
    };
  
    /**
    #### Состояния переключателя
    ### Правый БФ
    Name: `TBP61`
    Default: `1`
    States:
    - `0` - [Красный]
    - `1` - [Выкл.]
    - `2` - [Белый]
    **/
    enum class TBP61 : unsigned short {
      /**
      #### Правый БФ
      ### Исходное состояние
      **/
      DEFAULT = 1,

      /**
      #### Правый БФ
      ### [Красный]
      **/
      ST_0 = 0,

      /**
      #### Правый БФ
      ### [Выкл.]
      **/
      ST_1 = 1,

      /**
      #### Правый БФ
      ### [Белый]
      **/
      ST_2 = 2,
    };
  
    /**
    #### Состояния переключателя
    ### Номерные знаки
    Name: `TBP51`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class TBP51 : unsigned short {
      /**
      #### Номерные знаки
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Номерные знаки
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Номерные знаки
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Освещение пульта
    Name: `TBP41`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class TBP41 : unsigned short {
      /**
      #### Освещение пульта
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Освещение пульта
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Освещение пульта
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Освещение резервное
    Name: `TBP31`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class TBP31 : unsigned short {
      /**
      #### Освещение резервное
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Освещение резервное
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Освещение резервное
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Калориферы
    Name: `TBP21`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class TBP21 : unsigned short {
      /**
      #### Калориферы
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Калориферы
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Калориферы
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Вентиляторы
    Name: `TBP11`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class TBP11 : unsigned short {
      /**
      #### Вентиляторы
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Вентиляторы
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Вентиляторы
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Вольтметр
    Name: `TBP81`
    Default: `1`
    States:
    - `0` - [ЭПТ]
    - `1` - [Батарея]
    **/
    enum class TBP81 : unsigned short {
      /**
      #### Вольтметр
      ### Исходное состояние
      **/
      DEFAULT = 1,

      /**
      #### Вольтметр
      ### [ЭПТ]
      **/
      ST_0 = 0,

      /**
      #### Вольтметр
      ### [Батарея]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Тифон
    Name: `BTNP21`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class BTNP21 : unsigned short {
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
    ### Свисток
    Name: `BTNP11`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class BTNP11 : unsigned short {
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
    ### Комбинированный кран усл. 103
    Name: `KK1`
    Default: `1`
    States:
    - `0` - [Двойная тяга]
    - `1` - [Нормальное]
    - `2` - [Экстренное]
    **/
    enum class KK1 : unsigned short {
      /**
      #### Комбинированный кран усл. 103
      ### Исходное состояние
      **/
      DEFAULT = 1,

      /**
      #### Комбинированный кран усл. 103
      ### [Двойная тяга]
      **/
      ST_0 = 0,

      /**
      #### Комбинированный кран усл. 103
      ### [Нормальное]
      **/
      ST_1 = 1,

      /**
      #### Комбинированный кран усл. 103
      ### [Экстренное]
      **/
      ST_2 = 2,
    };
  
    /**
    #### Состояния переключателя
    ### Маневры
    Name: `BTN121`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class BTN121 : unsigned short {
      /**
      #### Маневры
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Маневры
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Маневры
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Свисток
    Name: `BTN131`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class BTN131 : unsigned short {
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
    ### РБС
    Name: `RBS1`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class RBS1 : unsigned short {
      /**
      #### РБС
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### РБС
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### РБС
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### РБП
    Name: `RBP1`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class RBP1 : unsigned short {
      /**
      #### РБП
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### РБП
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### РБП
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Вызов ДСП
    Name: `DSP1`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class DSP1 : unsigned short {
      /**
      #### Вызов ДСП
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Вызов ДСП
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Вызов ДСП
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Вызов ДНЦ
    Name: `DNC1`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class DNC1 : unsigned short {
      /**
      #### Вызов ДНЦ
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Вызов ДНЦ
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Вызов ДНЦ
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Подсветка
    Name: `PODSV1`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class PODSV1 : unsigned short {
      /**
      #### Подсветка
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Подсветка
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Подсветка
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Питание радиостанции
    Name: `PIT1`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class PIT1 : unsigned short {
      /**
      #### Питание радиостанции
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Питание радиостанции
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Питание радиостанции
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Ручной тормоз
    Name: `RT1`
    Default: `0`
    States:
    - `0` - [Закручен]
    - `1` - [75%]
    - `2` - [50%]
    - `3` - [25%]
    - `4` - [Откручен]
    **/
    enum class RT1 : unsigned short {
      /**
      #### Ручной тормоз
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Ручной тормоз
      ### [Закручен]
      **/
      ST_0 = 0,

      /**
      #### Ручной тормоз
      ### [75%]
      **/
      ST_1 = 1,

      /**
      #### Ручной тормоз
      ### [50%]
      **/
      ST_2 = 2,

      /**
      #### Ручной тормоз
      ### [25%]
      **/
      ST_3 = 3,

      /**
      #### Ручной тормоз
      ### [Откручен]
      **/
      ST_4 = 4,
    };
  
    /**
    #### Состояния переключателя
    ### Завод часов
    Name: `SLZAVOD1`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SLZAVOD1 : unsigned short {
      /**
      #### Завод часов
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Завод часов
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Завод часов
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Тормоз поезда
    Name: `R395`
    Default: `0`
    States:
    - `0` - [VI экстренное торм.]
    - `1` - [V торможение]
    - `2` - [Vэ торможение ЭПТ]
    - `3` - [IV перекрыша с пит.]
    - `4` - [III перекрыша без пит.]
    - `5` - [II поездное]
    - `6` - [I отпуск и зарядка]
    **/
    enum class R395 : unsigned short {
      /**
      #### Тормоз поезда
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Тормоз поезда
      ### [VI экстренное торм.]
      **/
      ST_0 = 0,

      /**
      #### Тормоз поезда
      ### [V торможение]
      **/
      ST_1 = 1,

      /**
      #### Тормоз поезда
      ### [Vэ торможение ЭПТ]
      **/
      ST_2 = 2,

      /**
      #### Тормоз поезда
      ### [IV перекрыша с пит.]
      **/
      ST_3 = 3,

      /**
      #### Тормоз поезда
      ### [III перекрыша без пит.]
      **/
      ST_4 = 4,

      /**
      #### Тормоз поезда
      ### [II поездное]
      **/
      ST_5 = 5,

      /**
      #### Тормоз поезда
      ### [I отпуск и зарядка]
      **/
      ST_6 = 6,
    };
  
    /**
    #### Состояния переключателя
    ### Тормоз локомотива
    Name: `R254`
    Default: `0`
    States:
    - `0` - [Торможение 4]
    - `1` - [Торможение 3]
    - `2` - [Торможение 2]
    - `3` - [Торможение 1]
    - `4` - [Поездное]
    - `5` - [Буфер]
    **/
    enum class R254 : unsigned short {
      /**
      #### Тормоз локомотива
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Тормоз локомотива
      ### [Торможение 4]
      **/
      ST_0 = 0,

      /**
      #### Тормоз локомотива
      ### [Торможение 3]
      **/
      ST_1 = 1,

      /**
      #### Тормоз локомотива
      ### [Торможение 2]
      **/
      ST_2 = 2,

      /**
      #### Тормоз локомотива
      ### [Торможение 1]
      **/
      ST_3 = 3,

      /**
      #### Тормоз локомотива
      ### [Поездное]
      **/
      ST_4 = 4,

      /**
      #### Тормоз локомотива
      ### [Буфер]
      **/
      ST_5 = 5,
    };
  
    /**
    #### Состояния переключателя
    ### Реверс
    Name: `REV`
    Default: `1`
    States:
    - `0` - [Назад]
    - `1` - [Нейтральный]
    - `2` - [Вперёд]
    **/
    enum class REV : unsigned short {
      /**
      #### Реверс
      ### Исходное состояние
      **/
      DEFAULT = 1,

      /**
      #### Реверс
      ### [Назад]
      **/
      ST_0 = 0,

      /**
      #### Реверс
      ### [Нейтральный]
      **/
      ST_1 = 1,

      /**
      #### Реверс
      ### [Вперёд]
      **/
      ST_2 = 2,
    };
  
    /**
    #### Состояния переключателя
    ### Контроллер
    Name: `KONT`
    Default: `7`
    States:
    - `0` - [торм.6]
    - `1` - [торм.5]
    - `2` - [торм.4]
    - `3` - [торм.3]
    - `4` - [торм.2]
    - `5` - [торм.1]
    - `6` - [П]
    - `7` - [0]
    - `8` - [1]
    - `9` - [2]
    - `10` - [3]
    - `11` - [4]
    - `12` - [5]
    - `13` - [6]
    - `14` - [7]
    - `15` - [8]
    - `16` - [9]
    - `17` - [10]
    - `18` - [11]
    - `19` - [12]
    - `20` - [13]
    - `21` - [14]
    - `22` - [15]
    **/
    enum class KONT : unsigned short {
      /**
      #### Контроллер
      ### Исходное состояние
      **/
      DEFAULT = 7,

      /**
      #### Контроллер
      ### [торм.6]
      **/
      ST_0 = 0,

      /**
      #### Контроллер
      ### [торм.5]
      **/
      ST_1 = 1,

      /**
      #### Контроллер
      ### [торм.4]
      **/
      ST_2 = 2,

      /**
      #### Контроллер
      ### [торм.3]
      **/
      ST_3 = 3,

      /**
      #### Контроллер
      ### [торм.2]
      **/
      ST_4 = 4,

      /**
      #### Контроллер
      ### [торм.1]
      **/
      ST_5 = 5,

      /**
      #### Контроллер
      ### [П]
      **/
      ST_6 = 6,

      /**
      #### Контроллер
      ### [0]
      **/
      ST_7 = 7,

      /**
      #### Контроллер
      ### [1]
      **/
      ST_8 = 8,

      /**
      #### Контроллер
      ### [2]
      **/
      ST_9 = 9,

      /**
      #### Контроллер
      ### [3]
      **/
      ST_10 = 10,

      /**
      #### Контроллер
      ### [4]
      **/
      ST_11 = 11,

      /**
      #### Контроллер
      ### [5]
      **/
      ST_12 = 12,

      /**
      #### Контроллер
      ### [6]
      **/
      ST_13 = 13,

      /**
      #### Контроллер
      ### [7]
      **/
      ST_14 = 14,

      /**
      #### Контроллер
      ### [8]
      **/
      ST_15 = 15,

      /**
      #### Контроллер
      ### [9]
      **/
      ST_16 = 16,

      /**
      #### Контроллер
      ### [10]
      **/
      ST_17 = 17,

      /**
      #### Контроллер
      ### [11]
      **/
      ST_18 = 18,

      /**
      #### Контроллер
      ### [12]
      **/
      ST_19 = 19,

      /**
      #### Контроллер
      ### [13]
      **/
      ST_20 = 20,

      /**
      #### Контроллер
      ### [14]
      **/
      ST_21 = 21,

      /**
      #### Контроллер
      ### [15]
      **/
      ST_22 = 22,
    };
  
    /**
    #### Состояния переключателя
    ### Задатчик тормозного усилия ЭДТ
    Name: `ZAD`
    Default: `11`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    - `2` - UNNAMED
    - `3` - UNNAMED
    - `4` - UNNAMED
    - `5` - UNNAMED
    - `6` - UNNAMED
    - `7` - UNNAMED
    - `8` - UNNAMED
    - `9` - UNNAMED
    - `10` - UNNAMED
    - `11` - UNNAMED
    **/
    enum class ZAD : unsigned short {
      /**
      #### Задатчик тормозного усилия ЭДТ
      ### Исходное состояние
      **/
      DEFAULT = 11,

      /**
      #### Задатчик тормозного усилия ЭДТ
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Задатчик тормозного усилия ЭДТ
      ### UNNAMED
      **/
      ST_1 = 1,

      /**
      #### Задатчик тормозного усилия ЭДТ
      ### UNNAMED
      **/
      ST_2 = 2,

      /**
      #### Задатчик тормозного усилия ЭДТ
      ### UNNAMED
      **/
      ST_3 = 3,

      /**
      #### Задатчик тормозного усилия ЭДТ
      ### UNNAMED
      **/
      ST_4 = 4,

      /**
      #### Задатчик тормозного усилия ЭДТ
      ### UNNAMED
      **/
      ST_5 = 5,

      /**
      #### Задатчик тормозного усилия ЭДТ
      ### UNNAMED
      **/
      ST_6 = 6,

      /**
      #### Задатчик тормозного усилия ЭДТ
      ### UNNAMED
      **/
      ST_7 = 7,

      /**
      #### Задатчик тормозного усилия ЭДТ
      ### UNNAMED
      **/
      ST_8 = 8,

      /**
      #### Задатчик тормозного усилия ЭДТ
      ### UNNAMED
      **/
      ST_9 = 9,

      /**
      #### Задатчик тормозного усилия ЭДТ
      ### UNNAMED
      **/
      ST_10 = 10,

      /**
      #### Задатчик тормозного усилия ЭДТ
      ### UNNAMED
      **/
      ST_11 = 11,
    };
  
    /**
    #### Состояния переключателя
    ### Блокировка тормозов усл. 367
    Name: `R367`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class R367 : unsigned short {
      /**
      #### Блокировка тормозов усл. 367
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Блокировка тормозов усл. 367
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Блокировка тормозов усл. 367
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Редуктор зарядного давления
    Name: `RED`
    Default: `12`
    States:
    - `0` - [4.0]
    - `1` - [4.1]
    - `2` - [4.2]
    - `3` - [4.3]
    - `4` - [4.4]
    - `5` - [4.5]
    - `6` - [4.6]
    - `7` - [4.7]
    - `8` - [4.8]
    - `9` - [4.9]
    - `10` - [5.0]
    - `11` - [5.1]
    - `12` - [5.2]
    - `13` - [5.3]
    - `14` - [5.4]
    - `15` - [5.5]
    - `16` - [5.6]
    - `17` - [5.7]
    - `18` - [5.8]
    - `19` - [5.9]
    **/
    enum class RED : unsigned short {
      /**
      #### Редуктор зарядного давления
      ### Исходное состояние
      **/
      DEFAULT = 12,

      /**
      #### Редуктор зарядного давления
      ### [4.0]
      **/
      ST_0 = 0,

      /**
      #### Редуктор зарядного давления
      ### [4.1]
      **/
      ST_1 = 1,

      /**
      #### Редуктор зарядного давления
      ### [4.2]
      **/
      ST_2 = 2,

      /**
      #### Редуктор зарядного давления
      ### [4.3]
      **/
      ST_3 = 3,

      /**
      #### Редуктор зарядного давления
      ### [4.4]
      **/
      ST_4 = 4,

      /**
      #### Редуктор зарядного давления
      ### [4.5]
      **/
      ST_5 = 5,

      /**
      #### Редуктор зарядного давления
      ### [4.6]
      **/
      ST_6 = 6,

      /**
      #### Редуктор зарядного давления
      ### [4.7]
      **/
      ST_7 = 7,

      /**
      #### Редуктор зарядного давления
      ### [4.8]
      **/
      ST_8 = 8,

      /**
      #### Редуктор зарядного давления
      ### [4.9]
      **/
      ST_9 = 9,

      /**
      #### Редуктор зарядного давления
      ### [5.0]
      **/
      ST_10 = 10,

      /**
      #### Редуктор зарядного давления
      ### [5.1]
      **/
      ST_11 = 11,

      /**
      #### Редуктор зарядного давления
      ### [5.2]
      **/
      ST_12 = 12,

      /**
      #### Редуктор зарядного давления
      ### [5.3]
      **/
      ST_13 = 13,

      /**
      #### Редуктор зарядного давления
      ### [5.4]
      **/
      ST_14 = 14,

      /**
      #### Редуктор зарядного давления
      ### [5.5]
      **/
      ST_15 = 15,

      /**
      #### Редуктор зарядного давления
      ### [5.6]
      **/
      ST_16 = 16,

      /**
      #### Редуктор зарядного давления
      ### [5.7]
      **/
      ST_17 = 17,

      /**
      #### Редуктор зарядного давления
      ### [5.8]
      **/
      ST_18 = 18,

      /**
      #### Редуктор зарядного давления
      ### [5.9]
      **/
      ST_19 = 19,
    };
  
    /**
    #### Состояния переключателя
    ### Ключ ЭПК
    Name: `EPK`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class EPK : unsigned short {
      /**
      #### Ключ ЭПК
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Ключ ЭПК
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Ключ ЭПК
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Прожектор яркий
    Name: `AZV1`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZV1 : unsigned short {
      /**
      #### Прожектор яркий
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Прожектор яркий
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Прожектор яркий
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Прожектор тускло
    Name: `AZV2`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZV2 : unsigned short {
      /**
      #### Прожектор тускло
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Прожектор тускло
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Прожектор тускло
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Питание ЭПТ
    Name: `AZV3`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZV3 : unsigned short {
      /**
      #### Питание ЭПТ
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Питание ЭПТ
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Питание ЭПТ
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### ЭПТ
    Name: `AZV4`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZV4 : unsigned short {
      /**
      #### ЭПТ
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### ЭПТ
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### ЭПТ
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Электрический тормоз
    Name: `AZV5`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZV5 : unsigned short {
      /**
      #### Электрический тормоз
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Электрический тормоз
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Электрический тормоз
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Топливный насос ведомого тепловоза
    Name: `AZV6`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZV6 : unsigned short {
      /**
      #### Топливный насос ведомого тепловоза
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Топливный насос ведомого тепловоза
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Топливный насос ведомого тепловоза
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Топливный насос ведущего тепловоза
    Name: `AZV7`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZV7 : unsigned short {
      /**
      #### Топливный насос ведущего тепловоза
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Топливный насос ведущего тепловоза
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Топливный насос ведущего тепловоза
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Управление тепловозом
    Name: `AZV8`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZV8 : unsigned short {
      /**
      #### Управление тепловозом
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Управление тепловозом
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Управление тепловозом
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Управление общее
    Name: `AZV9`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZV9 : unsigned short {
      /**
      #### Управление общее
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Управление общее
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Управление общее
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Освещение пульта
    Name: `AZV10`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZV10 : unsigned short {
      /**
      #### Освещение пульта
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Освещение пульта
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Освещение пульта
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Освещение кабины
    Name: `AZV011`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZV011 : unsigned short {
      /**
      #### Освещение кабины
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Освещение кабины
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Освещение кабины
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Вентиляция
    Name: `AZV12`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZV12 : unsigned short {
      /**
      #### Вентиляция
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Вентиляция
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Вентиляция
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Жалюзи масло
    Name: `TB1`
    Default: `0`
    States:
    - `0` - [Автомат]
    - `1` - [Ручное]
    **/
    enum class TB1 : unsigned short {
      /**
      #### Жалюзи масло
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Жалюзи масло
      ### [Автомат]
      **/
      ST_0 = 0,

      /**
      #### Жалюзи масло
      ### [Ручное]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Жалюзи вода
    Name: `TB2`
    Default: `0`
    States:
    - `0` - [Автомат]
    - `1` - [Ручное]
    **/
    enum class TB2 : unsigned short {
      /**
      #### Жалюзи вода
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Жалюзи вода
      ### [Автомат]
      **/
      ST_0 = 0,

      /**
      #### Жалюзи вода
      ### [Ручное]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### ОП II ступень
    Name: `TB3`
    Default: `0`
    States:
    - `0` - [Автомат]
    - `1` - [Ручное]
    **/
    enum class TB3 : unsigned short {
      /**
      #### ОП II ступень
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### ОП II ступень
      ### [Автомат]
      **/
      ST_0 = 0,

      /**
      #### ОП II ступень
      ### [Ручное]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### ОП I ступень
    Name: `TB4`
    Default: `0`
    States:
    - `0` - [Автомат]
    - `1` - [Ручное]
    **/
    enum class TB4 : unsigned short {
      /**
      #### ОП I ступень
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### ОП I ступень
      ### [Автомат]
      **/
      ST_0 = 0,

      /**
      #### ОП I ступень
      ### [Ручное]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Освещение приборов
    Name: `TB5`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class TB5 : unsigned short {
      /**
      #### Освещение приборов
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Освещение приборов
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Освещение приборов
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Освещение кабины
    Name: `TB6`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class TB6 : unsigned short {
      /**
      #### Освещение кабины
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Освещение кабины
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Освещение кабины
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Освещение расписания
    Name: `TB7`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class TB7 : unsigned short {
      /**
      #### Освещение расписания
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Освещение расписания
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Освещение расписания
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Электрикалорифер
    Name: `TB8`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class TB8 : unsigned short {
      /**
      #### Электрикалорифер
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Электрикалорифер
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Электрикалорифер
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Радиостанция
    Name: `TB10`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class TB10 : unsigned short {
      /**
      #### Радиостанция
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Радиостанция
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Радиостанция
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Манометры и термометры
    Name: `TB011`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class TB011 : unsigned short {
      /**
      #### Манометры и термометры
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Манометры и термометры
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Манометры и термометры
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### АЛСН
    Name: `TB12`
    Default: `1`
    States:
    - `0` - [Без АЛС]
    - `1` - [АЛС]
    **/
    enum class TB12 : unsigned short {
      /**
      #### АЛСН
      ### Исходное состояние
      **/
      DEFAULT = 1,

      /**
      #### АЛСН
      ### [Без АЛС]
      **/
      ST_0 = 0,

      /**
      #### АЛСН
      ### [АЛС]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Частота АСЛН
    Name: `TB13`
    Default: `0`
    States:
    - `0` - [25 Гц]
    - `1` - [50 Гц]
    **/
    enum class TB13 : unsigned short {
      /**
      #### Частота АСЛН
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Частота АСЛН
      ### [25 Гц]
      **/
      ST_0 = 0,

      /**
      #### Частота АСЛН
      ### [50 Гц]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Омыв окон
    Name: `TB14`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class TB14 : unsigned short {
      /**
      #### Омыв окон
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Омыв окон
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Омыв окон
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Стеклоочиститель
    Name: `TB15`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class TB15 : unsigned short {
      /**
      #### Стеклоочиститель
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Стеклоочиститель
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Стеклоочиститель
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Вызов помощника
    Name: `BTN4`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class BTN4 : unsigned short {
      /**
      #### Вызов помощника
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Вызов помощника
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Вызов помощника
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Отпуск тормозов локомотива
    Name: `BTN5`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class BTN5 : unsigned short {
      /**
      #### Отпуск тормозов локомотива
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Отпуск тормозов локомотива
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Отпуск тормозов локомотива
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Свисток
    Name: `BTN1`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class BTN1 : unsigned short {
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
    Name: `BTN2`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class BTN2 : unsigned short {
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
    Name: `BTN3`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class BTN3 : unsigned short {
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
    ### Рукоятка бдительности
    Name: `RB`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class RB : unsigned short {
      /**
      #### Рукоятка бдительности
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Рукоятка бдительности
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Рукоятка бдительности
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Пуск дизеля ведущего тепловоза
    Name: `BTN8`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class BTN8 : unsigned short {
      /**
      #### Пуск дизеля ведущего тепловоза
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Пуск дизеля ведущего тепловоза
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Пуск дизеля ведущего тепловоза
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Пуск дизеля ведомого тепловоза
    Name: `BTN7`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class BTN7 : unsigned short {
      /**
      #### Пуск дизеля ведомого тепловоза
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Пуск дизеля ведомого тепловоза
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Пуск дизеля ведомого тепловоза
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Проверка ЭТ
    Name: `BTN9`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class BTN9 : unsigned short {
      /**
      #### Проверка ЭТ
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Проверка ЭТ
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Проверка ЭТ
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### ВК
    Name: `BTN10`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class BTN10 : unsigned short {
      /**
      #### ВК
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### ВК
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### ВК
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Проверка АЛСН
    Name: `BTN011`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class BTN011 : unsigned short {
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
    ### Левый БФ
    Name: `TBP7`
    Default: `1`
    States:
    - `0` - [Красный]
    - `1` - [Выкл.]
    - `2` - [Белый]
    **/
    enum class TBP7 : unsigned short {
      /**
      #### Левый БФ
      ### Исходное состояние
      **/
      DEFAULT = 1,

      /**
      #### Левый БФ
      ### [Красный]
      **/
      ST_0 = 0,

      /**
      #### Левый БФ
      ### [Выкл.]
      **/
      ST_1 = 1,

      /**
      #### Левый БФ
      ### [Белый]
      **/
      ST_2 = 2,
    };
  
    /**
    #### Состояния переключателя
    ### Правый БФ
    Name: `TBP6`
    Default: `1`
    States:
    - `0` - [Красный]
    - `1` - [Выкл.]
    - `2` - [Белый]
    **/
    enum class TBP6 : unsigned short {
      /**
      #### Правый БФ
      ### Исходное состояние
      **/
      DEFAULT = 1,

      /**
      #### Правый БФ
      ### [Красный]
      **/
      ST_0 = 0,

      /**
      #### Правый БФ
      ### [Выкл.]
      **/
      ST_1 = 1,

      /**
      #### Правый БФ
      ### [Белый]
      **/
      ST_2 = 2,
    };
  
    /**
    #### Состояния переключателя
    ### Номерные знаки
    Name: `TBP5`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class TBP5 : unsigned short {
      /**
      #### Номерные знаки
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Номерные знаки
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Номерные знаки
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Освещение пульта
    Name: `TBP4`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class TBP4 : unsigned short {
      /**
      #### Освещение пульта
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Освещение пульта
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Освещение пульта
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Освещение резервное
    Name: `TBP3`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class TBP3 : unsigned short {
      /**
      #### Освещение резервное
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Освещение резервное
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Освещение резервное
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Калориферы
    Name: `TBP2`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class TBP2 : unsigned short {
      /**
      #### Калориферы
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Калориферы
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Калориферы
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Вентиляторы
    Name: `TBP1`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class TBP1 : unsigned short {
      /**
      #### Вентиляторы
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Вентиляторы
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Вентиляторы
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Вольтметр
    Name: `TBP8`
    Default: `1`
    States:
    - `0` - [ЭПТ]
    - `1` - [Батарея]
    **/
    enum class TBP8 : unsigned short {
      /**
      #### Вольтметр
      ### Исходное состояние
      **/
      DEFAULT = 1,

      /**
      #### Вольтметр
      ### [ЭПТ]
      **/
      ST_0 = 0,

      /**
      #### Вольтметр
      ### [Батарея]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Тифон
    Name: `BTNP2`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class BTNP2 : unsigned short {
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
    ### Свисток
    Name: `BTNP1`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class BTNP1 : unsigned short {
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
    ### Комбинированный кран усл. 103
    Name: `KK`
    Default: `1`
    States:
    - `0` - [Двойная тяга]
    - `1` - [Нормальное]
    - `2` - [Экстренное]
    **/
    enum class KK : unsigned short {
      /**
      #### Комбинированный кран усл. 103
      ### Исходное состояние
      **/
      DEFAULT = 1,

      /**
      #### Комбинированный кран усл. 103
      ### [Двойная тяга]
      **/
      ST_0 = 0,

      /**
      #### Комбинированный кран усл. 103
      ### [Нормальное]
      **/
      ST_1 = 1,

      /**
      #### Комбинированный кран усл. 103
      ### [Экстренное]
      **/
      ST_2 = 2,
    };
  
    /**
    #### Состояния переключателя
    ### Маневры
    Name: `BTN12`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class BTN12 : unsigned short {
      /**
      #### Маневры
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Маневры
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Маневры
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Свисток
    Name: `BTN13`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class BTN13 : unsigned short {
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
    ### РБС
    Name: `RBS`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class RBS : unsigned short {
      /**
      #### РБС
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### РБС
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### РБС
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### РБП
    Name: `RBP`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class RBP : unsigned short {
      /**
      #### РБП
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### РБП
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### РБП
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Вызов ДСП
    Name: `DSP`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class DSP : unsigned short {
      /**
      #### Вызов ДСП
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Вызов ДСП
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Вызов ДСП
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Вызов ДНЦ
    Name: `DNC`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class DNC : unsigned short {
      /**
      #### Вызов ДНЦ
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Вызов ДНЦ
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Вызов ДНЦ
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Подсветка
    Name: `PODSV`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class PODSV : unsigned short {
      /**
      #### Подсветка
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Подсветка
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Подсветка
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Питание радиостанции
    Name: `PIT`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class PIT : unsigned short {
      /**
      #### Питание радиостанции
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Питание радиостанции
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Питание радиостанции
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Ручной тормоз
    Name: `RT`
    Default: `0`
    States:
    - `0` - [Закручен]
    - `1` - [75%]
    - `2` - [50%]
    - `3` - [25%]
    - `4` - [Откручен]
    **/
    enum class RT : unsigned short {
      /**
      #### Ручной тормоз
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Ручной тормоз
      ### [Закручен]
      **/
      ST_0 = 0,

      /**
      #### Ручной тормоз
      ### [75%]
      **/
      ST_1 = 1,

      /**
      #### Ручной тормоз
      ### [50%]
      **/
      ST_2 = 2,

      /**
      #### Ручной тормоз
      ### [25%]
      **/
      ST_3 = 3,

      /**
      #### Ручной тормоз
      ### [Откручен]
      **/
      ST_4 = 4,
    };
  
    /**
    #### Состояния переключателя
    ### Завод часов
    Name: `SLZAVOD`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class SLZAVOD : unsigned short {
      /**
      #### Завод часов
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Завод часов
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Завод часов
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### UNNAMED
    Name: `STOR_1`
    Default: `1`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class STOR_1 : unsigned short {
      /**
      #### UNNAMED
      ### Исходное состояние
      **/
      DEFAULT = 1,

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
    Name: `STOR_2`
    Default: `1`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class STOR_2 : unsigned short {
      /**
      #### UNNAMED
      ### Исходное состояние
      **/
      DEFAULT = 1,

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
    Name: `STOR_3`
    Default: `1`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class STOR_3 : unsigned short {
      /**
      #### UNNAMED
      ### Исходное состояние
      **/
      DEFAULT = 1,

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
    Name: `STOR_11`
    Default: `1`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class STOR_11 : unsigned short {
      /**
      #### UNNAMED
      ### Исходное состояние
      **/
      DEFAULT = 1,

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
    Name: `STOR_22`
    Default: `1`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class STOR_22 : unsigned short {
      /**
      #### UNNAMED
      ### Исходное состояние
      **/
      DEFAULT = 1,

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
    Name: `STOR_33`
    Default: `1`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class STOR_33 : unsigned short {
      /**
      #### UNNAMED
      ### Исходное состояние
      **/
      DEFAULT = 1,

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
    ### Шкаф
    Name: `DOOR_F`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class DOOR_F : unsigned short {
      /**
      #### Шкаф
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Шкаф
      ### UNNAMED
      **/
      ST_0 = 0,

      /**
      #### Шкаф
      ### UNNAMED
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Переключение кабины
    Name: `RC1`
    Default: `0`
    States:
    - `0` - [Кабина 1]
    - `1` - [Кабина 2]
    **/
    enum class RC1 : unsigned short {
      /**
      #### Переключение кабины
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Переключение кабины
      ### [Кабина 1]
      **/
      ST_0 = 0,

      /**
      #### Переключение кабины
      ### [Кабина 2]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Переключение кабины
    Name: `RC2`
    Default: `0`
    States:
    - `0` - [Кабина 1]
    - `1` - [Кабина 2]
    **/
    enum class RC2 : unsigned short {
      /**
      #### Переключение кабины
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Переключение кабины
      ### [Кабина 1]
      **/
      ST_0 = 0,

      /**
      #### Переключение кабины
      ### [Кабина 2]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Питание топливного насоса
    Name: `TBM6`
    Default: `1`
    States:
    - `0` - [2 Тепловоза]
    - `1` - [2 Тепловоза]
    **/
    enum class TBM6 : unsigned short {
      /**
      #### Питание топливного насоса
      ### Исходное состояние
      **/
      DEFAULT = 1,

      /**
      #### Питание топливного насоса
      ### [2 Тепловоза]
      **/
      ST_0 = 0,

      /**
      #### Питание топливного насоса
      ### [2 Тепловоза]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Отключение 1 ТЭД
    Name: `OM1`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class OM1 : unsigned short {
      /**
      #### Отключение 1 ТЭД
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Отключение 1 ТЭД
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Отключение 1 ТЭД
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Отключение 2 ТЭД
    Name: `OM2`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class OM2 : unsigned short {
      /**
      #### Отключение 2 ТЭД
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Отключение 2 ТЭД
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Отключение 2 ТЭД
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Отключение 3 ТЭД
    Name: `OM3`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class OM3 : unsigned short {
      /**
      #### Отключение 3 ТЭД
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Отключение 3 ТЭД
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Отключение 3 ТЭД
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Отключение 4 ТЭД
    Name: `OM4`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class OM4 : unsigned short {
      /**
      #### Отключение 4 ТЭД
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Отключение 4 ТЭД
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Отключение 4 ТЭД
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Отключение 5 ТЭД
    Name: `OM5`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class OM5 : unsigned short {
      /**
      #### Отключение 5 ТЭД
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Отключение 5 ТЭД
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Отключение 5 ТЭД
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Отключение 6 ТЭД
    Name: `OM6`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class OM6 : unsigned short {
      /**
      #### Отключение 6 ТЭД
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Отключение 6 ТЭД
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Отключение 6 ТЭД
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### АЗВ освещение дизельного
    Name: `AZVM1`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZVM1 : unsigned short {
      /**
      #### АЗВ освещение дизельного
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### АЗВ освещение дизельного
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### АЗВ освещение дизельного
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### АЗВ резервное освещение дизельного
    Name: `AZVM2`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZVM2 : unsigned short {
      /**
      #### АЗВ резервное освещение дизельного
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### АЗВ резервное освещение дизельного
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### АЗВ резервное освещение дизельного
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### АЗВ освещение подкузовное
    Name: `AZVM3`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZVM3 : unsigned short {
      /**
      #### АЗВ освещение подкузовное
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### АЗВ освещение подкузовное
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### АЗВ освещение подкузовное
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### АЗВ освещение ВВК
    Name: `AZVM4`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZVM4 : unsigned short {
      /**
      #### АЗВ освещение ВВК
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### АЗВ освещение ВВК
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### АЗВ освещение ВВК
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### АЗВ питание розеток
    Name: `AZVM5`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZVM5 : unsigned short {
      /**
      #### АЗВ питание розеток
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### АЗВ питание розеток
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### АЗВ питание розеток
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### АЗВ питание автостопа
    Name: `AZVM6`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZVM6 : unsigned short {
      /**
      #### АЗВ питание автостопа
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### АЗВ питание автостопа
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### АЗВ питание автостопа
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### АЗВ питание автостопа
    Name: `AZVM7`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZVM7 : unsigned short {
      /**
      #### АЗВ питание автостопа
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### АЗВ питание автостопа
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### АЗВ питание автостопа
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### АЗВ пожарная сигнализация
    Name: `AZVM8`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZVM8 : unsigned short {
      /**
      #### АЗВ пожарная сигнализация
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### АЗВ пожарная сигнализация
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### АЗВ пожарная сигнализация
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### АЗВ буферные фонари
    Name: `AZVM9`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZVM9 : unsigned short {
      /**
      #### АЗВ буферные фонари
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### АЗВ буферные фонари
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### АЗВ буферные фонари
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### АЗВ питание розеток
    Name: `AZVM10`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZVM10 : unsigned short {
      /**
      #### АЗВ питание розеток
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### АЗВ питание розеток
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### АЗВ питание розеток
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### АЗВ вспомогательные цепи
    Name: `AZVM11`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZVM11 : unsigned short {
      /**
      #### АЗВ вспомогательные цепи
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### АЗВ вспомогательные цепи
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### АЗВ вспомогательные цепи
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### АЗВ компрессор
    Name: `AZVM12`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZVM12 : unsigned short {
      /**
      #### АЗВ компрессор
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### АЗВ компрессор
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### АЗВ компрессор
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### АЗВ топливный насос
    Name: `AZVM13`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZVM13 : unsigned short {
      /**
      #### АЗВ топливный насос
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### АЗВ топливный насос
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### АЗВ топливный насос
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### АЗВ калорифер
    Name: `AZVM14`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class AZVM14 : unsigned short {
      /**
      #### АЗВ калорифер
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### АЗВ калорифер
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### АЗВ калорифер
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Резервное питание насоса
    Name: `TBM1`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class TBM1 : unsigned short {
      /**
      #### Резервное питание насоса
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Резервное питание насоса
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Резервное питание насоса
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Автостоп
    Name: `TBM2`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class TBM2 : unsigned short {
      /**
      #### Автостоп
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Автостоп
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Автостоп
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Шунтировка
    Name: `TBM3`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class TBM3 : unsigned short {
      /**
      #### Шунтировка
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Шунтировка
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Шунтировка
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Электродинамический тормоз
    Name: `TBM4`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class TBM4 : unsigned short {
      /**
      #### Электродинамический тормоз
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Электродинамический тормоз
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Электродинамический тормоз
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Ручная прокачка масла
    Name: `TBM5`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class TBM5 : unsigned short {
      /**
      #### Ручная прокачка масла
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Ручная прокачка масла
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Ручная прокачка масла
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Батарея 1
    Name: `RUB_AB1`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class RUB_AB1 : unsigned short {
      /**
      #### Батарея 1
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Батарея 1
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Батарея 1
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### Батарея 2
    Name: `RUB_AB2`
    Default: `0`
    States:
    - `0` - [Выкл.]
    - `1` - [Вкл.]
    **/
    enum class RUB_AB2 : unsigned short {
      /**
      #### Батарея 2
      ### Исходное состояние
      **/
      DEFAULT = 0,

      /**
      #### Батарея 2
      ### [Выкл.]
      **/
      ST_0 = 0,

      /**
      #### Батарея 2
      ### [Вкл.]
      **/
      ST_1 = 1,
    };
  
    /**
    #### Состояния переключателя
    ### UNNAMED
    Name: `KR1`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class KR1 : unsigned short {
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
    Name: `KR2`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class KR2 : unsigned short {
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
    Name: `KR3`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class KR3 : unsigned short {
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
    Name: `KR4`
    Default: `0`
    States:
    - `0` - UNNAMED
    - `1` - UNNAMED
    **/
    enum class KR4 : unsigned short {
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
  
  };
  



  /**
    ## Источники света
   **/
  enum class lights : unsigned short {
    
    /**
    #### Источник света
    ### LCAB
    **/
    LCAB_0 = 0,

    /**
    #### Источник света
    ### LCAB
    **/
    LCAB_1 = 1,

    /**
    #### Источник света
    ### Lamp1P1
    **/
    Lamp1P1_2 = 2,

    /**
    #### Источник света
    ### Lamp1P2
    **/
    Lamp1P2_3 = 3,

    /**
    #### Источник света
    ### LCAB1
    **/
    LCAB1_4 = 4,

    /**
    #### Источник света
    ### LCAB1
    **/
    LCAB1_5 = 5,

    /**
    #### Источник света
    ### Lamp2P1
    **/
    Lamp2P1_6 = 6,

    /**
    #### Источник света
    ### Lamp2P2
    **/
    Lamp2P2_7 = 7,

    /**
    #### Источник света
    ### SVET
    **/
    SVET_8 = 8,

    /**
    #### Источник света
    ### LampM2
    **/
    LampM2_9 = 9,

    /**
    #### Источник света
    ### LampM3
    **/
    LampM3_10 = 10,

    /**
    #### Источник света
    ### LampM4
    **/
    LampM4_11 = 11,

    /**
    #### Источник света
    ### LampM5
    **/
    LampM5_12 = 12,

    /**
    #### Источник света
    ### LampM6
    **/
    LampM6_13 = 13,

    /**
    #### Источник света
    ### LampM7
    **/
    LampM7_14 = 14,

    /**
    #### Источник света
    ### Lamp1P3
    **/
    Lamp1P3_15 = 15,

    /**
    #### Источник света
    ### Lamp1P4
    **/
    Lamp1P4_16 = 16,

    /**
    #### Источник света
    ### Lamp2P3
    **/
    Lamp2P3_17 = 17,

    /**
    #### Источник света
    ### Lamp2P4
    **/
    Lamp2P4_18 = 18,

  };

  /**
    ## Анимации
   **/
  enum class anims : unsigned short {
  
      /**
      #### Анимация
      ### WIPERS_R
      **/
      WIPERS_R_0 = 0,

      /**
      #### Анимация
      ### WIPERS_L
      **/
      WIPERS_L_1 = 1,

      /**
      #### Анимация
      ### WIPERS_R1
      **/
      WIPERS_R1_2 = 2,

      /**
      #### Анимация
      ### WIPERS_L1
      **/
      WIPERS_L1_3 = 3,

  };
};

  