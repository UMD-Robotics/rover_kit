/*
drive.h - Elegoo smartcar library for driving functionality.
Created by the University of Minnesota Duluth Robotics Club
Fall, 2016
*/

#ifndef DRIVE_H
#define DRIVE_H

class Drive {
 private:
  
  //Stores arduino pins for right motor(s).
  int rIn1;
  int rIn2;
  int ENB;

  //Stores arduino pins for left motor(s).
  int lIn1;
  int lIn2;
  int ENA;
  
  /** Makes sure that all signal output pins are set to output mode. */
  void checkPins() const;
  
  /** Writes values to the output pins of the arduino. 
   *  Only Automatically scales values from -1 to 1 to their appropriate
   *  pwm/digital output values. */
  void write(const double& leftspeed, const double& rightspeed) const;

 public:
  
  //Default constructor. Forces client to set motor pins.
  Drive(const int& lPin1, const int& lPin2, const int& rPin1, const int& rPin2, const int& ENA_pin, const int& ENB_pin);

  /** Finds the current pin number for right motor input#1.
   *
   *  @return integer corresponding to current right motor pin#1. */
  int getRPin1() const;
  
  /** Finds the current pin number for right motor input#2.
   *
   *  @return integer corresponding to current right motor pin#2. */
  int getRPin2() const;

  /** Finds the current pin number for left motor input#1.
   *
   * @return integer corresponding to current left motor pin#1. */
  int getLPin1() const;
  
  /** Finds the current pin number for left motor input#2.
   *
   * @return integer corresponding to current left motor pin#2. */
  int getLPin2() const;
  
  /** Finds the current pin number assigned to ENA.
   * 
   *  @return integer corresponding to current ENA pin. */
  int getENA() const;
  
  /** Finds the current pin number assigned to ENB.
   * 
   *  @return integer corresponding to current ENB pin. */
  int getENB() const;
  
  /** Sets the output pins for this Drive object.
   * 
   *  @post Output pins have been set to the values defined by client. */
  void setPins(const int& lPin1, const int& lPin2, const int& rPin1, const int& rPin2, const int& ENA_pin, const int& ENB_pin);
  
  //Timed drive functions. Robot always stopped when no command received.-------------------
  
  /** Basic "Drive forward for time" function.
   *  
   *  @post Robot will drive forward at given speed for given time.
   *
   *  @param time The amount of time robot will drive forward in milliseconds.
   *
   *  @param speed The speed at which robot will move (0 to 1; 1 = maximum speed)
   *  Notice that the speed defaults to 1 if no input. */
  void fwdForTime(const int& time, const double& speed = 1) const;

  /** Basic "Drive backward for time" function.
   *  
   *  @post Robot will drive backward at given speed for given time.
   *
   *  @param time The amount of time robot will drive backward in milliseconds.
   *
   *  @param speed The speed at which robot will move (0 to 1; 1 = maximum speed)
   *  Notice that the speed defaults to 1 if no input. */
  void bckForTime(const int& time, const double& speed = 1) const;

  /** Basic "Drive" function. Gives the user full control over both motors.
   *
   *  @post Motors will rotate forward or back at the specified speeds for the 
   *  specified amount of time.
   *
   *  @param time The amount of time the motors will move in milliseconds.
   *
   *  @param leftspeed The speed at which the left motors will move(-1 to 1).
   *
   *  @param rightspeed The speed at which the right motors will move(-1 to 1). */
  void driveForTime(const int& time, const double& leftspeed, const double& rightspeed) const;

  //Set drive functions (Used for continuous updating or set-and-forget) ----------

  /** Basic "Drive" set function. Allows user to set speed for both motors.
   *
   *  @post Motors will rotate forward or back at the specified speeds.
   *
   *  @param leftspeed The speed at which the left motors will move (-1 to 1).
   *
   *  @param rightspeed The speed at which the right motors will move (-1 to 1). */
  void move(const double& leftspeed, const double& rightspeed) const;
};

#endif
