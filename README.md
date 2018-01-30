# ledSpeaker
Bluetooth speaker with audio reactive led rings
-----------------------------------------------

Uses 2 x Neopixel Rings (48 leds in total) in series that react to the left and right audio channels.
Makes extensive use of secondary buffer arrays to control the rings as separate units. This also allows for offsetting and reversing of the ring values. 

The right ring fitted to my build was 1 led anti-clockwise from where it should be. The starting point for both rings in the buffer arrays should start at the 0600 position on the led rings themselves. This is what the offset function corrects during setup. FastLED.h offered me no simple way to do that, or to reverse the led order.

Ive tried to keep the code simple enough to achieve what I need using 57% of storage and 31% of dynamic memory on a arduino pro mini.

This software will take the low, mid, and high values for left and right audio then pass that to one of 7 visualisations. A timer is set to a value between 2000 and 8000ms every visualisation change. When timer is met the visualisation will change on the next low peak.
Colour palettes will change on different visualisations depending on high frequency or low frequency peaks. The led rings also rotate in set directions or stop randomly on a low peak.

This code can and will be tidied up and trimmed down, im convinced this can be improved so ill likely stick at it :)

Ill keep this updated the best I can.

Elliot Brown


Requires these libraries to work:
---------------------------------

MSGEQ7 https://github.com/NicoHood/MSGEQ7.git       (for msgeq7 chips)

fastLED https://github.com/FastLED/FastLED.git      (runs the neopixel rings)

Button https://github.com/t3db0t/Button.git         (easy solution for simple button presses and debouncing)

