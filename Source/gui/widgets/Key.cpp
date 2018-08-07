/*
  ==============================================================================

    Key.cpp
    Created: 21 Jun 2018
    Author:  Corey Ford

  ==============================================================================
*/

#include "Key.h"

//==============================================================================
namespace gui
{
    Key::Key(const int noteNumberParam) : noteNumber(noteNumberParam){}
    
    Key::~Key(){}
    
    void Key::paint (Graphics& g)
    {
        Colour fillColour = ( MidiMessage::isMidiNoteBlack(noteNumber) == true ? Colours::black : Colours::white );
        Colour textColour = ( MidiMessage::isMidiNoteBlack(noteNumber) == true ? Colours::white : Colours::black );
        
        g.fillAll (fillColour);
        g.setColour(textColour);
        g.drawText(MidiMessage::getMidiNoteName(noteNumber, true, true, 4),
                   getLocalBounds(),
                   Justification::centred);
    }
    
    void Key::resized(){}
    
    int Key::getNoteNumber() const
    {
        return noteNumber;
    }
    
    
}

