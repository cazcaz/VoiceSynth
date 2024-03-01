#ifndef SOUNDBYTE_H
#define SOUNDBYTE_H

// This class holds one single sample of sound
class SoundByte {
    public:
        SoundByte(double = 0, double = 0);
        ~SoundByte();
        double getPitch();
        double getLength();
    private:
        double m_pitch;
        double m_length;
};

#endif