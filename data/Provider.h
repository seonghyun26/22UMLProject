#ifndef PROVIDER_H
#define PROVIDER_H

#include <vector>
#include "Cleaner.h"
#include "User.h"

using namespace std;
class Provider : public User
{
protected:
  vector<Cleaner *> cleaner_list;

public:
	Provider();
  vector<Cleaner *> getCleaners() ;
  void addCleaner(Cleaner *cleaner) ;
};

#endif
