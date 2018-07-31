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
    
    MidiMessage MidiEventList::getMidiEvent(const int index) const
    {
        // the index you are getitng is out of range!!!
        jassert(index < getSize());
        
        return _eventList[index];
    }
    
    void MidiEventList::setMidiEvent(const int index,
                                     const MidiMessage& midiMessage)
    {
        // the index you want to set is out of range!!!
        jassert(index < getSize());
        
        _eventList.set(index, midiMessage);
    }
    
    int MidiEventList::getSize() const
    {
        return _eventList.size();
    }
    
} //namespace audio
