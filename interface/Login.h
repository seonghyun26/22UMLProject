#ifndef LOGIN_H
#define LOGIN_H

#include <string>
#include <vector>
#include "../data/User.h"
using namespace std;

class Login
{
public:
  Login();
  void check();
  void menu(int userType);
  void addUser(string new_id, string new_pw, int new_type);
  void printFunctionList(int userType);
  void executeUserFunction(int userType, int funcNum);

protected:
  vector<User *> userList;
  string currentUserLogin;
  int currentUserType;
  string userTypeDic[4] = {
      "Administrator",
      "Provider",
      "User",
      "Government Agent",
  };
  vector<string> providerFunction = {"Provide Sensor", "Give Reward"};
  vector<string> cleanerFunction = {"Provide Cleaner", "Calculate Cleaned Area", "Calculate Improvement Air Quality"};
  vector<string> govFunction = {"Calculate Air Quality Mean", "Calculate Air Quality At Position", "Rank Sensor",
                                "Analyze Data Sensor", "Flag Unreliable", "Unflag", "Erase Data Unreliable Sensor"};
  vector<string> adminFunction = {};
  vector<vector<string>> functionList = {adminFunction, providerFunction, cleanerFunction, govFunction};
};

#endif
