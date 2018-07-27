/*
  ==============================================================================

    CartesianToggleButton.cpp
    Created: 20 Jun 2018 5:27:17pm
    Author:  Corey Ford

  ==============================================================================
*/

#include "CartesianToggleButton.h"

//==============================================================================

namespace gui
{
    CartesianToggleButton::CartesianToggleButton(const int x, const int y)
    {
        _coOrdinates.setX(x);
        _coOrdinates.setY(y);
        
        _state = false;
        _listener = nullptr;
    }
    
    CartesianToggleButton::~CartesianToggleButton(){}
    
    void CartesianToggleButton::paint (Graphics& g)
    {
        Colour fillColour = (_state == true ? Colours::green : Colours::red );
        g.fillAll(fillColour);
    }
    
    void CartesianToggleButton::resized(){}
    
    void CartesianToggleButton::mouseDown(const MouseEvent & event)
    {
        _state = !_state;
        
        if(_listener != nullptr)
        {
            // Broadcast all button information
            _listener->cartesianToggleChanged(_state, _coOrdinates.getX(), _coOrdinates.getY());
        }
        
        repaint();
    }
    
    bool CartesianToggleButton::getState() const
    {
        return _state;
    }
    
    void CartesianToggleButton::setState(const bool state)
    {
        _state = state;
    }
    
    //==========================================================================
    
    void CartesianToggleButton::addListener (Listener* listener)
    {
        _listener = listener;
    }

}
