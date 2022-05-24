#include <iostream>
#include <string>
#include "interface/Login.h"
#include "DAO/AttributesDAO.h"

int main()
{
  cout << "	AIR WATCHER	\n";

  // INITIALIZATION
  AttributesDAO daoAttr = AttributesDAO();
  daoAttr.parseAttributes("csv/attributes.csv");
  // Test for AttributesDAO
  // for (Attribute a : attrList)
  // {
  // 	cout << "{id:" << a.getId();
  // 	cout << ", unit:" << a.getUnit();
  // 	cout << ", description:" << a.getDescription() << "}" << endl;
  // }
  // TODO: initialization for providers, etc..
  //
  //

  // LOGIN, get user type
  /*
    0: administrator
    1: Environment agent
    2: Cleaner
  */
  cout << "please login to continue..\n";
  Login userLogin = Login();
  int user_type = userLogin.check();

  // Functions the user can do according to user type
  string cmd, exit_yn;
  while (1)
  {
    cout << ">> ";
    cin >> cmd;

    if (cmd == "exit" || cmd == "quit")
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

  return 0;
}
