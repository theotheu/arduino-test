/*

  Let op dat je voor het testen Seriele monitor aan moet zetten


  Je kunt tests uitzetten door de regel te laten beginnen met // 




*/

// Buttons -- Input
#define buttonLeft 2
#define buttonMiddle 7
#define buttonRight 8

// Sliders -- Input
#define sliderLeft 1
#define sliderRight 0

// initial status values
int buttonLeftStatus = -1;
int buttonMiddleStatus = -1;
int buttonRightStatus = -1;
int sliderLeftValue = -1;
int sliderRightValue = -1;

void setup() {
  // -- Input 
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
  
  // Get statuses of buttons
  // Skip tests by adding // at the beginning of a line
  buttonLeftStatus = testButton(buttonLeft);
  buttonMiddleStatus = testButton(buttonMiddle);
  buttonRightStatus = testButton(buttonRight);
  
  // Get values of sliders
  sliderLeftValue = testSlider(sliderLeft);
  sliderRightValue = testSlider(sliderRight); 
  
  // END TESTS
  
  // Display output of tests
  Serial.print("Button left = ");
  Serial.print(buttonLeftStatus);
  Serial.print("; Button middle = ");
  Serial.print(buttonMiddleStatus);
  Serial.print("; Button right = ");
  Serial.print(buttonRightStatus);
  Serial.print("; Slider left = ");
  Serial.print(sliderLeftValue);
  Serial.print("; Slider right = ");
  Serial.print(sliderRightValue);
 
  Serial.println("");
  
}


// Function to test the input status of the buttons
int testButton(int buttonPin) {
   int status = digitalRead(buttonPin);
   return status;
}

// Function to test the input status of the buttons
int testSlider(int sliderPin) {
   int val = analogRead(sliderPin);
   return val;
}


