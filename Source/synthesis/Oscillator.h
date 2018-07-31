/**
 *  @file    Oscillator.h
 *  @author  Corey Ford
 *  @date    2/07/2018
 *  @version 1.0
 *
 *  @section DESCRIPTION
 *
 *  A virtual base class for oscillator's based on "math type" implementations
 *  for sample by sample processing. (Header)
 *
 */

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

namespace synthesis{
namespace osc{

    class Oscillator
    {
    public:
        
        Oscillator();
        
        virtual ~Oscillator();
        
        // Setters
        
        void setFrequency(float frequency);
        
        void setAmplitude(float amp);
        
        void setSampleRate(double sampleRate);
        
        float getSample();
        
        virtual float waveshape(const float currentPhase) = 0;
        
    private:
        
        void setPhaseIncrement();
        
        float freq_;
        float amp_;
        float currentPhase_;
        float phaseIncrement_;
        double sampleRate_;
        
    }; // class Oscillator
        
} // namespace osc
} // namespace synthesis
