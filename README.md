# ledSpeaker
Bluetooth speaker with audio reactive led rings

Uses 2 x Neopixel Rings (48 leds in total) in series that react to the left and right audio channels.
Makes extensive use of secondary buffers to control the rings as separate units. Also allows for offsetting and reversing of the ring values.

Requires these libraries to work:

MSGEQ7 https://github.com/NicoHood/MSGEQ7.git       (for msgeq7 chips)
fastLED https://github.com/FastLED/FastLED.git      (runs the neopixel rings)
Button https://github.com/t3db0t/Button.git         (easy solution for simple button presses and debouncing)

Coding not perfect or efficient at all, however it currently works... so hey, thumbs up :) 
