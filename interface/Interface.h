#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include <vector>

using namespace std;

typedef bool (*funcPtr)();

class Interface
{
protected:
  string userType;
  vector<string> functionNameList = {};

public:
  Interface();
  void printUserType();
  vector<string> getFunctionList() { return functionNameList; }
  void printFunctionList();
  int chooseFunction();
  virtual bool executeFunction(int funcNum) = 0;
};

#endif
