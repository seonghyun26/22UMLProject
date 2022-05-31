#include <iostream>
#include <string>
#include <iomanip>
#include "ProviderInterface.h"
#include "../data/Provider.h"
#include "../data/Cleaner.h"
#include "../sevice_book/ServiceCleaners.h"

using namespace std;

extern vector<Provider> providerList;
extern vector<Cleaner> cleanerList;
extern vector<Sensor *> sensorList;

ProviderInterface::ProviderInterface() : Interface()
{
  userType = "Provider";
  functionNameList = {"Provide Cleaner", "Calculate Cleaned Area", "Calculate Improvement Air Quality"};
  serviceCleaner = new ServiceCleaners();
}

bool ProviderInterface::executeFunction(int funcNum)
{
  bool funcResult = true;

  switch (funcNum)
  {
  case 0:
    funcResult = provideCleaner();
    break;
  case 1:
    funcResult = calculateCleanedArea();
    break;
  case 2:
    funcResult = calculateImprovementAQ();
    break;
  default:
    funcResult = false;
  }

  return funcResult;
}

Provider *ProviderInterface::selectProvider()
{
  int providerNum;

  if (providerList.size() == 0)
  {
    cout << "No Providers Exist\n";
    return NULL;
  }

  cout << "List of Providers\n";
  cout << "-- -- -- -- -- -- --\n";
  for (int i = 0; i < providerList.size(); i++)
    cout << "- " << i << ": " << providerList[i].getId() << ", " << providerList[i].getCleaners().size() << " cleaners\n";
  cout << "-- -- -- -- -- -- --\n";
  cout << "Type Provider Number: ";
  cin >> providerNum;

  if (providerNum < 0 || providerNum > providerList.size())
  {
    cout << "Invalid Input!\n";
    return NULL;
  }

  return &(providerList[providerNum]);
}

Cleaner *ProviderInterface::selectCleaner()
{
  int cleanerNum;

  if (cleanerList.size() == 0)
  {
    cout << "No Providers Exist\n";
    return NULL;
  }

  cout << "List of Cleaners\n";
  cout << "-- -- -- -- -- -- --\n";
  for (int i = 0; i < cleanerList.size(); i++)
    cout << "- " << i << ": " << cleanerList[i].getId() << " ( lat: " << cleanerList[i].getLatitude() << ", long: " << cleanerList[i].getLongitude() << " )\n";
  cout << "-- -- -- -- -- -- --\n";
  cout << "Type Cleaner Number: ";
  cin >> cleanerNum;

  if (cleanerNum < 0 || cleanerNum >= cleanerList.size())
  {
    cout << "Invalid Input!\n";
    return NULL;
  }
  return &(cleanerList[cleanerNum]);
}

void ProviderInterface::strToTM(string *str, struct tm *tm)
{
}

bool ProviderInterface::provideCleaner()
{
  // Choose provider, cleaner
  Provider *provider = selectProvider();
  if (provider == NULL)
    return false;
  Cleaner *cleaner = selectCleaner();
  if (cleaner == NULL)
    return false;

  return serviceCleaner->provideCleaner(provider, cleaner);
}

bool ProviderInterface::calculateCleanedArea()
{
  // Choose Cleaner
  Cleaner *cleaner = selectCleaner();
  if (cleaner == NULL)
    return false;
  // cout << "FLAG\n";

  double radiusCleanedArea = serviceCleaner->calcRadiusCleanedArea(cleaner, sensorList);
  cout << "=> Radius of Cleaned Area: " << radiusCleanedArea << "\n";
  return radiusCleanedArea < 0 ? false : true;
}

bool ProviderInterface::calculateImprovementAQ()
{
  double latitude, longitude;
  struct tm startTM, endTM;

  cout << "> Latitude: ";
  cin >> latitude;
  cout << "> Longitude: ";
  cin >> longitude;
  cout << "> Start TM(YYYY-MM-DD HH:MM:SS): ";
  cin >> std::get_time(&startTM, "%Y-%m-%d %H:%M:%S");
  cout << "> End TM(YYYY-MM-DD HH:MM:SS): ";
  cin >> std::get_time(&endTM, "%Y-%m-%d %H:%M:%S");

  if (sensorList.size() == 0)
  {
    cout << "No Sensors in List\n";
    return false;
  }

  vector<pair<string, double>> result = serviceCleaner->calcImprovementAirQuality(
      latitude, longitude,
      startTM, endTM,
      sensorList);

  for (auto it : result)
  {
    cout << "Attribute " << it.first << " Improvment : " << it.second << "\n";
  }

  return false;
}
