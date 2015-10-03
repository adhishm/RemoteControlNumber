/* 
 * File:   main.cpp
 * Author: adhish
 *
 * Created on October 3, 2015, 5:56 PM
 */

#include <cstdlib>
#include <iostream>
#include <string.h>
#include <vector>

#include "Leap.h"
#include "SampleListener.h"

void EnableGestures (Leap::Controller* controller);

int main(int argc, char** argv)
{
    Leap::Controller* controller = new Leap::Controller();
    
    // Enable gestures
    EnableGestures(controller);
    
    Leap::SampleListener listener;
    controller->addListener(listener);
        
    std::cout << "Press enter to exit." << std::endl;
    std::cin.get();
    
    controller->removeListener(listener);
    
    delete controller;
    controller = NULL;
    
    return 0;
}

void EnableGestures(Leap::Controller* controller)
{
    controller->enableGesture(Leap::Gesture::TYPE_CIRCLE, true);
    controller->enableGesture(Leap::Gesture::TYPE_KEY_TAP, true);
    controller->enableGesture(Leap::Gesture::TYPE_SCREEN_TAP, true);
    controller->enableGesture(Leap::Gesture::TYPE_SWIPE, true);
}
