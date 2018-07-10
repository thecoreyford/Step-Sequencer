/*
  ==============================================================================

    PlayBackControls.cpp
    Created: 6 Jul 2018 7:20:31pm
    Author:  Corey Ford

  ==============================================================================
*/

#include "PlayBackControls.h"

//==============================================================================

namespace gui
{
    PlayBackControls::PlayBackControls()
    {
        // In your constructor, you should add any child components, and
        // initialise any special settings that your component needs.
        
    }
    
    PlayBackControls::~PlayBackControls()
    {
    }
    
    void PlayBackControls::paint (Graphics& g)
    {
        g.fillAll (Colours::crimson);   // clear the background
    }
    
    void PlayBackControls::resized()
    {
        // This method is where you should set the bounds of any child
        // components that your component contains..
        
    }
    
}
