#include "SawtoothWave.h"

SawtoothWave::SawtoothWave(double frequency, double amplitude)
    : Wave(frequency, amplitude){};

SawtoothWave::~SawtoothWave() = default;

double SawtoothWave::evaluateOriginal(double x) {
  if (x <= MathConsts::PI) {
    return x / MathConsts::PI;
  }
  return -1 + (x - MathConsts::PI) / MathConsts::PI;
}
