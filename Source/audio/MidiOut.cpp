/*
  ==============================================================================

    MidiOut.cpp
    Created: 20 Jul 2018 4:16:23pm
    Author:  Corey Ford

  ==============================================================================
*/

#include "MidiOut.h"

namespace audio
{
    MidiOut& MidiOut::getInstance()
    {
        static MidiOut instance;
        return instance;
    }
    
    void MidiOut::setPlayback (String setting, float value)
    {
        _playbackSettings.set(setting.toLowerCase().removeCharacters(" "),
                              value);
    }
    
    void MidiOut::cartesianToggleChanged(const bool state,
                                         const int x,
                                         const int y)
    {
        const int& row = y;
        const int& column = x;
        
        // calculate increment length for each step
        const float secPerMin = 60.0f;
        const float beatsInABar = 4;
        const float increment = _playbackSettings["tempo"]
        / secPerMin
        / beatsInABar;
        
        // calculate the note value for each step
        const int noteNumber = _playbackSettings["startnote"] + row;
        
//        DBG(noteNumber);
        //        DBG(increment * column);
        
    }
    
    float MidiOut::getSetting (String setting) const
    {
        setting = setting.toLowerCase().removeCharacters(" ");
        
        // The setting you were looking for does not exist!!!
        jassert(_playbackSettings.contains(setting));
        
        return _playbackSettings[setting];
    }
    
    //==========================================================================
    
    MidiOut::MidiOut()
    {
        // create our midi output interface
        _midiOutput = juce::MidiOutput::createNewDevice("step-sequencer");
        
        // initalise default playback settings
        setPlayback("tempo", 120.0f);
        setPlayback("startnote", 60.0f);
    }
    
    MidiOut::~MidiOut()
    {
        _midiOutput->clearAllPendingMessages();
        delete _midiOutput;
    }
    
} //namespace audio
