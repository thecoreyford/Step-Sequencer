/*
  ==============================================================================

    ControllerGUI.h
    Created: 6 Jul 2018 6:43:31pm
    Author:  Corey Ford

  ==============================================================================
*/

#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"

//==============================================================================

namespace gui
{
    /**
      Draws the visual components controlling musical parameters.
     */
    class ControllerGUI : public Component
    {
    public:
        ControllerGUI();
        ~ControllerGUI();
        
        void paint (Graphics&) override;
        void resized() override;
        
    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ControllerGUI)
    };
    
} //namespace gui
