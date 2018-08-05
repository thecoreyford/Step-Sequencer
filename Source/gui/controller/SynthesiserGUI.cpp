/*
  ==============================================================================

    SynthesiserGUI.cpp
    Created: 6 Jul 2018 7:21:09pm
    Author:  Corey Ford

  ==============================================================================
*/

#include "SynthesiserGUI.h"

//==============================================================================

namespace gui
{
    SynthesiserGUI::SynthesiserGUI(audio::Audio& audio) : _audio(audio)
    {
        // In your constructor, you should add any child components, and
        // initialise any special settings that your component needs.
        startTimer(1);
        
        addAndMakeVisible(oscChoice);
        oscChoice.addItem("sine", 1);
        oscChoice.addItem("square", 2);
        oscChoice.addItem("saw",3);
        oscChoice.addItem("triangle",4);
        oscChoice.onChange = [this]
        {
            _audio.setOscillator(oscChoice.getSelectedId());
        };
        
        //======================================================================
        
        addAndMakeVisible(filter);
        filter.setRange(20.0, 20000.0);
        filter.setValue(20000.0);
        filter.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
        filter.setSkewFactorFromMidPoint(10020);
        addAndMakeVisible (filterLabel);
        filterLabel.setText ("LPF", dontSendNotification);
        filterLabel.attachToComponent (&filter, true);
        filter.onValueChange = [this]
        {
            _audio.setFilterCutoff(filter.getValue());
        };
    }
    
    SynthesiserGUI::~SynthesiserGUI(){}
    
    void SynthesiserGUI::paint (Graphics& g)
    {
        g.fillAll (Colours::green);   // clear the background
    }
    
    void SynthesiserGUI::resized()
    {
        Rectangle<int> oscRect, filterRect;
        oscRect = filterRect = getLocalBounds();
        oscRect.removeFromBottom(getLocalBounds().getHeight() * 0.5);
        filterRect.removeFromTop(getLocalBounds().getHeight() * 0.5);
        filterRect.removeFromLeft(40/*for label*/);
        
        oscChoice.setBounds(oscRect);
        filter.setBounds(filterRect);
    }
    
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

