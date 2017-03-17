#include "CompactRover.h";

//Left, LeftPWM, Right, RightPWM
CompactRover bot(7,10,8,11);

//Direction to include the time you want the motors on and a speed
//in PWM.


void setup() {
  bot.begin();
}

void loop() {

  bot.forward(500, 100);
  while(bot.IsRunning()) {
    bot.update();
  }

bot.back(500, 100);
while(bot.IsRunning()) {
  bot.update();
}

bot.leftTight(500, 100);
while(bot.IsRunning()) {
  bot.update();
}

bot.rightTight(1000, 100);
while(bot.IsRunning()) {
  bot.update();
  }

bot.leftTight(500, 100);
while(bot.IsRunning()) {
  bot.update();
}


}
