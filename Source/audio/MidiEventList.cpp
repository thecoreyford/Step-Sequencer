/*
  ==============================================================================

    MidiEventList.cpp
    Created: 23 Jul 2018
    Author:  Corey Ford

  ==============================================================================
*/

#include "MidiEventList.h"

namespace audio
{
    MidiEventList::MidiEventList()
    {
        eventList.clear(); // ensure list is empty
    }
    
    MidiEventList::~MidiEventList(){}
    
    void MidiEventList::addMidiEvent(const MidiMessage& midiMessage)
    {
            eventList.add(midiMessage);
            eventList.sort(sorter); // sort by timestamp
    }
    
    void MidiEventList::removeMidiEvent(const MidiMessage& midiMessage)
    {
        for(int i = 0; i < eventList.size(); i++)
        {
            if(eventList[i] == midiMessage)
            {
                eventList.remove(i);
                break;  // leave the list
            }
        }
        
        eventList.sort(sorter); // sort by timestamp
    }
    
    MidiMessage MidiEventList::getMidiEvent(const int index) const
    {
        // the index you are getitng is out of range!!!
        jassert(index < getSize());
        
        return eventList[index];
    }
    
    void MidiEventList::setMidiEvent(const int index,
                                     const MidiMessage& midiMessage)
    {
        // the index you want to set is out of range!!!
        jassert(index < getSize());
        
        eventList.set(index, midiMessage);
    }
    
    int MidiEventList::getSize() const
    {
        return eventList.size();
    }
    
} //namespace audio
