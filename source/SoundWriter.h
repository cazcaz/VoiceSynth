#ifndef SOUNDWRITER_H
#define SOUNDWRITER_H

#include <fstream>
#include <memory>

class Sound;

class SoundWriter {
 public:
  SoundWriter(const Sound&);
  virtual ~SoundWriter() = 0;
  virtual bool write(std::ofstream&) = 0;

 protected:
  const Sound& m_sound;
};

#endif