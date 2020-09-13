#include <Joystick.h>
#include <Rotary.h>

int i, j, k;
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


int newXValue = 0;
int oldXValue = 0;
int newYValue = 0;
int oldYValue = 0;
int newZValue = 0;
int oldZValue = 0;
int newRxValue = 0;
int oldRxValue = 0;
int newRyValue = 0;
int oldRyValue = 0;
int newRzValue = 0;
int oldRzValue = 0;
int newThrottleValue = 0;
int oldThrottleValue = 0;


// Set up rotary encoders
  const int numEnc = 3;
  Rotary R[numEnc] = {Rotary(2,3), Rotary(10,16), Rotary(14,15)};  // Using the rotary library, set up pins for each
  int encDelay[numEnc] = {20, 20, 20};  //How long to turn the encoder on with each press in milliseconds.  Can set unique values for each encoder.
  int encButtons[4][2] = {{0, 1}, {4, 5}, {2, 3}};  // Joystick button to be sent by CW/CCW turns of each encoder
  unsigned char encResult;

// Set up the input pins for the axes
int xAxisPin = A0;
int yAxisPin = A1;
int zAxisPin = A2;
int RxAxisPin = A3;
int RyAxisPin = A6;
int RzAxisPin = A7;
int ThrottlePin = A8;


void setup() {
  JS1.begin();


  // Set up the input (INPUT_PULLUP) and output pins
  /* 
  for (i = 0; i < numWrites; i++)
  {
    pinMode(writePins[i], OUTPUT);
    digitalWrite(writePins[i], HIGH);
  }
  for (i = 0; i < numReads; i++)
  {
    pinMode(readPins[i], INPUT_PULLUP);
  }
  */
  
  // Set up the analog inputs
  pinMode(xAxisPin, INPUT);
  pinMode(yAxisPin, INPUT);
  pinMode(zAxisPin, INPUT);
  pinMode(RxAxisPin, INPUT);
  pinMode(RyAxisPin, INPUT);
  pinMode(RzAxisPin, INPUT);
  pinMode(ThrottlePin, INPUT);

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
  // To avoid jitter, only change outputs when the change is > analogMin
  // If within analogMin of the min or max, force the output to the min/max
  newXValue = analogRead(xAxisPin);
  if(newXValue != oldXValue)
  {
    JS1.setXAxis(newXValue);
    oldXValue = newXValue;
  }

  newYValue = analogRead(yAxisPin);
  if(newYValue != oldYValue)
  {
    JS1.setYAxis(newYValue);
    oldYValue = newYValue;
  }

  newZValue = analogRead(zAxisPin);
  if(newZValue != oldZValue)
  {
    JS1.setZAxis(newZValue);
    oldZValue = newZValue;
  }

  newRxValue = analogRead(RxAxisPin);
  if(newRxValue != oldRxValue)
  {
    JS1.setRxAxis(newRxValue);
    oldRxValue = newRxValue;
  }
 
  newRyValue = analogRead(RyAxisPin);
  if(newRyValue != oldRyValue)
  {
    JS1.setRyAxis(newRyValue);
    oldRyValue = newRyValue;
  }

  newRzValue = analogRead(RzAxisPin);
  if(newRzValue != oldRzValue)
  {
    JS1.setRzAxis(newRzValue);
    oldRzValue = newRzValue;
  }

  newThrottleValue = analogRead(ThrottlePin);
  if(newThrottleValue != oldThrottleValue)
  {
    JS1.setThrottle(newThrottleValue);
    oldThrottleValue = newThrottleValue;
  }


}
