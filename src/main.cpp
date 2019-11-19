/**
 * An example showing how you can make something happen ONLY when the button is released
 * Instead of every time it sees the button as held down.
 */

#include "../include/main.h"

pros::Controller controller(CONTROLLER_MASTER);
pros::Motor DriveTrainL(1);
pros::Motor DriveTrainR(2, true);

bool isAReleased = false;

void onARelease(bool isAPressed){
  if(isAPressed){
    //Have what you want the bot doing while the button isn't released here.
    DriveTrainL.move_velocity(0);
    DriveTrainR.move_velocity(0);
    isAReleased = false;
    //If A is pressed, it can't be released. Must change it to false
  }else if(!isAReleased){
    //Because this is the only bit of code that can change isAReleased to true, this will only ever trigger once.
    //Example. Moves Bot forward for 1 second
    DriveTrainL.move_velocity(127);
    DriveTrainR.move_velocity(127);
    isAReleased = true;
  }
}

void initialize() {}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
	while (true) {
    onARelease(
      controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)
    );
	}
}
