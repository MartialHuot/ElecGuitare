
//*********************************************************Declared Integers
int mode = 0;
int ModePin = A5;
int pot = 0;
int MasterPin = A0;

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
#include <Metronome.h>

Metronome metronome;


//**************************************************************Setup
void setup() {
  Serial.begin(9600);
  
  //DISPLAY
  pixels.begin(); //Initializes the Neopixel library

  //METRONOME
  //it's all in the library
}

//**************************************************************Main Loop
void loop() {
  mode = map(analogRead(ModePin), 0, 1023, 0, 1);

  if (mode == 0) {
    pot = analogRead(MasterPin);

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
    metronome.run();
    
  }

}
