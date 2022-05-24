#ifndef PROVIDERDAO_H
#define PROVIDERDAO_H

#include <vector>
#include <string>
#include "../data/Provider.h"
#include "../data/Cleaner.h"
using namespace std;

extern vector<Provider> providerList;
extern vector<Cleaner> cleanerList;

class ProviderDAO{
	public:
		void parseProviderAndCleaner(string providersPath, string cleanersPath);
};


#endif
