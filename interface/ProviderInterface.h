#ifndef PROVIDER_UI_H
#define PROVIDER_UI_H

#include "Interface.h"

using namespace std;

class ProviderInterface : public Interface
{
protected:
public:
  ProviderInterface();
  bool executeFunction(int funcNum);
  bool provideSensor();
};

#endif