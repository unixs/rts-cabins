#include <state.hpp>

Tep70Context::Tep70Context() : Context()
{
  this->_state = new Tep70State;
  ;
}

Tep70Context::~Tep70Context()
{ // BUG: mem leak
  delete this->_state->svistok_timer;
}

Tep70State *
Tep70Context::state()
{
  return this->_state;
}
