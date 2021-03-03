/*
  Metronome.cpp - Library for our shitty metronome.
  Created by groupe GATE 27.
*/

#include "Arduino.h"
#include "Metronome.h"

Metronome::Metronome()
{
	pinMode(_TempoPin, INPUT);
	pinMode(_RhythmPin, INPUT);
	pinMode(_BuzzPin, OUTPUT);
	pinMode(_LedPin, OUTPUT);
}

void Metronome::run()
{
	_rhythm=map(analogRead(_RhythmPin), 0, 1023, 0, 7); //Ligne à changer selon le futur button
	
	//Debut optionnel
	Serial.print("Rythme numero:");
	Serial.print(_rhythm);
	Serial.print(", tempo: ");
	Serial.println(_bpm);
	//Fin optionnel

	switch (_rhythm) {
	case 0:
		rhythm0();
		break;
	case 1:
		rhythm1();
		break;
	case 2:
		rhythm2();
		break;
	case 3:
		rhythm3();
		break;
	case 4:
		rhythm4();
		break;
	case 5:
		rhythm5();
		break;
	case 6:
		rhythm6();
		break;
	case 7:
		rhythm7();
		break;
	}
}

void Metronome::biphigh()
{
	_bpm = map(analogRead(_TempoPin), 0, 1023, _minbpm, _maxbpm);
	tone(_BuzzPin, 500);
	digitalWrite(_LedPin, HIGH);
	delay(_tempsbip);
	noTone(_BuzzPin);
	digitalWrite(_LedPin, LOW);
	delay(60000 / _bpm - _tempsbip);
}

void Metronome::biplow()
{
	_bpm = map(analogRead(_TempoPin), 0, 1023, _minbpm, _maxbpm);
	tone(_BuzzPin, 200);
	digitalWrite(_LedPin, HIGH);
	delay(_tempsbip);
	noTone(_BuzzPin);
	digitalWrite(_LedPin, LOW);
	delay(60000 / _bpm - _tempsbip);
}

void Metronome::silence()
{
	delay(60000 / _bpm);
}

void Metronome::rhythm0()
{
	biphigh();
}

void Metronome::rhythm1()
{
	biphigh();
	biplow();
}

void Metronome::rhythm2()
{
	biphigh();
	biplow();
	biplow();
}

void Metronome::rhythm3()
{
	biphigh();
	biplow();
	biplow();
	biplow();
}

void Metronome::rhythm4()
{
	biphigh();
	biplow();
	biplow();
	biplow();
	biplow();
}

void Metronome::rhythm5()
{
	biphigh();
	biplow();
	biplow();
	biplow();
	biplow();
	biplow();
}

void Metronome::rhythm6()
{
	biphigh();
	silence();
	biplow();
}

void Metronome::rhythm7()
{
	biphigh();
	silence();
	silence();
	biplow();
}