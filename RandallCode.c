#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Hubs,  S2, HTServo,  HTMotor,  none,     none)
#pragma config(Hubs,  S3, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     RFoot,         tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     LFoot,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     ShoulderZ,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     ShoulderY,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     ShoulderX,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     ElbowX,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     ElbowY,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     NeckX,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C2_1,     NeckY,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C2_2,     motorM,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C1_1,     motorN,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C1_2,     motorO,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S2_C1_1,    Wrist,                tServoStandard)
#pragma config(Servo,  srvo_S2_C1_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"
#include "Buttonmapping.h"
const int STOPPED = 0;
void initializeRobot(){
	motor[RFoot] = STOPPED;
	motor[LFoot] = STOPPED;
	motor[ShoulderX] = STOPPED;
	motor[ShoulderY] = STOPPED;
	motor[ShoulderZ] = STOPPED;
	motor[ElbowX] = STOPPED;
	motor[ElbowY] = STOPPED;
	motor[NeckX] = STOPPED;
	motor[NeckY] = STOPPED;
}
task movement()
{
	while(true)
	{
		if(joystick.joy1_y1 > 5 || joystick.joy1_y1 < -5)
			motor[LFoot] = joystick.joy1_y1 * 0.78125;
		else
			motor[LFoot] = 0;

		if(joystick.joy1_y2 > 5 || joystick.joy1_y2 < -5)
			motor[RFoot] = joystick.joy1_y2 * 0.78125;
		else
			motor[RFoot] = 0;

		if(joystick.joy1_TopHat == 4)
			motor[NeckX] = 20;
		else if(joystick.joy1_TopHat == 0)
			motor[NeckX] = -20;
		else
			motor[NeckX] = 0;

		if(joystick.joy1_TopHat == 6)
			motor[NeckY] = 20;
		else if(joystick.joy1_TopHat == 2)
			motor[NeckY] = -20;
		else
			motor[NeckY] = 0;

		if(RT(1))
			motor[ShoulderZ] = 15;
		else if(LT(1))
			motor[ShoulderZ] = -50;
		else
			motor[ShoulderZ] = 0;

		if(RB(1))
			motor[ElbowY] = 30;
		else if(LB(1))
			motor[ElbowY] = -30;
		else
			motor[ElbowY] = 0;

		if(B(1))
			servo[wrist] = 270;
		else if(X(1))
			servo[wrist] = 0;
		else
			servo[wrist] = 135;

		if(Y(1))
			motor[ElbowX] = 50;
		else if(A(1))
			motor[ElbowX] = -15;
		else
			motor[ElbowX] = 0;

		if(START(1))
			motor[Shoulder] = 100;
		else if(BACK(1))
			motor[Shoulder] = -100;
		else
			motor[Shoulder] = 0;

		abortTimeslice();
	}
}

task main()
{
	StartTask(stuff);
	while(true)
	{
		getJoystickSettings(joystick);
	}
}
