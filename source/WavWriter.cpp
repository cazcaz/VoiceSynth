#include "WavWriter.h"

#include <cmath>
#include <iostream>
#include <memory>

#include "LEndian.h"
#include "Sound.h"

WavWriter::WavWriter(const Sound& sound) : SoundWriter(sound) {}

WavWriter::~WavWriter() {}

bool WavWriter::write(std::ofstream& wavFile) {
  if (!m_sound.valid()) {
    return false;
  }
  int channels = 2;
  int bitsPerSample = 16;

  // write the header for the wav file
  wavFile << "RIFF----WAVEfmt ";  // (chunk size to be filled in later)
  LittleEndian::write_word(wavFile, 16, 4);
  LittleEndian::write_word(wavFile, 1, 2);
  LittleEndian::write_word(wavFile, 2, 2);
  LittleEndian::write_word(wavFile, (int)(m_sound.getSampleRate()), 4);
  LittleEndian::write_word(
      wavFile, (int)(m_sound.getSampleRate() * bitsPerSample * channels / 8),
      4);
  LittleEndian::write_word(wavFile, 4, 2);
  LittleEndian::write_word(wavFile, 16, 2);

  size_t data_chunk_pos = wavFile.tellp();
  wavFile << "data----";  // (chunk size to be filled in later)
  std::vector<SoundByte> soundData = m_sound.getSoundData();

  for (int n = 0; n < soundData.size(); n++) {
    LittleEndian::write_word(wavFile, (int)(soundData[n].getPitch()), 2);
    LittleEndian::write_word(wavFile, (int)(soundData[n].getPitch()), 2);
  }

  // (We'll need the final file size to fix the chunk sizes above)
  size_t file_length = wavFile.tellp();

  // Fix the data chunk header to contain the data size
  wavFile.seekp(data_chunk_pos + 4);
  LittleEndian::write_word(wavFile, file_length - data_chunk_pos + 8);

  // Fix the file header to contain the proper RIFF chunk size, which is (file
  // size - 8) bytes
  wavFile.seekp(0 + 4);
  LittleEndian::write_word(wavFile, file_length - 8, 4);

  return true;
}