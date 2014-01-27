/* @file   TestKeypadPassword.ino
|| @author Yoan Mollard
|| @contact yoan.mollard@konqi.fr
||
|| Circuit:
|| * 8-ohm speaker on digital pin 5
||
|| @description
|| |    This is a demonstration of using key codes with version 4.0
|| |
|| #
*/

#include <Arduino.h>

/* Keypad version 4.0 and above only */
#include <Keypad.h>


const byte ROWS = 4;
const byte COLS = 3;

char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte row_pins[ROWS] = { 9, 8, 7, 6 };
byte col_pins[COLS] = { 12, 11, 10 };
const byte beep_pin = 5;

const byte secret_code_length = 4;
const char secret_code[] = "1234";
const char secret_code2[] = "4321";

Keypad kpd = Keypad(makeKeymap(keys), row_pins, col_pins, ROWS, COLS, secret_code_length);
unsigned long lastPress = 0; // Warning, overflow after 50 days

/* This handler produces a short beep and stores the last key press */
void key_event_handler(char c) {
  if(kpd.getState()==PRESSED) {
       tone(5, 600, 50);
       lastPress = millis();
  }
}

void setup()
{
  
  /* Declare the handler */
  kpd.addEventListener(key_event_handler);
}


void loop() {
  kpd.getKey();
  
  /* We test the first password and produce a long sound when it is recognized */
  if(kpd.testPassword(secret_code, secret_code_length)) {
    tone(5, 500, 500);
    kpd.resetKeysInQueue();
  }
  /* We test the second password and produce a different long sound when it is recognized */
  else if(kpd.testPassword(secret_code2, secret_code_length)) {
    tone(5, 300, 500);
    kpd.resetKeysInQueue();
  }
  
  /* Below we make the password buffer expiring after 10 seconds of inactivity */
  if(lastPress + 10000 < millis()) {
    kpd.resetKeysInQueue();
  }
}
