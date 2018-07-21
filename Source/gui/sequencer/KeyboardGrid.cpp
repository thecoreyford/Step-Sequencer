/*
  ==============================================================================

    KeyboardGrid.cpp
    Created: 10 Jul 2018 4:13:35pm
    Author:  Corey Ford

  ==============================================================================
*/

#include "KeyboardGrid.h"

//==============================================================================

namespace gui
{
    KeyboardGrid::KeyboardGrid(const int rowCount) : _rowCount(rowCount)
    {
        for(int row = 0; row < rowCount; row++)
        {
            int inverseRow = rowCount - 1 - row; // so lowest note is at the bottom
            addAndMakeVisible ( _keys.add (new Key (inverseRow + 59)) );
        }
    }
    
    KeyboardGrid::~KeyboardGrid()
    {
    }
    
    void KeyboardGrid::paint (Graphics& g)
    {
        g.fillAll (Colours::darkgrey); // clear the background
    }
    
    void KeyboardGrid::resized()
    {
        Grid grid;
        
        grid.setGap(5_px);
        
        grid.templateColumns.add( Grid::TrackInfo (1_fr) );
        
        for(int row = 0; row < _rowCount; row++)
        {
            grid.templateRows.add( Grid::TrackInfo (1_fr) );
            grid.items.add( GridItem (_keys[row]) );
        }
        
        grid.performLayout( getLocalBounds() );
    }
    
} //namespace gui
