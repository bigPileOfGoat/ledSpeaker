/* will detetct a set number of low beats (or bass peaks) to cause a change in visualisation
   this could change random visualisations, or just change aspects of current visualisation */
void detectLowBeatChange(byte onNumBeats, byte cutOff) {
  onBeatLow = false;
  byte oldBeatReading = currentBeatReadingLow;
  currentBeatReadingLow = (left.low + right.low) / 2;
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

/* will detetct a set number of high beats (or high peaks) to cause a change in visualisation
   this could change random visualisations, or just change aspects of current visualisation */
void detectHighBeatChange(byte onNumBeats, byte cutOff) {
  onBeatHigh = false;
  byte oldBeatReading = currentBeatReadingHigh;
  currentBeatReadingHigh = (left.low + right.low) / 2;
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
