#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
using namespace webots;

int main(int argc, char **argv) {
  
  Robot *robot = new Robot();

  int timeStep = (int)robot->getBasicTimeStep();

  // You should insert a getDevice-like function in order to get the
  // instance of a device of the robot. Something like:
  Motor *motor = robot->getMotor("motor");
  motor->setPosition(INFINITY);
  motor->setForce(0.0);
  PositionSensor *ds = robot->getDistanceSensor("encoder");
  ds->enable(timeStep);

  // Main loop:
  // - perform simulation steps until Webots is stopping the controller
  while (robot->step(timeStep) != -1) {
  double val =  ds->getValue();
    cout << "Posicion Actual" << val << endl; 
    motor->setPosition(6.2832);
  };

  // Enter here exit cleanup code.

  delete robot;
  return 0;
}
