/*
  ==============================================================================

    SequencerGrid.h
    Created: 10 Jul 2018 4:13:13pm
    Author:  Corey Ford

  ==============================================================================
*/

#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../widgets/CustomToggle.h"

//==============================================================================

namespace gui
{
    /*
     */
    class SequencerGrid    : public Component
    {
    public:
        SequencerGrid(const int rowCount, const int columnCount);
        ~SequencerGrid();
        
        void paint (Graphics&) override;
        void resized() override;
        
    private:
        
        SequencerGrid();
        
        int _rowCount;
        int _columnCount;
        
        CustomToggle** steps; ///< Dynamically allocate 2D array
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SequencerGrid)
    };
    
} // namespace gui

