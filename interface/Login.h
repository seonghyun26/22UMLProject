#ifndef LOGIN_H
#define LOGIN_H

#include <string>
#include <vector>
#include "../data/User.h"
#include "./Interface.h"
#include "./ProviderInterface.h"

using namespace std;

class Login
{
protected:
  vector<User *> userList;
  Interface *UI;
  // UserInterface UserUI;
  // GovAgentInterface GovAgentUI;
  ProviderInterface ProviderUI;
  // vector<string> cleanerFunction = {"Provide Cleaner", "Calculate Cleaned Area", "Calculate Improvement Air Quality"};
  // vector<string> govFunction = {"Calculate Air Quality Mean", "Calculate Air Quality At Position", "Rank Sensor",
  //                               "Analyze Data Sensor", "Flag Unreliable", "Unflag", "Erase Data Unreliable Sensor"};

public:
  Login();
  void check();
  void menu(int userType);
  void addUser(string new_id, string new_pw, int new_type);
};

#endif
