/* 
 * File:   SampleListener.h
 * Author: adhish
 *
 * Created on October 3, 2015, 6:16 PM
 */

#ifndef SAMPLELISTENER_H
#define	SAMPLELISTENER_H

#include "Leap.h"
#include "Counter.h"

#ifndef PI
#define PI 3.141596
#endif

/**
 * @brief SampleListener class, child of Leap::Listener class
 */
namespace Leap
{
    class SampleListener
        : public Listener
    {
    public:
        // Constructor
        SampleListener();
        // Destructor
        virtual ~SampleListener();
        
        // Overriden virtual functions
        virtual void onConnect(const Controller& controller);
        virtual void onFrame(const Controller& controller);
        virtual void onDisconnect(const Controller& controller);
        
    private:
        // Private functions
        void _displayFrameData(const Frame& f) const;
        void _analyzeGestures(const Frame& f);
        void _analyzeCircle(const Gesture& g);
        void _analyzeKeyTap(const Gesture& g);
        void _analyzeScreenTap(const Gesture& g);
        void _analyzeSwipe(const Gesture& g);
        bool _isClockwise(CircleGesture& c) const;
        Counter* _counter;
    };
}

#endif	/* SAMPLELISTENER_H */

