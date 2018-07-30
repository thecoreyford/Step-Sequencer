/*
  ==============================================================================

    SequencerGUI.h
    Created: 6 Jul 2018 6:43:06pm
    Author:  Corey Ford

  ==============================================================================
*/

#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../../audio/MidiOut.h"
#include "SequencerGrid.h"
#include "KeyboardGrid.h"

//==============================================================================

namespace gui
{
    /**
     * Draws the visual components making up the sequencer grid.
     */
    class SequencerGUI : public Component,
                         public audio::MidiOut::Listener
    {
    public:
        /** Constructor. Makes sub components visible. */
        SequencerGUI();
        
        /** Destructor. Currently does nothing. */
        ~SequencerGUI();
        
        /**
         *  Fills component;
         *  @param the graphics context for painting.
         */
        void paint (Graphics&) override;
        
        /**
         *  Sets bounds and proprtions for components.
         */
        void resized() override;

        /**
         *  Callback getting the current playback value from midi out.
         *  @param  the current state of playback.
         */
        void playbackStateChanged(bool isPlaying) override;

    private:
        std::unique_ptr<SequencerGrid> _seqGrid;
        std::unique_ptr<KeyboardGrid> _keyGrid;
        
        const int _rowCount = 16;
        const int _columnCount = 8;
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SequencerGUI)
    };
    
} //namespace gui
