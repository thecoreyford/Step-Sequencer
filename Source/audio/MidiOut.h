/*
  ==============================================================================

    MidiOut.h
    Created: 20 Jul 2018 4:16:23pm
    Author:  Corey Ford

  ==============================================================================
*/

#pragma once

#include "../gui/widgets/CartesianToggleButton.h"
#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================

//TODO(corey2.ford@live.uwe.ac.uk): seperate event list into a seperate class
//                                      such as a scheduler type arrangement.

namespace audio
{
    
    typedef Array<MidiMessage> EventList;
    
    /**
     *  MidiOut singleton for scheduling and playback of midi messages.
     */
    class MidiOut : public gui::CartesianToggleButton::Listener
    {
    public:
        
        /**
         *  The accessor for the only instance of this class
         *  @return A reference to the static class instance.
         */
        static MidiOut& getInstance();
        
        /**
         *  Callback function for each toggle button.
         *  @param state is if the button is on or off
         *  @param x is the x-cordinate for the button
         *  @param y is the y-cordinate for the button
         */
        void cartesianToggleChanged(const bool state,
                                    const int x,
                                    const int y) override;
        
        /**
         *  Returns the paired float value for the input string.
         *  @param  the label for a synthesiser setting param.
         *  @return the value for the input setting.
         */
        float getSetting(String setting) const;
        
    private:
        /**
         * Private constructor. Must call get instance.
         * Initialises the virtual midi output device & playback settings.
         */
        MidiOut();
        
        /**
         * Private Destructor. 
         * Clears all pending midi out events and destroys the device.
         */
        ~MidiOut();
        
        /**
         * Private copy constructor - cannot to copy object.
         * @param reference for another MidiOut
         */
        MidiOut(const MidiOut&);
        
        /**
         * Private copy operator - cannot to copy object.
         * @param reference for another MidiOut
         */
        void operator= (const MidiOut& ); //cannot copy
        
        /** Hash map for each playback setting parameters.*/
        HashMap<String, float> _playbackSettings;
        /** Pointer for the sequencers virtual midi output device. */
        juce::MidiOutput* _midiOutput;
        /** The list of events ready for playback. */
        EventList _eventList;
        
        /**
         * Wrapper for setting parameters for each playback setting. 
         * @param  setting is the label for a syntheisiser param.
         * @param  value is the value for the passed parameter.
         */
        void setPlayback (String setting, float value);

    };
    
    //==========================================================================
    
    /**
     *  Class used to sort the array in order of midi messages
     *  https://docs.juce.com/master/classArray.html
     */
    class MidiMessageTimestampSorter
    {
    public:
        static int compareElements(MidiMessage a, MidiMessage b)
        {
            if (a.getTimeStamp() < b.getTimeStamp())
                return -1;
            else if (a.getTimeStamp() > b.getTimeStamp())
                return 1;
            else // if a == b
                return 0;
        }
    };
    
    /**
     *  Overloaded equals operator for 2 midi messages.
     *  @param lhs is the leftmost midi message to be evaluated. 
     *  @param rhs is the rightmost midi message to be evaluated.
     *  @returns true if both midi messages are equivalents.
     */
    static bool operator == (const MidiMessage & lhs, const MidiMessage & rhs)
    {
        if(lhs.getRawDataSize() != rhs.getRawDataSize())
        {
            return false;
        }
        
        const uint8* lhsPtr = lhs.getRawData();
        const uint8* rhsPtr = rhs.getRawData();
        for(int i = 0; i < lhs.getRawDataSize(); ++i)
        {
            // equivalents to lhsPtr[i] & rhsPtr[i] - what aren't defined :(
            if( *(lhsPtr+i) != *(rhsPtr+i) )
            {
                return false;
            }
        }
        
        return true;
        
    }
    
} //namespace audio
