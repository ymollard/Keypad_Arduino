Keypad_Arduino (Keypad 4.0)
==============

Forked and enhanced Keypad library, based on the official version 3.1.

Added feature: Built-in password and codes recognition
--------------

We can see so many people implementing their own password detection code, that would be a pity not offering this feature in the Keypad lib.

I've added an internal buffer recording the last n strokes. Associated to a code check method it allows to easily read passwords or any sequence of keys with length <=n. Plus added a destructor to free cleanly the buffer when it's not used anymore.

Everything is optional so that this version is backward compatible with versions <4.0
