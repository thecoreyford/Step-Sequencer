/*
 ==============================================================================
 
 CustomToggle.h
 Created: 20 Jun 2018 5:27:17pm
 Author:  Corey Ford
 
 ==============================================================================
 */

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================

namespace gui
{
    /*
     */
    class CustomToggle : public Component
    {
    public:
        CustomToggle();
        ~CustomToggle();
        
        void paint (Graphics&) override;
        void resized() override;
        
        void mouseDown(const MouseEvent & event) override;
        
        bool getState() const;
        
    private:
        bool state;
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CustomToggle)
    };
    
} // namespace


