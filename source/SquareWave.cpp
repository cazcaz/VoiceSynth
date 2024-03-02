#include "SquareWave.h"

SquareWave::SquareWave(double frequency, double amplitude)
    : Wave(frequency, amplitude){};

SquareWave::~SquareWave() = default;

double SquareWave::evaluateOriginal(double x) {
  if (x <= MathConsts::PI) {
    return 1;
  }
  return -1;
}