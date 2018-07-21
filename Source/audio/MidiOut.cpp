/*
  ==============================================================================

    MidiOut.cpp
    Created: 20 Jul 2018 4:16:23pm
    Author:  Corey Ford

  ==============================================================================
*/

#include "MidiOut.h"

namespace audio
{
    MidiOut& MidiOut::getInstance()
    {
        static MidiOut instance;
        return instance;
    }
    
    MidiOut::MidiOut()
    {
        _midiOutput = juce::MidiOutput::createNewDevice("step-sequencer");
        
    }
    
    MidiOut::~MidiOut()
    {
        _midiOutput->clearAllPendingMessages();
        delete _midiOutput;
    }
    
    void MidiOut::cartesianToggleChanged(const bool state,
                                         const int x,
                                         const int y)
    {
        DBG("Row" + (String)y);
        DBG("Column" + (String)x);
    }
    
} //namespace audio
