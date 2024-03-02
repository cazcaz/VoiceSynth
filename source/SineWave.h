#ifndef SINE_WAVE_H
#define SINE_WAVE_H

#include "Wave.h"

class SineWave : public Wave {
 public:
  SineWave(double frequency, double amplitude);
  ~SineWave();

 private:
  double evaluateOriginal(double) override;
};

#endif