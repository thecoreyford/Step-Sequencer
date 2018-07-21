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
    /**
     MidiOut singleton for scheduling and playback of midi messages.
     */
    class MidiOut : public gui::CartesianToggleButton::Listener
    {
    public:
        
        static MidiOut& getInstance();
        
        void cartesianToggleChanged(const bool state,
                                    const int x,
                                    const int y) override;
        
        float getSetting (String setting) const;
        
    private:
        MidiOut(); // must call get instance
        ~MidiOut();
        MidiOut(const MidiOut&); // cannot copy
        void operator= (const MidiOut& ); //cannot copy
        
        HashMap<String, float> _playbackSettings;

        juce::MidiOutput* _midiOutput;
        MidiMessageSequence _eventList;
        
        void setPlayback (String setting, float value);

    };
} //namespace audio
