/*
  ==============================================================================

    SequencerGUI.h
    Created: 6 Jul 2018 6:43:06pm
    Author:  Corey Ford

  ==============================================================================
*/

#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"

//==============================================================================

namespace gui
{
    /**
     * Draws the visual components making up the sequencer grid.
     */
    class SequencerGUI : public Component
    {
    public:
        SequencerGUI();
        ~SequencerGUI();
        
        void paint (Graphics&) override;
        void resized() override;
        
    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SequencerGUI)
    };
    
} //namespace gui
