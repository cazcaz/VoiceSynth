#ifndef SAWTOOTH_WAVE_H
#define SAWTOOTH_WAVE_H

#include "Wave.h"

class SawtoothWave : public Wave {
    public:
        SawtoothWave(double frequency, double amplitude);
        ~SawtoothWave();
    private:
        double evaluateOriginal(double) override;
};

#endif