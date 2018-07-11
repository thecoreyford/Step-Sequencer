/*
 ==============================================================================
 
 SequencerGrid.cpp
 Created: 10 Jul 2018 4:13:13pm
 Author:  Corey Ford
 
 ==============================================================================
 */

#include "SequencerGrid.h"

//==============================================================================

namespace gui
{
    SequencerGrid::SequencerGrid(const int rowCount, const int columnCount) :
    _rowCount(rowCount),
    _columnCount(columnCount)
    {
        //dynamically create a 2D array of Custom Toggle Buttons
        steps = new CustomToggle*[_rowCount];
        for(int row = 0; row < _rowCount; ++row)
            steps[row] = new CustomToggle[_columnCount];
        
        //make array visible
        for(int col = 0; col < _columnCount; col++)
        {
            for(int row = 0; row < _rowCount; row++)
            {
                addAndMakeVisible(steps[row][col]);
            }
        }
        
    }
    
    SequencerGrid::~SequencerGrid()
    {
        for(int row = 0; row < _rowCount; row++) {
            delete [] steps[row];
        }
        delete [] steps;
    }
    
    void SequencerGrid::paint (Graphics& g)
    {
        g.fillAll (Colours::darkgrey);   // clear the background
        
    }
    
    void SequencerGrid::resized()
    {
        Grid grid;
        
        grid.setGap(5_px);
        
        for(int row = 0; row < _rowCount; row++)
            grid.templateRows.add( Grid::TrackInfo (1_fr) );
        
        for(int col = 0; col < _columnCount; col++)
            grid.templateColumns.add( Grid::TrackInfo (1_fr) );
        
        //--
        
        for(int col = 0; col < _columnCount; col++)
        {
            for(int row = 0; row < _rowCount; row++)
            {
                grid.items.add( steps[row][col] );
            }
        }
        
        grid.performLayout( getLocalBounds() );
    }
    
} //namespace gui
