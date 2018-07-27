/*
 ==============================================================================
 
 CartesianToggleButton.h
 Created: 20 Jun 2018 5:27:17pm
 Author:  Corey Ford
 
 ==============================================================================
 */

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================

namespace gui
{
    /*
     */
    class CartesianToggleButton : public Component
    {
    public:
        
        CartesianToggleButton(const int x, const int y);
        
        ~CartesianToggleButton();
        
        void paint (Graphics&) override;
        void resized() override;
        
        void mouseDown (const MouseEvent & event) override;
        
        bool getState() const;
        
        void setState(const bool state);
        
        //======================================================================
        
        class Listener
        {
        public:
            virtual ~Listener() {}
            
            virtual void cartesianToggleChanged(const bool state,
                                                const int x,
                                                const int y) = 0;
        };
        
        void addListener (Listener* listener);
        
        //======================================================================
        
    private:
        
        CartesianToggleButton();
        
        bool _state;
        
        Point<int> _coOrdinates;
        
        Listener* _listener;
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CartesianToggleButton)
    };
    
} // namespace


