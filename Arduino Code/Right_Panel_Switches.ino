#include <Joystick.h>
// #include <Rotary.h>

int i, j, k;
int NB = 1023;
int analogStep = 3;
int analogMin = 0;
int analogMax = 1023;

// Control will have:
// 6x8 button matrix (48 x 2 = 96 inputs)
// No Rotary encoders
Joystick_ JS1(
  0x03, // Address. Cannot use 0x01 or 0x02
  JOYSTICK_TYPE_JOYSTICK,
  64, // Button count
  0, // Number of hat switches
  false, // include x axis
  false, // include y axis
  false, // include z axis
  false, // include Rx axis
  false, // include Ry axis
  false, // include Rz axis
  false, // include Rudder axis
  false, // include throttle axis
  false, // include accelerator axis
  false, // include brake axis
  false // include steering axis
);

// Set up the parameters of the button matrix
const int numReads = 8; // These are the "signal" side of the switches with diodes
const int numWrites = 6; // These are the "common" side of the switches
int readPins[numReads] = {2, 3, 4, 5, 6, 7, 8, 9};  // These are the pins that will be set as inputs and be read in each cycle ("Columns")
int writePins[numWrites] = {10, 16, 14, 15, A0, A1}; // These are the pins that will be turned on/off ("Rows")

// This specifies the joystick button to be activated when each point in
// the matrix is turned on (closed switch).
int outputButton[numWrites][numReads] = {
  {49, 50, 51, 44, 45, 46, 47, 48},
  {39, 40, 41, 42, 43, 28, 34, 32},
  {37, 55, 35, NB, 29, 54, 27, 31},
  {22, 24, 26, 16, 18,  9, 11, 13},
  {52, 53, 21, 19, 14, NB, NB, NB},
  { 5,  6, NB, NB,  1, 56,  7, NB}
};

// This specifies the joystick button to be activated when each point in
// the matrix is turned off (open switch).
int outputButtonLift[numWrites][numReads] = {
  {NB, NB, NB, NB, NB, NB, NB, NB},
  {NB, NB, NB, NB, NB, NB, 33, 33},
  {38, NB, 36, NB, 30, NB, NB, 30},
  {23, 25, 25, 17, 17, 10, 12, 12},
  {NB, NB, 20, 20, 15, NB, NB, NB},
  {NB, NB, NB, NB,  0, NB,  8, NB}
};

