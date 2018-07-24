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
        
        // place converted values into a midi message
        MidiMessage newMessageOn = MidiMessage::noteOn(1, noteNumber, (uint8)98);
        newMessageOn.addToTimeStamp(increment * column);
        MidiMessage newMessageOff = MidiMessage::noteOff(1, noteNumber, (uint8)98);
        newMessageOff.addToTimeStamp(increment * (column+1));
        
        // modify the event list
        if(state == true)
        {
            _eventList.addMidiEvent(newMessageOn);
            _eventList.addMidiEvent(newMessageOff);
        }
        else
        {
            // as all values are gaurenteed to be unique on a grid we can...
            _eventList.removeMidiEvent(newMessageOn);
            _eventList.removeMidiEvent(newMessageOff);
        }
        
        _eventList.printMe();
    }

    //==========================================================================
    
    void MidiOut::timerCallback()
    {
        // figure out how much time has elapsed
        double elapsedTime = Time::getMillisecondCounterHiRes() - timeStart.get();
        
        // if it is the appropriate amount of time...
        if(elapsedTime >= _eventList.getMidiEvent(playPosition.get()).getTimeStamp())
        {
            // output the message
            _midiOutput->sendMessageNow(_eventList.getMidiEvent(playPosition.get()));
            
            // increment to the next play position
            playPosition.set(playPosition.get() + 1);
        }
        
        // wrap around the play position
        if(playPosition.get() == _eventList.getSize())
        {
            playPosition.set(0);
            timeStart.set(Time::getMillisecondCounterHiRes());
        }
        
    }
    
    //==========================================================================
    
    void MidiOut::buttonClicked (Button* button)
    {
        if(button->getComponentID() == "stop") // to be played
        {
            playPosition = 0;
            timeStart.set(Time::getMillisecondCounterHiRes());
            startTimer(1);
        }
        
        if(button->getComponentID() == "play") // to be stopped
        {
            stopTimer();
        }
    }
    
} //namespace audio
