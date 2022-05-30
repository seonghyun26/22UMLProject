#ifndef USER_UI_H
#define USER_UI_H

#include "Interface.h"

class UserInterface : public Interface
{
protected:
public:
  UserInterface();
  bool executeFunction(int funcNum);
  bool provideSensor();
  bool giveReward();
};

#endif