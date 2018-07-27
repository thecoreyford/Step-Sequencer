/**
 *  @file    OscillatorTypes.h
 *  @author  Corey Ford
 *  @date    2/07/2018
 *  @version 1.0
 *
 *  @section DESCRIPTION
 *
 *  A collection of different waveshapes for various oscillators.
 *
 */

#pragma once

#include "Oscillator.h"

#define _USE_MATH_DEFINES
#include <math.h>

namespace synthesis{
namespace osc{
    
    class Sine : public Oscillator
    {
    public:
        virtual float waveshape(const float currentPhase) override
        {
            return sinf(currentPhase);
        }
    };
    
    //======================================================================
    
    class Square : public Oscillator
    {
    public:
        virtual float waveshape(const float currentPhase) override
        {
            if(currentPhase > M_PI)
                return 1.f;
            else
                return -1.f;
        }
    };
    
    //======================================================================
    
    class Triangle : public Oscillator
    {
    public:
        virtual float waveshape(const float currentPhase) override
        {
            float x = currentPhase / (2.f * M_PI);
            return fabsf( ( fmodf( (2.f * x) , 4.f) ) - 2.f ) - 1.f;
        }
    };
    
    //======================================================================
    
    class Saw : public Oscillator
    {
    public:
        virtual float waveshape(const float currentPhase) override
        {
            float x = currentPhase / (2.f * M_PI);
            return 2.f * fabsf( fmodf( x , 1.f ) ) - 1.f;
        }
    };
        
}// namespace osc
} // namespace synthesis
