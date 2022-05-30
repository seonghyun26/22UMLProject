#ifndef PROVIDER_UI_H
#define PROVIDER_UI_H

#include "Interface.h"

class ProviderInterface : public Interface
{
protected:
public:
  ProviderInterface();
  bool executeFunction(int funcNum);
  bool provideCleaner();
  bool calculateCleanedArea();
  bool calculateImprovementAQ();
};

#endif