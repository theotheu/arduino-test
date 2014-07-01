/*************************************************************************************************
* This file contains code and definitions to make your life using the Danger Shield really easy.
**************************************************************************************************/
#include "Arduino.h"

//these are our digital input pins
#define BUTTON1_PIN 10
#define BUTTON2_PIN 11
#define BUTTON3_PIN 12

//these are our analog input pins
#define SLIDER1_PIN 0
#define SLIDER2_PIN 1
#define SLIDER3_PIN 2
#define LIGHT_SENSOR_PIN 3
#define TEMP_SENSOR_PIN 4

//these are our output pins
#define LED1_PIN 6
#define LED2_PIN 5
#define BUZZER_PIN 3

//these are for the shift register
#define LATCH_PIN 7
#define CLOCK_PIN 8
#define DATA_PIN 4

//our init and bootup function
void ds_init()
{
  //buttons are inputs.
  pinMode(BUTTON1_PIN, INPUT);
  pinMode(BUTTON2_PIN, INPUT);
  pinMode(BUTTON3_PIN, INPUT);

  //leds and buzzers are outputs.
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  //shift register pins are output.
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);

  //flash our LEDs
  digitalWrite(LED1_PIN, HIGH);
  digitalWrite(LED2_PIN, HIGH);

  //turn 7-segment on
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, B00000000);
  digitalWrite(LATCH_PIN, HIGH);

  //buzz for a bit.
  for (int i=0; i<500; i++)
  {
  digitalWrite(BUZZER_PIN, HIGH);
  delayMicroseconds(1915);
  digitalWrite(BUZZER_PIN, LOW);
  }

  //turn off LEDs
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);

  //turn 7-segment off
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, B11111111);
  digitalWrite(LATCH_PIN, HIGH);

}
/* CHANGED 24-10-2012 by Robert Holwerda
/* call 'turn7SegmentLedsOnOrOff(...)' with a bitPattern of 8 bits
   as a parameter. Such patterns look like this:
     B00000000
     B11111111
     B10010110
   Always use EIGHT 1's or 0's.
   Notice the use of bitpatterns in the array 'ledCharSet' above. That
   array contains the bitpatterns to display the numbers 0,1,2,3,4,5,6,
   7,8 and 9.
   To show an interesting pattern on the 7-segment display, you could
   call for example:
     turn7SegmentLedsOnOrOff( B10101010 );  //weird pattern
     turn7SegmentLedsOnOrOff( B00000000 );  //all 0's: all leds are on
     turn7SegmentLedsOnOrOff( B11111111 );  //all 1's: all leds are off
   You'll have to use your own experiments to find out exactly which bit
   turns which segment in the display on or off.
*/
void turn7SegmentLedsOnOrOff( byte bitPattern )
{
    digitalWrite(LATCH_PIN, LOW);
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, bitPattern);
    digitalWrite(LATCH_PIN, HIGH);
}

//this is useful to display numbers on the 7-segment LED
const byte digitLEDs[10] = {
  B11000000,B11111001,B10100100,
  B10110000,B10011001,B10010010,
  B10000010,B11111000,B10000000,
  B10010000
};

/* Use 'showDigitOn7SegmentDisplay(...)' to show a number
   between 0 and 9.
   It uses the array 'ledCharSet' above. That array contains the
   bitpatterns to display the numbers 0,1,2,3,4,5,6,7,8 and 9.
*/
void showDigitOn7SegmentDisplay( int digit )
{
  turn7SegmentLedsOnOrOff(  digitLEDs[digit] );
}

/* Use 'clear7SegmentDisplay()' to turn off all
   the leds in the 7 segment display.
*/
void clear7SegmentDisplay()
{
  turn7SegmentLedsOnOrOff(B11111111);
}
