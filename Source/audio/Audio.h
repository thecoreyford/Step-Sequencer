/**
 *  @file    Audio.h
 *  @author  Corey Ford
 *  @date    6/07/2018
 *  @version 1.0
 *
 *  @section DESCRIPTION
 *
 *  Handles midi input and audio output.
 *
 */

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "MidiOut.h"
#include "../synthesis/Oscillator.h"
#include "../synthesis/OscillatorTypes.h"
#include "../synthesis/Filters.h"

//==============================================================================

namespace audio
{    
    /**
     * Handles MIDI input and audio output.
     */
    class Audio : public AudioIODeviceCallback, public MidiInputCallback
    {
    public:
        
        /** Constructor. Sets up the audio device manager threads. */
        Audio();
        
        /** Destructor. Removes audio device manager threads. */
        ~Audio();
        
        /**
         *  Called before audio callback starts or whenever the sample rate / frame size changes.
         *  @param the audio device object.
         */
        virtual void audioDeviceAboutToStart (AudioIODevice* device) override;
        
        /**
         *  The processing function iterating over each audio sample of our buffer
         *  modifying by our synthesiser object.
         *
         *  @param inputChannelData is a pointer for our incoming audio
         *  @param numInputChannels is the number of audio input channels avaliable
         *  @param outputChannelData is a pointer to the audio output to our audio device.
         *  @param numOutputChannels is the number of audio channels e.g. 2 for stereo.
         *  @param numSamples is the size of our audio buffer in samples.
         */
        virtual void audioDeviceIOCallback (const float** inputChannelData,
                                            int numInputChannels,
                                            float** outputChannelData,
                                            int numOutputChannels,
                                            int numSamples) override;
        
        /**
         * Called to indicate that the device has stopped.
         */
        virtual void audioDeviceStopped() override;
        
        /**
         * Callback function trigger for every midi message recieved.
         * 
         * @param source is the midi input source to be listened to.
         * @param message is the midi message recieved.
         */
        virtual void handleIncomingMidiMessage (MidiInput* source,
                                                const MidiMessage& message) override;
        
        /**
         * Initialises the midi input device and starts the callback.
         * @param  The name of the midi input to be listened to.
         */
        void setupMidiInput(String midiInput);
        
        /**
         * Adds a shared pointer to an audio visualiser.
         * @param  The current pointer to the audio visualiser.
         */
        void linkAudioVisualiserComponent(std::shared_ptr<AudioVisualiserComponent> av);
        
        /**
         * Changes the chosen bank of oscillators depending on their.
         * @param  the ID for each oscillator.
         */
        void setOscillator(int ID);
        
        /**
         * Calls the LPF's co-efficent calculation function changing the cutoff.
         * @param  The new value for the cutoff frequency.
         */
        void setFilterCutoff(float cutoff);
        
    private:
        /** The audio device manager handling all ins & outs!*/
        AudioDeviceManager audioDeviceManager;
        
        /** No of midi channels avaliable. */
        static const int MIDI_CHANNEL_TOTAL = 16;
        /** Pointer for oscillators - demonstrating polymorphism. */
        Atomic<synthesis::osc::Oscillator*> osc[MIDI_CHANNEL_TOTAL];
        
        /** Bank of sine oscillators. */
        synthesis::osc::Sine sine[MIDI_CHANNEL_TOTAL];
        /** Bank of square wave oscillators.*/
        synthesis::osc::Square square[MIDI_CHANNEL_TOTAL];
        /** Bank of saw wave oscillators.*/
        synthesis::osc::Saw saw[MIDI_CHANNEL_TOTAL];
        /** Bank of triangle wave oscillators.*/
        synthesis::osc::Triangle triangle[MIDI_CHANNEL_TOTAL];
        
        /** A simple one pole LPF.*/
        synthesis::filter::OnePole filter;
        
        /** A reference to the visualiser for the audio. */
        std::shared_ptr<AudioVisualiserComponent> visualiser;
    };
    
} //namespace audio
