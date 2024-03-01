#ifndef WAVWRITER_H
#define WAVWRITER_H

#include "SoundWriter.h"


class WavWriter : public SoundWriter {
    public:
        WavWriter(const Sound&);
        ~WavWriter();
        bool write(std::ofstream&) override;
};

#endif