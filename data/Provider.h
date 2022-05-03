#ifndef PROVIDER_H
#define PROVIDER_H
#include "Cleaner.h"
#include <vector>

using namespace std;
class Provider : public User{
	procted:
		vector<Cleaner> cleaners;
	public:
		vector<Cleaner> getCleaners(){return cleaners;}
		void setCleaners(vector<Cleaner> cleaners){this->cleaners=cleaners;}
		void addCleaner(Cleaner *cleaner) { cleaner_list.push_back(cleaner); }
};
#endif
