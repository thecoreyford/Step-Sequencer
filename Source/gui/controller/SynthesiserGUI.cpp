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
    SynthesiserGUI::SynthesiserGUI()
    {
        // In your constructor, you should add any child components, and
        // initialise any special settings that your component needs.
        
    }
    
    SynthesiserGUI::~SynthesiserGUI()
    {
    }
    
    void SynthesiserGUI::paint (Graphics& g)
    {
        g.fillAll (Colours::green);   // clear the background
    }
    
    void SynthesiserGUI::resized()
    {
        // This method is where you should set the bounds of any child
        // components that your component contains..
        
    }
    
}//namespace gui

