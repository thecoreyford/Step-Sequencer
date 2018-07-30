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
        updateTempo();
        
        setPlayback("startnote", 60.0f);
        isPlaying.set(false);
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
        
        // calculate the note value for each step
        const int noteNumber = _playbackSettings["startnote"] + row;
        
        // place converted values into a midi message
        MidiMessage newMessageOn = MidiMessage::noteOn((row+1), noteNumber, (uint8)98);
        newMessageOn.addToTimeStamp(/*increment */ column);
        MidiMessage newMessageOff = MidiMessage::noteOff((row+1), noteNumber, (uint8)98);
        newMessageOff.addToTimeStamp(/*increment */ (column+1));
        
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
    }

    //==========================================================================
    
    void MidiOut::timerCallback()
    {
        // ensure that realtime settings have been updated
        updateTempo();
        
        // figure out how much time has elapsed
        double elapsedTime = Time::getMillisecondCounterHiRes() - timeStart.get();
        
        // if it is the appropriate amount of time...
        if(elapsedTime >= (_eventList.getMidiEvent(playPosition.get()).getTimeStamp() * _increment))
        {
            // output the message
            _midiOutput->sendMessageNow(_eventList.getMidiEvent(playPosition.get()));
            
            // increment to the next play position
            playPosition.set(playPosition.get() + 1);
            DBG((String)playPosition.get());
        }
        
        // wrap around the play position
        if(playPosition.get() >= _eventList.getSize())
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
            // add an ending message for the length of the sequence
            _dummyMessage = MidiMessage::noteOn(1, 60, (uint8)0);
            const float endStamp = _playbackSettings["tempo"]
                                    * (_playbackSettings["colcount"])
                                    / 60.0f /* secPerMin */
                                    / 4  /* beatsInABar */
                                    * 1000 /* for milliseconds*/;
            _dummyMessage.setTimeStamp(endStamp);
            _eventList.addMidiEvent(_dummyMessage);
            //TODO: left off here
            
            // trigger settings for starting playback
            playPosition = 0;
            isPlaying.set(true);
            if(_listener != nullptr)
                _listener->playbackStateChanged(true);
            timeStart.set(Time::getMillisecondCounterHiRes());
            startTimer(1);
        }
        
        if(button->getComponentID() == "play") // to be stopped
        {
            // stop playback
            isPlaying.set(false);
            if(_listener != nullptr)
                _listener->playbackStateChanged(false);
            stopTimer();
        }
    }
    
    //==========================================================================
    
    void MidiOut::updateTempo()
    {
        // calculate increment length for each step
        _increment = (330.0 - _playbackSettings["tempo"])
                        / 60.0f /* secPerMin */
                        / 4  /* beatsInABar */
                        * 1000 /* for milliseconds*/;
    }
    
    
} //namespace audio
