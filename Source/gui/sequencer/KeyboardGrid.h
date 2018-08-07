/**
 *  @file    KeyboardGrid.h
 *  @author  Corey Ford
 *  @date    10/07/2018
 *  @version 1.0
 *
 *  @section DESCRIPTION
 *
 *  A visual representation of an oncreen keyboard with a grid.
 *
 */

#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../widgets/Key.h"
#include "../../audio/MidiOut.h"

//==============================================================================

namespace gui
{
    /*
     *  A visual representation of an onscreen keyboard within a grid.
     */
    class KeyboardGrid : public Component
    {
    public:
        /**
         * Constructor. Adds each key to visuals.
         * @param The number of keys to be added.
         */
        KeyboardGrid(const int rowCountParam);
        
        /** Destructor. */
        ~KeyboardGrid();
        
        /**
         *  Fills component with spacing colour.
         *  @param the graphics context for painting.
         */
        void paint (Graphics&) override;
        
        /** Sets bounds for sub components.*/
        void resized() override;
        
    private:
        /** Private constructor, must supply no of rows */
        KeyboardGrid();
        
        /** Total number of rows (keys) to be added.*/
        int rowCount;
        
        /** Pointers to key objects. */
        OwnedArray<Key> keys;
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KeyboardGrid)
    };
    
} // namespace gui

