#include <Adafruit_NeoPixel.h> 

#define LED_PIN 11 

Adafruit_NeoPixel strip = Adafruit_NeoPixel(18, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.clear();
  strip.begin();
}

void loop() {
  darken();
}

void darken() {
  //Serial.begin(9600);
  uint16_t i, j;
  for (j = 255; j > 0; j--) {
    for (i = 0; i < strip.numPixels() and strip.numPixels(); i++) {
      strip.setPixelColor(i, random(j), random(j), random(j)  );
    }
    strip.show();
  }
}
