/*
 ==============================================================================
 
 Oscillator.cpp
 Created: 02 Jul 2018
 Author:  Corey Ford
 
 ==============================================================================
 */

#include "Oscillator.h"

namespace synthesis
{
    namespace osc
    {
            
        Oscillator::Oscillator()
        {
            //Assign defaults for local variables.
            freq = 440.f;
            amp = 0.9f;
            sampleRate = 44100.0;
            currentPhase = 0.f;
            setPhaseIncrement();
        }
        
        Oscillator::~Oscillator(){}
        
        void Oscillator::setFrequency(float frequencyParam)
        {
            freq = frequencyParam;
            setPhaseIncrement();
        }
        
        void Oscillator::setAmplitude(float ampParam)
        {
            amp = ampParam;
        }
        
        void Oscillator::setSampleRate(double sampleRateParam)
        {
            sampleRate = sampleRateParam;
            setPhaseIncrement();
        }
        
        float Oscillator::getSample()
        {
            float sample = 0;
            
            currentPhase += phaseIncrement;
            sample =  waveshape(currentPhase);
            sample *= amp;
            
            if( currentPhase > ( 2.f * M_PI ) )
                currentPhase -= ( 2.f * M_PI );
            
            return sample;
        }
        
        void Oscillator::setPhaseIncrement()
        {
            phaseIncrement = (2.f * M_PI * freq) / sampleRate;
        }
            
    }// namespace osc
} // namespace synthesis
