void mirrorBarEQ (byte audioFrequency) {

  clearColour();
  if (audioFrequency == 0) {
    /* reading low frequency for left and right channel */
    /* left side */
    byte tempVal = map((left.low + left.high) / 2, 0, 255, 0, 11); //average low and high frequency
    for (int j = 0; j < tempVal; j++) {
      leds[lRing[j].pos] = CRGB(left.low, left.mid, left.high);
    }
    tempVal = map((left.low + left.high) / 2, 0, 255, 0, 11);
    for (int j = 23; j > (24 - tempVal); j--) {
      leds[lRing[j].pos] = CRGB(left.low, left.mid, left.high);
    }
    /* right side */
    tempVal = map((right.low + right.high) / 2, 0, 255, 0, 11);
    for (int j = 0; j < tempVal; j++) {
      leds[rRing[j].pos] = CRGB(right.low, right.mid, right.high);
    }
    tempVal = map((right.low + right.high) / 2, 0, 255, 0, 11);
    for (int j = 23; j > (24 - tempVal); j--) {
      leds[rRing[j].pos] = CRGB(right.low, right.mid, right.high);
    }
  }

}
