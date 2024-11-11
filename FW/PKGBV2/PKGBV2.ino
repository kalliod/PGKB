#include <Adafruit_NeoPixel.h>
#include "Keyboard.h"
#include <OneButton.h>
#include <RotaryEncoder.h>



// Neopixel
#define PIN 26
#define NUMPIXELS 11
#define PIN_IN1 17
#define PIN_IN2 18


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

RotaryEncoder encoder(PIN_IN1, PIN_IN2, RotaryEncoder::LatchMode::TWO03);

String incomingString = "S";
String functionM1 = "";

const long interval = 10; 
unsigned long previousMillis = 0;

int M1[] = {0, 20, 255};
int M1_tmp[] = {0, 0, 0};

int M2[] = {30, 128, 200};
int M2_tmp[] = {0, 0, 0};

int M3[] = {128, 128, 200};
int M3_tmp[] = {0, 0, 0};

int M4[] = {30, 50, 255};
int M4_tmp[] = {0, 0, 0};

int M5[] = {255, 128, 200};
int M5_tmp[] = {0, 0, 0};

int M6[] = {70, 70, 200};
int M6_tmp[] = {0, 0, 0};

int M7[] = {30, 128, 200};
int M7_tmp[] = {0, 0, 0};

int M8[] = {30, 255, 200};
int M8_tmp[] = {0, 0, 0};

int M9[] = {128, 255, 40};
int M9_tmp[] = {0, 0, 0};

int M10[] = {100, 128, 200};
int M10_tmp[] = {0, 0, 0};

int M11[] = {0, 255, 200};
int M11_tmp[] = {0, 0, 0};

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
  
 

  // Set defaul NeoPixel colors
  pixels.setPixelColor(0, pixels.Color(M1[0], M1[1], M1[2]));
  pixels.setPixelColor(1, pixels.Color(M2[0], M2[1], M2[2]));
  pixels.setPixelColor(2, pixels.Color(M3[0], M3[1], M3[2]));
  pixels.setPixelColor(3, pixels.Color(M4[0], M4[1], M4[2]));
  pixels.setPixelColor(4, pixels.Color(M5[0], M5[1], M5[2]));
  pixels.setPixelColor(5, pixels.Color(M6[0], M6[1], M6[2]));
  pixels.setPixelColor(6, pixels.Color(M7[0], M7[1], M7[2]));
  pixels.setPixelColor(7, pixels.Color(M8[0], M8[1], M8[2]));
  pixels.setPixelColor(8, pixels.Color(M9[0], M9[1], M9[2]));
  pixels.setPixelColor(9, pixels.Color(M10[0], M10[1], M10[2]));
  pixels.setPixelColor(10, pixels.Color(M11[0], M11[1], M11[2]));
  pixels.show();

  // open the serial port:
  //Serial.begin(9600);
  
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {

  unsigned long currentMillis = millis();


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

    if (currentMillis - previousMillis >= interval) {
      // save the last time
      previousMillis = currentMillis;
      checkFade();     

  }


  static int pos = 0;
  encoder.tick();

  int newPos = encoder.getPosition();
  if (pos < newPos) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ARROW);


    Keyboard.releaseAll();
    pos = newPos;
  }
  if (pos > newPos) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_RIGHT_ARROW);

    Keyboard.releaseAll();
    pos = newPos;
  }

}

void Button_M1()
{
  M1_tmp[0] = 0;
  M1_tmp[1] = 0;
  M1_tmp[2] = 0;
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.write('l');
  Keyboard.releaseAll();
  pixels.setPixelColor(0, pixels.Color(M1_tmp[0], M1_tmp[1], M1_tmp[2]));
  pixels.show();
}

void Button_M2()
{
  M2_tmp[0] = 0;
  M2_tmp[1] = 0;
  M2_tmp[2] = 0;
  Keyboard.write('2');
  pixels.setPixelColor(1, pixels.Color(M2_tmp[0], M2_tmp[1], M2_tmp[2]));
  pixels.show();
}

void Button_M3()
{
  M3_tmp[0] = 0;
  M3_tmp[1] = 0;
  M3_tmp[2] = 0;
  Keyboard.write('3');
  pixels.setPixelColor(2, pixels.Color(M3_tmp[0], M3_tmp[1], M3_tmp[2]));
  pixels.show();
}

void Button_M4()
{
  M4_tmp[0] = 0;
  M4_tmp[1] = 0;
  M4_tmp[2] = 0;
  Keyboard.write('4');
  pixels.setPixelColor(3, pixels.Color(M4_tmp[0], M4_tmp[1], M4_tmp[2]));
  pixels.show();
}

