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
        oscChoice.addListener(this);
    }
    
    SynthesiserGUI::~SynthesiserGUI(){}
    
    void SynthesiserGUI::paint (Graphics& g)
    {
        g.fillAll (Colours::green);   // clear the background
    }
    
    void SynthesiserGUI::resized()
    {
        oscChoice.setBounds(getLocalBounds());
        
    }
    
    void SynthesiserGUI::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
    {
        if(comboBoxThatHasChanged == &oscChoice)
        {
            _audio.setOscillator(comboBoxThatHasChanged->getSelectedId());
        }
    }
    
    void SynthesiserGUI::timerCallback()
    {
        if(audio::MidiOut::getInstance().getPlaying() == true)
        {
            DBG("INVISBIBLE");
            oscChoice.setVisible(false);
        }
        else
        {
            oscChoice.setVisible(true);
        }
        
        repaint();
    }

    
}//namespace gui

