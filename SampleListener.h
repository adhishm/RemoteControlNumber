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

/**
 * @brief SampleListener class, child of Leap::Listener class
 */
namespace Leap
{
    class SampleListener
        : public Leap::Listener
    {
    public:
        virtual void onConnect(const Leap::Controller& controller);
        virtual void onFrame(const Leap::Controller& controller);
        virtual void onDisconnect(const Leap::Controller& controller);
        SampleListener();
        virtual ~SampleListener();
    private:
        void _displayFrameData(const Frame& f) const;
        void _analyzeGestures(const Frame& f);
        void _analyzeCircle(const Leap::Gesture& g);
        void _analyzeKeyTap(const Leap::Gesture& g);
        void _analyzeScreenTap(const Leap::Gesture& g);
        void _analyzeSwipe(const Leap::Gesture& g);
        Counter* _counter;
    };
}

#endif	/* SAMPLELISTENER_H */

