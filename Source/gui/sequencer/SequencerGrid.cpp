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
    SequencerGrid::SequencerGrid(const int rowCount, const int columnCount) : _rowCount(rowCount),
                                                                              _columnCount(columnCount)
    {
        Array< std::shared_ptr<CustomToggle> > column;
        for(int col = 0; col < columnCount; col++)
        {
            column.clear(); //empty the column
            for(int row = 0; row < rowCount; row++)
            {
                //populate the column with buttons
                column.add( std::make_shared<CustomToggle>(row, col) );
                addAndMakeVisible(column.getLast().get()); //show on screen 
            }
            steps.add( column ); //add that newly filled column
        }
        
    }
    
    SequencerGrid::~SequencerGrid(){}
    
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
        
        for(int row = 0; row < _rowCount; row++)
        {
            for(int col = 0; col < _columnCount; col++)
            {
                auto column = steps.getUnchecked(col);
                grid.items.add( column.getUnchecked(row).get() );
            }
        }
        
        grid.performLayout( getLocalBounds() );
    }
    
} //namespace gui
