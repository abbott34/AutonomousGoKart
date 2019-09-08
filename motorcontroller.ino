#include <ArduinoRobot.h>
#include <math.h>

int E1Sensor = A0; //left value
int E2Sensor = A1; //right value
int sensor_value_left = 0; //Sensor Value for forward
int sensor_value_right = 0; //Sensor Value for backward

double angleHeld(double, double, double);
double detectChange(double);
void setup() {
Robot.begin();

//Serial.begin(9600);

}

void loop() {
  int updatedRev;
  double throttle; 
  double currentSteering;
  double userAngle; // motor value for angle
  updatedRev = 0;
  updatedRev += angleHeld(userAngle, throttle, currentSteering);

}

double angleHeld(double currentAngle, double throttle, double steering){

  //Sensor_value_forward = analogRead(E1Sensor);
  //Sensor_value_backward = analogRead(E2Sensor);
  //Serial.println(Sensor_value_forward);
  //Serial.println(Sensor_value_backward);
  double updatedAngle;
  int leftVal;
  int rightVal;
  updatedAngle = atan2(throttle, steering); //gives angle
  //leftVal = (updatedAngle / 90) * 255; //Check this later
  //rightVal = (updatedAngle / 90) * 255; //Check this later

  while(currentAngle != updatedAngle){
  if (currentAngle > updatedAngle){

    Robot.motorsWrite(leftVal,rightVal); //Does not work properly
    updatedAngle = atan2(throttle, steering); //gives angle
    currentAngle = updatedAngle;
  }

  else if(currentAngle < updatedAngle){
    Robot.motorsWrite(leftVal,rightVal); //Does not work properly
    updatedAngle = atan2(throttle, steering); //gives angle
    currentAngle = updatedAngle;

  }
  }
  updatedAngle = atan2(throttle, steering); //gives angle

  return(currentAngle);
}


double detectChange(double currentAngle){
   sensor_value_left = analogRead(E1Sensor);
   sensor_value_right = analogRead(E2Sensor);
   double revolutions = 1000;
  while(sensor_value_left > sensor_value_right){
    currentAngle--;
  }
  while(sensor_value_left < sensor_value_right){
    currentAngle++;
  }
}


// 100 revolution of motor leads to 1 revolution of gearbox
// Given an angle, tell the program to hold that angle ---> still working on this //DONE
// Feedback loop that tells program to slow down --> need to do this
// Work on how to change angle
// Main Idea: Given inputs from the RC controller, we have to output the hold angle.

int E1Sensor = 2; //assigns E1Sensor to pin 2 i think
int E2Sensor = 3; //assigns E1Sensor to pin 3 i think
int motorcontroller = 13; //assigns motorcontroller to pin 13 prob
double revolutions = 1000; //The initial number of revoultions

void setup() {

  pinMode(motorcontroller, OUTPUT); //outputting revolutions
  pinMode(E1Sensor, INPUT);
  pinMode(E2Sensor, INPUT);
  attachInterrupt(0, firstsensorpassed, HIGH); //matches with E1Sensor
  attachInterrupt(1, secondsensorpassed, HIGH); //matches with E2Sensor
}

void loop()
{
  }

void firstsensorpassed()
{

  digitalWrite(motorcontroller, HIGH); //Turns the fucking motor fucker on
  if (E2Sensor == LOW){
    revolution++;
    pinMode(E1Sensor, LOW);
  }

}

void secondsensorpassed()
{
  digitalWrite(motorcontroller, HIGH); //Turns the fucking motor fucker on
  if(E1Sensor == LOW){
    revolution--;
    pinMode(E2Sensor, LOW)
  }

}
prevCountE1 = 0;
prevCountE2 = 0;
if(E1Sensor == HIGH){
  prevCountE1++;
}
if(E2Sensor == HIGH){
  prevCountE2++;
}




if (prevCountE1 > prevCountE2){
  revolutions++
}

else if (prevCountE2 > prevCountE1){
  revolutions--
}
/*
If E1 is high first, and then E2, then increment number of revolutions by 1
else decrement number of revolutions by 1





*/
