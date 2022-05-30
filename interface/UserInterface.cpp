#include <iostream>

#include "UserInterface.h"

using namespace std;

UserInterface::UserInterface() : Interface()
{
  userType = "User";
  functionNameList = {"Provide Sensor", "Give Reward"};
}

bool UserInterface::executeFunction(int funcNum)
{
  bool funcResult = true;

  switch (funcNum)
  {
  case 0:
    funcResult = provideSensor();
    break;
  case 1:
    funcResult = giveReward();
    break;
  default:
    funcResult = false;
  }

  return funcResult;
}

bool UserInterface::provideSensor()
{
  return false;
}

bool UserInterface::giveReward()
{
  return false;
}