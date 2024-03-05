#include "Wave.h"

#include <cmath>

#include "MathConsts.h"

Wave::Wave(double frequency, double amplitude)
    : m_frequency(MathConsts::TWO_PI * frequency), m_amplitude(amplitude) {}

Wave::~Wave() {}

std::vector<SoundByte> Wave::getSoundBytes(double duration, double sampleRate) {
  std::vector<SoundByte> soundBytes;
  soundBytes.reserve(duration * sampleRate);
  for (int i = 0; i < duration * sampleRate; i++) {
    soundBytes.push_back(SoundByte(evaluate(i / sampleRate), 1 / sampleRate));
  }
  return soundBytes;
};

double Wave::evaluate(double x) {
  double scaledX = m_frequency * x;
  double movedX =
      scaledX - floor(scaledX / MathConsts::TWO_PI) * MathConsts::TWO_PI;
  return m_amplitude * evaluateOriginal(movedX);
}
