#include <iostream>
#include "GovAgentInterface.h"

using namespace std;

GovAgentInterface::GovAgentInterface() : Interface()
{
  userType = "Government Agent";
  functionNameList = {
      "Calculate Air Quality Mean",
      "Calculate Air Quality At Position",
      "Rank Sensor",
      "Analyze Data Sensor",
      "Flag Unreliable",
      "Unflag",
      "Erase Data Unreliable Sensor"};
}

bool GovAgentInterface::executeFunction(int funcNum)
{
  bool funcResult = true;

  switch (funcNum)
  {
  case 0:
    funcResult = calculateAQMean();
    break;
  case 1:
    funcResult = calculateAQatPosition();
    break;
  case 2:
    funcResult = rankSensor();
    break;
  case 3:
    funcResult = analyzeDataSensor();
    break;
  case 4:
    funcResult = flagUnreliable();
    break;
  case 5:
    funcResult = Unflag();
    break;
  case 6:
    funcResult = eraseDataUnreliableSensor();
    break;
  default:
    funcResult = false;
  }

  return funcResult;
}

bool GovAgentInterface::calculateAQMean()
{
  return false;
}

bool GovAgentInterface::calculateAQatPosition()
{
  return false;
}

bool GovAgentInterface::rankSensor()
{
  return false;
}

bool GovAgentInterface::analyzeDataSensor()
{
  return false;
}

bool GovAgentInterface::flagUnreliable()
{
  return false;
}

bool GovAgentInterface::Unflag()
{
  return false;
}

bool GovAgentInterface::eraseDataUnreliableSensor()
{
  return false;
}