#ifndef WAVE_H
#define WAVE_H

#include "MathConsts.h"
#include "SoundByte.h"
#include <vector>

// generic wave form to make sounds from
// needs to be defined from 0 to 2pi and it will be assumed that it is periodic

// one second is x = 1
class Wave {
    public:
        Wave(double frequency, double amplitude);
        ~Wave();
        // Returns the wave as a sound
        std::vector<SoundByte> getSoundBytes(double duration, double sampleRate);
    private:
        // returns a double for every x between 0 and 2pi
        double evaluate(double x);
        virtual double evaluateOriginal(double x) = 0;
        double m_frequency = MathConsts::TWO_PI;
        double m_amplitude = 1.0;
};

#endif