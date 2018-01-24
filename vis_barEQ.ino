//EQ bar visualisation
/* Select 1,2,3 bars
   audioFreq selection only works for 1 EQ bar
   if allColour = true then a freq will be assigned to each colour */
void barEQ(byte numBars, byte audioFreq, boolean allColour) {
  
  //clears all led colour values to 0
  clearColour();
  if (numBars == 1) {
    if (audioFreq == 0) {
      //reading low frequency for left and right channel
      byte tempVal = map(left.low, 0, 255, 0, 23);
      for (int j=0; j<tempVal; j++) {
        if (!allColour) {
          leds[lRing[j].pos] = CRGB(left.low,0,0);
        } else {
          leds[lRing[j].pos] = CRGB(left.low,left.low,left.low);
        }
      }
      tempVal = map(right.low, 0, 255, 0, 23);
      for (int j=0; j<tempVal; j++) {
        if (!allColour) {
          leds[rRing[j].pos] = CRGB(right.low,0,0);
        } else {
          leds[rRing[j].pos] = CRGB(right.low,right.low,right.low);
        }
      }
    }
    //reading mid frequency for left and right channels
    if (audioFreq == 1) {
      //reading mid frequency for left and right channels
      byte tempVal = map(left.mid, 0, 255, 0, 23);
      for (int j=0; j<tempVal; j++) {
        if (!allColour) {
          leds[lRing[j].pos] = CRGB(0,left.mid,0);
        } else {
          leds[lRing[j].pos] = CRGB(left.mid,left.mid,left.mid);
        }
      }
      tempVal = map(right.mid, 0, 255, 0, 23);
      for (int j=0; j<tempVal; j++) {
        if (!allColour) {
          leds[rRing[j].pos] = CRGB(0,right.mid,0);
        } else {
          leds[rRing[j].pos] = CRGB(right.mid,right.mid,right.mid);
        }
      }
    }
    //reading high frequency for left and right channels
    if (audioFreq == 2) {
      //reading low frequency for left and right channels
      byte tempVal = map(left.high, 0, 255, 0, 23);
      for (int j=0; j<tempVal; j++) {
        if (!allColour) {
          leds[lRing[j].pos] = CRGB(0,0,left.high);
        } else {
          leds[lRing[j].pos] = CRGB(left.high,left.high,left.high);
        }
      }
      tempVal = map(right.high, 0, 255, 0, 23);
      for (int j=0; j<tempVal; j++) {
        if (!allColour) {
          leds[rRing[j].pos] = CRGB(0,0,right.high);
        } else {
          leds[rRing[j].pos] = CRGB(right.high,right.high,right.high);
        }
      }
    }
  }
  
  //two EQ bars on opposite sides of led ring
  if (numBars == 2) {
    //reading low frequency for left and right channels
    //create first EQ bar for low
    byte tempVal = map(left.low, 0, 255, 0, 11);
    for (int j=0; j<tempVal; j++) {
      if (!allColour) {
        leds[lRing[j].pos] = CRGB(left.low,0,0);
      } else {
        leds[lRing[j].pos] = CRGB(left.low,left.low,left.low);
      }
    }
    tempVal = map(right.low, 0, 255, 0, 11);
    for (int j=0; j<tempVal; j++) {
      if (!allColour) {
        leds[rRing[j].pos] = CRGB(right.low,0,0);
      } else {
        leds[rRing[j].pos] = CRGB(right.low,right.low,right.low);
      }
    }
    //reading low frequency for left and right channels
    //create second EQ bar for high
    tempVal = map(left.mid, 0, 255, 12, 23);
    for (int j=12; j<tempVal; j++) {
      if (!allColour) {
        leds[lRing[j].pos] = CRGB(0,left.mid,0);
      } else {
        leds[lRing[j].pos] = CRGB(left.mid,left.mid,left.mid);
      }
    }
    tempVal = map(right.mid, 0, 255, 12, 23);
    for (int j=12; j<tempVal; j++) {
      if (!allColour) {
        leds[rRing[j].pos] = CRGB(0,right.mid,0);
      } else {
        leds[rRing[j].pos] = CRGB(right.mid,right.mid,right.mid);
      }
    }      
  }
  
  //three EQ bars on around the led ring
  if (numBars == 3) {
    //reading low frequency for left and right channels
    //create first EQ bar for low
    byte tempVal = map(left.low, 0, 255, 0, 7);
    for (int j=0; j<tempVal; j++) {
      if (!allColour) {
        leds[lRing[j].pos] = CRGB(left.low,0,0);
      } else {
        leds[lRing[j].pos] = CRGB(left.low,left.low,left.low);
      }
    }
    tempVal = map(right.low, 0, 255, 0, 7);
    for (int j=0; j<tempVal; j++) {
      if (!allColour) {
        leds[rRing[j].pos] = CRGB(right.low,0,0);
      } else {
        leds[rRing[j].pos] = CRGB(right.low,right.low,right.low);
      }
    }
    //reading mid frequency for left and right channels
    //create second EQ bar for mid
    tempVal = map(left.mid, 0, 255, 8, 15);
    for (int j=8; j<tempVal; j++) {
      if (!allColour) {
        leds[lRing[j].pos] = CRGB(0,left.mid,0);
      } else {
        leds[lRing[j].pos] = CRGB(left.mid,left.mid,left.mid);
      }
    }
    tempVal = map(right.mid, 0, 255, 8, 15);
    for (int j=8; j<tempVal; j++) {
      if (!allColour) {
        leds[rRing[j].pos] = CRGB(0,right.mid,0);
      } else {
        leds[rRing[j].pos] = CRGB(right.mid,right.mid,right.mid);
      }
    }
    //reading high frequency for left and right channels
    //create third EQ bar for high
    tempVal = map(left.high, 0, 255, 16, 23);
    for (int j=16; j<tempVal; j++) {
      if (!allColour) {
        leds[lRing[j].pos] = CRGB(0,0,left.high);
      } else {
        leds[lRing[j].pos] = CRGB(left.high,left.high,left.high);
      }
    }
    tempVal = map(right.high, 0, 255, 16, 23);
    for (int j=16; j<tempVal; j++) {
      if (!allColour) {
        leds[rRing[j].pos] = CRGB(0,0,right.high);
      } else {
        leds[rRing[j].pos] = CRGB(right.high,right.high,right.high);
      }
    }      
  }
}
