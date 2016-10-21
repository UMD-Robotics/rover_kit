/*
drive.h - Elegoo smartcar library for driving functionality.
Created by the University of Minnesota Duluth Robotics Club
10/20/16
*/

#ifndef DRIVE_H
#define DRIVE_H

#include "Arduino.h"

/** Basic "Drive forward for time" function.
 *  
 *  @post Robot will drive forward at given speed for given time.
 *
 *  @param time The amount of time robot will drive forward in seconds.
 *
 *  @param speed The speed at which robot will move (0 to 1; 1 = maximum speed)
 *  Notice that the speed defaults to 1 if no input. */
void fwdForTime(const double& time, const double& speed = 1);

/** Basic "Drive backward for time" function.
 *  
 *  @post Robot will drive backward at given speed for given time.
 *
 *  @param time The amount of time robot will drive backward in seconds.
 *
 *  @param speed The speed at which robot will move (0 to 1; 1 = maximum speed)
 *  Notice that the speed defaults to 1 if no input. */
void bckForTime(const double& time, const double& speed = 1);

/** Basic "Drive" function. Gives the user full control over both motors.
 *
 *  @post Motors will rotate forward or back at the specified speeds for the 
 *  specified amount of time.
 *
 *  @param time The amount of time the motors will move.
 *
 *  @param leftspeed The speed at which the left motors will move(-1 to 1).
 *
 *  @param rightspeed The speed at which the right motors will move(-1 to 1). */
void driveForTime(const double& time, const double& leftspeed, const double& rightspeed);

#endif
