/**
 *  @file    SynthesiserGUI.h
 *  @author  Corey Ford
 *  @date    6/07/2018
 *  @version 1.0
 *
 *  @section DESCRIPTION
 *
 *  Handles the controls for playback from @see Audio.hpp
 *
 */

#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../../audio/Audio.h"
#include "../../audio/MidiOut.h"

//==============================================================================

namespace gui
{
    /**
     *  Handles the controls for playback from @see Audio.hpp
     */
    class SynthesiserGUI    : public Component,
                              public Timer
    {
    public:
        /**
         * Constructor. Contains lambdas for audio controls.
         * @param the Audio component.
         */
        SynthesiserGUI(audio::Audio& audioParam);
        
        /** Destructor. */
        ~SynthesiserGUI();
        
        /**
         *  Fills component with a background colour.
         *  @param the graphics context for painting.
         */
        void paint (Graphics&) override;
        
        /** Sets bounds for sub components.*/
        void resized() override;
        
        /** Timer callback listener for retriving playstate. */
        void timerCallback() override;
        
    private:
        
        /** Private constructor: must provide audio! */
        SynthesiserGUI();
        
        /** Choices for oscillator banks. */
        ComboBox oscChoice;
        
        /** Slider controlling LPF cutoff. */
        Slider filter;
        /** Label for filter slider */
        Label filterLabel; 
        
        /** The audio component */
        audio::Audio& audio;
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthesiserGUI)
    };
} //namespace gui


