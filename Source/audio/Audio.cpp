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
        
        sine.setSampleRate(44100.0);
        sine.setAmplitude(0.0);
    }
    
    Audio::~Audio()
    {
        _audioDeviceManager.removeAudioCallback (this);
        _audioDeviceManager.removeMidiInputCallback("step-sequencer", this);
    }
    
    void Audio::audioDeviceAboutToStart (AudioIODevice* device){}
    
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
        if ( MidiOut::getInstance().getPlaying() == false )
            sine.setAmplitude(0.0f);
            
        // at sample rate
        while(numSamples--)
        {
            float out = sine.getSample();
            *outL = out;
            *outR = out;
            
//            inL++;
//            inR++;
            outL++;
            outR++;
        }
    }
    
    void Audio::audioDeviceStopped(){}
    
    //==========================================================================
    void Audio::setupMidiInput(String midiInput)
    {
        _audioDeviceManager.setMidiInputEnabled(midiInput, true);
        _audioDeviceManager.addMidiInputCallback(midiInput, this);
    }
    
    
    void Audio::handleIncomingMidiMessage (MidiInput* source,
                                           const MidiMessage& message)
    {
        if( message.isNoteOn() )
        {
            sine.setAmplitude( message.getFloatVelocity() );
        }
        else
        {
            sine.setAmplitude(0.0f);
        }
        
        float freq = MidiMessage::getMidiNoteInHertz( message.getNoteNumber() );
        sine.setFrequency(freq);
    }
    
} //namespace audio
