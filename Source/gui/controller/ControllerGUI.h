/*
  ==============================================================================

    ControllerGUI.h
    Created: 6 Jul 2018 6:43:31pm
    Author:  Corey Ford

  ==============================================================================
*/

#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"
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
        ControllerGUI();
        
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
        /** The gui for playback controls. */
        PlayBackControls _playback;
        
        /** The gui for the synthesiser. */
        SynthesiserGUI _synthGUI; 
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ControllerGUI)
    };
    
} //namespace gui
