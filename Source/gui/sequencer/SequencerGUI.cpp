/*
  ==============================================================================

    SequencerGUI.cpp
    Created: 6 Jul 2018 6:43:06pm
    Author:  Corey Ford

  ==============================================================================
*/

#include "SequencerGUI.h"

//==============================================================================

namespace gui
{
    SequencerGUI::SequencerGUI()
    {
        addAndMakeVisible(_seqGrid);
        addAndMakeVisible(_keyGrid);
    }
    
    SequencerGUI::~SequencerGUI()
    {
    }
    
    void SequencerGUI::paint (Graphics& g)
    {
        g.fillAll (Colours::red);   // clear the background
    }
    
    void SequencerGUI::resized()
    {
        Rectangle<int> sequencerRectangle, keyboardRectangle;
        sequencerRectangle = keyboardRectangle = getLocalBounds();
        sequencerRectangle.removeFromLeft(getWidth() * 0.30);
        keyboardRectangle.removeFromRight(getWidth() * 0.70);
        
        _seqGrid.setBounds(sequencerRectangle);
        _keyGrid.setBounds(keyboardRectangle);
    }
    
}
