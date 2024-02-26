/*
 * Title: Twinkle_Pixels_Main
 * 
 * Description:
 *      - This sketch was created for controling a WS2812B LED light strip (or similar) using the FastLED library. 
 *      
 * Author: Electriangle
 *      - Video: https://www.youtube.com/watch?v=JK9GOKha5fU
 *      - Channel: https://www.youtube.com/@Electriangle
 *      
 * License: MIT License
 *      - Copyright (c) 2024 Electriangle
 *
 * Date Created: 2/24/2024
 * Last Updated: 2/24/2024
*/

#include <FastLED.h>
void TwinklePixels(int Color = random(256), int ColorSaturation = 255,  int PixelVolume = 20, int FadeAmount = 50, int DelayDuration = 50);

#define NUM_LEDS      150     // Enter the total number of LEDs on the strip
#define LED_PIN       4       // The pin connected to DATA line to control the LEDs
CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 1500);    // Set power limit of LED strip to 5V, 1500mA
  FastLED.clear();                                    // Initialize all LEDs to "OFF"
}

void loop() {
  TwinklePixels();    // Default example (random rainbow colors)
}