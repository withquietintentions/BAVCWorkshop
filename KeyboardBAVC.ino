
/*
TrinketKeyboard example
For Trinket by Adafruit Industries
*/

#include <TrinketKeyboard.h>

#define First_Thing_To_Say 0
#define Next_Thing_To_Say    2

void setup()
{
  // button pins as inputs
  pinMode(First_Thing_To_Say, INPUT);
  pinMode(Next_Thing_To_Say, INPUT);

  // setting input pins to high means turning on internal pull-up resistors
  digitalWrite(First_Thing_To_Say, HIGH);
  digitalWrite(Next_Thing_To_Say, HIGH);
  // remember, the buttons are active-low, they read LOW when they are not pressed

  // start USB stuff
  TrinketKeyboard.begin();
}

void loop()
{
  // the poll function must be called at least once every 10 ms
  // or cause a keystroke
  // if it is not, then the computer may think that the device
  // has stopped working, and give errors
  TrinketKeyboard.poll();

  if (digitalRead(First_Thing_To_Say) == LOW)
  {
    // this should type a capital A
    TrinketKeyboard.print("This is Fun!");
    // this releases the key (otherwise it is held down!)
    TrinketKeyboard.pressKey(0, 0);
  }

  if (digitalRead(Next_Thing_To_Say) == LOW)
  {
    // type out a string using the Print class
    TrinketKeyboard.print("This is Funner!");
  }
}
