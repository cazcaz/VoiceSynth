#ifndef SQUARE_WAVE_H
#define SQUARE_WAVE_H

#include "Wave.h"

class SquareWave : public Wave {
    public:
        SquareWave(double frequency, double amplitude);
        ~SquareWave();
    private:
        double evaluateOriginal(double) override;
};

#endif