void Button_M5()
{
  M5_tmp[0] = 0;
  M5_tmp[1] = 0;
  M5_tmp[2] = 0;
  Keyboard.write('5');
  pixels.setPixelColor(4, pixels.Color(M5_tmp[0], M5_tmp[1], M5_tmp[2]));
  pixels.show();
}
void Button_M6()
{
  M6_tmp[0] = 0;
  M6_tmp[1] = 0;
  M6_tmp[2] = 0;
  Keyboard.write('6');
  pixels.setPixelColor(5, pixels.Color(M6_tmp[0], M6_tmp[1], M6_tmp[2]));
  pixels.show();
}
void Button_M7()
{
  M7_tmp[0] = 0;
  M7_tmp[1] = 0;
  M7_tmp[2] = 0;
  Keyboard.write('7');
  pixels.setPixelColor(6, pixels.Color(M7_tmp[0], M7_tmp[1], M7_tmp[2]));
  pixels.show();
}
void Button_M8()
{
  M8_tmp[0] = 0;
  M8_tmp[1] = 0;
  M8_tmp[2] = 0;
  Keyboard.write('8');
  pixels.setPixelColor(7, pixels.Color(M8_tmp[0], M8_tmp[1], M8_tmp[2]));
  pixels.show();
}
void Button_M9()
{
  M9_tmp[0] = 0;
  M9_tmp[1] = 0;
  M9_tmp[2] = 0;
  Keyboard.write('9');
  pixels.setPixelColor(8, pixels.Color(M9_tmp[0], M9_tmp[1], M9_tmp[2]));
  pixels.show();
}
void Button_M10()
{
  M10_tmp[0] = 0;
  M10_tmp[1] = 0;
  M10_tmp[2] = 0;
  Keyboard.write('A');
  pixels.setPixelColor(9, pixels.Color(M10_tmp[0], M10_tmp[1], M10_tmp[2]));
  pixels.show();
}
void Button_M11()
{
  M11_tmp[0] = 0;
  M11_tmp[1] = 0;
  M11_tmp[2] = 0;
  Keyboard.write('B');
  pixels.setPixelColor(10, pixels.Color(M11_tmp[0], M11_tmp[1], M11_tmp[2]));
  pixels.show();
}
void Button_Encoder()
{
  Keyboard.write('E');
  //pixels.clear();
  //pixels.show();
}

