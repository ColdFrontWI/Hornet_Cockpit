#include <Joystick.h>
#include <Rotary.h>

int i, j, k;

// Control will have:
// 5x5 button matrix (25 available inputs)
// 4x Rotary encoders (8 inputs)
Joystick_ JS1(
   0x03, // Address. Cannot use 0x01 or 0x02
   JOYSTICK_TYPE_JOYSTICK,
   32, // Button count
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
const int numReads = 5;
const int numWrites = 5;
int readPins[numReads] = {15, 14, 16, 10, 8};  // These are the pins that will be set as inputs and be read in each cycle ("Columns")
int writePins[numWrites] = {A3, A2, A1, A0, 9}; // These are the pins that will be turned on/off ("Rows")
int outputButton[numWrites][numReads] = {
  { 0,  3,  6,  9},
  {13, 12, 15, 14},
  {16, 17, 18, 19},
  {20, 21, 22, 23},
  {24, 25, 26, 27, 28}
}; // This specifies the joystick button be output from each matix position.
int newButtonValue[numWrites][numReads] =
{
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0}
};
int oldButtonValue[numWrites][numReads] =
{
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0}
};


// Set up rotary encoders
const int numEnc = 4;
Rotary R[numEnc] = {Rotary(0,1), Rotary(2,3), Rotary(4,5), Rotary(6,7)};  // Using the rotary library, set up pins for each
int encDelay[numEnc] = {100, 10, 100, 100};  //How long to turn the encoder on with each press in milliseconds.  Can set unique values for each encoder.
int encButtons[4][2] = {{1, 2}, {4, 5}, {7, 8}, {10, 11}};  // Joystick button to be sent by CW/CCW turns of each encoder
unsigned char encResult;


// Set up the input pins for the axes
int xAxisPin = 8;


void setup() {
  JS1.begin();
  
  // Set up the input (INPUT_PULLUP) and output pins
  for(i = 0; i < numWrites; i++)
  {
    pinMode(writePins[i], OUTPUT);
    digitalWrite(writePins[i], HIGH);
  }
  for(i = 0; i < numReads; i++)
  {
    pinMode(readPins[i], INPUT_PULLUP);
  }

}

void loop() {
  // Run through the button matrix
  // Loop through the outputs checking each input as we go
  for(i = 0; i < numWrites; i++)
  {
    digitalWrite(writePins[i], LOW);
    for(j = 0; j < numReads; j++)
    {
      // Get the current value of the button, compare with previous value, and send if different
      // This is faster than sending the button value every cycle
      newButtonValue[i][j] = !digitalRead(readPins[j]);
      if(newButtonValue[i][j] != oldButtonValue[i][j])
        JS1.setButton(outputButton[i][j], newButtonValue[i][j]);
      oldButtonValue[i][j] = newButtonValue[i][j];
      
      // Since encoders are sensitive to timing, check them with every cycle
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
    }
    digitalWrite(writePins[i], HIGH);
  }

}
