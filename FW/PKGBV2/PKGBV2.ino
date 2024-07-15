
// Board Manger setup:
// https://github.com/earlephilhower/arduino-pico/releases/

#include "Keyboard.h"
#include <OneButton.h>


// Setup buttons
OneButton button1(28, true);
OneButton button2(29, true);

String incomingString = "S";
String functionM1 = "";

void setup() {
  button1.attachClick(Button_M1);
  button1.attachLongPressStop(Button_M1);

  button2.attachClick(Button_M2);
  button2.attachLongPressStop(Button_M2);

  // open the serial port:
  //Serial.begin(9600);
  
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {

  // keep watching the push buttons
  button1.tick();
  button2.tick();
}

void Button_M1()
{
  //Keyboard.press(KEY_LEFT_GUI);
  //Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.write('h');
  delay(10);
  Keyboard.releaseAll();
}

// fit to view by pressing the middle mouse button twice
void Button_M2()
{
  Keyboard.write('S');
  //Serial.println("pressed fit");
}







