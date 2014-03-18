#include "Arduino.h"

#define RGB1_RED 9
#define RGB1_GREEN 10
#define RGB1_BLUE 11

#define RGB2_RED 3
#define RGB2_GREEN 5
#define RGB2_BLUE 6

#define BUTTON1_PIN 8
#define BUTTON2_PIN 7
#define BUTTON3_PIN 2

// dit zijn eigenlijk de twee potmeters
#define SLIDER1_PIN 1
#define SLIDER2_PIN 0

#define BUZZER_PIN 4


void bb_init(){
  Serial.begin(9600);
  pinMode(RGB1_RED, OUTPUT);
  pinMode(RGB1_GREEN, OUTPUT);
  pinMode(RGB1_BLUE, OUTPUT);
  pinMode(RGB2_RED, OUTPUT);
  pinMode(RGB2_GREEN, OUTPUT);
  pinMode(RGB2_BLUE, OUTPUT);
  pinMode(BUTTON1_PIN, INPUT);
  pinMode(BUTTON2_PIN, INPUT);
  pinMode(BUTTON3_PIN, INPUT);
  pinMode(SLIDER1_PIN, INPUT);
  pinMode(SLIDER2_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  
  analogWrite(RGB1_RED, 255);
  analogWrite(RGB1_GREEN, 255);
  analogWrite(RGB1_BLUE, 255);
  
  analogWrite(RGB2_RED, 255);
  analogWrite(RGB2_GREEN, 255);
  analogWrite(RGB2_BLUE, 255);
  
  for (int i=0; i<500; i++)
  {
     digitalWrite(BUZZER_PIN, HIGH);
     delayMicroseconds(1915);
     digitalWrite(BUZZER_PIN, LOW);
  }

  analogWrite(RGB1_RED, 0);
  analogWrite(RGB1_GREEN, 0);
  analogWrite(RGB1_BLUE, 0);
  
  analogWrite(RGB2_RED, 0);
  analogWrite(RGB2_GREEN, 0);
  analogWrite(RGB2_BLUE, 0);

}









