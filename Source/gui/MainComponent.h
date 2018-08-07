/**
 *  @file    MainComponent.h
 *  @author  Corey Ford
 *  @date    6/07/2018
 *  @version 1.0
 *
 *  @section DESCRIPTION
 *
 *  Entry Point for GUI. Lives inside our window.
 *
 */

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "../audio/Audio.h"
#include "sequencer/SequencerGUI.h"
#include "controller/ControllerGUI.h"

//==============================================================================

namespace gui
{
    /*
     Entry point for GUI. Lives inside our window.
     */
    class MainComponent : public Component
    {
    public:
        
        /**
         Constructor. Initialises GUI components.
         @param the audio playback component.
         */
        MainComponent (audio::Audio& audioParam);
        
        /** Destructor. */
        ~MainComponent();
        
        /**
         *  Fills component with horrible colour as this should be hidden.
         *  @param the graphics context for painting.
         */
        void paint (Graphics&) override;
        
        /** Sets bounds for sub components. */
        void resized() override;
        
    private:
        
        /** Our audio device. */
        audio::Audio& audio;
        
        /** The sequencer GUI component. */
        SequencerGUI sequencer;
        /** The controller GUI component. */
        ControllerGUI controller;
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
    };
    
} //namespace gui
