#include <Joystick.h>
#include <Rotary.h>

int i = 0, j = 0, k = 0;
int NB = 1023;
int analogStep = 3;
int analogMin = 0;
int analogMax = 1023;

Joystick_ JS1(
  0x03, // Address. Cannot use 0x01 or 0x02
  JOYSTICK_TYPE_JOYSTICK,
  64, // Button count
  0, // Number of hat switches
  true, // include x axis
  true, // include y axis
  true, // include z axis
  true, // include Rx axis
  true, // include Ry axis
  true, // include Rz axis
  false, // include Rudder axis
  true, // include throttle axis
  false, // include accelerator axis
  false, // include brake axis
  false // include steering axis
);


// AXIS SETUP
// Declare a function that will figure out which axis to set based on an index
void setAxis(int axisIndex, int axisSetValue);
const int numAxes = 7;
const int numSamples = 10; // How many samples to use for smoothing

// Set up the input pins for the axes
int axisPin[numAxes] = {A0, A1, A2, A3, A6, A7, A8};

// Set up placeholder variables for the axes
int newAxisValue;
int oldAxisValue[numAxes];
int newAxisSum[numAxes] = {5,5,5,5,5,5,5};
int oldAxisSum[numAxes] = {5,5,5,5,5,5,5};
int axisMatrix[numSamples][numAxes] =
  {
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
  };

// Set up rotary encoders
  const int numEnc = 1;
  Rotary R[numEnc] = {Rotary(2,3)};  // Using the rotary library, set up pins for each
  int encDelay[numEnc] = {100};  //How long to turn the encoder on with each press in milliseconds.  Can set unique values for each encoder.
  int encButtons[1][2] = {{1, 0}};  // Joystick button to be sent by CW/CCW turns of each encoder
  unsigned char encResult;




void setup() {
  JS1.begin();
  // Serial.begin(9600);

  // Set up the analog inputs
  for(i = 0; i < numAxes; i++)
    pinMode(axisPin[i], INPUT);

  delay(2500);
 
}

void loop() {
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
  
  // Code for analog controls
  // To avoid jitter, only change outputs when the change is > analogMin (not in use)
  // If within analogMin of the min or max, force the output to the min/max (not in use)
  // CODE WITHOUT SMOOTHING
  /*
  for(i = 0; i < numAxes; i++)
  {
    newAxisValue[i] = analogRead(axisPin[i]);
    if(newAxisValue[i] != oldAxisValue[i])
    {
      setAxis(i, newAxisValue[i]);
      oldAxisValue[i] = newAxisValue[i];
    }
  }
  */
  // CODE WITH SMOOTHING
  // MOVING AVERAGE DOES NOT WORK!!!
  // TRY COMBINING MOVING AVERAGE WITH MIN STEP CHANGE.
  
  if(j >= numSamples)
    j = 0;
  for(i = 0; i < numAxes; i++)
  {
    newAxisValue = analogRead(axisPin[i]);
    if(abs(newAxisValue - axisMatrix[j][i]) > analogStep)
    {
      newAxisSum[i] = oldAxisSum[i] + newAxisValue - axisMatrix[j][i];
      /*
      Serial.print("Cycle ");
      Serial.print(j);
      Serial.print(": After read i = ");
      Serial.print(i);
      Serial.print(" newAxisValue = ");
      Serial.print(newAxisValue);
      Serial.print(" axisMatrix = ");
      Serial.print(axisMatrix[j][i]);
      Serial.print(" oldAxisSum = ");
      Serial.print(oldAxisSum[i]);
      Serial.print(" newAxisSum = ");
      Serial.print(newAxisSum[i]);
      Serial.print(" oldAxisSum/10 = ");
      Serial.print(oldAxisSum[i]/10);
      Serial.print(" newAxisSum/10 = ");
      Serial.println(newAxisSum[i]/10);
      */
      axisMatrix[j][i] = newAxisValue;
      if(newAxisSum[i]/10 != oldAxisSum[i]/10)
      {
        setAxis(i, newAxisSum[i] / 10);
      }
      oldAxisSum[i] = newAxisSum[i];
    }

  }
  j++;

  // GOING BACK TO THE WAY WITH min steps
  /*
  for(i = 0; i < numAxes; i++)
  {
    newAxisValue = analogRead(axisPin[i]);
    if(newAxisValue >= analogMax - analogStep)
    {
      setAxis(i, analogMax);
      oldAxisValue[i] = newAxisValue;
    }
    else if(newAxisValue <= analogMin + analogStep)
    {
      setAxis(i, analogMin);
      oldAxisValue[i] = newAxisValue;
    }
    else if(abs(newAxisValue - oldAxisValue[i]) >= analogStep)
    {
      setAxis(i, newAxisValue);
      oldAxisValue[i] = newAxisValue;
    }
  }
  */

  

}

void setAxis(int axisIndex, int axisSetValue)
{
  if(axisIndex == 0)
    JS1.setXAxis(axisSetValue);
  else if(axisIndex == 1)
    JS1.setYAxis(axisSetValue); 
  else if(axisIndex == 2)
    JS1.setZAxis(axisSetValue); 
  else if(axisIndex == 3)
    JS1.setRxAxis(axisSetValue); 
  else if(axisIndex == 4)
    JS1.setRyAxis(axisSetValue); 
  else if(axisIndex == 5)
    JS1.setRzAxis(axisSetValue); 
  // NOTE RUDDER AND THROTTLE SWAPPED
  // THROTTLE WORKS AS 7th AXIS, RUDDER DOES NOT
  else if(axisIndex == 7)  // Note it's 7
    JS1.setRudder(axisSetValue); 
  else if(axisIndex == 6)  // Note it's 6
    JS1.setThrottle(axisSetValue); 
  else if(axisIndex == 8)
    JS1.setAccelerator(axisSetValue); 
  else if(axisIndex == 9)
    JS1.setBrake(axisSetValue); 
  else if(axisIndex == 10)
    JS1.setSteering(axisSetValue);
}
