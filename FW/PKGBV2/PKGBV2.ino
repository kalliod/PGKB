#include <Adafruit_NeoPixel.h>
#include "Keyboard.h"
#include <OneButton.h>

// Neopixel
#define PIN 26
#define NUMPIXELS 11

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// Setup buttons
OneButton button1(1, true);
OneButton button2(2, true);
OneButton button3(7, true);
OneButton button4(8, true);
OneButton button5(9, true);
OneButton button6(13, true);
OneButton button7(14, true);
OneButton button8(15, true);
OneButton button9(16, true);
OneButton button10(27, true);
OneButton button11(28, true);

OneButton encoderButton(29, true);

String incomingString = "S";
String functionM1 = "";

void setup() {

  pixels.begin();

  pixels.clear();
  pixels.show();

  button1.attachClick(Button_M1);
  button1.attachLongPressStop(Button_M1);

  button2.attachClick(Button_M2);
  button2.attachLongPressStop(Button_M2);

  button3.attachClick(Button_M3);
  button3.attachLongPressStop(Button_M3);

  button4.attachClick(Button_M4);
  button4.attachLongPressStop(Button_M4);

  button5.attachClick(Button_M5);
  button5.attachLongPressStop(Button_M5);

  button6.attachClick(Button_M6);
  button6.attachLongPressStop(Button_M6);

  button7.attachClick(Button_M7);
  button7.attachLongPressStop(Button_M7);

  button8.attachClick(Button_M8);
  button8.attachLongPressStop(Button_M8);

  button9.attachClick(Button_M9);
  button9.attachLongPressStop(Button_M9);

  button10.attachClick(Button_M10);
  button10.attachLongPressStop(Button_M10);

  button11.attachClick(Button_M11);
  button11.attachLongPressStop(Button_M11);

  encoderButton.attachClick(Button_Encoder);
  encoderButton.attachLongPressStop(Button_Encoder);

  // open the serial port:
  //Serial.begin(9600);
  
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {

  // keep watching the push buttons
  button1.tick();
  button2.tick();
  button3.tick();
  button4.tick();
  button5.tick();
  button6.tick();
  button7.tick();
  button8.tick();
  button9.tick();
  button10.tick();
  button11.tick();

  encoderButton.tick();

}

void Button_M1()
{
  //Keyboard.press(KEY_LEFT_GUI);
  //Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.write('1');
  //delay(10);
  //Keyboard.releaseAll();
  pixels.setPixelColor(0, pixels.Color(0, 150, 0));
  pixels.show();
}

// fit to view by pressing the middle mouse button twice
void Button_M2()
{
  Keyboard.write('2');
  pixels.setPixelColor(1, pixels.Color(0, 150, 0));
  pixels.show();
  //Serial.println("pressed fit");
}

void Button_M3()
{
  Keyboard.write('3');
  pixels.setPixelColor(2, pixels.Color(150, 0, 0));
  pixels.show();
}

void Button_M4()
{
  Keyboard.write('4');
  pixels.setPixelColor(3, pixels.Color(0, 0, 150));
  pixels.show();
}

void Button_M5()
{
  Keyboard.write('5');
  pixels.setPixelColor(4, pixels.Color(150, 150, 150));
  pixels.show();
}
void Button_M6()
{
  Keyboard.write('6');
  pixels.setPixelColor(5, pixels.Color(50, 50, 50));
  pixels.show();
}
void Button_M7()
{
  Keyboard.write('7');
  pixels.setPixelColor(6, pixels.Color(30, 30, 30));
  pixels.show();
}
void Button_M8()
{
  Keyboard.write('8');
  pixels.setPixelColor(7, pixels.Color(0, 0, 255));
  pixels.show();
}
void Button_M9()
{
  Keyboard.write('9');
  pixels.setPixelColor(8, pixels.Color(0, 255, 0));
  pixels.show();
}
void Button_M10()
{
  Keyboard.write('A');
  pixels.setPixelColor(9, pixels.Color(255, 0, 0));
  pixels.show();
}
void Button_M11()
{
  Keyboard.write('B');
  pixels.setPixelColor(10, pixels.Color(50, 150, 50));
  pixels.show();
}
void Button_Encoder()
{
  Keyboard.write('E');
  pixels.clear();
  pixels.show();
}




