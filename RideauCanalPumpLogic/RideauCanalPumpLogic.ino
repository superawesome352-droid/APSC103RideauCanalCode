#include <AFMotor.h>

bool run = false;
int runSet = 1;

//ports each item is connected to
const int switchButton = A0;
const int stopButton = A1;
const int greenLED = A2;
const int redLED = A3;
const int set11 = 1;
const int set12 = 2;
const int set21 = 3;
const int set22 = 4;

AF_DCMotor pumpSet11(set11);
AF_DCMotor pumpSet12(set12);
AF_DCMotor pumpSet21(set21);
AF_DCMotor pumpSet22(set22);

void setup() {
  //defining pins
  pinMode(switchButton, INPUT_PULLUP);
  pinMode(stopButton, INPUT_PULLUP);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  //set up pumps
  pumpSet11.setSpeed(255);
  pumpSet12.setSpeed(255);
  pumpSet21.setSpeed(255);
  pumpSet22.setSpeed(255);
}

void loop() {
  // checks if the stop button has been pressed, and switches the system on and off
  if(digitalRead(stopButton) == LOW){
    run = !run;
    pumpSet11.run(RELEASE);
    pumpSet12.run(RELEASE);
    pumpSet21.run(RELEASE);
    pumpSet22.run(RELEASE);
    if(run){
      digitalWrite(greenLED, HIGH);
      digitalWrite(redLED, LOW);
    } else {
      digitalWrite(greenLED, LOW);
      digitalWrite(redLED, HIGH);
    }
    delay(1000);
  }

  //switches which set is run if the switch button is pressed
  if(digitalRead(switchButton) == LOW){
      pumpSet11.run(RELEASE);
      pumpSet12.run(RELEASE);
      pumpSet21.run(RELEASE);
      pumpSet22.run(RELEASE);
      runSet++;
      if(runSet>2){
        runSet = 1;
      }
      delay(200);
    }

  //running the set
  if(run){
    switch(runSet){
      case 1:
      pumpSet11.run(FORWARD);
      pumpSet12.run(FORWARD);
      break;
      case 2:
      pumpSet21.run(FORWARD);
      pumpSet22.run(FORWARD);
      break;
    }
  }
}
