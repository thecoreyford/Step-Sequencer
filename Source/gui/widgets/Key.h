/**
 *  @file    Key.h
 *  @author  Corey Ford
 *  @date    21/07/2018
 *  @version 1.0
 *
 *  @section DESCRIPTION
 *
 *  A graphical representation of a MIDI note keyboard key.
 *
 */

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================

namespace gui
{
    /**
     * A graphical representation of a MIDI note keyboard key.
     */
    class Key : public Component
    {
    public:
        /**
         * Constructor. Sets the number for this key.
         * @param The MIDI note number for this key.
         */
        Key(const int noteNumberParam);
        
        /** Destructor. */
        ~Key();
        
        
        /**
         *  Assigns the fill colour and text value colours depending on note number.
         *  @param the graphics context for painting.
         */
        void paint (Graphics&) override;
        
        /** Sets bounds. */
        void resized() override;
        
        /** Returns the MIDI note value for this key. */
        int getNoteNumber() const;
        
    private:
        /** Private Constructor */
        Key();
        
        /** The MIDI note value for this key. */
        int noteNumber;
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Key)
    };
    
} // namespace gui

