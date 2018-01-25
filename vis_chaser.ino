//single led chases around ring leaving trail of freq based colour
/* will change freq displayed and colour on the falling edge of a high frequency beat */
void chaser() {
  if (chaseFreq == 0) {
    leds[chasePos] = CRGB(left.low, left.mid, left.high);
    leds[48 - (chasePos + 1)] = CRGB(right.low, right.mid, right.high);
  }
  if (chaseFreq == 1) {
    leds[chasePos] = CRGB(left.low, 0, 0);
    leds[48 - (chasePos + 1)] = CRGB(right.low, 0, 0);
  }
  if (chaseFreq == 2) {
    leds[chasePos] = CRGB(0, left.mid, 0);
    leds[48 - (chasePos + 1)] = CRGB(0, right.mid, 0);
  }
  if (chaseFreq == 3) {
    leds[chasePos] = CRGB(0, 0, left.high);
    leds[48 - (chasePos + 1)] = CRGB(0, 0, right.high);
  }
  chasePos++;
  if (chasePos > 23) chasePos = 0;
}

