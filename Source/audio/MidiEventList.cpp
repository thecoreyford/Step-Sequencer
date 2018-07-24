/*
  ==============================================================================

    MidiEventList.cpp
    Created: 23 Jul 2018 6:01:41pm
    Author:  Corey Ford

  ==============================================================================
*/

#include "MidiEventList.h"

namespace audio
{
    MidiEventList::MidiEventList()
    {
        _eventList.clear();
    }
    
    MidiEventList::~MidiEventList(){}
    
    void MidiEventList::addMidiEvent(const MidiMessage& midiMessage)
    {
            _eventList.add(midiMessage);
            _eventList.sort(_sorter);
    }
    
    void MidiEventList::removeMidiEvent(const MidiMessage& midiMessage)
    {
        for(int i = 0; i < _eventList.size(); i++)
        {
            if(_eventList[i] == midiMessage)
            {
                _eventList.remove(i);
                break;  // leave the list
            }
        }
        
        _eventList.sort(_sorter);
    }
    
    MidiMessage MidiEventList::getMidiEvent(const int index)
    {
        return _eventList[index];
    }
    
    int MidiEventList::getSize()
    {
        return _eventList.size();
    }
    
    void MidiEventList::printMe()
    {
        DBG("==========");
        for(int i = 0; i < _eventList.size(); i++)
        {
            String output = (String)_eventList[i].getTimeStamp() + ", ";
            output += (String)(int)_eventList[i].isNoteOn() + ", ";
            output += (String)_eventList[i].getNoteNumber() + ", ";
            DBG(output);
        }
        DBG("==========");
        
    }
    
} //namespace audio
