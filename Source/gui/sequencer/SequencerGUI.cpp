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
        _keyGrid = std::make_unique<KeyboardGrid>(_rowCount);
        _seqGrid = std::make_unique<SequencerGrid>(_rowCount, _columnCount);
        addAndMakeVisible(_seqGrid.get());
        addAndMakeVisible(_keyGrid.get());
        
        audio::MidiOut& midiOut = audio::MidiOut::getInstance();
        midiOut.addListener(this);
    }
    
    SequencerGUI::~SequencerGUI()
    {
    }
    
    void SequencerGUI::paint (Graphics& g)
    {
        g.fillAll (Colours::darkslateblue);   // clear the background
    }
    
    void SequencerGUI::resized()
    {
        Rectangle<int> sequencerRectangle, keyboardRectangle;
        sequencerRectangle = keyboardRectangle = getLocalBounds();
        sequencerRectangle.removeFromLeft(getWidth() * 0.30);
        keyboardRectangle.removeFromRight(getWidth() * 0.70);
        
        _seqGrid->setBounds(sequencerRectangle);
        _keyGrid->setBounds(keyboardRectangle);
    }
    
    void SequencerGUI::playbackStateChanged(bool isPlaying)
    {
        if(isPlaying)
        {
            _seqGrid.get()->setVisible(false);
        }
        else
        {
            _seqGrid.get()->setVisible(true);
        }
    }
}
