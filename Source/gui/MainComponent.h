/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "../audio/Audio.h"

//==============================================================================

namespace gui
{
    /*
     This component lives inside our window, and this is where you should put all
     your controls and content.
     */
    class MainComponent : public Component
    {
    public:
        //==============================================================================
        MainComponent (audio::Audio& audio);
        ~MainComponent();
        
        //==============================================================================
        void paint (Graphics&) override;
        void resized() override;
        
    private:
        //==============================================================================
        // Your private member variables go here...
        audio::Audio& _audio;
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
    };
    
} //namespace gui
