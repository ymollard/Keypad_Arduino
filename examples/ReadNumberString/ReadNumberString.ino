/* @file   TestKeypadPassword.ino
|| @author Yoan Mollard
|| @contact yoan.mollard@konqi.fr
||
|| Circuit:
|| * 8-ohm speaker on digital pin 5
||
|| @description
|| |    Debug/test of generic buffer
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
  {'.','0','-'}
};

byte row_pins[ROWS] = { 9, 8, 7, 6 };
byte col_pins[COLS] = { 12, 11, 10 };
const byte beep_pin = 5;

const byte buffer_length = 7;


Keypad kpd = Keypad(makeKeymap(keys), row_pins, col_pins, ROWS, COLS, buffer_length);
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
  Serial.begin(9600);
  /* Declare the handler */
  kpd.addEventListener(key_event_handler);
}

//int sum = 0;

void loop() {
  kpd.getKey();
  
  float f;
  if(kpd.readQueue(TYPE_FLOAT, &f)) {
    Serial.print("f = ");
    Serial.print(f);
    Serial.print("\r\n"); 
  }
  int i;
  if(kpd.readQueue(TYPE_INT, &i)) {
    Serial.print("i = ");
    Serial.print(i);
    Serial.print("\r\n"); 
  }
  
  /* Below we make the buffer expiring after 4 seconds of inactivity */
  if(lastPress + 4000 < millis()) {
    kpd.resetKeysInQueue();
  }
  
  //Serial.print("Sum = "); Serial.print(sum); Serial.print("\r\n");
}
