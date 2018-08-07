/*
 ==============================================================================
 
 MainComponent.cpp
 Created: 6 Jul 2018
 Author:  Corey Ford
 
 ==============================================================================
 */

#include "MainComponent.h"

namespace gui
{
    //==========================================================================
    MainComponent::MainComponent(audio::Audio& audioParam) :
    audio(audioParam), sequencer(audioParam), controller(audioParam)
    {
        setSize (1200, 800);
        
        addAndMakeVisible(sequencer);
        addAndMakeVisible(controller);
    }
    
    MainComponent::~MainComponent(){}
    
    //==========================================================================
    
    void MainComponent::paint (Graphics& g)
    {
        //completely fill with a horrific solid colour so we know if anythings gone wrong!!!!
        g.fillAll (Colours::hotpink);
    }
    
    void MainComponent::resized()
    {
        // divide into rectangles
        Rectangle<int> sequenceRectangle, controllerRectangle;
        sequenceRectangle = controllerRectangle = getLocalBounds();
        sequenceRectangle.removeFromBottom(getHeight() * 0.25);
        controllerRectangle.removeFromTop(getHeight() * 0.75);
        
        // set component bounds to divided rectangles
        sequencer.setBounds(sequenceRectangle);
        controller.setBounds(controllerRectangle);
    }
    
} //namespace gui
