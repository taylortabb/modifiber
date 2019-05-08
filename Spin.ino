// Taylor Tabb. March 20 2018.
int i=0;
int spins=90;
int cycle=0;
int stat;
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <Adafruit_PWMServoDriver.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Connect a stepper motor with 200 steps per revolution (1.8 degree)
// to motor port #2 (M3 and M4)
Adafruit_StepperMotor *myMotor = AFMS.getStepper(200, 1);


void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Let's spin some twine!");

  AFMS.begin();  // create with the default frequency 1.6KHz
  TWBR = ((F_CPU /400000l) - 16) / 2;
//  AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  myMotor->setSpeed(3000000);  // 300 rpm   
}

void loop() {
    
while (Serial.available() == 0);
int stat = Serial.parseInt(); //read int or parseFloat
while (stat == 1) {
//float spins = Serial.parseFloat(); //read int or parseFloat
  
  cycle=200*spins; // number of spings * spins per rotation
//  Serial.println(cycle);
  myMotor->step(cycle, BACKWARD, DOUBLE); //spin # of times as input
//  delay(100);
//  Serial.println("I have spun twine.");
  i=i+90;
  Serial.println(i);
  int stat = Serial.parseInt(); //read int or parseFloat
}
}

