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
    
    //==========================================================================
    
    void MidiOut::setPlayback (String setting, float value)
    {
        _playbackSettings.set(setting.toLowerCase().removeCharacters(" "),
                              value);
    }
    
    float MidiOut::getSetting (String setting) const
    {
        setting = setting.toLowerCase().removeCharacters(" ");
        
        // The setting you were looking for does not exist!!!
        jassert(_playbackSettings.contains(setting));
        
        return _playbackSettings[setting];
    }
    
    //==========================================================================
    
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
                                / beatsInABar
                                * 1000 /* for milliseconds*/;
        
        // calculate the note value for each step
        const int noteNumber = _playbackSettings["startnote"] + row;
        
        // place into a midi message's
        //TODO(corey2.ford@live.uwe.ac.uk): left off here
        MidiMessage newMessageOn = MidiMessage::noteOn(1, noteNumber, (uint8)98);
        newMessageOn.addToTimeStamp(increment * column);
        MidiMessage newMessageOff = MidiMessage::noteOff(1, noteNumber, (uint8)98);
        newMessageOff.addToTimeStamp(increment * (column+1));
        
        MidiMessageTimestampSorter sorter;
        
        if(state == true)
        {
            _eventList.add(newMessageOn);
            _eventList.add(newMessageOff);
            _eventList.sort(sorter);
            
            MidiMessage test1 = MidiMessage::noteOff(1, 60, (uint8)98);
            MidiMessage test2 = MidiMessage::noteOff(1, 64, (uint8)98);
            
        }
        else
        {
            // as all values are gaurenteed to be unique on a grid we can...
            for(int i = 0; i < _eventList.size(); i++)
            {
                if(_eventList.getReference(i) == newMessageOn)
                    _eventList.remove(i);
                
                if(_eventList.getReference(i) == newMessageOff)
                    _eventList.remove(i);
            }
            
        }
        
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
