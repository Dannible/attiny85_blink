/*
 *  Created: December 5, 2015
 *  By: Dan Ward <dpw989@gmail.com>
 *
 * Using an ATtiny85, toggle 4 LEDs in a pattern.   
 */

//Number of LEDs
int NumLeds = 4;

//Pins used
int LedPins[] =
{
  0, 1, 3, 4
};

//Current Mills 
unsigned long currentTime = 0;

//Record time through loop. 
unsigned long LastLedTime[] =
{
  0, 0, 0, 0
};

//Led States
int LedState[] =
{
  LOW, LOW, LOW, LOW
};

//Flash Pattern
long Pattern[] =
{
  20, 25, 35, 30
};

/*
* Setup Pins
*/
void setup() {
  pinMode(LedPins[0], OUTPUT);
  pinMode(LedPins[1], OUTPUT);
  pinMode(LedPins[2], OUTPUT);
  pinMode(LedPins[3], OUTPUT);
}

/*
* Main Loop
*/
void loop() {
  currentTime = millis(); // Get Current Time.
  for (int i = 0; i < NumLeds; i++) // Loop each LED
  {
    if (currentTime - LastLedTime[i] >= Pattern[i]) // If enough time has passed toggle LED.
    {
      LastLedTime[i] = millis(); // Record Current time. 
      ToggleLed(i);// Toggle LED.
    }
  }
}

/*
* Toggle Specific LED
*/
void ToggleLed(int led)
{
  if (LedState[led] == LOW)
    LedState[led] = HIGH;
  else
    LedState[led] = LOW;

  digitalWrite(LedPins[led], LedState[led]);
}
