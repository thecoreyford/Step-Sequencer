/*
  ==============================================================================

    SequencerGUI.h
    Created: 6 Jul 2018 6:43:06pm
    Author:  Corey Ford

  ==============================================================================
*/

#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "SequencerGrid.h"
#include "KeyboardGrid.h"

//==============================================================================

namespace gui
{
    /**
     * Draws the visual components making up the sequencer grid.
     */
    class SequencerGUI : public Component
    {
    public:
        /** Constructor. Makes sub components visible. */
        SequencerGUI();
        
        /** Destructor. Currently does nothing. */
        ~SequencerGUI();
        
        /** */
        void paint (Graphics&) override;
        void resized() override;
        
    private:
        SequencerGrid* _seqGrid;
        KeyboardGrid* _keyGrid;
        
        const int _rowCount = 12;
        const int _columnCount = 8;
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SequencerGUI)
    };
    
} //namespace gui
