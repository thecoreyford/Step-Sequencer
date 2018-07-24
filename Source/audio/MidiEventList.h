/*
  ==============================================================================

    MidiEventList.h
    Created: 23 Jul 2018 6:01:41pm
    Author:  Corey Ford

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================

// TODO(corey2.ford@live.uwe.ac.uk): individual getters and setters!
//                                     Haven't implemented as not needed for this
//                                     project but would make the class more reusable.

namespace audio
{
    /**
     *  Class used to sort the array in order of midi messages.
     *  @see  https://docs.juce.com/master/classArray.html
     */
    class MidiMessageTimestampSorter
    {
    public:
        /**
         *  Returns a value determining what time stamp is larger.
         *  @param  lhs is the leftmost message to be compared.
         *  @param  rhs is the rightmost message to be compared.
         */
        static int compareElements(MidiMessage lhs, MidiMessage rhs)
        {
            if (lhs.getTimeStamp() < rhs.getTimeStamp())
                return -1;
            else if (lhs.getTimeStamp() > rhs.getTimeStamp())
                return 1;
            else // if a == b
                return 0;
        }
    };

    //==========================================================================
    
    /**
     *  Container for midi messages sorted by there timecode.
     */
    class MidiEventList
    {
    public:
        
        /**
         * Constructor. Clears the array.
         */
        MidiEventList();
        
        /** Destructor. Currently does nothing.*/
        ~MidiEventList();
        
        /**
         *  Adds the input midi event so long as not already in list. 
         *  @param The midi message to be added to the list.
         */
        void addMidiEvent(const MidiMessage& midiMessage);
        
        /**
         * Removes the first appearence of the midi event input.
         * @param The midi message to be removed from the list.
         */
        void removeMidiEvent(const MidiMessage& midiMessage);
        
        /**
         *  Returns the event at the index passed of the list.
         *  @param The index of the midi valude ot be found.
         */
        MidiMessage getMidiEvent(const int index);
        
        /**
         *  Returns the size of the event list.
         */
        int getSize();
        
        void printMe(); //TODO(corey2.ford@live.uwe.ac.uk): remove after testing
                
    private:
        
        /** Array holding all scheduled midi messages. */
        Array<MidiMessage> _eventList;
        /** Our sorter object for the array. */
        MidiMessageTimestampSorter _sorter;
    };
    
    //==========================================================================
    
    /**
     *  Overloaded equals operator for 2 midi messages.
     *  @param lhs is the leftmost midi message to be evaluated.
     *  @param rhs is the rightmost midi message to be evaluated.
     *  @returns true if both midi messages are equivalents.
     */
    static bool operator == (const MidiMessage & lhs, const MidiMessage & rhs)
    {
        // check messages are the same size
        if(lhs.getRawDataSize() != rhs.getRawDataSize())
        {
            return false;
        }
        
        // check each byte matches
        const uint8* lhsPtr = lhs.getRawData();
        const uint8* rhsPtr = rhs.getRawData();
        for(int i = 0; i < lhs.getRawDataSize(); ++i)
        {
            // equivalents to lhsPtr[i] & rhsPtr[i] - not defined
            if( *(lhsPtr+i) != *(rhsPtr+i) )
            {
                return false;
            }
        }
        
        // also check timestamps
        if(lhs.getTimeStamp() != rhs.getTimeStamp())
        {
            return false;
        }
        
        return true;
        
    }
    
} //namespace audio
