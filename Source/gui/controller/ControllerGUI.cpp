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
        addAndMakeVisible(_playback);
        addAndMakeVisible(_synthGUI);
    }
    
    ControllerGUI::~ControllerGUI(){}
    
    void ControllerGUI::paint (Graphics& g)
    {
        g.fillAll (Colours::hotpink);   // clear the background
    }
    
    void ControllerGUI::resized()
    {
        Rectangle<int> playbackRectangle, synthesiserRectangle;
        playbackRectangle = synthesiserRectangle = getLocalBounds();
        playbackRectangle.removeFromLeft(getWidth() * 0.25);
        synthesiserRectangle.removeFromRight(getWidth() * 0.75);
        
        _playback.setBounds(playbackRectangle);
        _synthGUI.setBounds(synthesiserRectangle);
        
    }
    
}//namespace gui

