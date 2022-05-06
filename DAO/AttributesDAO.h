#ifndef ATTRIBUTESDAO_H
#define ATTRIBUTESDAO_H

#include <vector>
#include <string>
#include "../data/Attribute.h"
using namespace std;

extern vector<Attribute> attrList;

class AttributesDAO{
	public:
		void parseAttributes(string path);
};


#endif
