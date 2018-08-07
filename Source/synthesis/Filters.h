/**
 *  @file    Filters.h
 *  @author  Corey Ford
 *  @date    5/08/2018
 *  @version 1.0
 *
 *  @section DESCRIPTION
 *
 *  A collection of very basic filters.
 *
 */


#pragma once

#include "Delay.h"
#define _USE_MATH_DEFINES // for use with windows
#include <math.h>
#include <assert.h>

namespace synthesis
{
    namespace filter
    {
        
        /**
         * A OnePole LPF Filter.
         */
        class OnePole
        {
        public:
            /**
             * Constructor, sets sample rate and co-efficients.
             */
            OnePole()
            {
                a0 = 0.0f;
                b1 = 0.0f;
                y1 = 0.0f;
                
                sampleRate = 44100.0; // assumed
                setCutoff(20000.0); // default
            }
            
            /**
             * Calculates co-efficents based on the cutoff asked for.
             * @param the cutoff frequency desired/
             */
            void setCutoff(float cutoff)
            {
                // input frequency cutoff must be within range
                assert( cutoff > 0 && cutoff < (sampleRate / 2.0f) );
                fc = cutoff;
                
                // calculate 'c'
                float c = 2.0f - cosf(2.0f * M_PI * fc / sampleRate);
                
                // update co-efficients
                b1 = sqrt( (c * c) - 1.0f ) - c;
                a0 = 1.0f + b1;
            }
            
            /**
             * The sample calulation for a filtered valued. 
             * @param the original 'dry' input sample.
             * @return the altered 'wet' output sample. 
             */
            float process(const float input)
            {
                float y0 = 0.0f;
                y0 = (a0 * input) - (b1 * y1);
                y1 = y0;
                return y0;
            }
            
        private:
            /** Co-efficents for algebraic filter calculation */
            float a0, b1, y1;
            /** The sample rate for the filter calcluations */
            float sampleRate; //TODO(corey2.ford@live.uwe.ac.uk): don't hardcode this!
            /** Filters current frequency cutoff */
            float fc;
        };
        
    } // namespace filter
} // namespace synthesis
