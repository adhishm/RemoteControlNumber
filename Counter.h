/* 
 * File:   Counter.h
 * Author: adhish
 *
 * Created on October 3, 2015, 6:19 PM
 */

#ifndef COUNTER_H
#define	COUNTER_H

#include <iostream>

class Counter {
public:
    Counter();
    Counter(const Counter& orig);
    
    int GetValue() const;
    
    void Increment();
    void Decrement();
    void Reset();
    void ShowValue() const;
    
    virtual ~Counter();
private:
    int _value;
};

#endif	/* COUNTER_H */

