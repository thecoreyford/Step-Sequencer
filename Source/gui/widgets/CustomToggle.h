/*
 ==============================================================================
 
 CustomToggle.h
 Created: 20 Jun 2018 5:27:17pm
 Author:  Corey Ford
 
 ==============================================================================
 */

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================

//TODO(corey2.ford@live.uwe.ac.uk): refactor to be modular as a toggle button
//                                  conjoined with the juce point class!

namespace gui
{
    /*
     */
    class CustomToggle : public Component
    {
    public:
        
        CustomToggle(const int row, const int column);
        
        ~CustomToggle();
        
        void paint (Graphics&) override;
        void resized() override;
        
        void mouseDown (const MouseEvent & event) override;
        
        bool getState() const;
        
        //======================================================================
        
        class Listener
        {
        public:
            virtual ~Listener() {}
            
            virtual void customToggleChanged(const bool state,
                                             const int row,
                                             const int column) = 0;
        };
        
        void addListener (Listener* listener);
        
        //======================================================================
        
    private:
        
        CustomToggle();
        
        bool _state;
        
        const int _row;
        const int _column;
        
        Listener* _listener;
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CustomToggle)
    };
    
} // namespace


