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
    Counter(int v);
    Counter(const Counter& orig);
    
    /**
     * VTK style static constructor.
     * @return Pointer to newly created instance.
     */
    static Counter* New()
    {
        return new Counter();
    }
    
    /**
     * VTK style static constructor with input value.
     * @param v Value to be set.
     * @return Pointer to newly created instance.
     */
    static Counter* New(int v)
    {
        return new Counter(v);
    }
    
    /**
     * Getter.
     * @return The value of the counter. 
     */
    int GetValue() const;
    
    /**
     * Increment the value of the counter by one.
     */
    void Increment();
    
    /**
     * Decrease the value of the counter by one.
     */
    void Decrement();
    
    /**
     * Reset the counter to zero.
     */
    void Reset();
    
    /**
     * Display the value.
     */
    void ShowValue() const;
    
    virtual ~Counter();
private:
    int _value;
};

#endif	/* COUNTER_H */

