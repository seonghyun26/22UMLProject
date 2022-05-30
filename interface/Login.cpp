#include <algorithm>
#include <iostream>
#include "Login.h"
#include "../data/User.h"
#include "../data/Provider.h"
#include "../data/Cleaner.h"
#include "ProviderInterface.h"

#define ADMIN_ID "asdf"
#define PROV_ID "prov"
#define SIMPLEUSER_ID "sim"
#define GOV_ID "gov"
#define PW "lyon"

using namespace std;

Login::Login()
{
  User *admin = new User(ADMIN_ID, ADMIN_ID, PW, 0);
  userList.push_back(admin);
  User *provider = new User(PROV_ID, PROV_ID, PW, 1);
  userList.push_back(provider);
  User *simpleUser = new User(SIMPLEUSER_ID, SIMPLEUSER_ID, PW, 2);
  userList.push_back(simpleUser);
  User *gov = new User(GOV_ID, GOV_ID, PW, 3);
  userList.push_back(gov);
}

/*
  Input: string id, string password
  Check given id, pw is in user list
  Return user type, return -1 if wrong
*/
void Login::check()
{
  cout << "please login to continue..\n";

  int userType = -1;
  string login_id, login_pw;

  while (1)
  {
    cout << "—- —- —- —- —- —- —-\n- login or exit(quit): ";
    cin >> login_id;
    if (login_id == "exit" || login_id == "quit")
      break;

    cout << "- password: ";
    cin >> login_pw;

    userType = -1;
    for (auto it : userList)
    {
      if (it->getLogin() == login_id && login_pw == "a")
      {
        userType = it->getType();
        break;
      }
    }

    if (userType >= 0 && userType <= 3)
      menu(userType);
    else
      cout << " User Doesn't Exist..\n";
  }
}

void Login::menu(int userType)
{
  string cmd;
  int funcNum;
  bool funcResult;

  switch (userType)
  {
  case 0:
    break;
  case 1:
    UI = &ProviderUI;
    break;
  case 2:
    break;
  case 3:
    break;
  }

  while (1)
  {
    UI->printUserType();
    cout << ">> ";
    cin >> cmd;

    if (cmd == "exit" || cmd == "quit" || cmd == "q")
      break;

    else if (cmd == "help" || cmd == "h")
    {
      cout << "help, h        Information about available commands\n";
      cout << "func, f        Execute a function\n";
      cout << "exit, quit, q  Quit Program\n";
    }

    else if (cmd == "func" || cmd == "f")
    {
      funcNum = UI->chooseFunction();
      if (funcNum == -1)
      {
        cout << "Invalid Function Number\n";
        continue;
      }
      funcResult = UI->executeFunction(funcNum);
      cout << "Function execution " << (funcResult ? "Succeed" : "Failed") << "\n";
    }
    else
      cout << "Invalid Command\nType “help” or 'h' to see what you can do!\n";
  }
}

void Login::addUser(string new_id, string new_pw, int new_type)
{
  User new_user = User(new_id, new_id, new_pw, new_type);
  userList.push_back(&new_user);
}