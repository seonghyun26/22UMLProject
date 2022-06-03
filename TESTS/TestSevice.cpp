#include <iostream>
#include <vector>

#include "TestSevice.h"
#include "../data/Cleaner.h"
#include "../sevice_book/ServiceCleaners.h"
#include "../interface/ProviderInterface.h"

extern vector<Cleaner> cleanerList;
extern vector<Sensor> sensorList;

using namespace std;

void testAllService()
{
  testServiceCleaners();
}

/*
  Functions in SertviceCleaners
  1. Calculate Raidus Cleaned Area
  2. Calulate Improvment AQ
*/
void testServiceCleaners()
{
  ServiceCleaners *serviceCleaner = new ServiceCleaners();
  Cleaner *cleanerTest = &(cleanerList[0]);

  // 1. Calculate Raidus Cleaned Area
  cout << "--- Testing Service Cleaners function - radiusCleaneadArea() ---\n";
  cout << "Using the first cleaner in the Cleaner List...\n";
  double radiusCleanedArea = serviceCleaner->calcRadiusCleanedArea(cleanerTest, sensorList);
  cout << "=> Radius of Cleaned Area: " << radiusCleanedArea << "\n";
  cout << "--- Testing Service Cleaners function - radiusCleaneadArea() ---\n\n";

  // 2. Calulate Improvment AQ
  cout << "--- Testing Service Cleaners function - calculateImprovementAQ() ---\n";
  cout << "Using the Date of the first cleaner in the Cleaner List...\n";
  double latitude = cleanerTest->getLatitude();
  double longitude = cleanerTest->getLongitude();
  struct tm startTM = cleanerTest->getStartTM();
  struct tm endTM = cleanerTest->getEndTM();
  double improvementAQ = serviceCleaner->calcImprovementAirQuality(latitude, longitude, startTM, endTM, sensorList);
  cout << " Improvment : " << improvementAQ << "\n";

  cout << "--- Testing Service Cleaners function - calculateImprovementAQ() ---\n\n";
}