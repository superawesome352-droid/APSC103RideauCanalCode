#include <AFMotor.h>

#define off 0
#define runSetOne 1
#define runSetTwo 2

const short pumpSet1;
const short pumpSet2;
const short buttonSet1;
const short buttonSet2;
const short buttonStop;
const short greenLED;
const short redLED;

AF_DCMotor pumpSetOne(pumpSet1);
AF_DCMotor pumpSetTwo(pumpSet2);

short state = off;

void setup() {
  Serial.begin(9600);

  // defining ports
  pinMode(buttonSet1, INPUT_PULLUP);
  pinMode(buttonSet2, INPUT_PULLUP);
  pinMode(buttonStop, INPUT_PULLUP);

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  state = switchState(state);

  switch(state){
    case off:
    pumpSetOne.run(RELEASE);
    pumpSetTwo.run(RELEASE);
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    break;
    case runSetOne:
    pumpSetOne.run(FORWARD);
    pumpSetTwo.run(RELEASE);
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
    break;
    case runSetTwo:
    pumpSetTwo.run(FORWARD);
    pumpSetOne.run(RELEASE);
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
    break;
    default:
    Serial.print("An error has occured. The state currently reads: " + state);
    break;
  }

}

short switchState(short currentState){
  bool b1Pressed = digitalRead(buttonSet1);
  bool b2Pressed = digitalRead(buttonSet2);
  bool sPressed = digitalRead(buttonStop);

  if(sPressed){
    return off;
  } else if (b1Pressed){
    return runSetOne;
  } else if (b2Pressed){
    return runSetTwo;
  } else {
    return currentState;
  }
}
