#ifndef SOUND_H
#define SOUND_H

#include <vector>
#include "SoundByte.h"

class Sound {
    public:
        Sound();
        ~Sound();
        void addSoundByte(SoundByte);
        void addSoundByte(std::vector<SoundByte>);
        const double getSampleRate() const { return m_samples; };
        double getLength() const { return m_length; };
        std::vector<SoundByte> getSoundData() const { return m_soundData; };
        bool valid() const;
    private:
        std::vector<SoundByte> m_soundData;
        const double m_samples = 44100;
        double m_length;
};

#endif