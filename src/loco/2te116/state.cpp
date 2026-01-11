#include <iostream>
#include <state.hpp>

State::State()
{}

State* State::set_dizel_start_time(int DST)
{
  this->var[0] = (float)(DST);
  return  this;
}

State* State::set_dizel_oil_time(float DOT)
{
  this->var[1] = DOT;
  return  this;
}

State* State::set_power(bool Power)
{
  this->var[2] = (float)(Power);
  return  this;
}

State* State::set_var(float* var)
{
  this->var = var + baseoffset + addoffset;
  return  this;
}

int State::get_dizel_start_time()
{
    return (int)this->var[0];
}

float State::get_dizel_oil_time()
{
    return this->var[1];
}

bool State::get_power()
{
    return  (bool)this->var[2];
}
