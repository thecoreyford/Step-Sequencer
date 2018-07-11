/*
  ==============================================================================

    Key.h
    Created: 21 Jun 2018 1:06:51pm
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
    class Key : public Component
    {
    public:
        Key(const int noteNumber);
        ~Key();
        
        void paint (Graphics&) override;
        void resized() override;
        
        int getNoteNumber() const;
        
    private:
        
        Key();
        
        int _noteNumber;
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Key)
    };
    
} // namespace gui

