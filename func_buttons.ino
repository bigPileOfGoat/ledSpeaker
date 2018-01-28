/* reads button states */
void readButtons() {

  if (ledPowerButton.uniquePress()) {
    FastLED.setBrightness(maxBrightness);
    FastLED.show();
    if (!powerButtonOn) powerButtonFadeOn(); // run fade on animation
    if (powerButtonOn) {
      pattern = random(maxPatterns); //resets pattern from max+5, now random visualisations
      powerButtonFadeOff(); //run fade off animation
    }
    animSelect = 0; //stops manual visualisation change 0 = stop
    powerButtonOn = !powerButtonOn;
    animSameAsPattern = true;
  }
  if ((ledStateButton.uniquePress()) && (powerButtonOn)) {  //ignore if leds are off
    buttonPulse();
    buttonPulse();
    animSelect++; //increment manually selected visualisation
    if (animSelect > maxAnimations) animSelect = 1; //wrap value to start positon 1
    if (animSameAsPattern) { //this pauses visualisation, presses after will increment the visualisation selection
      animSelect = pattern + 1;
      pattern = maxPatterns + 5; // if pattern > max the visualisations will only change by manual selection
      animSameAsPattern = false; //already moved to next visualisation
    }
  }
  if (powerButtonOn) {
    ledBrightness = maxBrightness; //turn leds back on
    ledsOn = true;
  }
  if (!powerButtonOn) {
    ledBrightness = 0; //turn leds off
    ledsOn = false;
    clearColour(); //set all leds to r:0 g:0 b:0
  }
  FastLED.setBrightness(ledBrightness); //update FastLED array brightness
}

/* 2 white pulses light on button press */
void buttonPulse() {
  for (int i = 0; i < 255; i = i + 6) {
    for (int j = 0; j < 24; j++) {
      leds[lRing[j].pos] = CRGB(i, i, i);
      leds[rRing[j].pos] = CRGB(i, i, i);
    }
    FastLED.show();
    delayMicroseconds(1);
  }
  for (int i = 255; i >= 0; i = i - 6) {
    for (int j = 0; j < 24; j++) {
      leds[lRing[j].pos] = CRGB(i, i, i);
      leds[rRing[j].pos] = CRGB(i, i, i);
    }
    FastLED.show();
    delayMicroseconds(1);
  }
  delay(10);
}

/* fades red light off when leds are turned off */
void powerButtonFadeOff() {
  for (int i = 255; i >= 0; i--) {
    for (int j = 0; j < 24; j++) {
      leds[lRing[j].pos] = CRGB(i, 0, 0);
      leds[rRing[j].pos] = CRGB(i, 0, 0);
    }
    FastLED.show();
    delayMicroseconds(2);
  }
}

/* fades red light on when leds are turned on */
void powerButtonFadeOn() {
  for (int i = 0; i < 255; i++) {
    for (int j = 0; j < 24; j++) {
      leds[lRing[j].pos] = CRGB(i, 0, 0);
      leds[rRing[j].pos] = CRGB(i, 0, 0);
    }
    FastLED.show();
    delayMicroseconds(2);
  }
}

/* 3 slowing red pulses as speaker powers on */
void powerOnAnim() {
  delay(1000);
  for (int i = 0; i < 255; i = i + 6) {
    for (int j = 0; j < 24; j++) {
      leds[lRing[j].pos] = CRGB(i, 0, 0);
      leds[rRing[j].pos] = CRGB(i, 0, 0);
    }
    FastLED.show();
    delayMicroseconds(20);
  }
  delay(50);
  for (int i = 0; i < 255; i = i + 3) {
    for (int j = 0; j < 24; j++) {
      leds[lRing[j].pos] = CRGB(0, i, 0);
      leds[rRing[j].pos] = CRGB(0, i, 0);
    }
    FastLED.show();
    delayMicroseconds(20);
  }
  delay(50);
  for (int i = 0; i < 255; i = i + 3) {
    for (int j = 0; j < 24; j++) {
      leds[lRing[j].pos] = CRGB(0, 0, i);
      leds[rRing[j].pos] = CRGB(0, 0, i);
    }
    FastLED.show();
    delayMicroseconds(20);
  }
  delay(50);
  for (int i = 0; i < 255; i++) {
    for (int j = 0; j < 24; j++) {
      leds[lRing[j].pos] = CRGB(i, i, i);
      leds[rRing[j].pos] = CRGB(i, i, i);
    }
    FastLED.show();
    delayMicroseconds(20);
  }
  delay(200);
}
