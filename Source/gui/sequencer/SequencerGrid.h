/**
 *  @file    SequencerGrid.h
 *  @author  Corey Ford
 *  @date    10/07/2018
 *  @version 1.0
 *
 *  @section DESCRIPTION
 *
 *  Holds a grid of each sequencer step and makes visible.
 *
 */

#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../widgets/CartesianToggleButton.h"
#include "../../audio/MidiOut.h"

//==============================================================================

namespace gui
{
    /*
     Holds a grid of each sequencer step and makes visible.
     */
    class SequencerGrid    : public Component
    {
    public:
        /**
         *  Constructor. Initilises each grid based on the size passed.
         *  @param rowCount is the no of buttons along the x axis.
         *  @param columnCount is the no of buttons along the y axis.
         *  @param midiOut is a reference to our midi output device.
         */
        SequencerGrid(const int rowCountParam, const int columnCountParam);
        
        
        /** Destructor. Currently does nothing */
        ~SequencerGrid();
        
        /**
         *  Fills component with a dark grey backdrop.
         *  @param the graphics context for painting.
         */
        void paint (Graphics&) override;
        
        /**
         *  Creates a grid object that is then populated with each
         *  button with the step sequencer.
         */
        void resized() override;
        
    private:
        
        /** 
         *  Private constructor. Object must initialise a size.
         */
        SequencerGrid();
        
        /** The number of rows for our grid */
        int rowCount;
        /** The number of columns for our grid */
        int columnCount;
        
        /** Instance of @see audio/MidiOut.h */
        audio::MidiOut& midiOut = audio::MidiOut::getInstance();
        
        /** 2D array of buttons representing our grid points */
        Array< Array< std::shared_ptr<CartesianToggleButton> > > steps; ///< Dynamically allocate 2D array
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SequencerGrid)
    };
    
} // namespace gui

