/*
 ==============================================================================
 
 SequencerGrid.cpp
 Created: 10 Jul 2018
 Author:  Corey Ford
 
 ==============================================================================
 */

#include "SequencerGrid.h"

//==============================================================================

namespace gui
{
    SequencerGrid::SequencerGrid(const int rowCountParam, const int columnCountParam):
    rowCount(rowCountParam), columnCount(columnCountParam)
    {
        // Rows are assigned to the corresponding midi channel,
        // so you can only have between 1 to 16 rows.
        jassert(rowCount > 0 && rowCount <= 16);
        
        // You must have at least on column.
        jassert(columnCount > 0);
        
        midiOut.setPlayback("colcount", columnCount);
        
        Array< std::shared_ptr<CartesianToggleButton> > column;
        for(int col = 0; col < columnCount; col++)
        {
            column.clear(); // empty the column
            for(int row = 0; row < rowCount; row++)
            {
                int inverseRow = rowCount - 1 - row; // so lowest note is at the bottom

                // populate the column with buttons
                column.add( std::make_shared<CartesianToggleButton>(col, inverseRow));
                addAndMakeVisible(column.getLast().get()); // show on screen
                
                // add listener to midi output
                column.getLast()->addListener(&midiOut);
            }
            steps.add( column ); // add that newly filled column
        }
    }
    
    SequencerGrid::~SequencerGrid(){}
    
    void SequencerGrid::paint (Graphics& g)
    {
        g.fillAll (Colours::darkgrey);   // clear the background
    }
    
    void SequencerGrid::resized()
    {
        // Setup grid with correct no of rows and columns
        Grid grid;
        
        grid.setGap(5_px);
        
        for(int row = 0; row < rowCount; row++)
            grid.templateRows.add( Grid::TrackInfo (1_fr) );
        
        for(int col = 0; col < columnCount; col++)
            grid.templateColumns.add( Grid::TrackInfo (1_fr) );
        
        // Add items to the grid from our 2d array of buttons (steps)
        for(int row = 0; row < rowCount; row++)
        {
            for(int col = 0; col < columnCount; col++)
            {
                auto column = steps.getUnchecked(col);
                grid.items.add( column.getUnchecked(row).get() );
            }
        }
        
        grid.performLayout( getLocalBounds() );
    }
    
} //namespace gui
