
class State
{
public:
    State();

private:
    float* var;
    const size_t baseoffset = 10;
    const size_t addoffset = 5;


public:
    State* set_dizel_start_time(int DST);
    State* set_dizel_oil_time(float DOT);
    State* set_power(bool Power);
    State* set_var(float* var);

    int get_dizel_start_time();
    float get_dizel_oil_time();
    bool get_power();
};
