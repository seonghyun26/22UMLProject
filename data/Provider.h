#ifndef PROVIDER_H
#define PROVIDER_H
#include "Cleaner.h"
#include <vector>
class Provider : public User{
	procted:
		vector<Cleaner> cleaners;
	public:
		vector<Cleaner> getCleaners(){return cleaners;}
		void setCleaners(vector<Cleaner> cleaners){this->cleaners=cleaners;}
};
#endif
