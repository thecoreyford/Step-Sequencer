/*
  ==============================================================================

    ControllerGUI.cpp
    Created: 6 Jul 2018 6:43:31pm
    Author:  Corey Ford

  ==============================================================================
*/

#include "ControllerGUI.h"

//==============================================================================

namespace gui
{
    ControllerGUI::ControllerGUI()
    {
    }
    
    ControllerGUI::~ControllerGUI()
    {
    }
    
    void ControllerGUI::paint (Graphics& g)
    {
        g.fillAll (Colours::hotpink);   // clear the background
    }
    
    void ControllerGUI::resized()
    {
    }
    
}//namespace gui

