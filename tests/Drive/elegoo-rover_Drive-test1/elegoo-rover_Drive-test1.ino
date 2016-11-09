#include <ElegooRover.h>

int lIn1(9);
int lIn2(8);
int rIn1(7);
int rIn2(6);
int ENA(10);
int ENB(5);
Drive drive(lIn1, lIn2, rIn1, rIn2, ENA, ENB);

void setup() {
drive.setPins(8, 9, 6, 7, 5, 10);

while(drive.getLPin1() != 8){}
while(drive.getLPin2() != 9){}
while(drive.getRPin1() != 6){}
while(drive.getRPin2() != 7){}
while(drive.getENA() != 5){}
while(drive.getENB() != 10){}

drive.setPins(lIn1, lIn2, rIn1, rIn2, ENA, ENB);
}

void loop() {
drive.fwdForTime(1000, .5); //drive forward
delay(1000);
drive.bckForTime(1000, .5); //drive backward
delay(1000);
drive.driveForTime(500, -.5, .5); //turn left
delay(500);
drive.driveForTime(500, .5, -.5); //turn right
delay(2000);
}
