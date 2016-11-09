#include <Servo.h>
int const potpin = A0; //Pin pot is plugged into
int potval; // variable to read the pot value
int angle; // value sent to servo
Servo myservo; // the name of the servo used

void setup() {
  myservo.attach(3);// connects servo on pin 3 to servo object my servo
  Serial.begin(9600); // opens serial connection to computer
}

void loop() {
  potval = analogRead(potpin); // reads the value of the potentiomeer

  angle = map(potval,0,1023,0,179); //converts the the pot value that is 0-1023 to angle, 0 - 179

  myservo.write(angle); // sends that angle value to the servo
  Serial.println(angle);
  delay(20); //gives the servo time to get to its position
}
