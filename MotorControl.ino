//Colin Hunt
//GitHub Science Hack Day 2018

#include <AFMotor.h>

AF_Stepper motorX(200, 1);//Stepper motor that rotates in X direction, 200 total steps per rotation
AF_Stepper motorY(200, 2);//Stepper motor that rotates in Y direction, 200 total steps per rotation

int xPin = A8;//Pin that will read the joystick X direction info
int yPin = A9;//Pin that will read the joystick Y direction info
int xPos; //Resting position of X appears to be 496 (0-1023)
int yPos; //Resting position of Y appears to be 531 (0-1023)
int initial_pos = 90;

void setup() {
  Serial.begin(9600);// set up Serial library at 9600 bps

  motorX.setSpeed(60);  //60 rpm   
  motorX.step(100, FORWARD, SINGLE); //Testing X the motor, half turn
  motorX.release();

  motorY.setSpeed(60);  //60 rpm   
  motorY.step(100, FORWARD, SINGLE);//Testing Y the motor, half turn
  motorY.release();
  
  delay(1000);

  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
}

void loop() {
  xPos = analogRead (xPin);
  yPos = analogRead (yPin);

  if (xPos < 400) {
      motorX.step(10, FORWARD, SINGLE); //This will move the moter forward 10 of a total 200 steps each time it is read
  }
  else if (xPos > 600) {
      motorX.step(10, BACKWARD, SINGLE);
  }

  if (yPos < 400) {
      motorY.step(10, FORWARD, SINGLE); 
  }
  else if (yPos > 600) {
      motorY.step(10, BACKWARD, SINGLE);
  }
}
