/**
 *  @file    PlayBackControls.h
 *  @author  Corey Ford
 *  @date    6/07/2018
 *  @version 1.0
 *
 *  @section DESCRIPTION
 *
 *  Handles the controls for playback from @see MidiOut.hpp
 *
 */


#pragma once

#include "../../audio/MidiOut.h"
#include "../../../JuceLibraryCode/JuceHeader.h"

//==============================================================================

namespace gui
{
    /*
     *  Handles the controls for playback from @see MidiOut.hpp
     */
    class PlayBackControls    : public Component
    {
    public:
        /**
         * Constructor. Contains lambda functions for each control.
         */
        PlayBackControls();
        
        /**
         * Destructor.
         */
        ~PlayBackControls();
        
        /**
         *  Fills component with a background colour.
         *  @param the graphics context for painting.
         */
        void paint (Graphics&) override;
        
        /** Sets bounds for sub components. */
        void resized() override;
        
    private:
        /** Play button */
        TextButton play;
        
        /** Tempo control on a slider. */
        Slider tempo;
        /** Label for tempo control. */
        Label tempoLabel;
        
        /** Velocity control on a slider. */
        Slider velocity;
        /** Label for velocity control. */
        Label velocityLabel;
        
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PlayBackControls)
    };
    
} //namespace gui

