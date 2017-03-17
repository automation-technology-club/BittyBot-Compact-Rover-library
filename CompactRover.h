/* 
CompactRover Motor Library v1 Copyright (C) LeRoy Miller Mar 17, 2017
Based from: BittyBot Motor Library version 2
created by LeRoy Miller, Oct 3, 2015
*/

#ifndef CompactRover_h
#define CompactRover_h

#include "Arduino.h"

class CompactRover {
private:
	int _Left1; //L1 
	int _Left2; //L2
	int _Right1; //L3
	int _Right2; //L4
	unsigned long _previousMillis;
	long _OnTime;
	int _speed;
	int _isrunning;
public: 
CompactRover(int Left1, int Left2, int Right1, int Right2); 
void begin();
void stop();
void forward(int OnTime, int speed);
void back(int OnTime, int speed);
void rightTight(int OnTime, int speed);
void leftTight(int OnTime, int speed);
void right(int OnTime, int speed);
void left(int OnTime, int speed);
void update();
int IsRunning();
};

#endif
