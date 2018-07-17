/*
  ==============================================================================

    KeyboardGrid.h
    Created: 10 Jul 2018 4:13:35pm
    Author:  Corey Ford

  ==============================================================================
*/

#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../widgets/Key.h"

//==============================================================================

namespace gui
{
    /*
     A visual representation of an onscreen keyboard within a grid. 
     */
    class KeyboardGrid : public Component
    {
    public:
        KeyboardGrid(const int rowCount);
        ~KeyboardGrid();
        
        void paint (Graphics&) override;
        void resized() override;
        
    private:
        
        KeyboardGrid();
        
        int _rowCount;
        
        OwnedArray<Key> _keys;
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KeyboardGrid)
    };
    
} // namespace gui

