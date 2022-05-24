#include <algorithm>
#include <iostream>
#include "Login.h"
#include "../data/User.h"

#define ADMIN_ID "asdf"
#define PROV_ID "prov"
#define SIMPLEUSER_ID "sim"
#define GOV_ID "gov"
#define PW "lyon"

using namespace std;

string userTypeDic[4] = {
    "Administrator",
    "Provider",
    "User",
    "Government Agent",
};

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

    if (userType == -1)
    {
      cout << "Doesn't Exist. Try Again.\n";
      continue;
    }
    else
      menu(userType);
  }
}

void Login::menu(int userType)
{
  string cmd, exit_yn;
  while (1)
  {
    cout << "\nYou are [ " << userTypeDic[userType] << " ]\n";
    cout << ">> ";
    cin >> cmd;

    if (cmd == "exit" || cmd == "quit" || cmd == "q")
    {
      cout << "Do you really want to exit Air Watcher? (y/n) ";
      cin >> exit_yn;
      if (exit_yn == "y")
      {
        cout << "Thank you\n";
        break;
      }
      else if (exit_yn == "n")
        continue;
      else
        cout << "Invalid Input. Returning to Menu\n";
    }
    else if (cmd == "help")
    {
    }
    else if (cmd == "")
    {
    }
    else if (cmd == "")
    {
    }
    else if (cmd == "")
    {
    }
    else
    {
      cout << "Invalid Command\n";
      cout << "Type “help” for a list of available command\n";
    }
  }
}

void Login::add(string new_id, string new_pw, int new_type)
{
  User new_user = User(new_id, new_id, new_pw, new_type);
  userList.push_back(&new_user);
}