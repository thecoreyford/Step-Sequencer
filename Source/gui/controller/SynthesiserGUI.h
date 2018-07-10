/*
  ==============================================================================

    SynthesiserGUI.h
    Created: 6 Jul 2018 7:21:09pm
    Author:  Corey Ford

  ==============================================================================
*/

#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"

//==============================================================================

namespace gui
{
    /*
     */
    class SynthesiserGUI    : public Component
    {
    public:
        SynthesiserGUI();
        ~SynthesiserGUI();
        
        void paint (Graphics&) override;
        void resized() override;
        
    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthesiserGUI)
    };
} //namespace gui


