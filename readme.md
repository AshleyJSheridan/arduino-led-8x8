# Arduino LED 8×8

An Arduino script to display messages on a MAX7219 module

Based on the [8×8 Matrix MAX7219 code](http://playground.arduino.cc/LEDMatrix/Max7219) available on the [Arduino Playground](http://playground.arduino.cc)

## Setup
The MAX7219 requires 5 connections:

* 5V to VCC
* Ground to GND
* Pin 2 to DIN (data in)
* Pin 3 to CS (load)
* Pin 4 to CLK (clock)

The data pins listed above are within the first few lines of the main `led_matrix_8x8.ino` file if you wish to change them.

## Why?
The original script was just written to output bitmaps, but had no preset ones in place, it was a raw template, essentially.

I wanted to alter this to allow for whole messages, or other fun symbols to be output to my board.

## Capabilities
Currently, standard strings can be output with the `display_string(String message)` using standard letters (upper and lowercase), numbers, and some basic punctuation.

The speed at which string messages are displayed is determined by the `letter_display_time` variable which is the delay in milliseconds between showing each character.

For characters outside of the standard ANSI, (e.g. beer, heart, and poop) there is the `display_symbol(String symbol)` method, which looks up a character by name in the `characters` array. This allows new characters and symbols outside of ANSI to be easily added to the main array quite easily with any name.

The calls to each can be mixed together in any combination, either within the `loop()` to repeat a message/display, or within the `setup()` method to run once.

## Examples
display_string("Wine smells better than ");
display_symbol("poop");

## Future Improvements
Going forward, I'd like to make some of the following updates:

* Allow for messages to be scrolled in pixel columns/rows
* Add UTF8 support to the string methods so that all messages can be displayed as strings, rather than character by character for those outside of the ANSI range
