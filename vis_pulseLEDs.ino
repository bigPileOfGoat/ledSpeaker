//pulse each ring a solid color based on EQ low, mid and high values
// red = low, green = mid, blue = high
void pulseLEDs() {

  for (int j = 0; j < 24; j++) {
    lRing[j].r = left.low;
    lRing[j].g = left.mid;
    lRing[j].b = left.high;
    rRing[j].r = right.low;
    rRing[j].g = right.mid;
    rRing[j].b = right.high;
    byte tempLR = lRing[j].r;
    byte tempLG = lRing[j].g;
    byte tempLB = lRing[j].b;
    byte tempRR = rRing[j].r;
    byte tempRG = rRing[j].g;
    byte tempRB = rRing[j].b;
    if (onBeatLow) pulseVar = random(0, 4);
    if (pulseVar == 0) {
      tempLR = lRing[j].g;
      tempLG = lRing[j].b;
      tempLB = lRing[j].r;
      tempRR = rRing[j].g;
      tempRG = rRing[j].b;
      tempRB = rRing[j].r;
    }
    if (pulseVar == 1) {
      tempLR = lRing[j].b;
      tempLG = lRing[j].r;
      tempLB = lRing[j].g;
      tempRR = rRing[j].b;
      tempRG = rRing[j].r;
      tempRB = rRing[j].g;
    }
    if (pulseVar == 2) {
      tempLR = lRing[j].g;
      tempLG = lRing[j].r;
      tempLB = lRing[j].b;
      tempRR = rRing[j].g;
      tempRG = rRing[j].r;
      tempRB = rRing[j].b;
    }
    if (pulseVar == 3) {
      tempLR = lRing[j].b;
      tempLG = lRing[j].g;
      tempLB = lRing[j].r;
      tempRR = rRing[j].b;
      tempRG = rRing[j].g;
      tempRB = rRing[j].r;
    }
    leds[lRing[j].pos] = CRGB(tempLR, tempLG, tempLB);
    leds[rRing[j].pos] = CRGB(tempRR, tempRG, tempRB);
  }
}
