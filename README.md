## VoiceSynth
An attempt at making a voice synthesiser, hopefully to take text and produce a sound file of the text being read, without any previous sound inputs (no ML or chopping up existing words). The plan to achieve this is to have some kind of database of pronounciations (downloaded or handmade) and then to break down each word into its pronounciation to produce the sound.

First time using Catch2 for unit tests and GitHub Actions to run clang-format checks and run units tests.

# To-do:
- Implement unit tests for existing code:
  - Add data store for tests that can be read and compared to []
  - Add raw data to dataStore of a middle C sound wave .wav file []
  - Create a test to see that the Sound class written with the WavWriter can produce a middle C sine wave sound file that matches a premade one []
  - Test wave producing classes []
  - Test little endian writer []

