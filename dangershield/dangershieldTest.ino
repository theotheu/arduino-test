#include "_init.h"

void setup() {
 ds_init(); 
 Serial.begin(9600);
}


int led1_freq = 1;
int led1_count = 0;
int led1_state = 0;
int led2_freq = 2;
int led2_count = 0;
int led2_state = 0;

int display_counter = 9;

void loop() {
   Serial.print( digitalRead( BUTTON1_PIN ));   Serial.print( "-" );
   Serial.print( digitalRead( BUTTON2_PIN ));   Serial.print( "-" );
   Serial.print( digitalRead( BUTTON3_PIN )); 
   Serial.print(" :: ");
   Serial.print( analogRead( SLIDER1_PIN ));   Serial.print( "-" );
   Serial.print( analogRead( SLIDER2_PIN ));   Serial.print( "-" );
   Serial.print( analogRead( SLIDER3_PIN )); 
   Serial.println();
   
   led1_count --;
   if(led1_count <= 0) {
     led1_count = led1_freq;
     led1_state = 1-led1_state;
     digitalWrite(LED1_PIN, led1_state);
   }
   led2_count --;
   if(led2_count <= 0) {
     led2_count = led2_freq;
     led2_state = 1-led2_state;
     digitalWrite(LED2_PIN, led2_state);
   }
   
   showDigitOn7SegmentDisplay(display_counter);
   display_counter--;
   if(display_counter<0) display_counter = 9;
   delay(200);
}
