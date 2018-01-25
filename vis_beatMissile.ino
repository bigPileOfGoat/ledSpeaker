struct Missile {
  byte pos;
  byte r, g, b;
  boolean isFired = false;
};

const byte maxMissiles = 30;
Missile bMissile[maxMissiles];

void beatMissile() {
  //main beatMissile visualisation loop
  static long prevMissileMillis = 0;
  unsigned long currentMissileMillis = millis(); // read time
  if (currentMissileMillis - prevMissileMillis > 30) {
    prevMissileMillis = currentMissileMillis;
    clearColour();
    fireMissile();
    updateMissile();
  }
}

void setupMissiles() {
  for (int j = 0; j < maxMissiles; j++) {

  }
}
void fireMissile() {
  //if beat detected fire missile
  if (onBeatHigh) {
    for (int j = 0; j < maxMissiles; j++) {
      if (bMissile[j].isFired = false) {
        bMissile[j].isFired = true;
        break;
      }
    }
  }
}

void updateMissile() {
  //move fired missiles and fade
  for (int j = 0; j < maxMissiles; j++) {
    if ((bMissile[j].isFired) && (bMissile[j].pos < 24)) {
      bMissile[j].pos++;
    }
    if (bMissile[j].pos > 23) {
      bMissile[j].isFired = false;
      bMissile[j].pos = 0;
    }
    leds[lRing[bMissile[j].pos].pos] = CRGB(left.low, left.mid, left.high);
    leds[rRing[bMissile[j].pos].pos] = CRGB(right.low, right.mid, right.high);
  }
  leds[lRing[0].pos] = CRGB::Green;
  leds[lRing[23].pos] = CRGB::Yellow;
  leds[rRing[0].pos] = CRGB::Green;
  leds[rRing[23].pos] = CRGB::Yellow;
}

