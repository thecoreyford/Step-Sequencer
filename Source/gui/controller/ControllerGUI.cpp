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
    ControllerGUI::ControllerGUI(audio::Audio& audio) : _audio(audio)
    {
        _playback = std::make_unique<PlayBackControls>();
        _synthGUI = std::make_unique<SynthesiserGUI>(_audio);
        
        addAndMakeVisible(_playback.get());
        addAndMakeVisible(_synthGUI.get());
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
        playbackRectangle.removeFromLeft(getWidth() * 0.35);
        synthesiserRectangle.removeFromRight(getWidth() * 0.65);
        
        _playback.get()->setBounds(playbackRectangle);
        _synthGUI.get()->setBounds(synthesiserRectangle);
    }
    
}//namespace gui

