Declared Integers
int mode = 0;
int ModePin = A5;
int pot = 0;

DISPLAY
#include Adafruit_NeoPixel.h

#define PIN 2    input pin Neopixel is attached to

#define NUMPIXELS  36  number of neopixels in strip

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int chord = 0;
int maxchord = 64;

int yellow[] = {255, 255, 0};
int purple[] = {255, 0, 255};
int blue[] = {0, 0, 255};
int orange[] = {255, 128, 0};
int red[] = {255, 0, 0};

WORK IN PROGRESS
void setColor (int s, int color[]) {
  pixels.setPixelColor(s, pixels.Color(color[0], color[1], color[2]));
}

void display (int s1, int color1[], int s2, int color2[], int s3, int color3[], int s4, int color4[], int s5, int color5[], int s6, int color6[]) {
  setColor(s1, color1);
  setColor(s2, color2);
  setColor(s3, color3);
  setColor(s4, color4);
  setColor(s5, color5);
  setColor(s6, color6);

   This sends the updated pixel color to the hardware.
  pixels.show();
}




Declared Integers
METRONOME
const int TempoPin=A0;
const int RhythmPin=A1;
const int BuzzPin=13;
const int LedPin=9;
int bpm=10;
const int minbpm=10;
const int maxbpm=260;
const int tempsbip=150; 
int rhythm=0;


void biphigh()
{
  bpm=map(analogRead(TempoPin),0,1023,minbpm,maxbpm);
  tone(BuzzPin,500);
  digitalWrite(LedPin, HIGH);
  delay(tempsbip);
  noTone(BuzzPin);
  digitalWrite(LedPin, LOW);
  delay(60000bpm-tempsbip);
}

void biplow()
{
  bpm=map(analogRead(TempoPin),0,1023,minbpm,maxbpm);
  tone(BuzzPin,200);
  digitalWrite(LedPin, HIGH);
  delay(tempsbip);
  noTone(BuzzPin);
  digitalWrite(LedPin, LOW);
  delay(60000bpm-tempsbip);
}

void silence()
{
  delay(60000bpm);
}

void rhythm0()
{
  biphigh();
}

void rhythm1()
{
  biphigh();
  biplow();
}

void rhythm2()
{
  biphigh();
  biplow();
  biplow();
}

void rhythm3()
{
  biphigh();
  biplow();
  biplow();
  biplow();
}

void rhythm4()
{
  biphigh();
  biplow();
  biplow();
  biplow();
  biplow();
}

void rhythm5()
{
  biphigh();
  biplow();
  biplow();
  biplow();
  biplow();
  biplow();
}

void rhythm6()
{
  biphigh();
  silence();
  biplow();
}

void rhythm7()
{
  biphigh();
  silence();
  silence();
  biplow();
}

Setup
void setup() {
  DISPLAY
  pixels.begin(); Initializes the Neopixel library

  METRONOME
  Serial.begin(9600);
  pinMode(TempoPin, INPUT);
  pinMode(RhythmPin, INPUT);
  pinMode(BuzzPin, OUTPUT);
  pinMode(LedPin, OUTPUT);
}

Main Loop
void loop() {
  mode = map(analogRead(ModePin), 0, 1023, 0, 1);

  if (mode == 0) {
    pot = analogRead(TempoPin);

    DISPLAY
    chord = map(pot, 0, 1023, 0, 5);

    for (int i = 0; i  36; i++) {
       pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    }

    display (chord, yellow, chord + 6, purple,  chord + 12, red, chord + 18, blue, chord + 24, orange, chord + 30, red);
    delay(200);
  }

  if (mode == 1) {
    METRONOME
    rhythm=map(analogRead(RhythmPin),0,1023,0,7); Ligne à changer selon le futur button
  
    Debut optionnel
    Serial.print(Rythme numero);
    Serial.print(rhythm);
    Serial.print(, tempo );
    Serial.println(bpm);
    Fin optionnel
  
    switch (rhythm){
      case 0
          rhythm0();
          break;
      case 1
          rhythm1();
          break;
      case 2
          rhythm2();
          break;
      case 3
          rhythm3();
          break;
      case 4
          rhythm4();
          break;
      case 5
          rhythm5();
          break;
      case 6
          rhythm6();
          break;
      case 7
          rhythm7();
          break;
    }
  }

}
