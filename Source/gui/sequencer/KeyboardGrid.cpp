/*
  ==============================================================================

    KeyboardGrid.cpp
    Created: 10 Jul 2018
    Author:  Corey Ford

  ==============================================================================
*/

#include "KeyboardGrid.h"

//==============================================================================

namespace gui
{
    KeyboardGrid::KeyboardGrid(const int rowCountParam) : rowCount(rowCountParam)
    {
        // get the midi output device for settings
        audio::MidiOut& midiOut = audio::MidiOut::getInstance();
        
        for(int row = 0; row < rowCount; row++)
        {
            int inverseRow = rowCount - 1 - row; // so lowest note is at the bottom
            addAndMakeVisible ( keys.add (new Key (inverseRow + midiOut.getSetting("startnote")) ));
        }
    }
    
    KeyboardGrid::~KeyboardGrid(){}
    
    void KeyboardGrid::paint (Graphics& g)
    {
        g.fillAll (Colours::darkgrey); // clear the background
    }
    
    void KeyboardGrid::resized()
    {
        Grid grid;
        
        grid.setGap(5_px);
        
        grid.templateColumns.add( Grid::TrackInfo (1_fr) );
        
        for(int row = 0; row < rowCount; row++)
        {
            grid.templateRows.add( Grid::TrackInfo (1_fr) );
            grid.items.add( GridItem (keys[row]) );
        }
        
        grid.performLayout( getLocalBounds() );
    }
    
} //namespace gui
