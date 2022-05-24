#include <algorithm>
#include <iostream>
#include "Login.h"
#include "../data/User.h"

#define ADMIN_ID "asdf"
#define ADMIN_PW "lyon"

using namespace std;

Login::Login()
{
  User *admin = new User(ADMIN_ID, ADMIN_ID, ADMIN_PW, 0);
  userList.push_back(admin);
}

/*
  Input: string id, string password
  Check given id, pw is in user list
  Return user type, return -1 if wrong
*/
int Login::check()
{
  int userType = -1;
  string login_id, login_pw;
  // [ administrator / provider / environment agent / cleaner ]

  while (1)
  {
    cout << "—- —- —- —- —- —- —-\n- login: ";
    cin >> login_id;
    cout << "- password: ";
    cin >> login_pw;
    if (login_id == "exit" || login_id == "quit")
      return -1;

    for (auto it : userList)
    {
      if (it->getLogin() == login_id && login_pw == "a")
      {
        userType = it->getType();
        break;
      }
    }
    if (userType == -1)
      cout << "Doesn't Exist. Try Again.\n";
    else
      break;
  }

  return userType;
}

void Login::add(string new_id, string new_pw, int new_type)
{
  User new_user = User(new_id, new_id, new_pw, new_type);
  userList.push_back(&new_user);
}