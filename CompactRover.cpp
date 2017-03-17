#include "Arduino.h"
#include "CompactRover.h"

CompactRover::CompactRover(int Left1, int Left2, int Right1, int Right2) 
{
  _Left1 = Left1; //Left Motor Pin
  _Left2 = Left2; //Left PWM Pin
  _Right1 = Right1; //Right Motor Pin
  _Right2 = Right2; //Right PWM Pin
  _previousMillis = 0;
}

void CompactRover::begin() {
  
	pinMode(_Left1, OUTPUT);
	pinMode(_Left2, OUTPUT);
	pinMode(_Right1, OUTPUT);
	pinMode(_Right2, OUTPUT);
	digitalWrite(_Left1, LOW);
	analogWrite(_Left2, 0);
	digitalWrite(_Right1, LOW);
	analogWrite(_Right2, 0);
	
}
 


void CompactRover::stop() {
    _previousMillis = millis();
	digitalWrite(_Left1, LOW);
	analogWrite(_Left2, 0);
	digitalWrite(_Right1, LOW);
	analogWrite(_Right2, 0);
	_isrunning = 0;
}

void CompactRover::forward(int OnTime, int speed) {
    _previousMillis = millis();
	digitalWrite(_Left1, LOW);
	analogWrite(_Left2, speed);
	digitalWrite(_Right1, LOW);
	analogWrite(_Right2, speed);
	_OnTime = OnTime;
	_isrunning = 1;
}

void CompactRover::back(int OnTime, int speed) {
    _previousMillis = millis();
	digitalWrite(_Left1, HIGH);
	analogWrite(_Left2, 255 - speed);
	digitalWrite(_Right1, HIGH);
	analogWrite(_Right2, 255 - speed);
	_OnTime = OnTime;
	_isrunning = 1;

}

void CompactRover::rightTight(int OnTime, int speed) {
    _previousMillis = millis();
	digitalWrite(_Left1, LOW);
	analogWrite(_Left2, speed);
	digitalWrite(_Right1, HIGH);
	analogWrite(_Right2, 255 - speed);
	_OnTime = OnTime;
	_isrunning = 1;
}

void CompactRover::leftTight(int OnTime, int speed) {
    _previousMillis = millis();
	digitalWrite(_Left1, HIGH);
	analogWrite(_Left2, 255 - speed);
	digitalWrite(_Right1, LOW);
	analogWrite(_Right2, speed);
	_OnTime = OnTime;
	_isrunning = 1;
}

void CompactRover::right(int OnTime, int speed) {
    _previousMillis = millis();
	digitalWrite(_Left1, LOW);
	analogWrite(_Left2, speed);
	digitalWrite(_Right1, LOW);
	analogWrite(_Right2, 0);
	_OnTime = OnTime;
	_isrunning = 1;
}

void CompactRover::left(int OnTime, int speed) {
    _previousMillis = millis();
	digitalWrite(_Left1, LOW);
	analogWrite(_Left2, 0);
	digitalWrite(_Right1, LOW);
	analogWrite(_Right2, speed);
	_OnTime = OnTime;
	_isrunning = 1;
}

void CompactRover::update() {
	unsigned long currentMillis = millis();
	if (currentMillis - _previousMillis >= _OnTime) {
		_previousMillis = currentMillis;
		CompactRover::stop();
		
	}
}

int CompactRover::IsRunning() {
	return (_isrunning);

};
