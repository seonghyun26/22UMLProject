#include <iostream>
#include <string>

#include "Interface.h"

Interface::Interface(){};

void Interface::printUserType()
{
  cout << "\nYou are [ " << userType << " ]\n";
}

void Interface::printFunctionList()
{
  cout << " List of functions you can use: \n";
  for (int i = 0; i < functionNameList.size(); i++)
  {
    cout << " - " << i << ": " << functionNameList[i] << "\n";
  }
}

int Interface::chooseFunction()
{
  int funcNum;
  bool funcResult;

  printFunctionList();
  cout << "Function you want to execute: ";
  cin >> funcNum;
  if (funcNum < 0 || funcNum >= functionNameList.size())
    return -1;

  return funcNum;
}