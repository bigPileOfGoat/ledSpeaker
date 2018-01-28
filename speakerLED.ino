/*/////////////////////////////////////////
  /                                       /
  /    Bluetooth Speaker v2.0             /
  /    ----------------------             /
  /                                       /
  /    Audio Reactive LED Visualisations  /
  /    and Button Control                 /
  /                                       /
  /    Coded By                           /
  /    Elliot Brown                       /
  /                                       /
  /    Jan 2018                           /
  /                                       /
  ///////////////////////////////////////*/

/* Pins and library for Button */
#include <Button.h>
const int ledPower = 14;
const int ledState = 9;
Button ledPowerButton = Button(ledPower, BUTTON_PULLUP_INTERNAL, true, 50);
Button ledStateButton = Button(ledState, BUTTON_PULLUP_INTERNAL, true, 50);
boolean powerButtonOn = true;

/* Pin configration for MSGEQ7 */
#include <MSGEQ7.h>
const int pinAnalogLeft = A1;
const int pinAnalogRight = A0;
const int pinReset = 8;
const int pinStrobe = 7;

/* store audio EQ data for left and right inputs */
struct Speaker {
  byte high, mid, low;
};
Speaker left, right;

/* Pin and Library setup for NeoPixels */
#include "FastLED.h"
#define DATA_PIN 6
#define NUM_LEDS 48
CRGB leds[NUM_LEDS]; //creates single array of leds for the FastLED library
byte ledBrightness = 10; //current brightness of leds
byte maxBrightness = 65; //maximum brightness of leds
boolean ledsOn = true;
CRGBPalette16 currentPalette; // used to change colour palletes during visualisations
byte hsvIndex = random(255);

//creates an object for the LED arrays
/*used in an array as a buffer for the CRGB leds[] object */
struct LED {
  byte r, g, b; //colour vales to be sent to FastLED.h
  byte pos;  //position of LED to be sent to FastLED.h
};

//creates buffer arrays from LED object for LEFT and RIGHT ring
/*using buffer arrays allows me to use 2 rings in series but control
  them separately like they are in paralel, so im only using 1 data pin
  rather than 2.Also allows the shifting of LED positions for
  corrective offset or reversing. The right ring starting position is
  actually 1 led out compared to the left ring, this allows me to fix
  that in code */
LED lRing[24];
LED rRing[24];

/* variables used for timing, visualisation changes, and duration */
byte maxPatterns = 6;                     // maximum number of visualisations
byte maxAnimations = 10;                  // same as maxPatterns, used for manual changes
int maxAnimTime = 8000;                   // max bounds for visualisation duration
boolean animSameAsPattern = true;         // the first manualy selected visualisation is the same as current random pattern
byte animOff = 0;                         // manual visualisation selection off
byte pattern= random(maxPatterns);        // randomise starting visualisation
byte animSelect = 0;                      // current manualy selected visualisation, 0 if randomised
int animTimer = random(2000, maxAnimTime);// sets visualisation duration timer
byte rotatePattern = random(500);                   // used for changing or freezing ring rotation (2 out of 5 chance of left or right, 1 out of 5 chance of stop)

/* used for beat detection  */
int currentBeatReadingLow = 0;            // stores current low beat reading
byte beatCounterLow = 0;                  // used to return a number of low beats
byte returnedBeatLow = 0;                 // returns number of low beats from detection function
boolean onBeatLow = false;                // returns true is a beat is detected

int currentBeatReadingHigh = 0;           // stores current high beat reading
byte beatCounterHigh = 0;                 // used to return a number of high beats
byte returnedBeatHigh = 0;                // returns number of high beats from detection function
boolean onBeatHigh = false;               // returns true if a beat is detected

/* used for barEQ visualisation */
boolean allColour = false;                // decides rgb or palette for barEQ visualisation 
byte barFreq = 0;                         // sets which single bar visualisation to display

/* used for chaser visualisation */
byte chaseFreq = 0;                       // frequency displayed in chaser visualisation
byte chasePos = 0;                        // used for moving chaser visualisation

