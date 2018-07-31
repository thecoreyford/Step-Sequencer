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
    SequencerGUI::SequencerGUI(audio::Audio& audio) : _audio(audio)
    {
        _keyGrid = std::make_unique<KeyboardGrid>(_rowCount);
        _seqGrid = std::make_unique<SequencerGrid>(_rowCount, _columnCount);
        addAndMakeVisible(_seqGrid.get());
        addAndMakeVisible(_keyGrid.get());
        
        audio::MidiOut& midiOut = audio::MidiOut::getInstance();
        midiOut.addListener(this);
        
        _visual = std::make_shared<AudioVisualiserComponent>(1);
        _visual.get()->setBufferSize(2048);
        _visual.get()->setRepaintRate(30);
        _audio.linkAudioVisualiserComponent(_visual);
        
        addAndMakeVisible(_visual.get());
        _visual.get()->setVisible(false);
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
        Rectangle<int> sequencerRectangle, keyboardRectangle, visualRectangle;
        sequencerRectangle = keyboardRectangle = visualRectangle = getLocalBounds();
        sequencerRectangle.removeFromLeft(getWidth() * 0.30);
        keyboardRectangle.removeFromRight(getWidth() * 0.70);
        visualRectangle.removeFromTop(getHeight() * 0.10);
        visualRectangle.removeFromBottom(getHeight() * 0.10);
        visualRectangle.removeFromLeft(keyboardRectangle.getWidth());
        
        _seqGrid->setBounds(sequencerRectangle);
        _keyGrid->setBounds(keyboardRectangle);
        _visual->setBounds(visualRectangle);
    }
    
    void SequencerGUI::playbackStateChanged(bool isPlaying)
    {
        if(isPlaying)
        {
            _seqGrid.get()->setVisible(false);
            _visual.get()->setVisible(true);
        }
        else
        {
            _seqGrid.get()->setVisible(true);
            _visual.get()->setVisible(false); 
        }
    }
}
