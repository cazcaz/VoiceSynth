#include "../header/SoundByte.h"

SoundByte::SoundByte(double pitch, double length) : m_pitch(pitch) , m_length(length) {};

SoundByte::~SoundByte() = default;

double SoundByte::getPitch() {
    return m_pitch;
}

double SoundByte::getLength() {
    return m_length;
}