/*
  ==============================================================================

    SynthesiserGUI.cpp
    Created: 6 Jul 2018
    Author:  Corey Ford

  ==============================================================================
*/

#include "SynthesiserGUI.h"

//==============================================================================

namespace gui
{
    SynthesiserGUI::SynthesiserGUI(audio::Audio& audioParam) : audio(audioParam)
    {
        // start timer to listen for playback state
        startTimer(1);
        
        // setup oscillator banks
        addAndMakeVisible(oscChoice);
        oscChoice.addItem("sine", 1);
        oscChoice.addItem("square", 2);
        oscChoice.addItem("saw",3);
        oscChoice.addItem("triangle",4);
        oscChoice.onChange = [this]
        {
            audio.setOscillator(oscChoice.getSelectedId());
        };
        
        //======================================================================
        
        // setup filter control
        addAndMakeVisible(filter);
        filter.setRange(20.0, 19999.0);
        filter.setValue(19999.0);
        filter.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
        filter.setSkewFactorFromMidPoint(10020);
        addAndMakeVisible (filterLabel);
        filterLabel.setText ("LPF", dontSendNotification);
        filterLabel.attachToComponent (&filter, true);
        filter.onValueChange = [this]
        {
            audio.setFilterCutoff(filter.getValue());
        };
    }
    
    SynthesiserGUI::~SynthesiserGUI(){}
    
    //==========================================================================
    
    void SynthesiserGUI::paint (Graphics& g)
    {
        g.fillAll (Colours::green);   // clear the background
    }
    
    void SynthesiserGUI::resized()
    {
        // setup rectangle portions
        Rectangle<int> oscRect, filterRect;
        oscRect = filterRect = getLocalBounds();
        oscRect.removeFromBottom(getLocalBounds().getHeight() * 0.5);
        filterRect.removeFromTop(getLocalBounds().getHeight() * 0.5);
        filterRect.removeFromLeft(40/*for label*/);
        
        // set objects to these portions
        oscChoice.setBounds(oscRect);
        filter.setBounds(filterRect);
    }
    
    //==========================================================================
    
    void SynthesiserGUI::timerCallback()
    {
        if(audio::MidiOut::getInstance().getPlaying() == true)
        {
            oscChoice.setVisible(false);
            filterLabel.setVisible(false);
            filter.setVisible(false);
        }
        else
        {
            oscChoice.setVisible(true);
            filterLabel.setVisible(true);
            filter.setVisible(true);
        }
        
        repaint();
    }
    
}//namespace gui

