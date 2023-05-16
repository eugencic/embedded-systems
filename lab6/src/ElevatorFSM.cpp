#include "ElevatorFSM.h"

ElevatorFSM::ElevatorFSM(int floorButtons[], int numFloors, int elevatorButtons[], int numElevatorButtons) 
{
  this->currentState = FLOOR_1;
  this->previousState = FLOOR_1;
  this->floorButtons = floorButtons;
  this->numFloors = numFloors;
  this->currentFloor = 1;
  this->targetFloor = 1;
  this->elevatorButtons = elevatorButtons;
  this->numElevatorButtons = numElevatorButtons;

  for (int i = 0; i < numFloors; i++) 
  {
    pinMode(floorButtons[i], INPUT_PULLUP);
  }

  for (int i = 0; i < numElevatorButtons; i++) 
  {
    pinMode(elevatorButtons[i], INPUT_PULLUP);
  }
}

void ElevatorFSM::handleState() 
{
  switch (currentState) 
  {
    case FLOOR_1:
    case FLOOR_2:
    case FLOOR_3:
    case FLOOR_4:
    case FLOOR_5:
    case FLOOR_6:
    case FLOOR_7:
    case FLOOR_8:
      for (int i = 0; i < numFloors; i++) 
      {
        if (digitalRead(floorButtons[i]) == LOW) 
        {
          analogWrite(22, 200);
          analogWrite(23, 0);
          targetFloor = i + 1;
          Serial.print("Current floor: ");
          Serial.print(currentFloor);
          Serial.print(" / Target floor: ");
          Serial.println(targetFloor);
          delay(2000);
          if (targetFloor == currentFloor) 
          {
            openDoors();
          }
          else 
          {
            moveToFloor(targetFloor);
          }
          break;
        }
      }

      for (int i = 0; i < numElevatorButtons; i++) 
      {
        if (digitalRead(elevatorButtons[i]) == LOW) 
        {
          analogWrite(22, 200);
          analogWrite(23, 0);
          targetFloor = i + 1;
          Serial.print("Current floor: ");
          Serial.print(currentFloor);
          Serial.print(" / Target floor (inside elevator): ");
          Serial.println(targetFloor);
          delay(2000);
          if (targetFloor == currentFloor) 
          {
            Serial.println("Already here");
          }
          else 
          {
            closeDoors();
            moveToFloor(targetFloor);
          }
          break;
        }
      }
    break;
  }
}

void ElevatorFSM::moveToFloor(int floor) 
{
  if (floor < 1 || floor > numFloors) 
  {
    return;
  }

  previousState = currentState;
  int direction = (floor > currentFloor) ? 1 : -1;

  while (currentFloor != floor) 
  {
    currentFloor += direction;

    if (currentFloor < 1 || currentFloor > numFloors) 
    {
      return;
    }

    currentState = static_cast<ElevatorState>(currentFloor - 1);

    if (direction == 1) 
    {
      Serial.print("The elevator is moving upward to floor ");
      Serial.println(currentFloor);
      delay(2000);
    } 
    else 
    {
      Serial.print("The elevator is moving downward to floor ");
      Serial.println(currentFloor);
      delay(2000);
    }
  }

  Serial.print("The elevator has arrived at floor ");
  Serial.println(currentFloor);
  
  analogWrite(22, 0);
  analogWrite(23, 0);
}

void ElevatorFSM::openDoors() 
{
  Serial.println("Doors are opening");
  analogWrite(22, 200);
  analogWrite(23, 0);
  delay(2000);
  analogWrite(22, 0);
  analogWrite(23, 0);
}

void ElevatorFSM::closeDoors() 
{
  Serial.println("Doors are closing");
  analogWrite(22, 200);
  analogWrite(23, 0);
  delay(2000);
  analogWrite(22, 0);
  analogWrite(23, 0);
}
