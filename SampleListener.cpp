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

void SampleListener::onConnect(const Leap::Controller& controller)
{
    std::cout << "Controller connected" << std::endl;
}

void SampleListener::onDisconnect(const Leap::Controller& controller)
{
    std::cout << "Controller disconnected" << std::endl;
}


void SampleListener::onFrame(const Leap::Controller& controller)
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
    Leap::GestureList gestures = f.gestures();
    
    if (gestures.count() > 0)
    {
        for (Leap::GestureList::const_iterator it = gestures.begin(); it != gestures.end(); ++it)
        {
            Leap::Gesture g = *(it);
            switch (g.type())
            {
                case Leap::Gesture::TYPE_CIRCLE:
                    _analyzeCircle(g);
                    break;
                case Leap::Gesture::TYPE_KEY_TAP:
                    _analyzeKeyTap(g);
                    break;
                case Leap::Gesture::TYPE_SCREEN_TAP:
                    _analyzeScreenTap(g);
                    break;
                case Leap::Gesture::TYPE_SWIPE:
                    _analyzeSwipe(g);
                    break;
                default:
                    break;
            }
        }
    }
}

void SampleListener::_analyzeCircle(const Leap::Gesture& g)
{
    Leap::CircleGesture circle = g;
    
    if (_isClockwise(circle))
    {
        // Clockwise
        _counter->Increment();
        _counter->ShowValue();
        return;
    }
    else
    {
        // Counterclockwise
        _counter->Decrement();
        _counter->ShowValue();
        return;
    }
}

bool SampleListener::_isClockwise(Leap::CircleGesture& c) const
{
    Leap::Vector v_p = c.pointable().direction();
    Leap::Vector c_n = c.normal();
    
    return (v_p.angleTo(c_n) <= (PI/2));
}

void SampleListener::_analyzeKeyTap(const Leap::Gesture& g)
{
    Leap::Pointable p = g.pointables().frontmost();
    
    Leap::Vector v = p.direction();
    
    if (v.y < 0.0)
    {
        // Tapping downward
        _counter->Decrement();
        _counter->ShowValue();
        return;
    }
    
    if (v.y > 0.0)
    {
        // Tapping upward
        _counter->Increment();
        _counter->ShowValue();
        return;
    }
}

void SampleListener::_analyzeScreenTap(const Leap::Gesture& g)
{
    Leap::Pointable p = g.pointables().frontmost();
    
    Leap::Vector v = p.direction();
    
    if (v.z < 0.0)
    {
        _counter->Reset();
        _counter->ShowValue();
    }
}

void SampleListener::_analyzeSwipe(const Leap::Gesture& g)
{
    Leap::Pointable p = g.pointables().frontmost();
    
    Leap::Vector v = p.direction();
    
    if (v.x < 0.0)
    {
        // Swiping left
        _counter->Decrement();
        _counter->ShowValue();
        return;
    }
    
    if (v.x > 0.0)
    {
        // Swiping right
        _counter->Increment();
        _counter->ShowValue();
        return;
    }
}
