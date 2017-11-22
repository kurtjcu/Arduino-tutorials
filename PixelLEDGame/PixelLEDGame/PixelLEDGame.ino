#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 5

#define DATA_PIN 3                // The pin we send the LED colour information to.
#define CLOCK_PIN 13              // Clock signal for timing of the Data Packets

#define BUTTON_PIN 2              // The pin we connect the button to (connect other input of button to ground.)

#define TIMEOUT_IN_MILLISECONDS 10000 // how long do we wait for our player to press the button in milliseconds



// Define the array of leds
CRGB leds[NUM_LEDS];


// this section does all the initial setup of our program
void setup() { 
  // setup the pin for a button connection
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // setup the LED's
  FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, BGR>(leds, NUM_LEDS);

  // setup the serial monitor
  Serial.begin(9600);      // open the serial port at 9600 bps:  
}


// this is our main program
void loop() { 

  int buttonPressed = !digitalRead(BUTTON_PIN);

  if(buttonPressed){

      // Let the player know a game is about to start
      getReadyFlash();

      //wait for a random amount of time between .5 and 5 seconds
      delay(random(500, 5000));

      // check to see if the person is alreay pressing the button
      buttonPressed = !digitalRead(BUTTON_PIN);
      if(buttonPressed){
        Serial.println("You pressed the button to early !!!");
        warningFlash();
        delay(1000);
        return;         // end the game
      }

      //get current millis and store to use as my 'zero' time
      unsigned long startMillis = millis();
      
      // Do a pattern to start the game
      startTimerFlash();

      // Here is where we wait for our player to press the button
      int i = 0;
      while(i <= TIMEOUT_IN_MILLISECONDS && !buttonPressed){
        buttonPressed = !digitalRead(BUTTON_PIN);
        delay(1);
        i++;
      }

      unsigned long finishMillis = millis();

      //check i to see if timed out
      if(TIMEOUT_IN_MILLISECONDS < finishMillis - startMillis){
        Serial.println("Oops you took too long to press the button");
        warningFlash();

      } else { //if not timed out then rainbow swirl and print time to monitor

        Serial.print("You took ");
        Serial.print( finishMillis - startMillis);
        Serial.println(" milliseconds to press the button"); 
      }
      
      delay(1000);  //wait for a little while so that we have time to un-press the button

  }
}

//
void getReadyFlash(){
  int flashPeriodInMilliseconds = 300;  // this is how long a LED is on or off for
  
  // Turn the Red LED on, then pause
  leds[1] = CRGB::Red;              // set the colour to red
  FastLED.show();                   // send our colour information to the LED Strip
  delay(flashPeriodInMilliseconds); // Wait for flashPeriodInMilliseconds milliseconds 
  // Now turn the LED off, then pause
  leds[1] = CRGB::Black;            // Turn Off the LED
  FastLED.show();
  delay(flashPeriodInMilliseconds);// Wait for flashPeriodInMilliseconds milliseconds
  
  // Turn the Green LED on, then pause
  leds[1] = CRGB::Green;            // set the colour to Green
  FastLED.show();                   // send our colour information to the LED Strip
  delay(flashPeriodInMilliseconds); // Wait for flashPeriodInMilliseconds milliseconds
  // Now turn the LED off, then pause
  leds[1] = CRGB::Black;            // Turn Off the LED
  FastLED.show();
  delay(flashPeriodInMilliseconds);// Wait for flashPeriodInMilliseconds milliseconds
  
  // Turn the Blue LED on, then pause
  leds[1] = CRGB::Blue;             // set the colour to Blue
  FastLED.show();                   // send our colour information to the LED Strip
  delay(flashPeriodInMilliseconds);// Wait for flashPeriodInMilliseconds milliseconds
  // Now turn the LED off, then pause
  leds[1] = CRGB::Black;            // Turn Off the LED
  FastLED.show();
  delay(flashPeriodInMilliseconds);// Wait for flashPeriodInMilliseconds milliseconds
}

// This function is called when we want to flash the LED's at the start of the timer
void startTimerFlash(){
  
  for(int k = 0; k < NUM_LEDS; k++){
    leds[k] = CRGB::Green;              // set the colour to green
  }
  FastLED.show();                   // send our colour information to the LED Strip
  delay(100);                       // Wait for 100 milliseconds (0.1 second) so the green is seen

  for(int k = 0; k < NUM_LEDS; k++){
    leds[k] = CRGB::Black;              // Turn led off
  }
  FastLED.show();                   // send our colour information to the LED Strip
}

// this function is called when we want to show a warning by flashing all the LED's
void warningFlash(){
  
  for (int j = 0; j < 3; j++){
    
    for(int k = 0; k < NUM_LEDS; k++){
      leds[k] = CRGB::Red;              // set the colour to red
      FastLED.show();                   // send our colour information to the LED Strip
      delay(300);                       // Wait for 1000 milliseconds (1 second)
    }
  
    for(int k = 0; k < NUM_LEDS; k++){
      leds[k] = CRGB::Black;              // Turn led off
      FastLED.show();                   // send our colour information to the LED Strip
      delay(300);                       // Wait for 1000 milliseconds (1 second)
    }
  }
}

