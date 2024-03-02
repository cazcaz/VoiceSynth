#ifndef TRIANGLE_WAVE_H
#define TRIANGLE_WAVE_H

#include "Wave.h"

class TriangleWave : public Wave {
 public:
  TriangleWave(double frequency, double amplitude);
  ~TriangleWave();

 private:
  double evaluateOriginal(double) override;
};

#endif