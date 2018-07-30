/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

namespace gui
{
    //==============================================================================
    MainComponent::MainComponent(audio::Audio& audio) :
    _audio(audio)
    {
        setSize (1200, 800);
        
        addAndMakeVisible(_sequencer);
        addAndMakeVisible(_controller);
    }
    
    MainComponent::~MainComponent(){}
    
    //==============================================================================
    void MainComponent::paint (Graphics& g)
    {
        //completely fill with a horrific solid colour so we know if anythings gone wrong!!!!
        g.fillAll (Colours::hotpink);
    }
    
    void MainComponent::resized()
    {
        Rectangle<int> sequenceRectangle, controllerRectangle;
        sequenceRectangle = controllerRectangle = getLocalBounds();
        sequenceRectangle.removeFromBottom(getHeight() * 0.25);
        controllerRectangle.removeFromTop(getHeight() * 0.75);
        
        _sequencer.setBounds(sequenceRectangle);
        _controller.setBounds(controllerRectangle);
    }
    
} //namespace gui
