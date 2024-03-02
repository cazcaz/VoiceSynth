#include "TriangleWave.h"

TriangleWave::TriangleWave(double frequency, double amplitude)
    : Wave(frequency, amplitude){};

TriangleWave::~TriangleWave() = default;

double TriangleWave::evaluateOriginal(double x) {
  if (x <= MathConsts::PI / 2) {
    return x / (MathConsts::PI / 2);
  }
  if (x <= MathConsts::PI * 3 / 2) {
    return 1 - (x - MathConsts::PI / 2) / (MathConsts::PI / 2);
  }
  return -1 + (x - MathConsts::PI * 3 / 2) / (MathConsts::PI / 2);
}