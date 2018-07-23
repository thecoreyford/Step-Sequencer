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
        bool found = false;
        for(int i = 0; i < _eventList.size(); ++i)
        {
            if(_eventList[i] == midiMessage)
                found = true;
        }
        
        if(found == false)
            _eventList.add(midiMessage);
            _eventList.sort(_sorter);
    }
    
    void MidiEventList::removeMidiEvent(const MidiMessage& midiMessage)
    {
        for(int i = 0; i < _eventList.size(); i++)
        {
            if(_eventList.getReference(i) == midiMessage)
            {
                _eventList.remove(i);
                break;  // leave the list
            }
        }
        
        _eventList.sort(_sorter);
    }
    
    Array<MidiMessage> & MidiEventList::getArray()
    {
        return _eventList;
    }

    
} //namespace audio
