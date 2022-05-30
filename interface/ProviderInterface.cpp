#include <iostream>
#include "ProviderInterface.h"
#include "../data/Provider.h"
#include "../data/Cleaner.h"

using namespace std;

extern vector<Provider> providerList;
extern vector<Cleaner> cleanerList;

ProviderInterface::ProviderInterface() : Interface()
{
  userType = "Provider";
  functionNameList = {"Provide Cleaner", "Calculate Cleaned Area", "Calculate Improvement Air Quality"};
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

bool ProviderInterface::provideCleaner()
{
  int providerNum, cleanerNum;

  // Choose provider, cleaner from list
  if (providerList.size() == 0)
  {
    cout << "No Providers Exist\n";
    return false;
  }
  cout << "List of Providers\n";
  cout << "-- -- -- -- -- -- --\n";
  for (int i = 0; i < providerList.size(); i++)
    cout << "- " << i << ": " << providerList[i].getId() << "\n";
  cout << "-- -- -- -- -- -- --\n";
  cout << "Type Provider Number: ";
  cin >> providerNum;
  if (providerNum < 0 || providerNum > providerList.size())
  {
    cout << "Invalid Input!\n";
    return false;
  }
  Provider *provider = &(providerList[providerNum]);

  if (cleanerList.size() == 0)
  {
    cout << "No Providers Exist\n";
    return false;
  }
  cout << "List of Cleaners\n";
  cout << "-- -- -- -- -- -- --\n";
  for (int i = 0; i < cleanerList.size(); i++)
    cout << "- " << i << ": " << cleanerList[i].getId() << "\n";
  cout << "-- -- -- -- -- -- --\n";
  cout << "Type Cleaner Number: ";
  cin >> cleanerNum;
  if (cleanerNum < 0 || cleanerNum >= cleanerList.size())
  {
    cout << "Invalid Input!\n";
    return false;
  }
  Cleaner *cleaner = &(cleanerList[cleanerNum]);

  return provider->addCleaner(cleaner);
}

bool ProviderInterface::calculateCleanedArea()
{
  return false;
}

bool ProviderInterface::calculateImprovementAQ()
{
  return false;
}
