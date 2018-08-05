/*
  ==============================================================================

    Filters.h
    Created: 5 Aug 2018 10:55:48pm
    Author:  Corey Ford

  ==============================================================================
*/

#pragma once

#include "Delay.h"
#define _USE_MATH_DEFINES // for use with windows
#include <math.h>
#include <assert.h>

namespace synthesis{
namespace filter{
        
    class OnePole
    {
    public:
        OnePole()
        {
            a0 = 0.0f;
            b1 = 0.0f;
            y1 = 0.0f;
            
            sampleRate = 44100.0; // assumed
            setCutoff(20000.0);
        }
        
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
        
        float process(const float input)
        {
            float y0 = 0.0f;
            y0 = (a0 * input) - (b1 * y1);
            y1 = y0;
            return y0;
        }
        
    private:
        float a0, b1, y1;
        float sampleRate;
        float fc;
    };
        
} // namespace filter
} // namespace synthesis
