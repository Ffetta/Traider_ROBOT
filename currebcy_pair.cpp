#include "currebcy_pair.h"

Currebcy_Pair::Currebcy_Pair()
{

}

time_t Currebcy_Pair::getTime() const
{
    return time;
}

void Currebcy_Pair::setTime(const time_t &value)
{
    time = value;
}

double Currebcy_Pair::getBay_Praice() const
{
    return bay_Praice;
}

void Currebcy_Pair::setBay_Praice(double value)
{
    bay_Praice = value;
}
