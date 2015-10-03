/* 
 * File:   SampleListener.cpp
 * Author: adhish
 *
 * Created on October 3, 2015, 6:19 PM
 */

#include "SampleListener.h"

using namespace Leap;

SampleListener::SampleListener()
    : Listener()
{
    _counter = Counter::New();
}

SampleListener::~SampleListener()
{
    if (NULL!=_counter)
    {
        delete _counter;
        _counter = NULL;
    }
}

void SampleListener::onConnect(const Controller& controller)
{
    std::cout << "Controller connected" << std::endl;
}

void SampleListener::onDisconnect(const Controller& controller)
{
    std::cout << "Controller disconnected" << std::endl;
}


void SampleListener::onFrame(const Controller& controller)
{
    _analyzeGestures(controller.frame());
}

void SampleListener::_displayFrameData(const Frame& f) const
{
    std::cout << "Frame id: " << f.id() << std:: endl
              << "Timestamp: " << f.timestamp() << std::endl
              << "Hands: " << f.hands().count() << std::endl
              << "Fingers: " << f.fingers().count() << std::endl
              << "Tools: " << f.tools().count() << std::endl
              << "Gestures: " << f.gestures().count() << std::endl;
}

void SampleListener::_analyzeGestures(const Frame& f)
{
    GestureList gestures = f.gestures();
    
    if (gestures.count() > 0)
    {
        for (GestureList::const_iterator it = gestures.begin(); it != gestures.end(); ++it)
        {
            Gesture g = *(it);
            switch (g.type())
            {
                case Gesture::TYPE_CIRCLE:
                    _analyzeCircle(g);
                    break;
                case Gesture::TYPE_KEY_TAP:
                    _analyzeKeyTap(g);
                    break;
                case Gesture::TYPE_SCREEN_TAP:
                    _analyzeScreenTap(g);
                    break;
                case Gesture::TYPE_SWIPE:
                    _analyzeSwipe(g);
                    break;
                default:
                    break;
            }
        }
    }
}

void SampleListener::_analyzeCircle(const Gesture& g)
{
    CircleGesture circle = g;
    
    if (_isClockwise(circle))
    {
        // Clockwise
        _counter->Increment();
        std::cout << _counter->GetValue() << "\tCircle clockwise." << std::endl;
        return;
    }
    else
    {
        // Counterclockwise
        _counter->Decrement();
        std::cout << _counter->GetValue() << "\tCircle counterclockwise." << std::endl;
        return;
    }
}

bool SampleListener::_isClockwise(CircleGesture& c) const
{
    Vector v_p = c.pointable().direction();
    Vector c_n = c.normal();
    
    return (v_p.angleTo(c_n) <= (PI/2));
}

void SampleListener::_analyzeKeyTap(const Gesture& g)
{
    Pointable p = g.pointables().frontmost();
    
    Vector v = p.direction();
    
    if (v.y < 0.0)
    {
        // Tapping downward
        _counter->Decrement();
        std::cout << _counter->GetValue() << "\tTap down." << std::endl;
        return;
    }
    
    if (v.y > 0.0)
    {
        // Tapping upward
        _counter->Increment();
        std::cout << _counter->GetValue() << "\tTap up." << std::endl;
        return;
    }
}

void SampleListener::_analyzeScreenTap(const Gesture& g)
{
    Pointable p = g.pointables().frontmost();
    
    Vector v = p.direction();
    
    if (v.z < 0.0)
    {
        _counter->Reset();
        std::cout << _counter->GetValue() << "\tScreen tap." << std::endl;
    }
}

void SampleListener::_analyzeSwipe(const Gesture& g)
{
    Pointable p = g.pointables().frontmost();
    
    Vector v = p.direction();
    
    if (v.x < 0.0)
    {
        // Swiping left
        _counter->Decrement();
        std::cout << _counter->GetValue() << "\tSwipe left." << std::endl;
        return;
    }
    
    if (v.x > 0.0)
    {
        // Swiping right
        _counter->Increment();
        std::cout << _counter->GetValue() << "\tSwipe right." << std::endl;
        return;
    }
}
