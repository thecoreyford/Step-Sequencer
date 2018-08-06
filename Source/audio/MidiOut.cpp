/*
  ==============================================================================

    MidiOut.cpp
    Created: 20 Jul 2018
    Author:  Corey Ford

  ==============================================================================
*/

#include "MidiOut.h"

namespace audio
{
    MidiOut::MidiOut()
    {
        // create our midi output interface
        midiOutput = juce::MidiOutput::createNewDevice("step-sequencer");
        
        // initalise default playback settings
        setPlayback("tempo", 120.0f);
        setPlayback("velocity", 90.0f);
        preparePlayback();
        setPlayback("startnote", 60.0f);
        isPlaying.set(false);
    }
    
    MidiOut::~MidiOut()
    {
        midiOutput->clearAllPendingMessages();
        delete midiOutput;
    }
    
    MidiOut& MidiOut::getInstance()
    {
        static MidiOut instance;
        return instance;
    }
    
    //==========================================================================
    
    void MidiOut::setPlayback (String setting, float value)
    {
        playbackSettings.set(setting.toLowerCase().removeCharacters(" "),
                              value);
    }
    
    float MidiOut::getSetting (String setting) const
    {
        setting = setting.toLowerCase().removeCharacters(" ");
        
        // The setting you were looking for does not exist!!!
        jassert(playbackSettings.contains(setting));
        
        return playbackSettings[setting];
    }
    
    //==========================================================================
    
    void MidiOut::cartesianToggleChanged(const bool state,
                                         const int x,
                                         const int y)
    {
        const int& row = y;
        const int& column = x;
        
        // calculate the note value for each step
        const int noteNumber = playbackSettings["startnote"] + row;
        
        // place converted values into a midi message
        MidiMessage newMessageOn = MidiMessage::noteOn((row+1),
                                                       noteNumber,
                                                       (uint8)playbackSettings["velocity"]);
        newMessageOn.addToTimeStamp(/*increment */ column);
        
        MidiMessage newMessageOff = MidiMessage::noteOff((row+1),
                                                         noteNumber,
                                                         (uint8)0);
        newMessageOff.addToTimeStamp(/*increment */ (column+1));
        
        // modify the event list
        if(state == true)
        {
            eventList.addMidiEvent(newMessageOn);
            eventList.addMidiEvent(newMessageOff);
        }
        else
        {
            // as all values are gaurenteed to be unique on a grid we can...
            eventList.removeMidiEvent(newMessageOn);
            eventList.removeMidiEvent(newMessageOff);
        }
    }

    //==========================================================================
    
    void MidiOut::timerCallback()
    {
        // figure out how much time has elapsed
        double elapsedTime = Time::getMillisecondCounterHiRes() - timeStart.get();
        
        // if it is the appropriate amount of time...
        if(elapsedTime >= (eventList.getMidiEvent(playPosition.get()).getTimeStamp() * increment))
        {
            // output the message
            midiOutput->sendMessageNow(eventList.getMidiEvent(playPosition.get()));
            
            // increment to the next play position
            playPosition.set(playPosition.get() + 1);
        }
        
        // wrap around the play position
        if(playPosition.get() == eventList.getSize())
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
            dummyMessage = MidiMessage::noteOn(1, 60, (uint8)0);
            dummyMessage.setTimeStamp(playbackSettings["colcount"]);
            eventList.addMidiEvent(dummyMessage);
            
            // ensure that settings have been updated before playback
            preparePlayback();
            
            // trigger settings for starting playback
            playPosition = 0;
            isPlaying.set(true);
            if(listener != nullptr)
                listener->playbackStateChanged(true);
            timeStart.set(Time::getMillisecondCounterHiRes());
            startTimer(1);
        }
        
        if(button->getComponentID() == "play") // to be stopped
        {
            // stop playback
            isPlaying.set(false);
            if(listener != nullptr)
                listener->playbackStateChanged(false);
            stopTimer();
        }
    }
    
    //==========================================================================
    
    void MidiOut::preparePlayback()
    {
        // calculate increment length for each step
        increment = (330.0 - playbackSettings["tempo"])
                        / 60.0f /* secPerMin */
                        / playbackSettings["colcount"]  /* beatsInABar */
                        * 1000 /* for milliseconds*/;
        
        // check message velocities within list
        for(int i = 0; i < eventList.getSize(); i++)
        {
            if(eventList.getMidiEvent(i).isNoteOn())
            {
                if(eventList.getMidiEvent(i).getVelocity() != (uint8)playbackSettings["velocity"])
                {
                    auto newEvent = eventList.getMidiEvent(i);
                    newEvent.setVelocity(playbackSettings["velocity"] / 127.0f);
                    eventList.setMidiEvent(i, newEvent);
                }
            }
        }
    }
    
} //namespace audio
