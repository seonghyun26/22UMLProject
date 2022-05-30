#include "Provider.h"

Provider::Provider(string id, string login, string password) : User(id, login, password, 0)
{
  this->cleaner_list = vector<Cleaner *>();
  type = 1;
}
vector<Cleaner *> Provider::getCleaners() { return cleaner_list; }

bool Provider::addCleaner(Cleaner *cleaner)
{
  cleaner_list.push_back(cleaner);
  cleaner->setProvider(this);
  return true;
}
