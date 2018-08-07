/*
 ==============================================================================
 
 Delay.h
 Created: 15 Jul 2018 9:27:47pm
 Author:  Corey Ford
 
 ==============================================================================
 */

#pragma once

namespace synthesis {
    
    /**
     * A delay buffer object.
     */
    class Delay
    {
    public:
        /**
         * Constructor. Initialises the buffer with 0 values.
         */
        Delay() //TODO(corey2.ford@live.uwe.ac.uk): dynamically allocate buffer: maybe template specialisations for different durations
        {
            //populate with zero delay to start with
            for(int i = 0; i < BUFFER_SIZE; i++)
            {
                buffer[i] = 0.0f;
            }
            
            //initilise write and read positions
            writePosition = 0;
            readPosition = 0;
        }
        
        /** Destructor. */
        ~Delay(){}
        
        /**
         * Return one queue movement for the delayed buffer.
         * @param input is the 'dry' sample to be added
         * @param delayInSamples is how long the value should wait until. 
         * @return the delayed output sample.
         */
        float process(const float input, const int delayInSamples)
        {
            jassert(delayInSamples <= BUFFER_SIZE);
            
            writePosition++;
            if(writePosition == BUFFER_SIZE)
            {
                writePosition = 0;
            }
            buffer[writePosition] = input;
            
            readPosition = writePosition - delayInSamples;
            if(readPosition < 0)
            {
                readPosition += BUFFER_SIZE;
            }
            
            return buffer[readPosition];
            
        }
        
    private:
        /** A buffer count for a 4sec delay assuming 44.1khz fs */
        static const int BUFFER_SIZE = 176400;
        /** Our buffer array of samples. */
        float buffer[BUFFER_SIZE];
        
        /** The current write position (array index). */
        int writePosition;
        /** The current read position (array index). */
        int readPosition;
    };
    
    //==========================================================================
    
    /**
     * A single sample delay.
     */
    class SampleDelay
    {
    public:
        /**
         * Constructor. Ensure delayed sample starts at 0.
         */
        SampleDelay()
        {
            delayedSample = 0.0f;
        }
        
        /**
         * Delays the input by a single sample value.
         * @param the dry input sample to be delayed. 
         * @return the previous "delayed" sample.
         */
        float process(const float input)
        {
            float output = delayedSample;
            delayedSample = input;
            return output;
        }
        
    private:
        /** Value holding our previous delayed sample. */
        float delayedSample;
    };

} //namespace synthesis
