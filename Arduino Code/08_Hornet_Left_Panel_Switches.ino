#include <Joystick.h>
// #include <Rotary.h>

int i, j, k;
int NB = 1023;
int analogStep = 3;
int analogMin = 0;
int analogMax = 1023;

// Control will have:
// 5x5 button matrix (25 available inputs)
// 4x Rotary encoders (8 inputs)
Joystick_ JS1(
  0x03, // Address. Cannot use 0x01 or 0x02
  JOYSTICK_TYPE_JOYSTICK,
  64, // Button count
  0, // Number of hat switches
  true, // include x axis
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
int outputButton[numWrites][numReads] = {
  {48, 55, 53, 52, 50, 37, NB, NB},
  {45, 47, 44, 42, 41, 39, NB, NB},
  {35, 36, 33, 31, 28, 30, NB, NB},
  {27, 25, 14,  9, 11, 22, 26, 31},
  { 1,  8,  6,  5,  2,  3, NB, NB},
  {19, 18, 17, 16, 15, 20, NB, NB}
}; // This specifies the joystick button be output from each matix position.

int outputButtonLift[numWrites][numReads] = {
  {49, NB, 54, 51, NB, 38, NB, NB},
  {46, 46, 43, 43, 40, 40, NB, NB},
  {NB, NB, 34, 32, 29, 29, NB, NB},
  {NB, NB, 13, 10, 12, 21, NB, NB},
  { 0,  7,  7,  4, NB, NB, NB, NB},
  {NB, NB, NB, NB, NB, NB, NB, NB}
}; // This specifies the joystick button be output from each matix position.



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

int newXValue = 0;
int oldXValue = 0;
// int newYValue = 0;
// int oldYValue = 0;

// Set up stuff for the parking brake
int parkBrkPin = A3;
int parkBrkReading;
int parkBrkThresh[4] = {1024*.92, 1024*0.88, 1024*.64, 1024*0.60};
int parkBrkLeft = 23, parkBrkRight = 24;
int oldParkBrkValue = LOW, newParkBrkValue = LOW;

// Set up rotary encoders
/*
  const int numEnc = 4;
  Rotary R[numEnc] = {Rotary(0,1), Rotary(2,3), Rotary(4,5), Rotary(6,7)};  // Using the rotary library, set up pins for each
  int encDelay[numEnc] = {100, 10, 100, 100};  //How long to turn the encoder on with each press in milliseconds.  Can set unique values for each encoder.
  int encButtons[4][2] = {{1, 2}, {4, 5}, {7, 8}, {10, 11}};  // Joystick button to be sent by CW/CCW turns of each encoder
  unsigned char encResult;
*/

// Set up the input pins for the axes
// int xAxisPin = A3;
// int yAxisPin = A3;

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

  // Need special code to check for the off value in three position toggles.
  // First the ATT/AOA switch on the HUD panel
  // NEED TO UPDATE THIS FOR 3-WAY TOGGLES
  /*
  if(oldButtonValue[0][0] == HIGH || oldButtonValue[0][1] == HIGH)
    JS1.setButton(outputButtonLift[0][0], LOW);
  // Then the DISPENSER switch
  if(oldButtonValue[5][6] == HIGH || oldButtonValue[5][7] == HIGH)
    JS1.setButton(outputButtonLift[5][6], LOW);
  */

  // Set the initial position of the parking brake
  if(analogRead(parkBrkPin) > parkBrkThresh[0])
  {
    oldParkBrkValue = HIGH;
    JS1.setButton(parkBrkLeft, LOW);
    JS1.setButton(parkBrkRight, HIGH);
  }
  else
  {
    oldParkBrkValue = LOW;
    JS1.setButton(parkBrkRight, LOW);
    JS1.setButton(parkBrkLeft, HIGH);
  }

  
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
  // Code for the parking brake
  // To avoid jitter, only change outputs when the change is > analogMin
  // If within analogMin of the min or max, force the output to the min/max
  parkBrkReading = analogRead(parkBrkPin);
  if(parkBrkReading > parkBrkThresh[0])
    newParkBrkValue = 0;
  else if(parkBrkReading <= parkBrkThresh[1] && parkBrkReading > parkBrkThresh[2])
    newParkBrkValue = 1;
  else if(parkBrkReading < parkBrkThresh[3])
    newParkBrkValue = 2;
  if(newParkBrkValue != oldParkBrkValue)
  {
    if(newParkBrkValue == 0)
    {
      JS1.setButton(parkBrkRight, HIGH);
      delay(5);
      JS1.setButton(parkBrkRight, LOW);
    }
    else if(newParkBrkValue == 1 && oldParkBrkValue == 0)
    {
      JS1.setButton(parkBrkLeft, HIGH);
      delay(5);
      JS1.setButton(parkBrkLeft, LOW);
    }
    else if(newParkBrkValue == 2)
    {
      JS1.setButton(parkBrkLeft, HIGH);
    }
    else if(newParkBrkValue == 1 && oldParkBrkValue == 2)
    {
      JS1.setButton(parkBrkLeft, LOW);
    }
    oldParkBrkValue = newParkBrkValue;
  }

}
