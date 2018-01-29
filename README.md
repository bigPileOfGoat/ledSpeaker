# ledSpeaker
Bluetooth speaker with audio reactive led rings

Uses 2 x Neopixel Rings (48 leds in total) in series that react to the left and right audio channels.
Makes extensive use of secondary buffer arrays to control the rings as separate units. Also allows for offsetting and reversing of the ring values. 

The right ring fitted to my build was 1 led clockwise from where it should be, the starting point for both rings in the buffer arrays should at the 0600 position on the led rings themselves. This is what the offset function corrects during setup. FastLED.h offered me no simple way to do that, or to reverse the led order.

Ive tried to keep the code simple enough to achieve what I need using only 57% storage and 31% memory on a arduino pro mini.

This software will take the low, mid, and high values for left and right audio then pass that to one of 7 visualisations. A timer is set to a value between 2000 and 8000ms every visualisation change. When timer is met the visualisation will change on the next low peak.
Colour palettes will change on different visualisations depending on high frequency or low frequency peaks. The led rings also rotate in set directions or stop randomly on a low peak.

This code can and will be tidied up and trimmed down, im convinced this can be improved so ill stick at it :)

Ill keep this updated the best I can.

Requires these libraries to work:

MSGEQ7 https://github.com/NicoHood/MSGEQ7.git       (for msgeq7 chips)

fastLED https://github.com/FastLED/FastLED.git      (runs the neopixel rings)

Button https://github.com/t3db0t/Button.git         (easy solution for simple button presses and debouncing)

Coding not perfect or efficient at all, however it currently works... so hey, thumbs up :) 
