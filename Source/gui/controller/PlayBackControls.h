/*
  ==============================================================================

    PlayBackControls.h
    Created: 6 Jul 2018 7:20:31pm
    Author:  Corey Ford

  ==============================================================================
*/

#pragma once

#include "../../audio/MidiOut.h"
#include "../../../JuceLibraryCode/JuceHeader.h"

//==============================================================================

namespace gui
{
    /*
     *  Handles the controls for playback from @see MidiOut.hpp
     */
    class PlayBackControls    : public Component
    {
    public:
        PlayBackControls();
        ~PlayBackControls();
        
        void paint (Graphics&) override;
        void resized() override;
        
    private:
        TextButton play;
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PlayBackControls)
    };
    
} //namespace gui

