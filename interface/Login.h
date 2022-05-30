#ifndef LOGIN_H
#define LOGIN_H

#include <string>
#include <vector>
#include "../data/User.h"
#include "./Interface.h"
#include "./ProviderInterface.h"
#include "./UserInterface.h"

using namespace std;

class Login
{
protected:
  vector<User *> userList;
  Interface *UI;
  ProviderInterface ProviderUI;
  UserInterface UserUI;
  // GovAgentInterface GovAgentUI;

public:
  Login();
  void check();
  void menu(int userType);
  void addUser(string new_id, string new_pw, int new_type);
};

#endif
