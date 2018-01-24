//reads in audio EQ values for high, mid, and low.
void readAudio() {

  MSGEQ7.read(); //read EQ values
  left.low = MSGEQ7.get(MSGEQ7_BASS, MSGEQ7_LEFT);
  right.low = MSGEQ7.get(MSGEQ7_BASS, MSGEQ7_RIGHT);
  left.mid = MSGEQ7.get(MSGEQ7_MID, MSGEQ7_LEFT);
  right.mid = MSGEQ7.get(MSGEQ7_MID, MSGEQ7_RIGHT);
  left.high = MSGEQ7.get(MSGEQ7_HIGH, MSGEQ7_LEFT);
  right.high = MSGEQ7.get(MSGEQ7_HIGH, MSGEQ7_RIGHT);
}

//clears colours to 0 in led array and buffer
void clearColour() {

  //clears ring buffer arrays
  for (int j=0; j<24; j++) { 
    lRing[j].r = 0;    
    lRing[j].g = 0;
    lRing[j].b = 0;
    rRing[j].r = 0;    
    rRing[j].g = 0;
    rRing[j].b = 0;
  }
  //clears fastLED arrays
  for (int j=0; j<24; j++){  
    leds[lRing[j].pos] = CRGB(0,0,0);
    leds[rRing[j].pos] = CRGB(0,0,0);
  }
  FastLED.show();
}

//offsets the starting point of each ring in a set direction and offset amount
void ringOffset(LED inputRing[], byte offsetValue, boolean turnLeft) {
  
  LED tmpRing[24]; //create temporary array for shifting values
  if (!turnLeft) { //move from left to right 
    for (int j=0; j<offsetValue; j++) {
      for (int i=0; i<23; i++) {
        tmpRing[i+1].pos = inputRing[i].pos;
        tmpRing[i+1].r = inputRing[i].r;
        tmpRing[i+1].g = inputRing[i].g;
        tmpRing[i+1].b = inputRing[i].b;      
      }
      tmpRing[0].pos = inputRing[23].pos; //wrap last value
      for (int i=0; i<24; i++) {   //copy all data back to led buffers
        inputRing[i].pos = tmpRing[i].pos;
        inputRing[i].r = tmpRing[i].r;
        inputRing[i].g = tmpRing[i].g;
        inputRing[i].b = tmpRing[i].b;
      }
    }
  } else { //move from right to left
    for (int j=0; j<offsetValue; j++) {
      for (int i=1; i<24; i++) {
        tmpRing[i-1].pos = inputRing[i].pos;
        tmpRing[i-1].r = inputRing[i].r;
        tmpRing[i-1].g = inputRing[i].g;
        tmpRing[i-1].b = inputRing[i].b;      
      }
      tmpRing[23].pos = inputRing[0].pos;
      for (int i=0; i<24; i++) {
        inputRing[i].pos = tmpRing[i].pos;
        inputRing[i].r = tmpRing[i].r;
        inputRing[i].g = tmpRing[i].g;
        inputRing[i].b = tmpRing[i].b;
      }
    }
  }
}

//reverse ring led buffer direction
void reverseRing(LED inputRing[]) {

  LED tmpRing[24];
  for (int i=0; i<24; i++) {
    tmpRing[23-i].pos = inputRing[i].pos;
    tmpRing[23-i].r = inputRing[i].r;
    tmpRing[23-i].g = inputRing[i].g;
    tmpRing[23-i].b = inputRing[i].b;
  }
  for (int j=0; j<24; j++) {
      inputRing[j].pos = tmpRing[j].pos;
      inputRing[j].r = tmpRing[j].r;
      inputRing[j].g = tmpRing[j].g;
      inputRing[j].b = tmpRing[j].b;
  }
}

//this will reverse and correct offset of right led position data and 
//set all RGB values to 0
void setupLedRingArrays(byte bR,byte bG, byte bB) {

  //set buffer RGB values and FastLED position for each led on each ring
  for (int i=0; i<24; i++) {
    lRing[i].r = bR;
    lRing[i].g = bG;
    lRing[i].b = bB;
    lRing[i].pos = i;
    rRing[i].r = bR;
    rRing[i].g = bG;
    rRing[i].b = bB;
    rRing[i].pos = i+24; //rRing leds start at position 24
  }
  reverseRing(rRing);
  ringOffset(rRing,1,false);
  clearColour();
}

//will detetct a set number of low beats (or bass peaks) to cause a change in visualisation
//this could change random visualisations, or just change aspects of current visualisation
void detectLowBeatChange(byte onNumBeats, byte cutOff) {
  onBeatLow = false;
  byte oldBeatReading = currentBeatReadingLow;
  currentBeatReadingLow = (left.low + right.low)/2;
  if ((currentBeatReadingLow > cutOff) && (oldBeatReading < cutOff)) {
    if (onNumBeats > 0) {
      if (beatCounterLow > onNumBeats) {
        beatCounterLow = 0;
        onBeatLow = true;
      } else {
        beatCounterLow++;
      }
    } else {
      onBeatLow = true;
    }
  }
}

//will detetct a set number of high beats (or high peaks) to cause a change in visualisation
//this could change random visualisations, or just change aspects of current visualisation
void detectHighBeatChange(byte onNumBeats, byte cutOff) {
  onBeatHigh = false;
  byte oldBeatReading = currentBeatReadingHigh;
  currentBeatReadingHigh = (left.low + right.low)/2;
  if ((currentBeatReadingHigh > cutOff) && (oldBeatReading < cutOff)) {
    if (onNumBeats > 0) {
      if (beatCounterHigh > onNumBeats) {
        beatCounterHigh = 0;
        onBeatHigh = true;
      } else {
        beatCounterHigh++;
      }
    } else {
      onBeatHigh = true;
    }
  }
}