int newButtonValue[numWrites][numReads] =
{
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};
int oldButtonValue[numWrites][numReads] =
{
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

// The minimum time it has to be before the code will capture a change in a switch
// This gets reset to millis() + debounceDelay after each change in state.
long debounceTime[numWrites][numReads] = 
{
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

// How much time the code will delay between captures at each point in the matrix
int debounceDelay[numWrites][numReads] = 
{
  {50, 50, 50, 50, 50, 50, 50, 50},
  {50, 50, 50, 50, 50, 50, 50, 50},
  {50, 50, 50, 50, 50, 50, 50, 50},
  {50, 50, 50, 50, 50, 50, 50, 50},
  {50, 50, 50, 50, 50, 50, 50, 50},
  {50, 50, 50, 50, 50, 50, 50, 50}
};

// Set up stuff for the wing fold
int wingFoldPin = A3;
int wingFoldReading;
int wingFoldThresh[3][2] = {{700, 780}, {880, 940}, {1000, 1023}};
int wingFoldButtonSet[3] = {2, 3, 4};
int oldWingFoldValue = LOW, newWingFoldValue = LOW;


// Set up rotary encoders
/*
  const int numEnc = 4;
  Rotary R[numEnc] = {Rotary(0,1), Rotary(2,3), Rotary(4,5), Rotary(6,7)};  // Using the rotary library, set up pins for each
  int encDelay[numEnc] = {100, 10, 100, 100};  //How long to turn the encoder on with each press in milliseconds.  Can set unique values for each encoder.
  int encButtons[4][2] = {{1, 2}, {4, 5}, {7, 8}, {10, 11}};  // Joystick button to be sent by CW/CCW turns of each encoder
  unsigned char encResult;
*/

void setup() {
  JS1.begin();

  // Set up the input (INPUT_PULLUP) and output pins
  for (i = 0; i < numWrites; i++)
  {
    pinMode(writePins[i], OUTPUT);
    digitalWrite(writePins[i], HIGH);
  }
  for (i = 0; i < numReads; i++)
  {
    pinMode(readPins[i], INPUT_PULLUP);
  }

  // Set up the analog inputs
  // pinMode(xAxisPin, INPUT);
  // pinMode(yAxisPin, INPUT);

  delay(2500);
  // Set all the "old button" values WRONG so it has to set all the values the first time it runs the loop
  for (i = 0; i < numWrites; i++)
  {
    digitalWrite(writePins[i], LOW);
    for (j = 0; j < numReads; j++)
    {
      oldButtonValue[i][j] = digitalRead(readPins[j]);
    }
    digitalWrite(writePins[i], HIGH);
  }

  // Now run through the loop once to set the correct values and send initial button presses
  for (i = 0; i < numWrites; i++)
  {
    digitalWrite(writePins[i], LOW);
    for (j = 0; j < numReads; j++)
    {
      // Get the current value of the button, compare with previous value, and send if different
      // This is faster than sending the button value every cycle
      // Also, if a switch has been turned OFF, check to see if it has a "lift" button and activate that button
      newButtonValue[i][j] = !digitalRead(readPins[j]);
      if (newButtonValue[i][j] != oldButtonValue[i][j])
      {
        if (outputButtonLift[i][j] != NB)
        {
          if (newButtonValue[i][j] == LOW)
          {
            JS1.setButton(outputButton[i][j], LOW);
            JS1.setButton(outputButtonLift[i][j], HIGH);
          }
          else
          {
            JS1.setButton(outputButtonLift[i][j], LOW);
            JS1.setButton(outputButton[i][j], HIGH);
          }
        }
        else
          JS1.setButton(outputButton[i][j], newButtonValue[i][j]);
      }
      oldButtonValue[i][j] = newButtonValue[i][j];
    }
    digitalWrite(writePins[i], HIGH);
  }

  // Set the initial position and button value of the wing fold handle
  wingFoldReading = analogRead(wingFoldPin);
  for(i = 0; i < 3; i++)
  {
    if(wingFoldReading > wingFoldThresh[i][0] && wingFoldReading < wingFoldThresh[i][1])
      newWingFoldValue = wingFoldButtonSet[i];
  }
  if(newWingFoldValue != oldWingFoldValue)
  {
    JS1.setButton(oldWingFoldValue, LOW);
    JS1.setButton(newWingFoldValue, HIGH);
    oldWingFoldValue = newWingFoldValue;
  }

  // Need special code to check for the off value in three position toggles.
  // First the ATT/AOA switch on the HUD panel
  // THIS HAS TO BE REWRITTEN
  /*
  if(oldButtonValue[0][0] == HIGH || oldButtonValue[0][1] == HIGH)
    JS1.setButton(outputButtonLift[0][0], LOW);
  // Then the DISPENSER switch
  if(oldButtonValue[5][6] == HIGH || oldButtonValue[5][7] == HIGH)
    JS1.setButton(outputButtonLift[5][6], LOW);
  */
}

void loop() {
  // Run through the button matrix
  // Loop through the outputs checking each input as we go
  for (i = 0; i < numWrites; i++)
  {
    digitalWrite(writePins[i], LOW);
    for (j = 0; j < numReads; j++)
    {
      // Get the current value of the button, compare with previous value, and send if different
      // This is faster than sending the button value every cycle
      // Also, if a switch has been turned OFF, check to see if it has a "lift" button and activate that button
      newButtonValue[i][j] = !digitalRead(readPins[j]);
      if (newButtonValue[i][j] != oldButtonValue[i][j] && millis() > debounceTime[i][j])
      {
        debounceTime[i][j] = millis() + debounceDelay[i][j];
    		if (outputButtonLift[i][j] != NB)
          {
            if (newButtonValue[i][j] == LOW)
            {
              JS1.setButton(outputButton[i][j], LOW);
              JS1.setButton(outputButtonLift[i][j], HIGH);
            }
            else
            {
              JS1.setButton(outputButtonLift[i][j], LOW);
              JS1.setButton(outputButton[i][j], HIGH);
            }
          }
          else
            JS1.setButton(outputButton[i][j], newButtonValue[i][j]);
          // delay(debounceDelay);
      }
      oldButtonValue[i][j] = newButtonValue[i][j];

      // Since encoders are sensitive to timing, check them with every cycle
      /*
        for(k = 0; k < numEnc; k++)
        {
        encResult = R[k].process();
        if (encResult == DIR_CCW)
        {
          JS1.pressButton(encButtons[k][0]);
          delay(encDelay[k]);
          JS1.releaseButton(encButtons[k][0]);
        }
        else if (encResult == DIR_CW)
        {
          JS1.pressButton(encButtons[k][1]);
          delay(encDelay[k]);
          JS1.releaseButton(encButtons[k][1]);
        }
        }
      */
    }
    digitalWrite(writePins[i], HIGH);
  }

  // Check the position fo the wing fold handle and update if needed
  wingFoldReading = analogRead(wingFoldPin);
  for(i = 0; i < 3; i++)
  {
    if(wingFoldReading >= wingFoldThresh[i][0] && wingFoldReading <= wingFoldThresh[i][1])
      newWingFoldValue = wingFoldButtonSet[i];
  }
  if(newWingFoldValue != oldWingFoldValue)
  {
    JS1.setButton(oldWingFoldValue, LOW);
    JS1.setButton(newWingFoldValue, HIGH);
    oldWingFoldValue = newWingFoldValue;
  }
  
  // Code for analog controls
  // To avoid jitter, only change outputs when the change is > analogMin
  // If within analogMin of the min or max, force the output to the min/max
  /*
  newXValue = analogRead(xAxisPin);
  if(newXValue >= analogMax - analogStep)
  {
    JS1.setXAxis(analogMax);
    oldXValue = newXValue;
  }
  else if(newXValue <= analogMin + analogStep)
  {
    JS1.setXAxis(analogMin);
    oldXValue = newXValue;
  }
  else if(abs(newXValue - oldXValue) >= analogStep)
  {
    JS1.setXAxis(newXValue);
    oldXValue = newXValue;
  }

  newYValue = analogRead(yAxisPin);
  if(newYValue >= analogMax - analogStep)
  {
    JS1.setYAxis(analogMax);
    oldYValue = newYValue;
  }
  else if(newYValue <= analogMin + analogStep)
  {
    JS1.setYAxis(analogMin);
    oldYValue = newYValue;
  }
  else if(abs(newYValue - oldYValue) >= analogStep)
  {
    JS1.setYAxis(newYValue);
    oldYValue = newYValue;
  }
  */

}
