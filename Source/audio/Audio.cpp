/*
 ==============================================================================
 
 Audio.cpp
 Created: 6 Jul 2018 4:01:38pm
 Author:  Corey Ford
 
 ==============================================================================
 */

#include "Audio.h"

namespace audio
{
    Audio::Audio()
    {
        // setup audio processing
        _audioDeviceManager.initialiseWithDefaultDevices (0, 2);
        _audioDeviceManager.addAudioCallback (this);
    }
    
    Audio::~Audio()
    {
        _audioDeviceManager.removeAudioCallback (this);
        _audioDeviceManager.removeMidiInputCallback("step-sequencer", this);
    }
    
    void Audio::audioDeviceAboutToStart (AudioIODevice* device)
    {
        
    }
    
    void Audio::audioDeviceIOCallback (const float** inputChannelData,
                                       int numInputChannels,
                                       float** outputChannelData,
                                       int numOutputChannels,
                                       int numSamples)
    {
        // const float *inL = inputChannelData[0];
        // const float *inR = inputChannelData[1];
        float *outL = outputChannelData[0];
        float *outR = outputChannelData[1];
        
        // at buffer rate
        
        // at sample rate
        while(numSamples--)
        {
            *outL = 0;
            *outR = 0;
        }
    }
    
    void Audio::audioDeviceStopped()
    {
        
    }
    
    //==========================================================================
    void Audio::setupMidiInput(String midiInput)
    {
        _audioDeviceManager.setMidiInputEnabled(midiInput, true);
        _audioDeviceManager.addMidiInputCallback(midiInput, this);
    }
    
    
    void Audio::handleIncomingMidiMessage (MidiInput* source,
                                           const MidiMessage& message)
    {
        
    }
    
} //namespace audio
