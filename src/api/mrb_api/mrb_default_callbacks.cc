#include <mrb_default_callbacks.hpp>

mrb_value
true_cb(struct mrb_state *mrb, mrb_value self)
{
  return mrb_true_value();
}

mrb_value
false_cb(struct mrb_state *mrb, mrb_value self)
{
  return mrb_false_value();
}

mrb_value
nil_cb(struct mrb_state *mrb, mrb_value self)
{
  return mrb_nil_value();
}
