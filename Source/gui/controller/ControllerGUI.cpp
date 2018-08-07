/*
  ==============================================================================

    ControllerGUI.cpp
    Created: 6 Jul 2018
    Author:  Corey Ford

  ==============================================================================
*/

#include "ControllerGUI.h"

//==============================================================================

namespace gui
{
    ControllerGUI::ControllerGUI(audio::Audio& audioParam) : audio(audioParam)
    {
        playback = std::make_unique<PlayBackControls>();
        synthGUI = std::make_unique<SynthesiserGUI>(audio);
        
        addAndMakeVisible(playback.get());
        addAndMakeVisible(synthGUI.get());
    }
    
    ControllerGUI::~ControllerGUI(){}
    
    void ControllerGUI::paint (Graphics& g)
    {
        g.fillAll (Colours::hotpink);   // clear the background
    }
    
    void ControllerGUI::resized()
    {
        // setup rectangles
        Rectangle<int> playbackRectangle, synthesiserRectangle;
        playbackRectangle = synthesiserRectangle = getLocalBounds();
        playbackRectangle.removeFromLeft(getWidth() * 0.35);
        synthesiserRectangle.removeFromRight(getWidth() * 0.65);
        
        // apply rectangles to bounds
        playback.get()->setBounds(playbackRectangle);
        synthGUI.get()->setBounds(synthesiserRectangle);
    }
    
}//namespace gui

