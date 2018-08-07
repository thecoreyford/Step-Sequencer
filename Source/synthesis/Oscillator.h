/**
 *  @file    Oscillator.h
 *  @author  Corey Ford
 *  @date    2/07/2018
 *  @version 1.0
 *
 *  @section DESCRIPTION
 *
 *  A virtual base class for oscillator's based on "math type" implementations
 *  for sample by sample processing.
 *
 */

#pragma once

#include "Oscillator.h"
#define _USE_MATH_DEFINES // for use with windows
#include <math.h>
#include "../JuceLibraryCode/JuceHeader.h"

namespace synthesis
{
    namespace osc
    {
        /**
         *  A virtual base class for oscillator's based on "math type" implementations
         *  for sample by sample processing.
         */
        class Oscillator
        {
        public:
            /**
             * Constructor. Initalises defaults.
             */
            Oscillator();
            
            /** Destructor. */
            virtual ~Oscillator();
            
            /**
             * Setter for frequency, updates phase increment.
             * @param the new frequency value.
             */
            void setFrequency(float frequencyParam);
            
            /**
             * Setter for amplitude.
             * @param the new amplitude value wanted.
             */
            void setAmplitude(float ampParam);
            
            /**
             * Setter for sampleRate.
             * @param the new sample rate.
             */
            void setSampleRate(double sampleRateParam);
            
            /**
             * Returns the next sample needed for an oscillation. 
             * @return the next sample needed for the oscillaton.
             */
            float getSample();
            
            /**
             * The waveshaping function determing the oscillators shape. 
             * @param the current phase of the oscillation. 
             * @return the altered sample value based on the current phase.
             */
            virtual float waveshape(const float currentPhaseParam) = 0;
            
        private:
            
            /**
             * Setter, updating the phase increment based on samplerate.
             */
            void setPhaseIncrement();
            
            float freq;
            float amp;
            float currentPhase;
            float phaseIncrement;
            double sampleRate;
            
        }; // class Oscillator
            
    } // namespace osc
} // namespace synthesis
