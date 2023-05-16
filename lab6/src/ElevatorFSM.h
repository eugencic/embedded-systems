#ifndef ELEVATOR_FSM_H
#define ELEVATOR_FSM_H

#include <Arduino.h>

class ElevatorFSM 
{
public:
  enum ElevatorState 
  {
    FLOOR_1,
    FLOOR_2,
    FLOOR_3,
    FLOOR_4,
    FLOOR_5,
    FLOOR_6,
    FLOOR_7,
    FLOOR_8
  };

  ElevatorFSM(int floorButtons[], int numFloors, int elevatorButtons[], int numElevatorButtons);
  void handleState();

private:
  void moveToFloor(int floor);
  void openDoors();
  void closeDoors();

  ElevatorState currentState;
  ElevatorState previousState;
  int* floorButtons;
  int numFloors;
  int currentFloor;
  int targetFloor;
  int* elevatorButtons;
  int numElevatorButtons;
};

#endif
