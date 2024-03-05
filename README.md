## VoiceSynth
An attempt at making a voice synthesiser, hopefully to take text and produce a sound file of the text being read, without any previous sound inputs (no ML or chopping up existing words). The plan to achieve this is to have some kind of database of pronounciations (downloaded or handmade) and then to break down each word into its pronounciation to produce the sound.

First time using Catch2 for unit tests and GitHub Actions to run clang-format checks and run units tests.

# To-do:
- Implement unit tests for existing code:
  - Create tests to see that the Sound class can produce a middle C wave sound values that matches a premade ones [x]
  - Test little endian writer []

