#include <cmath>
#include <memory>

#include "../catch2/src/catch2/catch_test_macros.hpp"
#include "../source/MathConsts.h"
#include "../source/SawtoothWave.h"
#include "../source/SineWave.h"
#include "../source/SquareWave.h"
#include "../source/TriangleWave.h"

class TestHelper {
 public:
  static bool checkSoundValues(std::vector<double> sourceSoundData,
                               std::vector<double> testSoundData) {
    if (sourceSoundData.size() != testSoundData.size()) {
      return false;
    }
    for (int i = 0; i < sourceSoundData.size(); i++) {
      if (sourceSoundData[i] != testSoundData[i]) {
        return false;
      }
    }
    return true;
  }
};
TEST_CASE("Wave can produce") {
  SECTION("a middle C sine wave") {
    double hz = 44100;           // samples per second
    double frequency = 261.626;  // middle C
    double seconds = 2;          // time
    double amplitude = 16000;    // "volume"
    int N = hz * seconds;        // total number of samples

    std::vector<double> sourceSoundData;
    for (int n = 0; n < N; n++) {
      double value = sin((MathConsts::TWO_PI * n * frequency) / hz);
      sourceSoundData.push_back((int)(amplitude * value));
    }
    SineWave testWave1(261.626, 16000);
    std::vector<SoundByte> testSoundBytes = testWave1.getSoundBytes(2, 44100);
    std::vector<double> testSoundData;
    for (auto& soundByte : testSoundBytes) {
      testSoundData.push_back((int)(soundByte.getPitch()));
    }
    CHECK(TestHelper::checkSoundValues(sourceSoundData, testSoundData));
  }
  SECTION("a middle C square wave") {
    double hz = 44100;           // samples per second
    double frequency = 261.626;  // middle C
    double seconds = 2;          // time
    double amplitude = 16000;    // "volume"
    int N = hz * seconds;        // total number of samples

    std::vector<double> sourceSoundData;
    for (int n = 0; n < N; n++) {
      double value =
          sin((MathConsts::TWO_PI * n * frequency) / hz) >= 0 ? 1.0 : -1.0;
      sourceSoundData.push_back((int)(amplitude * value));
    }
    SquareWave testWave2(261.626, 16000);
    std::vector<SoundByte> testSoundBytes = testWave2.getSoundBytes(2, 44100);
    std::vector<double> testSoundData;
    for (auto& soundByte : testSoundBytes) {
      testSoundData.push_back((int)(soundByte.getPitch()));
    }
    CHECK(TestHelper::checkSoundValues(sourceSoundData, testSoundData));
  }
  SECTION("a middle C triangle wave") {
    double hz = 44100;           // samples per second
    double frequency = 261.626;  // middle C
    double seconds = 2;          // time
    double amplitude = 16000;    // "volume"
    int N = hz * seconds;        // total number of samples

    std::vector<double> sourceSoundData;
    for (int n = 0; n < N; n++) {
      double x = (MathConsts::TWO_PI * n * frequency) / hz -
                 floor((n * frequency) / hz) * MathConsts::TWO_PI;
      double value =
          (x <= MathConsts::PI / 2) ? (x / (MathConsts::PI / 2))
          : (x <= MathConsts::PI * 3 / 2)
              ? (1 - (x - MathConsts::PI / 2) / (MathConsts::PI / 2))
              : (-1 + (x - MathConsts::PI * 3 / 2) / (MathConsts::PI / 2));
      sourceSoundData.push_back((int)(amplitude * value - 1));
    }
    TriangleWave testWave3(261.626, 16000);
    std::vector<SoundByte> testSoundBytes = testWave3.getSoundBytes(2, 44100);
    std::vector<double> testSoundData;
    for (auto& soundByte : testSoundBytes) {
      testSoundData.push_back((int)(soundByte.getPitch()));
    }
    CHECK(TestHelper::checkSoundValues(sourceSoundData, testSoundData));
  }
  SECTION("a middle C sawtooth wave") {
    double hz = 44100;           // samples per second
    double frequency = 261.626;  // middle C
    double seconds = 2;          // time
    double amplitude = 16000;    // "volume"
    int N = hz * seconds;        // total number of samples

    std::vector<double> sourceSoundData;
    for (int n = 0; n < N; n++) {
      double x = (MathConsts::TWO_PI * n * frequency) / hz -
                 floor((n * frequency) / hz) * MathConsts::TWO_PI;
      double value = x <= MathConsts::PI
                         ? x / MathConsts::PI
                         : -1 + (x - MathConsts::PI) / MathConsts::PI;

      sourceSoundData.push_back((int)(amplitude * value - 1));
    }
    SawtoothWave testWave4(261.626, 16000);
    std::vector<SoundByte> testSoundBytes = testWave4.getSoundBytes(2, 44100);
    std::vector<double> testSoundData;
    for (auto& soundByte : testSoundBytes) {
      testSoundData.push_back((int)(soundByte.getPitch()));
    }
    CHECK(TestHelper::checkSoundValues(sourceSoundData, testSoundData));
  }
}