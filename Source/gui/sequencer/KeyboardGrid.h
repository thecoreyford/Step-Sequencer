/*
  ==============================================================================

    KeyboardGrid.h
    Created: 10 Jul 2018 4:13:35pm
    Author:  Corey Ford

  ==============================================================================
*/

#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"

//==============================================================================

namespace gui
{
    /*
     */
    class KeyboardGrid    : public Component
    {
    public:
        KeyboardGrid();
        ~KeyboardGrid();
        
        void paint (Graphics&) override;
        void resized() override;
        
    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KeyboardGrid)
    };
    
} // namespace gui

