#include <fstream>
#include <cstring>
#include "AttributesDAO.h"
vector<Attribute> attrList=vector<Attribute>();

void AttributesDAO::parseAttributes(string path){
	fstream fs;
	attrList=vector<Attribute>();
	char forgot[256];
	char id[32];
	char unit[32];
	char description[256];
	fs.open (path, fstream::in);
	fs.getline(forgot,256);
	// hacky solution but works for now
	while(fs.getline(id,32,';') || strlen(id)!=0){
		fs.getline(unit,32,';');
		fs.getline(description,128,';');
		attrList.push_back(Attribute(id,unit,description));
		fs.getline(forgot,256);
	}
	fs.close();
}
