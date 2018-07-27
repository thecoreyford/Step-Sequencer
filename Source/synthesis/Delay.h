/*
 ==============================================================================
 
 Delay.h
 Created: 15 Jul 2018 9:27:47pm
 Author:  Corey Ford
 
 ==============================================================================
 */

#pragma once

namespace synthesis {
    
    class Delay
    {
    public:
        Delay()
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
        
        ~Delay(){}
        
        float process(const float input, const int delayInSamples)
        {
            
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
        const int BUFFER_SIZE = 176400; //< 4sec delay assuming 44.1khz fs
        float buffer[BUFFER_SIZE];
        
        int writePosition;
        int readPosition;
        
    };

} //namespace synthesis
