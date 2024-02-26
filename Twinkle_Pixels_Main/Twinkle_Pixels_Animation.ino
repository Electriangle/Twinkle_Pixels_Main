/*
  *  ========== Twinkle_Pixels_Animation ==========
  *  FUNCTION CALL:
  *   TwinklePixels(Color, ColorSaturation, PixelVolume, FadeAmount, DelayDuration);
  *  
  *  PARAMETERS:
  *   Color - select the color of the animation with one of the following numbers (or anything in between) [range = 0 to 255; default = random(256)]:
        Red: 0
        Orange: 30
        Yellow: 42
        Green: 85
        Cyan: 127
        Blue: 170
        Purple: 210
        Pink: 218
  *   ColorSaturation - Sets the color saturation according to HSV color code. Set to 0 for white and set to 255 for max saturation
  *                     [max range = 0 to 255; default = 255]
  *   PixelVolume - Use a larger value for less LEDs to twinkle [default = 20]
  *   FadeAmount - Use a larger value for a faster fade amount [max range = 0 to 255; default = 50]
  *   DelayDuration - Use a larger value for a slower animation speed [default = 50]
  *  
  *  NOTES:
  *  - You can combine twinkling colors by putting two of the function calls together in the loop() function. Try it out!
  *  - You can get many unique effects by changing the various arguments. Here are some examples to try:
  *      TwinklePixels(170, 255, 70, 20, 50);   // Blue color with lower pixel volume and slower speed
  *      TwinklePixels(0, 255, 40, 80, 80);     // Red color with moderate pixel volume and moderate speed
  *      TwinklePixels(85, 200, 15, 50, 30);    // Green color with high pixel volume and faster speed
  *      TwinklePixels(255, 0, 100, 120, 0);    // White color with low pixel volume and max speed
*/

void TwinklePixels(int Color, int ColorSaturation, int PixelVolume, int FadeAmount, int DelayDuration) {
  for (int i = 0; i < NUM_LEDS; i++) {
    // Draw twinkling pixels
    if (random(PixelVolume) < 2) {     // Chance for pixel to twinkle
      uint8_t intensity = random(100, 255);     // Configure random intensity
      CRGB set_color = CHSV(Color, ColorSaturation, intensity);     // Configure color with max saturation and variable value (intensity)
      leds[i] = set_color;    // Set the pixel color
    }

    // Fade LEDs
    if (leds[i].r > 0 || leds[i].g > 0 || leds[i].b > 0) {    // Check if pixel is lit
      leds[i].fadeToBlackBy(FadeAmount);    // Fade pixel to black
    }
  }

  FastLED.show();
  delay(DelayDuration);
}