#ifndef ATTRIBUTESDAO_H
#define ATTRIBUTESDAO_H

#include <vector>
#include <string>
using namespace std;

class AttributesDAO{
	public:
		void parseAttributes(string path);
}

vector<Attribute> * attrList;

#endif
