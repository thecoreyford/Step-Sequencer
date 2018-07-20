/*
  ==============================================================================

    SequencerGrid.h
    Created: 10 Jul 2018 4:13:13pm
    Author:  Corey Ford

  ==============================================================================
*/

#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../widgets/CartesianToggleButton.h"

//==============================================================================

namespace gui
{
    /*
     Holds a grid of each sequencer step and makes visible.
     */
    class SequencerGrid    : public Component,
                             public CartesianToggleButton::Listener
    {
    public:
        /**
         *  Constructor. Initilises each grid based on the size passed.
         *  @param rowCount is the no of buttons along the x axis.
         *  @param columnCount is the no of buttons along the y axis.
         */
        SequencerGrid(const int rowCount, const int columnCount);
        
        
        /** Destructor. Currently does nothing */
        ~SequencerGrid();
        
        /**
         Fills component with a dark grey backdrop.
         @param the graphics context for painting.
         */
        void paint (Graphics&) override;
        
        /**
         Creates a grid object that is then populated with each 
         button with the step sequencer.
         */
        void resized() override;
        
        //--TODO(corey2.ford@live.uwe.ac.uk): remove after proving listener concept
        void cartesianToggleChanged(const bool state,
                                    const int row,
                                    const int column) override;
    private:
        
        /** 
         Private constructor. Object must initialise a size.
         */
        SequencerGrid();
        
        int _rowCount;
        int _columnCount;
        
        Array< Array< std::shared_ptr<CartesianToggleButton> > > steps; ///< Dynamically allocate 2D array
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SequencerGrid)
    };
    
} // namespace gui

