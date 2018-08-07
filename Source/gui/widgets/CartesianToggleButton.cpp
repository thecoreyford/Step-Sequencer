/*
  ==============================================================================

    CartesianToggleButton.cpp
    Created: 20 Jun 2018
    Author:  Corey Ford

  ==============================================================================
*/

#include "CartesianToggleButton.h"

//==============================================================================

namespace gui
{
    CartesianToggleButton::CartesianToggleButton(const int x, const int y)
    {
        // update index
        coOrdinates.setX(x);
        coOrdinates.setY(y);
        
        // initialise defaults
        state = false;
        listener = nullptr;
    }
    
    CartesianToggleButton::~CartesianToggleButton(){}
    
    void CartesianToggleButton::paint (Graphics& g)
    {
        Colour fillColour = (state == true ? Colours::green : Colours::red );
        g.fillAll(fillColour);
    }
    
    void CartesianToggleButton::resized(){}
    
    void CartesianToggleButton::mouseDown(const MouseEvent & event)
    {
        state = !state;
        
        if(listener != nullptr)
        {
            // Broadcast all button information
            listener->cartesianToggleChanged(state, coOrdinates.getX(), coOrdinates.getY());
        }
        
        repaint();
    }
    
    bool CartesianToggleButton::getState() const
    {
        return state;
    }
    
    void CartesianToggleButton::setState(const bool stateParam)
    {
        state = stateParam;
    }
    
    //==========================================================================
    
    void CartesianToggleButton::addListener (Listener* listenerParam)
    {
        listener = listenerParam;
    }

}
