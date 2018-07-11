/*
  ==============================================================================

    CustomToggle.cpp
    Created: 20 Jun 2018 5:27:17pm
    Author:  Corey Ford

  ==============================================================================
*/

#include "CustomToggle.h"

//==============================================================================

namespace gui
{
    CustomToggle::CustomToggle()
    {
        state = 0;
    }
    
    CustomToggle::~CustomToggle()
    {
    }
    
    void CustomToggle::paint (Graphics& g)
    {
        Colour fillColour = (state == 1 ? Colours::green : Colours::red );
        g.fillAll(fillColour);
    }
    
    void CustomToggle::resized(){}
    
    void CustomToggle::mouseDown(const MouseEvent & event)
    {
        state = !state;
        repaint();
    }
    
    bool CustomToggle::getState() const
    {
        return state; 
    }
}

