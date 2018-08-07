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
    SequencerGUI::SequencerGUI(audio::Audio& audioParam) : audio(audioParam)
    {
        // add grid components
        keyGrid = std::make_unique<KeyboardGrid>(ROW_COUNT);
        seqGrid = std::make_unique<SequencerGrid>(ROW_COUNT, COLUMN_COUNT);
        addAndMakeVisible(seqGrid.get());
        addAndMakeVisible(keyGrid.get());
        
        // listener to the midi output device
        audio::MidiOut& midiOut = audio::MidiOut::getInstance();
        midiOut.addListener(this);
        
        // setup visual component
        visual = std::make_shared<AudioVisualiserComponent>(1);
        visual.get()->setSamplesPerBlock(512);
        visual.get()->setRepaintRate(30);
        audio.linkAudioVisualiserComponent(visual);
        
        addAndMakeVisible(visual.get());
        visual.get()->setVisible(false);
    }
    
    SequencerGUI::~SequencerGUI(){}
    
    void SequencerGUI::paint (Graphics& g)
    {
        g.fillAll (Colours::darkslateblue);   // clear the background
    }
    
    void SequencerGUI::resized()
    {
        // split screen bounds into different rectange areas
        Rectangle<int> sequencerRectangle, keyboardRectangle, visualRectangle;
        sequencerRectangle = keyboardRectangle = visualRectangle = getLocalBounds();
        sequencerRectangle.removeFromLeft(getWidth() * 0.30);
        keyboardRectangle.removeFromRight(getWidth() * 0.70);
        visualRectangle.removeFromTop(getHeight() * 0.10);
        visualRectangle.removeFromBottom(getHeight() * 0.10);
        visualRectangle.removeFromLeft(keyboardRectangle.getWidth());
        
        // apply components to these areas
        seqGrid->setBounds(sequencerRectangle);
        keyGrid->setBounds(keyboardRectangle);
        visual->setBounds(visualRectangle);
    }
    
    void SequencerGUI::playbackStateChanged(bool isPlaying)
    {
        // change visibility of classes depending on playback state
        if(isPlaying)
        {
            seqGrid.get()->setVisible(false);
            visual.get()->setVisible(true);
        }
        else
        {
            seqGrid.get()->setVisible(true);
            visual.get()->setVisible(false); 
        }
    }
}
