/**
 *  @file    SequencerGrid.h
 *  @author  Corey Ford
 *  @date    6/07/2018
 *  @version 1.0
 *
 *  @section DESCRIPTION
 *
 * Draws the visual components making up the sequencer GUI.
 *
 */

#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../../audio/MidiOut.h"
#include "../../audio/Audio.h"
#include "SequencerGrid.h"
#include "KeyboardGrid.h"

//==============================================================================

namespace gui
{
    /**
     * Draws the visual components making up the sequencer GUI.
     */
    class SequencerGUI : public Component,
                         public audio::MidiOut::Listener
    {
    public:
        /** Constructor. Makes sub components visible. */
        SequencerGUI(audio::Audio& audioParam);
        
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
        /** Pointer for our sequencer grid GIO. */
        std::unique_ptr<SequencerGrid> seqGrid;
        /** Pointer for our keyboard grid GUI. */
        std::unique_ptr<KeyboardGrid> keyGrid;
        /** Shared pointer for the audio visualisations. */
        std::shared_ptr<AudioVisualiserComponent> visual;

        /**Our audio component. */
        audio::Audio& audio;
        
        /** constant for row count */
        const int ROW_COUNT = 16;
        /** constant for column count */
        const int COLUMN_COUNT = 8;
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SequencerGUI)
    };
    
} //namespace gui
