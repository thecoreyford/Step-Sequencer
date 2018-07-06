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
        
    }
    
}
