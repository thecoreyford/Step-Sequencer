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
        
        // setup visualiser as null unless set
        visualiser = nullptr;
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
        float *outL = outputChannelData[0];
        float *outR = outputChannelData[1];
        
        // set amplitude to zero if midi isn't playing
        if ( MidiOut::getInstance().getPlaying() == false )
        {
            for(int i = 0; i < MIDI_CHANNEL_TOTAL; ++i)
                osc[i].get()->setAmplitude(0.0f);
        }
  
        float accumulator = 0.0f;
        while(numSamples--)
        {
            // sum all oscillators
            for(int i = 0; i < MIDI_CHANNEL_TOTAL; ++i)
            {
                accumulator += osc[i].get()->getSample();
            }
            
            // scale for no clipping
            accumulator *= 1.0f / MIDI_CHANNEL_TOTAL;
            
            // test for clipping range
            jassert(accumulator >= -1.0f && accumulator <= 1.0f);
            
            // write to output
            *outL = accumulator;
            *outR = accumulator;
            
            // update visualiser
            if(visualiser.get() != nullptr)
            {
                visualiser.get()->pushSample(outL, 1);
            }
            
            // increment to next sample in buffer
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
            else // message.isNoteOff()
            {
                osc[message.getChannel()-1].get()->setAmplitude(0.0f);
            }
            
            float freq = MidiMessage::getMidiNoteInHertz( message.getNoteNumber() );
            osc[message.getChannel()-1].get()->setFrequency(freq);
        }
    }
    
    //==========================================================================
    
    void Audio::linkAudioVisualiserComponent(std::shared_ptr<AudioVisualiserComponent> av)
    {
        visualiser = av;
    }
    
} //namespace audio
