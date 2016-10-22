/*
drive.cpp - Elegoo smartcar library implementation for driving functionality.
Created by the University of Minnesota Duluth Robotics Club
Fall, 2016
*/

#include "Arduino.h"
#include "drive.h"

Drive::Drive(const int& lPin1, const int& lPin2, const int& rPin1, const int& rPin2, const int& ENA_pin, const int& ENB_pin){

  rIn1 = rPin1;
  rIn2 = rPin2;
  lIn1 = lPin1;
  lIn2 = lPin2;
  ENA = ENA_pin;
  ENB = ENB_pin;

  checkPins();
}

int Drive::getRPin1() const{

  return rIn1;
}

int Drive::getRPin2() const{

  return rIn2;
}

int Drive::getLPin1() const{

  return lIn1;
}

int Drive::getLPin2() const{

  return lIn2;
}

int Drive::getENA() const{

  return ENA;
}

int Drive::getENB() const{

  return ENB;
}

void Drive::setPins(const int& lPin1, const int& lPin2, const int& rPin1, const int& rPin2, const int& ENA_pin, const int& ENB_pin){

  rIn1 = rPin1;
  rIn2 = rPin2;
  lIn1 = lPin1;
  lIn2 = lPin2;
  ENA = ENA_pin;
  ENB = ENB_pin;

  checkPins();
}

void Drive::fwdForTime(const int& time, const double& speed) const{

  write(speed, speed);
  delay(time);
  write(0, 0);
}

void Drive::bckForTime(const int& time, const double& speed) const{

  write(speed * -1, speed * -1);
  delay(time);
  write(0, 0);
}

void Drive::driveForTime(const int& time, const double& leftspeed, const double& rightspeed) const{

  write(leftspeed, rightspeed);
  delay(time);
  write(0, 0);
}

void Drive::move(const double& leftspeed, const double& rightspeed) const{

  write(leftspeed, rightspeed);
}

void Drive::checkPins() const{

  pinMode(rIn1, OUTPUT);
  pinMode(rIn2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(lIn1, OUTPUT);
  pinMode(lIn2, OUTPUT);
  pinMode(ENA, OUTPUT);
}

void Drive::write(const double& leftspeed, const double& rightspeed) const{

  //Settings for left side.
  if (leftspeed > 0){ //Set left side to forward
    digitalWrite(lIn1, LOW);
    digitalWrite(lIn2, HIGH);
    if (leftspeed > 1)
      analogWrite(ENA, 1);
    else
      analogWrite(ENA, leftspeed * 255);
  }
  else if (leftspeed < 0){ //Set left side to reverse
    digitalWrite(lIn1, HIGH);
    digitalWrite(lIn2, LOW);
    if (leftspeed < -1)
      analogWrite(ENA, -1);
    else
      analogWrite(ENA, leftspeed * -255);
  }
  
  else{ //Set output to off. Don't care about ENA
    digitalWrite(lIn1, LOW);
    digitalWrite(lIn2, LOW);
  }

  
  //Settings for right side.
  if (rightspeed > 0){ //Set right side to forward
    digitalWrite(rIn1, LOW);
    digitalWrite(rIn2, HIGH);
    if (rightspeed > 1)
      analogWrite(ENB, 1);
    else
      analogWrite(ENB, rightspeed * 255);
  }
  else if (rightspeed < 0){ //Set right side to reverse
    digitalWrite(rIn1, HIGH);
    digitalWrite(rIn2, LOW);
    if (rightspeed < -1)
      analogWrite(ENB, -1);
    else
      analogWrite(ENB, rightspeed * -255);
  }

  else{ //Set output to off. Don't care about ENB
    digitalWrite(rIn1, LOW);
    digitalWrite(rIn2, LOW);
  }
}
