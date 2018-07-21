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
        
    private:
        
        /** 
         Private constructor. Object must initialise a size.
         */
        SequencerGrid();
        
        int _rowCount;
        int _columnCount;
        
        audio::MidiOut& _midiOut = audio::MidiOut::getInstance();
        
        Array< Array< std::shared_ptr<CartesianToggleButton> > > steps; ///< Dynamically allocate 2D array
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SequencerGrid)
    };
    
} // namespace gui

