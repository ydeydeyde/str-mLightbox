#include <Adafruit_NeoPixel.h> 
#define LED_PIN 11 
#define SOUND_PIN 9
#define TOGGLE_PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(18, LED_PIN, NEO_GRB + NEO_KHZ800);

int soundDetect = HIGH;

void setup() {
  strip.clear();
  strip.begin();
  
  // Input from sound detection module
  pinMode(SOUND_PIN, INPUT); 
}

void loop() {
  soundDetect = digitalRead (SOUND_PIN); 
    // If we hear sound
  //  if (soundDetect == LOW) {
  if (soundDetect == 1) {
     fadeDown(); 
    } else {
      uint16_t i;
      for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, 0,0,0); 
       }
    }
}

void fadeDown() {
  uint16_t i, j;
  for (j = 255; j > 0; j--) {
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, random(j), random(j), random(j)  );
    }
    strip.show();
  }
}
