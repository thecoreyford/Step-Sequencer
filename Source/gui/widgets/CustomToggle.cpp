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
    CustomToggle::CustomToggle(const int row, const int column) : _row(row), _column(column)
    {
        _state = false;
    }
    
    CustomToggle::~CustomToggle()
    {
    }
    
    void CustomToggle::paint (Graphics& g)
    {
        Colour fillColour = (_state == true ? Colours::green : Colours::red );
        g.fillAll(fillColour);
    }
    
    void CustomToggle::resized(){}
    
    void CustomToggle::mouseDown(const MouseEvent & event)
    {
        _state = !_state;
        
        if(_state == true)
        {
            //fire off message to midi out
        }
        
        repaint();
    }
    
    bool CustomToggle::getState() const
    {
        return _state;
    }
}

