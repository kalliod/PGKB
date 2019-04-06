#include <Wire.h>
#include "Adafruit_MCP23017.h"
#include "KD_ardu_button.h"
#include <Keyboard.h>

// FIN:
// * = (
// ( = )

/* Hardware configuration */

// HW
#define BUTTON_DEBOUNCE 20                          // button debounce (ms)

// ADC
#define AUX_VREF 2.56
#define ADC_CHANNELS 1024

/* Define debugging level */

#define DEBUG_LEVEL 5
#define POST_INTERVAL 5000

/* Serial port */

#define SERIAL_BAUD_RATE 57600                      // 57600 max with internal 8 MHz oscillator

/***********************************************************************************************************************/
/*                                                  pin definitions                                                    */
/***********************************************************************************************************************/

/* Arduino digital */
const int buttonA0_pin = 6;
const int buttonA1_pin = 12;
//const int buttonB0_pin = 1;   // NOT CONNECTED IN PCB REV 1.00
const int buttonB1_pin = 8;
const int buttonC0_pin = 10;
const int buttonC1_pin = 9;
const int buttonD0_pin = 11;
const int buttonD1_pin = 13;

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
Button buttonA0(buttonA0_pin, HIGH, HIGH);
Button buttonA1(buttonA1_pin, HIGH, HIGH);
//Button buttonB0(buttonB0_pin, HIGH, HIGH);
Button buttonB1(buttonB1_pin, HIGH, HIGH);
Button buttonC0(buttonC0_pin, HIGH, HIGH);
Button buttonC1(buttonC1_pin, HIGH, HIGH);
Button buttonD0(buttonD0_pin, HIGH, HIGH);
Button buttonD1(buttonD1_pin, HIGH, HIGH);

// Debugging
unsigned long _last_post_time = 0;
byte cycle_count = 0;

/***********************************************************************************************************************/
/*                                                   FUNCTIONS                                                         */
/***********************************************************************************************************************/

/* Analog in */
float read_voltage();

/***********************************************************************************************************************/
/*                                                   SETUP LOOP                                                        */
/***********************************************************************************************************************/

void setup() {

  // ADC
  analogReference(INTERNAL);

  /* Pin settings on Arduino */

  // pins
  pinMode(interrupt7_pin, INPUT_PULLUP);

  //pinMode(rx_led_pin, OUTPUT);
  //digitalWrite(rx_led_pin, LOW);

  //pinMode(tx_led_pin, OUTPUT);
  //digitalWrite(tx_led_pin, LOW);

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


// Debugging
#if DEBUG_LEVEL > 4
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
