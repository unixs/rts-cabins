//---------------------------------------------------------------------------

#include <common.h>
#include <main_loop.h>
#include <ts.h>
#include <uv.h>

#undef __APPLE__
#define MRB_USE_ETEXT_RO_DATA_P
#include <mruby.h>
#include <mruby/dump.h>

#define MAIN_LOOP_DELAY 0.3

#define CABIN_MOD_NAME "Cabin"
#define CABIN_SWITCHED_METHOD_NAME "switched"

static uv_timer_t timer;
static MainLoop *main_loop;
// static uv_loop_t *main_loop ;
static mrb_state *mrb;

static mrb_sym cabin_mod_sym;
static mrb_sym switched_method_sym;

static void switch_timer(uv_timer_t *timer) {
  DieselLocomotive *loco = (DieselLocomotive *)timer->data;

  loco->PostTriggerCab(24);
}

int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason,
                         void *lpReserved) {
  return TRUE;
}
//---------------------------------------------------------------------------

extern "C" __export void
Run(ElectricEngine *eng,
                             const ElectricLocomotive *loco,
                             unsigned long State, float time,
                             float AirTemperature) {

  main_loop->run(time);
}

extern "C" __export bool
CanSwitch(const ElectricLocomotive *loco,
                                   ElectricEngine *eng, unsigned int SwitchID,
                                   unsigned int setState) {
  return true;
}

extern "C" void __export
Switched(const ElectricLocomotive *loco,
                                  ElectricEngine *eng, unsigned int SwitchID,
                                  unsigned int PrevState) {



  mrb_bool cabin_is_defined = mrb_class_defined_id(mrb, cabin_mod_sym);

  if (cabin_is_defined) {
    RClass *cabin_mod = mrb_module_get_id(mrb, cabin_mod_sym);
    mrb_bool cab_respond_to_switched = mrb_obj_respond_to(mrb, cabin_mod, switched_method_sym);
    mrb_value cabin_mod_obj = mrb_class_path(mrb, cabin_mod);

    if (cab_respond_to_switched) {
      mrb_funcall_argv(mrb, cabin_mod_obj, switched_method_sym, 0, NULL);
    }
  }

  Cabin *cab = loco->Cab();

  if (cab->Switch(13) || cab->Switch(113)) {
    cab->SetDisplayState(20, 1);
    cab->SetDisplayState(120, 1);

    if (!timer.loop) {
      uv_timer_init(main_loop->get_loop(), &timer);
      timer.data = (void *)loco;
    }

    uv_timer_start(
        &timer,
        [](uv_timer_t *timer) {
          DieselLocomotive *loco = (DieselLocomotive *)timer->data;

          loco->PostTriggerCab(24);
        },
        2000, 2000);

  } else {
    cab->SetDisplayState(20, 0);
    cab->SetDisplayState(120, 0);

    if (timer.loop) {
      uv_timer_stop(&timer);
    }
  }

  loco->PostTriggerCab(24);
}

extern "C" bool __export
Init(DieselEngine *eng, DieselLocomotive *loco,
                              unsigned long State, float time,
                              float AirTemperature) {

  mrb = mrb_open();

  if (!mrb) {
    // printf("MRUBY failed. Sad day..");
    // noop
  } else {
    FILE *fp = fopen("cabin.mrb", "r");

    cabin_mod_sym = mrb_intern_str(
      mrb,
      mrb_str_new_lit(mrb, CABIN_MOD_NAME)
    );

    cab_switched_method = mrb_intern_str(
      mrb,
      mrb_str_new_lit(mrb, CABIN_SWITCHED_METHOD_NAME)
    );

    mrb_load_irep_file(mrb, fp);
    // mrb_close(mrb);
  }

  main_loop = new MainLoop(MAIN_LOOP_DELAY);
  // main_loop = (uv_loop_t *) malloc(sizeof(uv_loop_t));
  // uv_loop_init(main_loop);

  return true;
}

extern "C" void __export
ChangeLoco(Locomotive *loco, const Locomotive *Prev,
                                    unsigned long State) {}

extern "C" bool __export
CanWorkWith(const Locomotive *loco,
                                     const wchar_t *Type) {
  return false;
}
