/*
  ==============================================================================

    PlayBackControls.cpp
    Created: 6 Jul 2018 7:20:31pm
    Author:  Corey Ford

  ==============================================================================
*/

#include "PlayBackControls.h"

//==============================================================================

namespace gui
{
    PlayBackControls::PlayBackControls()
    {
        // In your constructor, you should add any child components, and
        // initialise any special settings that your component needs.
        audio::MidiOut& midiOut = audio::MidiOut::getInstance();
        
        play.setButtonText("play");
        play.setComponentID("play");
        play.addListener(&midiOut);
        addAndMakeVisible(play);
        
    }
    
    PlayBackControls::~PlayBackControls()
    {
    }
    
    void PlayBackControls::paint (Graphics& g)
    {
        g.fillAll (Colours::crimson);   // clear the background
    }
    
    void PlayBackControls::resized()
    {
        play.setBounds(getLocalBounds());
    }
    
}