void checkFade() {
 
// M1 Button
  if (M1_tmp[0] < M1[0]) {
        M1_tmp[0]++;
        pixels.setPixelColor(0, pixels.Color(M1_tmp[0], M1_tmp[1], M1_tmp[2]));
        pixels.show();
      }

  if (M1_tmp[1] < M1[1]) {
        M1_tmp[1]++;
        pixels.setPixelColor(0, pixels.Color(M1_tmp[0], M1_tmp[1], M1_tmp[2]));
        pixels.show();
      }

  if (M1_tmp[2] < M1[2]) {
        M1_tmp[2]++;
        pixels.setPixelColor(0, pixels.Color(M1_tmp[0], M1_tmp[1], M1_tmp[2]));
        pixels.show();
      }
  
  // M2 Button
  if (M2_tmp[0] < M2[0]) {
        M2_tmp[0]++;
        pixels.setPixelColor(1, pixels.Color(M2_tmp[0], M2_tmp[1], M2_tmp[2]));
        pixels.show();
      }

  if (M2_tmp[1] < M2[1]) {
        M2_tmp[1]++;
        pixels.setPixelColor(1, pixels.Color(M2_tmp[0], M2_tmp[1], M2_tmp[2]));
        pixels.show();
      }

  if (M2_tmp[2] < M2[2]) {
        M2_tmp[2]++;
        pixels.setPixelColor(1, pixels.Color(M2_tmp[0], M2_tmp[1], M2_tmp[2]));
        pixels.show();
      }

  // M3 Button
  if (M3_tmp[0] < M3[0]) {
        M3_tmp[0]++;
        pixels.setPixelColor(2, pixels.Color(M3_tmp[0], M3_tmp[1], M3_tmp[2]));
        pixels.show();
      }

  if (M3_tmp[1] < M3[1]) {
        M3_tmp[1]++;
        pixels.setPixelColor(2, pixels.Color(M3_tmp[0], M3_tmp[1], M3_tmp[2]));
        pixels.show();
      }

  if (M3_tmp[2] < M3[2]) {
        M3_tmp[2]++;
        pixels.setPixelColor(2, pixels.Color(M3_tmp[0], M3_tmp[1], M3_tmp[2]));
        pixels.show();
      }

  // M4 Button
  if (M4_tmp[0] < M4[0]) {
        M4_tmp[0]++;
        pixels.setPixelColor(3, pixels.Color(M4_tmp[0], M4_tmp[1], M4_tmp[2]));
        pixels.show();
      }

  if (M4_tmp[1] < M4[1]) {
        M4_tmp[1]++;
        pixels.setPixelColor(3, pixels.Color(M4_tmp[0], M4_tmp[1], M4_tmp[2]));
        pixels.show();
      }

  if (M4_tmp[2] < M4[2]) {
        M4_tmp[2]++;
        pixels.setPixelColor(3, pixels.Color(M4_tmp[0], M4_tmp[1], M4_tmp[2]));
        pixels.show();
      }

  // M5 Button
  if (M5_tmp[0] < M5[0]) {
        M5_tmp[0]++;
        pixels.setPixelColor(4, pixels.Color(M5_tmp[0], M5_tmp[1], M5_tmp[2]));
        pixels.show();
      }

  if (M5_tmp[1] < M5[1]) {
        M5_tmp[1]++;
        pixels.setPixelColor(4, pixels.Color(M5_tmp[0], M5_tmp[1], M5_tmp[2]));
        pixels.show();
      }

  if (M5_tmp[2] < M5[2]) {
        M5_tmp[2]++;
        pixels.setPixelColor(4, pixels.Color(M5_tmp[0], M5_tmp[1], M5_tmp[2]));
        pixels.show();
      }

  // M6 Button
  if (M6_tmp[0] < M6[0]) {
        M6_tmp[0]++;
        pixels.setPixelColor(5, pixels.Color(M6_tmp[0], M6_tmp[1], M6_tmp[2]));
        pixels.show();
      }

  if (M6_tmp[1] < M6[1]) {
        M6_tmp[1]++;
        pixels.setPixelColor(5, pixels.Color(M6_tmp[0], M6_tmp[1], M6_tmp[2]));
        pixels.show();
      }

  if (M6_tmp[2] < M6[2]) {
        M6_tmp[2]++;
        pixels.setPixelColor(5, pixels.Color(M6_tmp[0], M6_tmp[1], M6_tmp[2]));
        pixels.show();
      }

  // M7 Button
  if (M7_tmp[0] < M7[0]) {
        M7_tmp[0]++;
        pixels.setPixelColor(6, pixels.Color(M7_tmp[0], M7_tmp[1], M7_tmp[2]));
        pixels.show();
      }

  if (M7_tmp[1] < M7[1]) {
        M7_tmp[1]++;
        pixels.setPixelColor(6, pixels.Color(M7_tmp[0], M7_tmp[1], M7_tmp[2]));
        pixels.show();
      }

  if (M7_tmp[2] < M7[2]) {
        M7_tmp[2]++;
        pixels.setPixelColor(6, pixels.Color(M7_tmp[0], M7_tmp[1], M7_tmp[2]));
        pixels.show();
      }
  
  // M8 Button
  if (M8_tmp[0] < M8[0]) {
        M8_tmp[0]++;
        pixels.setPixelColor(7, pixels.Color(M8_tmp[0], M8_tmp[1], M8_tmp[2]));
        pixels.show();
      }

  if (M8_tmp[1] < M8[1]) {
        M8_tmp[1]++;
        pixels.setPixelColor(7, pixels.Color(M8_tmp[0], M8_tmp[1], M8_tmp[2]));
        pixels.show();
      }

  if (M8_tmp[2] < M8[2]) {
        M8_tmp[2]++;
        pixels.setPixelColor(7, pixels.Color(M8_tmp[0], M8_tmp[1], M8_tmp[2]));
        pixels.show();
      }

  // M9 Button
  if (M9_tmp[0] < M9[0]) {
        M9_tmp[0]++;
        pixels.setPixelColor(8, pixels.Color(M9_tmp[0], M9_tmp[1], M9_tmp[2]));
        pixels.show();
      }

  if (M9_tmp[1] < M9[1]) {
        M9_tmp[1]++;
        pixels.setPixelColor(8, pixels.Color(M9_tmp[0], M9_tmp[1], M9_tmp[2]));
        pixels.show();
      }

  if (M9_tmp[2] < M9[2]) {
        M9_tmp[2]++;
        pixels.setPixelColor(8, pixels.Color(M9_tmp[0], M9_tmp[1], M9_tmp[2]));
        pixels.show();
      }

  // M10 Button
  if (M10_tmp[0] < M10[0]) {
        M10_tmp[0]++;
        pixels.setPixelColor(9, pixels.Color(M10_tmp[0], M10_tmp[1], M10_tmp[2]));
        pixels.show();
      }

  if (M10_tmp[1] < M10[1]) {
        M10_tmp[1]++;
        pixels.setPixelColor(9, pixels.Color(M10_tmp[0], M10_tmp[1], M10_tmp[2]));
        pixels.show();
      }

  if (M10_tmp[2] < M10[2]) {
        M10_tmp[2]++;
        pixels.setPixelColor(9, pixels.Color(M10_tmp[0], M10_tmp[1], M10_tmp[2]));
        pixels.show();
      }

  // M11 Button
  if (M11_tmp[0] < M11[0]) {
        M11_tmp[0]++;
        pixels.setPixelColor(10, pixels.Color(M11_tmp[0], M11_tmp[1], M11_tmp[2]));
        pixels.show();
      }

  if (M11_tmp[1] < M11[1]) {
        M11_tmp[1]++;
        pixels.setPixelColor(10, pixels.Color(M11_tmp[0], M11_tmp[1], M11_tmp[2]));
        pixels.show();
      }

  if (M11_tmp[2] < M11[2]) {
        M11_tmp[2]++;
        pixels.setPixelColor(10, pixels.Color(M11_tmp[0], M11_tmp[1], M11_tmp[2]));
        pixels.show();
      }

}




