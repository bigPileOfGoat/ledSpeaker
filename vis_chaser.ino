//single led chases around ring leaving trail of freq based colour
/* will change freq displayed and colour on the falling edge of a high frequency beat */
void chaser() {
  if (chaseFreq == 0) {
    leds[chasePos] = CRGB(left.low, left.mid, left.high);
    leds[48 - (chasePos + 1)] = CRGB(right.low, right.mid, right.high);
  }
  if (chaseFreq == 1) {
    leds[chasePos] = ColorFromPalette(currentPalette, left.low, 255, LINEARBLEND);
    leds[48 - (chasePos + 1)] = ColorFromPalette(currentPalette, right.low, 255, LINEARBLEND);
  }
  if (chaseFreq == 2) {
    leds[chasePos] = ColorFromPalette(currentPalette, left.mid, 255, LINEARBLEND);
    leds[48 - (chasePos + 1)] = ColorFromPalette(currentPalette, right.mid, 255, LINEARBLEND);
  }
  if (chaseFreq == 3) {
    leds[chasePos] = ColorFromPalette(currentPalette, left.high, 255, LINEARBLEND);
    leds[48 - (chasePos + 1)] = ColorFromPalette(currentPalette, right.high, 255, LINEARBLEND);
  }
  //if (chaseFreq == 4) {
  //  leds[chasePos] = ColorFromPalette(currentPalette, left.high, left.high, LINEARBLEND);
  //  leds[48 - (chasePos + 1)] = ColorFromPalette(currentPalette, right.high, right.high, LINEARBLEND);
  //}
  chasePos++;
  if (chasePos > 23) chasePos = 0;
}

