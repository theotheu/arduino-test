/*

  Let op dat je voor het testen Seriele monitor aan moet zetten


  Je kunt tests uitzetten door de regel te laten beginnen met // 

*/
int length = 15; // the number of notes
char notes[] = "ccggaagffeeddc "; // a space represents a rest
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempo = 300;


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

void setup() {
  // -- Output
  // Left Led
  pinMode(ledLeftRed, OUTPUT);
  pinMode(ledLeftGreen, OUTPUT);
  pinMode(ledLeftBlue, OUTPUT);

  // Right Led
  pinMode(ledRightRed, OUTPUT);
  pinMode(ledRightGreen, OUTPUT);
  pinMode(ledRightBlue, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Serial
  Serial.begin(9600);

  // Dim lights
  
}


void loop() {
  // BEGIN TESTS
  buzzerTest(100, 200);

 
  Serial.println("Left red"); 
  testLed(ledLeftRed, ledLeftGreen, ledLeftBlue, 255, 0, 0);
  delay(300);

  Serial.println("Left green"); 
  testLed(ledLeftRed, ledLeftGreen, ledLeftBlue, 0, 255, 0);
  delay(300);
  
  Serial.println("Left blue"); 
  testLed(ledLeftRed, ledLeftGreen, ledLeftBlue, 0, 0, 255);
  delay(300);

  Serial.println("Left yellow"); 
  testLed(ledLeftRed, ledLeftGreen, ledLeftBlue, 255, 255, 0);
  delay(300);
 
  Serial.println("Left magenta"); 
  testLed(ledLeftRed, ledLeftGreen, ledLeftBlue, 255, 0, 255);
  delay(300);
 
  Serial.println("Left cyan"); 
  testLed(ledLeftRed, ledLeftGreen, ledLeftBlue, 0, 255, 255);
  delay(300);
   
  Serial.println("Left white"); 
  testLed(ledLeftRed, ledLeftGreen, ledLeftBlue, 255, 255, 255);
  delay(300);

  Serial.println("Left led off"); 
  testLed(ledLeftRed, ledLeftGreen, ledLeftBlue, 0, 0, 0);
  delay(300);
  
  buzzerTest(300, 1000);

  
  Serial.println("Right red"); 
  testLed(ledRightRed, ledRightGreen, ledRightBlue, 255, 0, 0);
  delay(300);

  Serial.println("Right green"); 
  testLed(ledRightRed, ledRightGreen, ledRightBlue, 0, 255, 0);
  delay(300);
  
  Serial.println("Right blue"); 
  testLed(ledRightRed, ledRightGreen, ledRightBlue, 0, 0, 255);
  delay(300);

  Serial.println("Right yellow"); 
  testLed(ledRightRed, ledRightGreen, ledRightBlue, 255, 255, 0);
  delay(300);
 
  Serial.println("Right magenta"); 
  testLed(ledRightRed, ledRightGreen, ledRightBlue, 255, 0, 255);
  delay(300);
 
  Serial.println("Right cyan"); 
  testLed(ledRightRed, ledRightGreen, ledRightBlue, 0, 255, 255);
  delay(300);
   
  Serial.println("Right white"); 
  testLed(ledRightRed, ledRightGreen, ledRightBlue, 255, 255, 255);
  delay(300);
  
  Serial.println("Right led off"); 
  testLed(ledRightRed, ledRightGreen, ledRightBlue, 0, 0, 0);
  delay(300);

}


// Procedure to test set the colors of a led
void testLed(int pinRed, int pinGreen, int pinBlue, int colorRed, int colorGreen, int colorBlue) {
  analogWrite(pinRed, 255 - colorRed);
  analogWrite(pinGreen, 255 - colorGreen);
  analogWrite(pinBlue, 255 - colorBlue);  
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
