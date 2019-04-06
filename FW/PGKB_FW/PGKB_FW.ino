#include <Wire.h>
#include "Adafruit_MCP23017.h"
#include "KD_ardu_button.h"
#include <Keyboard.h>

// FIN:
// * = (
// ( = )

/* Hardware configuration */

// TL: My keyboard writes 900 characters if a key is pressed for 30 sec. If
// two keys are pressed the amount of characters is doubled

// HW
#define BUTTON_DEBOUNCE 20                          // button debounce (ms)
#define NO_OF_BUTTONS 8

// ADC
#define AUX_VREF 2.56
#define ADC_CHANNELS 1024

/* Define debugging level */

#define DEBUG_LEVEL 5
#define POST_INTERVAL 5000

/* Serial port */

#define SERIAL_BAUD_RATE 57600                      // 57600 max with internal 8 MHz oscillator

/* Keyboard layout */

#define KB_LAYOUT_US

/***********************************************************************************************************************/
/*                                                  pin definitions                                                    */
/***********************************************************************************************************************/

/* Arduino digital */
const int button1_pin = 12;
const int button2_pin = 6;
const int button3_pin = 8;
const int button4_pin = 0;   // NOT CONNECTED IN PCB REV 1.00
const int button5_pin = 9;
const int button6_pin = 10;
const int button7_pin = 11;
const int button8_pin = 13;

const int interrupt7_pin = 7;

//const int rx_led_pin = ??; // ARE THESE HW FUNCTIONS?
//const int tx_led_pin = 4;

/* Arduino analog */
const int analog0 = 14;
const int analog1 = 15;
//const int analog2 = 16;     // NOT IN USE
//const int analog3 = 17;     // NOT IN USE
const int analog4 = 18;
const int analog5 = 19;
//const int analog6 = 20;     // WHICH PIN?
//const int analog7 = 21;     // WHICH PIN?

/***********************************************************************************************************************/
/*                                                   VARIABLES                                                         */
/***********************************************************************************************************************/

/* Other variables */

// pin, pullup, inverted
Button onb_button[NO_OF_BUTTONS];

// Debugging
unsigned long _last_post_time = 0;
byte cycle_count = 0;

// Keyboard chars



//bool b1pressed = false;
//bool b2pressed = false;
//bool b3pressed = false;
//bool b4pressed = false;
//bool b5pressed = false;
//bool b6pressed = false;
//bool b7pressed = false;
//bool b8pressed = false;

bool b_pressed[NO_OF_BUTTONS];
char b_char[NO_OF_BUTTONS];



/***********************************************************************************************************************/
/*                                                   FUNCTIONS                                                         */
/***********************************************************************************************************************/

/* Analog in */
float read_voltage();

/***********************************************************************************************************************/
/*                                                   SETUP LOOP                                                        */
/***********************************************************************************************************************/

void setup() {

/* Keyboard layout */

#ifdef KB_LAYOUT_US
  b_char[0] = ')';
  b_char[1] = '(';
  b_char[2] = '}';
  b_char[3] = '{';
  b_char[4] = ']';
  b_char[5] = '[';
  b_char[6] = '"';
  b_char[7] = '\'';
#endif

#ifdef KB_LAYOUT_FI
  b_char[0] = '(';
  b_char[1] = '*';
  b_char[2] = '’';
  b_char[3] = '½';
  b_char[4] = '‘';
  b_char[5] = '¾';
  b_char[6] = '\\';
  b_char[7] = '@';
#endif

  // ADC
  analogReference(INTERNAL);

  /* Pin settings on Arduino */

  // pins
  pinMode(interrupt7_pin, INPUT_PULLUP);

  //pinMode(rx_led_pin, OUTPUT);
  //digitalWrite(rx_led_pin, LOW);

  //pinMode(tx_led_pin, OUTPUT);
  //digitalWrite(tx_led_pin, LOW);

  onb_button[0].setPin(button1_pin);
  onb_button[1].setPin(button2_pin);
  onb_button[2].setPin(button3_pin);
  onb_button[3].setPin(button4_pin);
  onb_button[4].setPin(button5_pin);
  onb_button[5].setPin(button6_pin);
  onb_button[6].setPin(button7_pin);
  onb_button[7].setPin(button8_pin);
  

  for (int i = 0; i < NO_OF_BUTTONS; i++){
    b_pressed[i] = false;
  }

  for (int i = 0; i < NO_OF_BUTTONS; i++){
    onb_button[i].setPullup(HIGH);
    onb_button[i].setInverted(HIGH);
  }

  // Keyboard
  Keyboard.begin();

  /* Serial communications setup */
  
  Serial.begin(SERIAL_BAUD_RATE);
  while(!Serial){
    ;                                               // Needed for Atmega32U4
  }  

#if DEBUG_LEVEL > 1
  Serial.println(F("Serial port opened"));
  Serial.print(F("Serial baud rate: "));
  Serial.print(SERIAL_BAUD_RATE);
  Serial.println(F(" bit/s"));
#endif

  /* Setup complete */

#if DEBUG_LEVEL > 1
  Serial.println(F("Setup complete"));
#endif
  
}

/***********************************************************************************************************************/
/*                                                   MAIN LOOP                                                         */
/***********************************************************************************************************************/

void loop() {

  for (int i = 0; i < 8; i++){
    if (onb_button[i].pressed()) {
      delay(BUTTON_DEBOUNCE);
      if(onb_button[i].state()) {
#if DEBUG_LEVEL > 3
        Serial.print(F("pressed key: "));
        Serial.println(i+1);
#endif
        Keyboard.press(b_char[i]);
        b_pressed[i] = true;
      }

    } else if (b_pressed[i] && onb_button[i].isReleased()) {
      b_pressed[i] = false;
#if DEBUG_LEVEL > 3
      Serial.print(F("released key: "));
      Serial.println(i+1);
#endif
      Keyboard.releaseAll();
    }
  }

// Debugging
#if DEBUG_LEVEL > 6
    if((_last_post_time + POST_INTERVAL) < millis())
    {
      // Debug info
      Serial.println(F("debugging info:"));
      Serial.print(F("Cycle: "));
      Serial.println(cycle_count);

      _last_post_time = millis();
      cycle_count++;
      Serial.println("------");
  }
#endif
} // void loop()

/* Analog in */
float read_voltage() {
  float _result = 0;
  _result = AUX_VREF * analogRead(A1) / ADC_CHANNELS;
  return _result;
}
