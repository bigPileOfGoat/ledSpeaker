/* 6 leds per low,mid and high frequencies, at random positions */
void sparkle() {
  
  clearColour();
  /* update buffer with upto 18 led values each ring. upto 6 for each frequency with
     brightness and number of leds defined by frequency value and colour defined by frequency band. */
  static long prevMillisSp = 0;
  unsigned long currentMillisSp = millis(); // read time
  if (currentMillisSp - prevMillisSp > 50) {
    prevMillisSp = currentMillisSp;
    byte tVal = map(left.low, 0, 255, 0, left.low / 17); //scale EQ value to 6
    for (int j = 0; j < tVal; j++) {
      lRing[random(24)].r = left.low;
    }
    tVal = map(left.mid, 0, 255, 0, left.mid / 17);
    for (int j = 0; j < tVal; j++) {
      lRing[random(24)].g = left.mid;
    }
    tVal = map(left.high, 0, 255, 0, left.high / 17);
    for (int j = 0; j < tVal; j++) {
      lRing[random(24)].b = left.high;
    }
    tVal = map(right.low, 0, 255, 0, right.low / 17);
    for (int j = 0; j < tVal; j++) {
      rRing[random(24)].r = right.low;
    }
    tVal = map(right.mid, 0, 255, 0, right.mid / 17);
    for (int j = 0; j < tVal; j++) {
      rRing[random(24)].g = right.mid;
    }
   tVal = map(right.high, 0, 255, 0, right.high / 17);
    for (int j = 0; j < tVal; j++) {
      rRing[random(24)].b = right.high;
    }
    /* update left and right ring buffers to fastLED array */
    for (int j = 0; j < 24; j++) {
      leds[lRing[j].pos] = CRGB(lRing[j].r, lRing[j].g, lRing[j].b);
      leds[rRing[j].pos] = CRGB(rRing[j].r, rRing[j].g, rRing[j].b);
    } 
  }
}
