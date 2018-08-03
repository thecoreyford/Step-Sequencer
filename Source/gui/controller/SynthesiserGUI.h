/*
  ==============================================================================

    SynthesiserGUI.h
    Created: 6 Jul 2018 7:21:09pm
    Author:  Corey Ford

  ==============================================================================
*/

#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../../audio/Audio.h"
#include "../../audio/MidiOut.h"

//==============================================================================

namespace gui
{
    /*
     */
    class SynthesiserGUI    : public Component,
                              public ComboBox::Listener,
                              public Timer
    {
    public:
        SynthesiserGUI(audio::Audio& audio);
        ~SynthesiserGUI();
        
        void paint (Graphics&) override;
        void resized() override;
        
        void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
        
        void timerCallback() override;
        
    private:
        
        SynthesiserGUI();
        
        ComboBox oscChoice;
        audio::Audio& _audio;
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthesiserGUI)
    };
} //namespace gui


