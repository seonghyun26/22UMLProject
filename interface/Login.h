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
  void add(string new_id, string new_pw, int new_type);

protected:
  vector<User *> userList;
};

#endif
