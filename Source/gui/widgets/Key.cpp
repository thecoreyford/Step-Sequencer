/*
  ==============================================================================

    Key.cpp
    Created: 21 Jun 2018 1:06:51pm
    Author:  Corey Ford

  ==============================================================================
*/

#include "Key.h"

//==============================================================================
namespace gui
{
    Key::Key(const int noteNumber) : _noteNumber(noteNumber){}
    
    
    Key::~Key(){}
    
    void Key::paint (Graphics& g)
    {
        Colour fillColour = ( MidiMessage::isMidiNoteBlack(_noteNumber) == true ? Colours::black : Colours::white );
        Colour textColour = ( MidiMessage::isMidiNoteBlack(_noteNumber) == true ? Colours::white : Colours::black );
        
        g.fillAll (fillColour);
        g.setColour(textColour);
        g.drawText(MidiMessage::getMidiNoteName(_noteNumber, true, true, 4), getLocalBounds(), Justification::centred);
    }
    
    void Key::resized(){}
    
    int Key::getNoteNumber() const
    {
        return _noteNumber;
    }
    
    
}

