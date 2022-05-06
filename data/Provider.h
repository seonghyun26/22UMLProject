#ifndef PROVIDER_H
#define PROVIDER_H

#include <string>
#include <vector>
class Cleaner;
#include "Cleaner.h"
#include "User.h"

using namespace std;
class Provider : public User
{
protected:
  vector<Cleaner *> cleaner_list;

public:
	Provider(string id, string login, string password);
  vector<Cleaner *> getCleaners() ;
  void addCleaner(Cleaner *cleaner) ;
};

#endif
