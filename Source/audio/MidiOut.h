/*
  ==============================================================================

    MidiOut.h
    Created: 20 Jul 2018 4:16:23pm
    Author:  Corey Ford

  ==============================================================================
*/

#pragma once

#include "../gui/widgets/CartesianToggleButton.h"
#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================

//TODO(corey2.ford!@live.uwe.ac.uk): come back here after refactoring CustomToggle

namespace audio
{
    class MidiOut : gui::CartesianToggleButton::Listener
    {
    public:
        
        void cartesianToggleChanged(const bool state,
                                    const int row,
                                    const int column) override;
        
    private:
        juce::MidiOutput _midiOutput;
        
    };
} //namespace audio
