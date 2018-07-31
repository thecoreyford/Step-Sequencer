/**
 *  @file    Oscillator.cpp
 *  @author  Corey Ford
 *  @date    2/07/2018
 *  @version 1.0
 *
 *  @section DESCRIPTION
 *
 *  A virtual base class for oscillator's based on "math type" implementations
 *  for sample by sample processing. (Implementation)
 *
 */


#include "Oscillator.h"
#define _USE_MATH_DEFINES // for use with windows
#include <math.h>

namespace synthesis{
namespace osc{
        
    Oscillator::Oscillator()
    {
        //Assign defaults for local variables.
        freq_ = 440.f;
        amp_ = 0.9f;
        sampleRate_ = 44100.0;
        currentPhase_ = 0.f;
        setPhaseIncrement();
    }
    
    Oscillator::~Oscillator(){}
    
    void Oscillator::setFrequency(float frequency)
    {
        freq_ = frequency;
        setPhaseIncrement();
    }
    
    void Oscillator::setAmplitude(float amp)
    {
        amp_ = amp;
    }
    
    void Oscillator::setSampleRate(double sampleRate)
    {
        sampleRate_ = sampleRate;
        setPhaseIncrement();
    }
    
    float Oscillator::getSample()
    {
        float sample = 0;
        
        currentPhase_ += phaseIncrement_;
        sample =  waveshape(currentPhase_);
        sample *= amp_;
        
        if( currentPhase_ > ( 2.f * M_PI ) )
            currentPhase_ -= ( 2.f * M_PI );
        
        return sample;
    }
    
    void Oscillator::setPhaseIncrement()
    {
        phaseIncrement_ = (2.f * M_PI * freq_) / sampleRate_;
    }
        
}// namespace osc
} // namespace synthesis
