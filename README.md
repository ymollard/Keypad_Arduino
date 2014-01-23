Keypad_Arduino
==============

Forked and enhanced Keypad library, based on the official version 3.1. Supports passwords and key codes (any sequence of n keys) and improves the listener feature.

Changed feature: Listener type (Pressed, Released or Both)
--------------

I've added an optional "type" to the listener to allow the programmer to choose in which cases the handler will be called, i.e. either when a key is pressed, or released, or in both cases like it was by default until now.

Added feature: Built-in password and codes recognition
--------------

We can see so many people implementing their own password detection code, that would be a pity not offering this feature in the Keypad lib.

I've added an internal buffer recording the last n strokes. Associated to a code check method it allows to easily read passwords or any sequence of keys with length <=n. Plus added a destructor to free cleanly the buffer when it's not used anymore.

Everything is optional so that this version is backward compatible with versions <4.0
