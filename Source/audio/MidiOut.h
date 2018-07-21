/*
  ==============================================================================

    MidiOut.h
    Created: 20 Jul 2018 4:16:23pm
    Author:  Corey Ford

  ==============================================================================
*/

#pragma once

#include "../gui/widgets/CartesianToggleButton.h"
#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================

namespace audio
{
    class MidiOut : public gui::CartesianToggleButton::Listener
    {
    public:
        
        static MidiOut& getInstance();
        
        /**
         Structure holding different settings for playback.
         */
        struct PlaybackSettings
        {
            int tempo;
            uint8 velocity;
            //TODO(corey2.ford@live.uwe.ac.uk): more settings???
        };
        
        
        void cartesianToggleChanged(const bool state,
                                    const int x,
                                    const int y) override;
        
    private:
        MidiOut(); // must call get instance
        ~MidiOut();
        MidiOut(const MidiOut&); // cannot copy
        void operator= (const MidiOut& ); //cannot copy
        
        juce::MidiOutput* _midiOutput;
        MidiMessageSequence _eventList;
    };
} //namespace audio
