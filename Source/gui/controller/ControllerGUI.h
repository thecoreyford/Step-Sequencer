/**
 *  @file    ControllerGUI.h
 *  @author  Corey Ford
 *  @date    6/07/2018
 *  @version 1.0
 *
 *  @section DESCRIPTION
 *
 *  The gui for controlling musical parameters.
 *
 */

#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../../audio/Audio.h"
#include "PlayBackControls.h"
#include "SynthesiserGUI.h"

//==============================================================================

namespace gui
{
    /**
     *  Draws the visual components controlling musical parameters.
     */
    class ControllerGUI : public Component
    {
    public:
        /** Constructor. Makes sub components visible. */
        ControllerGUI(audio::Audio& audioParam);
        
        /** Destructor. Currently does nothing. */
        ~ControllerGUI();
        
        /** 
         *  Fills component with horrible colour as this should be hidden.
         *  @param the graphics context for painting.
         */
        void paint (Graphics&) override;
        
        /** Sets bounds for sub components. */
        void resized() override;
        
    private:
        /** The audio playback component */
        audio::Audio& audio;
        
        /** The gui for playback controls. */
        std::unique_ptr<PlayBackControls> playback;
        
        /** The gui for the synthesiser. */
        std::unique_ptr<SynthesiserGUI> synthGUI;
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ControllerGUI)
    };
    
} //namespace gui