/* used for pulse visualisation */
byte pulseVar = 5;                        // changes the pulse visualisation colour order on beat. 5 = default

/* setup all data and run "power on" animation */
void setup() {
  randomSeed(analogRead(0));

  /* setup the neopixel rings */
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS); //initialise LEDs
  FastLED.setDither(1); // prevent flickering
  FastLED.setBrightness(maxBrightness);// value from 0 - 255
  FastLED.show(); // update LEDs
  setupLedRingArrays(150, 150, 150); // set starting colours and correct led offset on right ring

  /* get MSGEQ7 and arduino ready for reading audio */
  MSGEQ7.begin(pinReset, pinStrobe, pinAnalogLeft, pinAnalogRight); // initialise the EQ library
  powerOnAnim(); // runs pulsing "power on" animation
}

/* main loop, where all the good stuff happens */
void loop() {

  /* timer for main loop, every 20ms update the visualisation */
  readButtons(); // checks for button presses
  detectLowBeatChange(0, 155); //detects falling edge of bass beat below threshold, not fast or accurate but kinda works
  detectHighBeatChange(0, 160);
  static long prevMillis = 0;
  unsigned long currentMillis = millis(); // read time
  if ((currentMillis - prevMillis > 20) && (ledsOn)) {
    prevMillis = currentMillis;
    readAudio(); //copy eq values to buffer for visualisations to use this frame
    if ((pattern == 0) || (animSelect == 1)) barEQ(1, barFreq);
    if ((pattern == 1) || (animSelect == 2)) barEQ(2, 0);
    if ((pattern == 2) || (animSelect == 3)) barEQ(3, 0);
    if ((pattern == 3) || (animSelect == 4)) sparkle();
    if ((pattern == 4) || (animSelect == 5)) pulseLEDs();
    if ((pattern == 5) || (animSelect == 6)) mirrorBarEQ(0);
    if ((pattern == 6) || (animSelect == 7)) chaser();
    //if ((pattern == 7) || (animSelect == 8)) {
      // new visualisation?
    //}
    if (animSelect == 8) barEQ(1, 0);
    if (animSelect == 9) barEQ(1, 1);
    if (animSelect == 10) barEQ(1, 2);
    FastLED.show(); //update leds with new data
  }
  /* choose value to decide next rotation change when low beat has returned true
     allows direction to change based on falling edge of beat (not very accurate
     but it looks good, so meh ;) */
  if (onBeatLow) {
    rotatePattern = random(500);
    if ((pattern == 3) || (animSelect == 4)) rotatePattern = 0; //stop rotation if sparkle visualisation running
    //decide whether to use palette or rgb for barEQ visualisation
    hsvIndex = random(255);
    changePallete();
    if (allColour) { 
      allColour = false;
    } else {
      allColour = true;
    }
  }
  if (onBeatHigh) {
    changePallete();
    barFreq = random(0, 3);
    chaseFreq = random(3);
  }
  /* set timers for rotation and visualistion changes.
     between 2 seconds and 12 seconds */
  static long prevMillis1 = 0;
  unsigned long currentMillis1 = millis();
  if ((currentMillis1 - prevMillis1 > animTimer) && (ledsOn) && (onBeatHigh)) {
    prevMillis1 = currentMillis1;
    animTimer = random(2000, maxAnimTime); //set visualisation change timer
    if (pattern < maxPatterns) {
      pattern = random(maxPatterns);
    }
  }
  /* timer for rotation at set speed if leds are on
     rotates by one position every 200millis if rotatePattern > 100 */
  static long prevMillis2 = 0;
  unsigned long currentMillis2 = millis();
  if ((currentMillis2 - prevMillis2 > 200) && (ledsOn)) {
    prevMillis2 = currentMillis2;
    if ((rotatePattern >= 99) && (rotatePattern < 300)) {
      /* rotate 1 to the left */
      ringOffset(lRing, 1, true);
      ringOffset(rRing, 1, true);
    }
    if ((rotatePattern >= 299 ) && (rotatePattern < 500)) {
      /* rotate 1 to the right */
      ringOffset(lRing, 1, false);
      ringOffset(rRing, 1, false);
    }
  }
}

