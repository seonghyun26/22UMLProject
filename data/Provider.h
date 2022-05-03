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
	vector<Cleaner *> getCleaners() { return cleaner_list; }
	void addCleaner(Cleaner *cleaner) { cleaner_list.push_back(cleaner); }
};
#endif
