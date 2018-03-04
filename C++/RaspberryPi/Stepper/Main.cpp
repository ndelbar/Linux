/*
 * File name   : stepperMotor.c
 * Description : control a stepper motor.
 * Website     : www.adeept.com
 * E-mail      : support@adeept.com
 * Author      : Jason
 * Date        : 2015/06/21
 */
#include <wiringPi.h>  
#include <stdio.h>  
#include <thread>

using namespace std;

#define OUT1 0    // wiringPi GPIO0(pin11)  
#define OUT2 1    // pin12 
#define OUT3 2    // pin13
#define OUT4 3    // pin15
#define OUT5 6 	  // pin22

#define IN1 4 //pin16
#define IN2 5 //pin18

void RunAlarm()
{
	unsigned char nStopValue = 0;
	
	while(1)
	{
		digitalWrite(OUT5, LOW);  //beep on
		delay(100);                  //delay
		digitalWrite(OUT5, HIGH); //beep off
		delay(100);                  //delay
		
		nStopValue   = digitalRead(IN1);
		
		if (nStopValue)
			break;
	}
	
	delay(1000);
}

void StopSound()
{
	int nDelay = 20;
	
	for (int i = 0; i < 10; i++)
	{
		digitalWrite(OUT5, LOW);  //beep on
		delay(nDelay);            //delay
		digitalWrite(OUT5, HIGH); //beep off
		delay(nDelay);            //delay
	}
}

bool setStep(int a, int b, int c, int d)  
{  
	digitalWrite(OUT1, a);     
	digitalWrite(OUT2, b);     
	digitalWrite(OUT3, c);     
	digitalWrite(OUT4, d);
	
	unsigned char nReadValue = digitalRead(IN1);
	
	if (nReadValue == 1)
		return false;
		
	return true;
}  

void stop(void)  
{  
	setStep(0, 0, 0, 0);      
}  

bool forward(int t, int steps)  
{  
	int i;  
	bool bStatus = true;
	for(i = 0; i < steps; i++){
		  
		setStep(1, 0, 0, 0);  
		delay(t);  
		setStep(0, 1, 0, 0);      
		delay(t);  
		setStep(0, 0, 1, 0);      
		delay(t);  
		bStatus = setStep(0, 0, 0, 1);      
		delay(t);  
		
		if (!bStatus)
			return bStatus;
	} 
	
	return bStatus; 
}  

bool backward(int t, int steps)  
{  
	int i;  
	bool bStatus = true;
	for(i = 0; i < steps; i++){  
		setStep(0, 0, 0, 1);  
		delay(t);  
		setStep(0, 0, 1, 0);      
		delay(t);  
		setStep(0, 1, 0, 0);      
		delay(t);  
		bStatus = setStep(1, 0, 0, 0);      
		delay(t);  
		
		if (!bStatus)
			return bStatus;
	}
	
	return bStatus;  
}  

void RunStepperMotorLoop()
{
	while (1)
	{  
		printf("forward...\n");  
		
		if (!forward(2, 512))
			break;

		printf("stop...\n");  
		stop();  
		delay(2000);       // 2s  

		printf("backward...\n");  
		
		if (!backward(3, 256))  // 512 steps ---- 360 angle    
			break;

		printf("stop...\n");  
		stop();  
		delay(2000);       // 2s
	}  
}

void RunMotionDetectionLoop()
{
	printf("Running Motion Detection\n");
	
	unsigned char nMotionValue = 0;
	unsigned char nPreviousValue = 0;
	unsigned char nStopValue = 0;
	int nInstance = 0;
		
	while (1)
	{
		delay(100);
		
		nMotionValue = digitalRead(IN2);
		nStopValue   = digitalRead(IN1);
		
		if (nStopValue)
			break;
		
		if (nMotionValue != nPreviousValue)
		{
			if (nMotionValue)
			{
				printf("Motion Detected: %d\n" , nInstance);
				nInstance++;
				nPreviousValue = nMotionValue;
				
				thread tl1(RunStepperMotorLoop);
				thread tl2(RunAlarm);
	
				tl1.join();
				tl2.join();
			}
			else
			{
				printf("Resume Monitoring\n");
				nPreviousValue = nMotionValue;
			}
		}
	}
	
	printf("Finished Motion Detection\n");
}

int main(void) 
{  
	if (wiringPiSetup() < 0) {  
		printf("Setup wiringPi failed!\n");  
		return -1;  
	}  

	/* set pins mode as output */  
	pinMode(OUT1, OUTPUT);  
	pinMode(OUT2, OUTPUT);  
	pinMode(OUT3, OUTPUT);  
	pinMode(OUT4, OUTPUT);  
	pinMode(OUT5, OUTPUT);
	pinMode(IN1, INPUT);
	pinMode(IN2, INPUT);

	//RunStepperMotorLoop();
	
	RunMotionDetectionLoop();
	
	//RunAlarm();
	
	//thread tl1(RunStepperMotorLoop);
	//thread tl2(RunAlarm);
	
	//tl1.join();
	//tl2.join();
	
	StopSound();

	return 0;  
}  
