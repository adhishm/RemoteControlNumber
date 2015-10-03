/* 
 * File:   Counter.cpp
 * Author: adhish
 * 
 * Created on October 3, 2015, 6:19 PM
 */

#include "Counter.h"

Counter::Counter() {
    _value = 0;
}

Counter::Counter(const Counter& orig) {
    _value = orig.GetValue();
}

Counter::~Counter() {
}

int Counter::GetValue() const
{
    return _value;
}

void Counter::Increment()
{
    ++_value;
}

void Counter::Decrement()
{
    --_value;
}

void Counter::Reset()
{
    _value = 0;
}

void Counter::ShowValue() const
{
    std::cout << _value << std::endl;
}
