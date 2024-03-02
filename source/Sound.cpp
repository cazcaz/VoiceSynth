#include "Sound.h"

Sound::Sound(){};

Sound::~Sound() = default;

void Sound::addSoundByte(SoundByte soundByte) {
  m_soundData.push_back(soundByte);
  m_length += soundByte.getLength();
}

void Sound::addSoundByte(std::vector<SoundByte> soundBytes) {
  m_soundData.insert(m_soundData.end(), soundBytes.begin(), soundBytes.end());
  for (auto& soundByte : soundBytes) {
    m_length += soundByte.getLength();
  }
}

bool Sound::valid() const {
  if (m_samples <= 0) {
    return false;
  }
  if (m_length <= 0) {
    return false;
  }
  if (m_soundData.empty()) {
    return false;
  }
  return true;
}