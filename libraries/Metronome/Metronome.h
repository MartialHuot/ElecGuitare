/*
  Metronome.h - Library for our shitty metronome.
  Created by groupe GATE 27.
*/

#ifndef Metronome_h
#define Metronome_h

#include "Arduino.h"

class Metronome
{
  public:
    Metronome();
    void run();

  private:
    const int _TempoPin = A0;
    const int _RhythmPin = A1;
    const int _BuzzPin = 13;
    const int _LedPin = 9;
    int _bpm = 10;
    const int _minbpm = 10;
    const int _maxbpm = 260;
    const int _tempsbip = 150;
    int _rhythm = 0;

    void biphigh();
    void biplow();
    void silence();
    void rhythm0();
    void rhythm1();
    void rhythm2();
    void rhythm3();
    void rhythm4();
    void rhythm5();
    void rhythm6();
    void rhythm7();
};

#endif
