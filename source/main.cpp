
#include "../header/wavWriter.h"
#include "../header/Sound.h"
#include "../header/SoundByte.h"
#include "../header/SineWave.h"
#include "../header/SquareWave.h"
#include "../header/TriangleWave.h"
#include "../header/SawtoothWave.h"

#include <iostream>

int main() {
    
    Sound testSound{};
    std::ofstream testFile("test.wav", std::ios::binary);
    SineWave testWave1(256, 5000);
    SquareWave testWave2(256, 5000);
    TriangleWave testWave3(256, 5000);
    SawtoothWave testWave4(256, 5000);
    testSound.addSoundByte(testWave1.getSoundBytes(1, testSound.getSampleRate()));
    testSound.addSoundByte(testWave2.getSoundBytes(1, testSound.getSampleRate()));
    testSound.addSoundByte(testWave3.getSoundBytes(1, testSound.getSampleRate()));
    testSound.addSoundByte(testWave4.getSoundBytes(1, testSound.getSampleRate()));
    WavWriter wavWriter(testSound);
    if (!wavWriter.write(testFile)) {
        std::cout << "Wav file not written" << std::endl;
        return 1;
    }
    std::cout << "Wav file written" << std::endl;
    return 0;
}