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
        // setup oscillators
        for(int i = 0; i < MIDI_CHANNEL_TOTAL; ++i)
        {
            osc[i].set(&triangle[i]);
        }
        
        // setup audio processing
        _audioDeviceManager.initialiseWithDefaultDevices (0, 2);
        _audioDeviceManager.addAudioCallback (this);
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
        {
            for(int i = 0; i < MIDI_CHANNEL_TOTAL; ++i)
                osc[i].get()->setAmplitude(0.0f);
        }
  
        float out = 0.0f;
        
        // at sample rate
        while(numSamples--)
        {
            // accumulate all oscillators
            for(int i = 0; i < MIDI_CHANNEL_TOTAL; ++i)
            {
                out += osc[i].get()->getSample();
            }
            out *= 1.0f / MIDI_CHANNEL_TOTAL;
            
            // write to output
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
        if(osc[message.getChannel()-1].get() != nullptr)
        {
            if( message.isNoteOn() )
            {
                osc[message.getChannel()-1].get()->setAmplitude( message.getFloatVelocity() );
            }
            else
            {
                osc[message.getChannel()-1].get()->setAmplitude(0.0f);
            }
            
            float freq = MidiMessage::getMidiNoteInHertz( message.getNoteNumber() );
            osc[message.getChannel()-1].get()->setFrequency(freq);
        }

    }
    
} //namespace audio
