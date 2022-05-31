#ifndef PROVIDER_UI_H
#define PROVIDER_UI_H

#include "Interface.h"
#include "../sevice_book/ServiceCleaners.h"

class ProviderInterface : public Interface
{
protected:
  ServiceCleaners *serviceCleaner;

public:
  ProviderInterface();
  bool executeFunction(int funcNum);
  Provider *selectProvider();
  Cleaner *selectCleaner();
  bool provideCleaner();
  bool calculateCleanedArea();
  bool calculateImprovementAQ();
};

#endif