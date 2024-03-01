#include "../header/SineWave.h"
#include <cmath>

SineWave::SineWave(double frequency, double amplitude) : Wave(frequency, amplitude) {};

SineWave::~SineWave() = default;

double SineWave::evaluateOriginal(double x) {
    return sin(x);
}