/*
  ==============================================================================

    SequencerGrid.h
    Created: 10 Jul 2018 4:13:13pm
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
    class SequencerGrid    : public Component
    {
    public:
        SequencerGrid();
        ~SequencerGrid();
        
        void paint (Graphics&) override;
        void resized() override;
        
    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SequencerGrid)
    };
    
} // namespace gui

