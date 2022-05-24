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
  currentUserLogin = "asdf";
  currentUserType = 0;

  // TODO: not now..
  // adminFunction.insert(adminFunction.begin(), providerFunction.begin(), providerFunction.end());
  // adminFunction.insert(adminFunction.end(), cleanerFunction.begin(), cleanerFunction.end());
  // adminFunction.insert(adminFunction.end(), govFunction.begin(), govFunction.end());
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
  string cmd;
  int funcNum;

  while (1)
  {
    cout << "\nYou are [ " << userTypeDic[userType] << " ]\n";
    cout << ">> ";
    cin >> cmd;

    if (cmd == "exit" || cmd == "quit" || cmd == "q")
    {
      break;
      // cout << "Do you really want to exit Air Watcher? (y/n) ";
      // cin >> exit_yn;
      // if (exit_yn == "y")
      // {
      //   cout << "Thank you\n";
      //   break;
      // }
      // else if (exit_yn == "n")
      //   continue;
      // else
      //   cout << "Invalid Input. Returning to Menu\n";
    }
    else if (cmd == "help" || cmd == "h")
    {
      printFunctionList(userType);
      cout << " Type 'func' of 'f' to use one\n";
    }
    else if (cmd == "func" || cmd == "f")
    {
      printFunctionList(userType);
      cout << "Function you want to execute: ";
      cin >> funcNum;
      executeUserFunction(userType, funcNum);
    }
    else
    {
      cout << "Invalid Command\n";
      cout << "Type “help” for a list of available command\n";
    }
  }
}

void Login::addUser(string new_id, string new_pw, int new_type)
{
  User new_user = User(new_id, new_id, new_pw, new_type);
  userList.push_back(&new_user);
}

void Login::printFunctionList(int userType)
{
  cout << " List of functions you can use: \n";
  for (int i = 0; i < functionList[userType].size(); i++)
  {
    cout << " - " << i << ": " << functionList[userType][i] << "\n";
  }
}

void Login::executeUserFunction(int userType, int funcNum)
{
  int size = functionList[userType].size();
  if (funcNum < 0 || funcNum >= size)
  {
    cout << "Invalid Function Number\n";
    return;
  }

  // Map function number with class methods in data/User,GovAgent, ...
  switch (userType)
  {
  // ADMIN
  case 0:
    break;

  // Provider
  case 1:
    break;

  // Cleaner
  case 2:
    break;

  // Government Agent
  case 3:
    break;

  default:
    break;
  }

  return;
}
