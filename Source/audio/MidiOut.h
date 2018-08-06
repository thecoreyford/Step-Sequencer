/**
 *  @file    MidiOut.h
 *  @author  Corey Ford
 *  @date    20/07/2018
 *  @version 1.0
 *
 *  @section DESCRIPTION
 *
 *  MidiOut singleton for scheduling and playback of midi messages.
 *
 */

#pragma once

#include "MidiEventList.h"
#include "../gui/widgets/CartesianToggleButton.h"
#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================

namespace audio
{
    /**
     *  MidiOut singleton for scheduling and playback of midi messages.
     */
    class MidiOut : public gui::CartesianToggleButton::Listener,
                    public Timer,
                    public Button::Listener
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
        
        /**
         * Wrapper for setting parameters for each playback setting.
         * @param  setting is the label for a syntheisiser param.
         * @param  value is the value for the passed parameter.
         */
        void setPlayback (String setting, float value);
        
        /**
         *  Timer outputting midi messages from the event list based on timecode.
         */
        void timerCallback() override;
        
        /**
         *  Callback for button clicks.
         *  @param the button that has been clicked.
         */
        void buttonClicked (Button* button) override;
        
        /**
         *  Listener for output changes.
         */
        class Listener
        {
        public:
            /**
             *  Virtual destructor.
             */
            virtual ~Listener(){}
            
            /**
             *  Alerts when the playback has changed. 
             *  @param  if the sequencer is currently playing.
             */
            virtual void playbackStateChanged(bool isPlaying) = 0;
        };
        
        /**
         *  Setter for the output listener.
         *  @param A pointer to the listener.
         */
        void addListener(Listener* listenerParam) { listener = listenerParam; }
        
        /** Getter for retreiving playstate of midi output. */
        bool getPlaying() const { return isPlaying.get(); }
        
    private:
        /** Pointer to the playback state listener. */
        Listener* listener;
        
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
        void operator= (const MidiOut&);
        
        /** 
         *  Calculates the increment required for tempo & velocity.
         */
        void preparePlayback();
        
        /** Hash map for each playback setting parameters.*/
        HashMap<String, float> playbackSettings;
        /** Pointer for the sequencers virtual midi output device. */
        juce::MidiOutput* midiOutput;
        
        /** The list of events ready for playback. */
        MidiEventList eventList;
        /** The current play position within the event list.*/
        Atomic<int> playPosition;
        /** The time playback started. */
        Atomic<double> timeStart;
        /** The current state of playback. */
        Atomic<bool> isPlaying;
        
        /** Increment amount for the change in tempo. */
        float increment;
        
        /** A sys ex message for blank output steps in the sequencer. */
        MidiMessage dummyMessage;
    };
    
} //namespace audio
