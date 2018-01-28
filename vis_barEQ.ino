//EQ bar visualisation
/* Select 1,2,3 bars
   audioFreq selection only works for 1 EQ bar
   if allColour = true then a freq will be assigned to each colour */
void barEQ(byte numBars, byte audioFreq) {

  //clears all led colour values to 0
  clearColour();
  if (numBars == 1) {
    if (audioFreq == 0) {
      //reading low frequency for left and right channel
      byte tempVal = map(left.low, 0, 255, 0, 23);
      for (int j = 0; j < tempVal; j++) {
        if (!allColour) {
          leds[lRing[j].pos] = CHSV(HUE_RED, 255, 255);
        } else {
          leds[lRing[j].pos] = ColorFromPalette( currentPalette, hsvIndex, 255, LINEARBLEND);
        }
      }
      tempVal = map(right.low, 0, 255, 0, 23);
      for (int j = 0; j < tempVal; j++) {
        if (!allColour) {
          leds[rRing[j].pos] = CHSV(HUE_RED, 255, 255);
        } else {
          leds[rRing[j].pos] = ColorFromPalette( currentPalette, hsvIndex, 255, LINEARBLEND);
        }
      }
    }
    //reading mid frequency for left and right channels
    if (audioFreq == 1) {
      //reading mid frequency for left and right channels
      byte tempVal = map(left.mid, 0, 255, 0, 23);
      for (int j = 0; j < tempVal; j++) {
        if (!allColour) {
          leds[lRing[j].pos] = CHSV(HUE_GREEN, 255, 255);
        } else {
          leds[lRing[j].pos] = ColorFromPalette( currentPalette, hsvIndex, 255, LINEARBLEND);
        }
      }
      tempVal = map(right.mid, 0, 255, 0, 23);
      for (int j = 0; j < tempVal; j++) {
        if (!allColour) {
          leds[rRing[j].pos] = CHSV(HUE_GREEN, 255, 255);
        } else {
          leds[rRing[j].pos] = ColorFromPalette( currentPalette, hsvIndex, 255, LINEARBLEND);
        }
      }
    }
    //reading high frequency for left and right channels
    if (audioFreq == 2) {
      //reading low frequency for left and right channels
      byte tempVal = map(left.high, 0, 255, 0, 23);
      for (int j = 0; j < tempVal; j++) {
        if (!allColour) {
          leds[lRing[j].pos] = CHSV(HUE_BLUE, 255, 255);
        } else {
          leds[lRing[j].pos] = ColorFromPalette( currentPalette, hsvIndex, 255, LINEARBLEND);
        }
      }
      tempVal = map(right.high, 0, 255, 0, 23);
      for (int j = 0; j < tempVal; j++) {
        if (!allColour) {
          leds[rRing[j].pos] = CHSV(HUE_BLUE, 255, 255);
        } else {
          leds[rRing[j].pos] = ColorFromPalette( currentPalette, hsvIndex, 255, LINEARBLEND);
        }
      }
    }
  }

  //two EQ bars on opposite sides of led ring
  if (numBars == 2) {
    //reading low frequency for left and right channels
    //create first EQ bar for low
    byte tempVal = map(left.low, 0, 255, 0, 11);
    for (int j = 0; j < tempVal; j++) {
      leds[lRing[j].pos] = CHSV(HUE_RED, 255, 255);
    }
    tempVal = map(right.low, 0, 255, 0, 11);
    for (int j = 0; j < tempVal; j++) {
      leds[rRing[j].pos] = CHSV(HUE_RED, 255, 255);
    }
    //reading low frequency for left and right channels
    //create second EQ bar for high
    tempVal = map(left.mid, 0, 255, 12, 23);
    for (int j = 12; j < tempVal; j++) {
      leds[lRing[j].pos] = CHSV(HUE_GREEN, 255, 255);
    }
    tempVal = map(right.mid, 0, 255, 12, 23);
    for (int j = 12; j < tempVal; j++) {
      leds[rRing[j].pos] = CHSV(HUE_GREEN, 255, 255);
    }
  }

  //three EQ bars on around the led ring
  if (numBars == 3) {
    //reading low frequency for left and right channels
    //create first EQ bar for low
    byte tempVal = map(left.low, 0, 255, 0, 7);
    for (int j = 0; j < tempVal; j++) {
      leds[lRing[j].pos] = CHSV(HUE_RED, 255, 255);
    }
    tempVal = map(right.low, 0, 255, 0, 7);
    for (int j = 0; j < tempVal; j++) {
      leds[rRing[j].pos] = CHSV(HUE_RED, 255, 255);
    }
    //reading mid frequency for left and right channels
    //create second EQ bar for mid
    tempVal = map(left.mid, 0, 255, 8, 15);
    for (int j = 8; j < tempVal; j++) {
      leds[lRing[j].pos] = CHSV(HUE_GREEN, 255, 255);
    }
    tempVal = map(right.mid, 0, 255, 8, 15);
    for (int j = 8; j < tempVal; j++) {
      leds[rRing[j].pos] = CHSV(HUE_GREEN, 255, 255);
    }
    //reading high frequency for left and right channels
    //create third EQ bar for high
    tempVal = map(left.high, 0, 255, 16, 23);
    for (int j = 16; j < tempVal; j++) {
      leds[lRing[j].pos] = CHSV(HUE_BLUE, 255, 255);
    }
    tempVal = map(right.high, 0, 255, 16, 23);
    for (int j = 16; j < tempVal; j++) {
      leds[rRing[j].pos] = CHSV(HUE_BLUE, 255, 255);
    }
  }
}
