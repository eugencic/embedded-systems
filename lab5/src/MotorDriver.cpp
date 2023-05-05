#include "MotorDriver.h"

MotorDriver::MotorDriver(int pin1, int pin2, int pin3)
{
    motor.init(pin1, pin2, pin3);
}

void MotorDriver::drive(int speed)
{
    motor.changeSpeed((speed >= 0), (abs(speed) * 2.55 + 0.5));
}
