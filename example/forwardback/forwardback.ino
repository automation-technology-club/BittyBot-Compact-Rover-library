#include "CompactRover.h";

//Left, LeftPWM, Right, RightPWM
CompactRover bot(7,10,8,11);

//Direction to include the time you want the motors on and a speed
//in PWM.

void setup() {

  bot.begin();
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
bot.forward(1000, 100);

while(bot.IsRunning()) {
  bot.update();
}

bot.back(1000, 100);

while(bot.IsRunning()) {
  bot.update();
}

}
