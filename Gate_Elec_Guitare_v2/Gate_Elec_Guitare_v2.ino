//*********************************************************Declared Integers
int mode = 0;
int ModePin = A5;
int pot = 0;

//DISPLAY
#include <Adafruit_NeoPixel.h>

#define PIN 2   // input pin Neopixel is attached to

#define NUMPIXELS  36 // number of neopixels in strip

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

class Color {
  public:
    int R;
    int G;
    int B;

    Color(int R, int G, int B) {
      this -> R = R;
      this -> G = G;
      this -> B = B;
    }
};

int chord = 0;
int maxchord = 64;

Color yellow = Color(255, 255, 0);
Color purple = Color(255, 0, 255);
Color blue = Color(0, 0, 255);
Color orange = Color(255, 128, 0);

// problème1: pixels.Color n'accepte pas mes doubles en argument
// problème2: si j'enlève pixels.Color, les couleurs sont pas bonnes

//WORK IN PROGRESS
void display (int s1, int s2, int s3, int s4, int s5, int s6) {
  //1 argument par corde. Chaque argument de la forme (LED, doigt)

  pixels.setPixelColor(s1, pixels.Color(yellow.R, yellow.G, yellow.B));
  pixels.setPixelColor(s2, pixels.Color(purple.R, purple.G, purple.B));
  pixels.setPixelColor(s3, pixels.Color(255, 0, 0));
  pixels.setPixelColor(s4, pixels.Color(blue.R, blue.G, blue.B));
  pixels.setPixelColor(s5, pixels.Color(orange.R, orange.G, orange.B));
  pixels.setPixelColor(s6, pixels.Color(255, 0, 0));

  // This sends the updated pixel color to the hardware.
  pixels.show();
}




//*********************************************************Declared Integers
//METRONOME
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
  delay(60000/bpm-tempsbip);
}

void biplow()
{
  bpm=map(analogRead(TempoPin),0,1023,minbpm,maxbpm);
  tone(BuzzPin,200);
  digitalWrite(LedPin, HIGH);
  delay(tempsbip);
  noTone(BuzzPin);
  digitalWrite(LedPin, LOW);
  delay(60000/bpm-tempsbip);
}

void silence()
{
  delay(60000/bpm);
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

//**************************************************************Setup
void setup() {
  //DISPLAY
  pixels.begin(); //Initializes the Neopixel library

  //METRONOME
  Serial.begin(9600);
  pinMode(TempoPin, INPUT);
  pinMode(RhythmPin, INPUT);
  pinMode(BuzzPin, OUTPUT);
  pinMode(LedPin, OUTPUT);
}

//**************************************************************Main Loop
void loop() {
  mode = map(analogRead(ModePin), 0, 1023, 0, 1);

  if (mode == 0) {
    pot = analogRead(TempoPin);

    //DISPLAY
    chord = map(pot, 0, 1023, 0, 5);

    for (int i = 0; i < 36; i++) {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    }

    display (chord, chord + 6, chord + 12, chord + 18, chord + 24, chord + 30);
    delay(200);
  }

  if (mode == 1) {
    //METRONOME
    rhythm=map(analogRead(RhythmPin),0,1023,0,7); //Ligne à changer selon le futur button
  
  	//Debut optionnel
  	Serial.print("Rythme numero:");
  	Serial.print(rhythm);
  	Serial.print(", tempo: ");
  	Serial.println(bpm);
  	//Fin optionnel
  
  	switch (rhythm){
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

}
