Keypad_Arduino (Keypad 4.0)
==============

Forked and enhanced Keypad library for Arduino, based on the official version 3.1.

This version has an internal buffer recording the last n strokes. The buffer can be used to read numbers and strings or to check passwords. Everything is optional so that this version is backward compatible with versions <4.0

Reading a float, int, long, string or hex made easier
--------------
A method readQueue() helps you to read instantly the content of the buffer into a float, int, long or string value.

An example?
bool intRead = keypad.readQueue(TYPE_INT, &my_int);

Password and codes recognition
--------------
Willing to protect your arduino setup with a password or any secret code? As an extension of buffering and interpreting the content of the buffer, a method is able to check instantly whether the typed password is correct.

An example?
bool accessGranted = keypad.testCode("12345", 5);


How to install and use?
--------------
Like the previous lib, add Keypad.h, Keypad.cpp and utility/ in a new folder of your lib path (e.g. /usr/share/arduino/libraries/Keypad/).
Then see the sample files (examples/) to see example sketches testing multiple passwords, reading numbers and strings, and reseting automatically the presses after 10 seconds of inactivity.
