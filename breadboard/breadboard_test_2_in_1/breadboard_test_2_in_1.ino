/*
  Druk op de knoppen om de LED's en de buzzer te testen.
  Draai aan de PODmeters om de LED's te dimmen.
*/

// Buttons -- Input
int buttonLeft = 2;
int buttonMiddle = 7;
int buttonRight = 8;

// Sliders -- Input
int sliderLeft = 1;
int sliderRight = 0;

// Leds -- Output
int ledLeftRed = 3;
int ledLeftGreen = 5;
int ledLeftBlue = 6;

// Leds -- Output
int ledRightRed = 9;
int ledRightGreen = 10;
int ledRightBlue = 11;

// Buzzer -- Output
int buzzerPin = 4;

// Array with the currently used LEDpins (starting with rightLED)
int ledRGBArray[] = {ledRightRed, ledRightGreen, ledRightBlue};


void setup() {
  // Left Led
  pinMode(ledLeftRed, OUTPUT);
  pinMode(ledLeftGreen, OUTPUT);
  pinMode(ledLeftBlue, OUTPUT);

  // Right Led
  pinMode(ledRightRed, OUTPUT);
  pinMode(ledRightGreen, OUTPUT);
  pinMode(ledRightBlue, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Buttons
  pinMode(buttonLeft, INPUT);
  pinMode(buttonMiddle, INPUT);
  pinMode(buttonRight, INPUT);

  // Sliders
  pinMode(sliderLeft, INPUT);
  pinMode(sliderRight, INPUT); 
  
  // Serial
  Serial.begin(9600);

}

void loop() {
  // BEGIN TESTS
      performActionBasedOn(theButtonThatWasTouched());
      mapSliderToLED(sliderLeft);
      mapSliderToLED(sliderRight);
}

// Maps actions to buttons (not pinnumbers!)
void performActionBasedOn(int button){
  switch (button) {
    case 0:
      testLedOn("Left");
      break;
    case 1:
      testLedOn("Right");
      break;
    case 2:
      buzzerTest(300, 1000);
      break;
  }
}

// Returns a number corresponding with the button that was touched.
// 0 = left, 1 = middle, 2 = right, -1 on no touch
int theButtonThatWasTouched(){
    int buttonTouched = -1;
    if(testButton(buttonLeft) == 1){
        Serial.println("Left button Pressed");
        buttonTouched = 0;
    }
    else if(testButton(buttonMiddle) == 1){
        Serial.println("Middle button Pressed");
        buttonTouched = 1;
    }
    else if(testButton(buttonRight) == 1){
        Serial.println("Right button Pressed");
        buttonTouched = 2;
    } 
    return buttonTouched;
}

// Adjusts the brightness of the LED based on the corresponding slider
void mapSliderToLED(int slider){
     changeLedRGBArrayTo("Right");
     if(slider == sliderLeft){
        changeLedRGBArrayTo("Left");
     }
     int sliderValue = map(analogRead(slider), 0, 1022, 0, 255);
     Serial.print("Slider ");
     Serial.print(slider);
     Serial.print(" staat op: ");
     Serial.println(sliderValue);
     testLed(sliderValue, sliderValue, sliderValue);
     

}

// Function that modifies the ledRGBArray to correspond with the correct LEDpins.
// C functions can't return arrays, hence VOID
void changeLedRGBArrayTo(String direction){
  
  if(direction == "Left" || direction == "left"){
    ledRGBArray[0] = ledLeftRed;
    ledRGBArray[1] = ledLeftGreen; 
    ledRGBArray[2] = ledLeftBlue;
  }else{
    ledRGBArray[0] = ledRightRed;
    ledRGBArray[1] = ledRightGreen; 
    ledRGBArray[2] = ledRightBlue;
  }
  
}

// Procedure to test set the colors of a led
void testLed(int colorRed, int colorGreen, int colorBlue) {
  analogWrite(ledRGBArray[0], 255 - colorRed);
  analogWrite(ledRGBArray[1], 255 - colorGreen);
  analogWrite(ledRGBArray[2], 255 - colorBlue);  
}

// Procedure to test the buzzer
// duration in milliseconds
void buzzerTest(int duration, int tone) {
  Serial.println("Buzzer...");
  for(int i = 0; i < duration; i++) {
    digitalWrite(buzzerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(buzzerPin, LOW);
    delayMicroseconds(tone);
  }
}

// Function that returns the status of a button
int testButton(int buttonPin) {
   int status = digitalRead(buttonPin);
   return status;
}


//Procedure that tests all primary colors of the LED of your choice
void testLedOn(String direction){
    changeLedRGBArrayTo(direction);
    Serial.println("red"); 
    testLed(255, 0, 0);
    delay(300);

    Serial.println("green"); 
    testLed(0, 255, 0);
    delay(300);
  
    Serial.println("blue"); 
    testLed(0, 0, 255);
    delay(300);
}








