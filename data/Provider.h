#ifndef PROVIDER_H
#define PROVIDER_H

using namespace std;

#include <vector>
#include "Cleaner.h"
#include "User.h"

class Provider : public User
{
protected:
  vector<Cleaner *> cleaner_list;

public:
  void addCleaner(Cleaner *cleaner) { cleaner_list.push_back(cleaner); }

  vector<Cleaner *> getCleanerList() { return cleaner_list; }
};

#endif