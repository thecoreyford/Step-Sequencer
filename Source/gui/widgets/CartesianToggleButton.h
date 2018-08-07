/**
 *  @file    KeyboardGrid.h
 *  @author  Corey Ford
 *  @date    20/07/2018
 *  @version 1.0
 *
 *  @section DESCRIPTION
 *
 *  An binary toggle button indexed via a pair of co-ordinates.
 *
 */

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================

namespace gui
{
    /**
     *  An binary toggle button indexed via a pair of co-ordinates.
     */
    class CartesianToggleButton : public Component
    {
    public:
        /**
         * Constructor. Sets co-ordinate object & initalises variables.
         * @param x is the X-axis index co-ordinate.
         * @param y is the Y-axis index co-ordinate.
         */
        CartesianToggleButton(const int x, const int y);
        
        /**
         * Destructor. 
         */
        ~CartesianToggleButton();
        
        /**
         *  Sets the fill colour depending on toggled state.
         *  @param the graphics context for painting.
         */
        void paint (Graphics&) override;
        
        /** Sets bounds. */
        void resized() override;
        
        /**
         * Changes the current state and broadcasts a change event. 
         * @param the mouse event triggered.
         */
        void mouseDown (const MouseEvent & event) override;
        
        /**
         * Acessor for the current state of the button.
         */
        bool getState() const;
        
        /**
         * Mutator for the button state. 
         * @param the new state for the cartesian toggle button.
         */
        void setState(const bool stateParam);
        
        //======================================================================
        
        /**
         * Listener for when the button changes state.
         */
        class Listener
        {
        public:
            /** Destructor. */
            virtual ~Listener() {}
            
            /**
             * Callback for change of toggle state. 
             * @param the current (new) state of the button.
             * @param the x co-ordinate indexing the button. 
             * @param the y co-ordinate indexing the button.
             */
            virtual void cartesianToggleChanged(const bool state,
                                                const int x,
                                                const int y) = 0;
        };
        
        /**
         * Acessor for the listener object. 
         * @param the pointer this object will be assigned to.
         */
        void addListener (Listener* listenerParam);
        
        //======================================================================
        
    private:
        /** Private constructor. */
        CartesianToggleButton();
        
        /** The state of the button - either on or off. */
        bool state;
        
        /** The index object for this button. */
        Point<int> coOrdinates;
        
        /** Pointer to any listening objects. */
        Listener* listener;
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CartesianToggleButton)
    };
    
} // namespace


