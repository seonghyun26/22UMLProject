#include <fstream>

#include "AttributesDAO.h"
#include "../Attribute.h"

void AttributesDAO::parseAttributes(string path){
	fstream fs;
	attrList=new vector<Attribute>();
	char forgot[256];
	char id[32];
	char unit[32];
	fs.open (path, fstream::in);
	fs.getline(forgot,256);
	while(!fs.eof()){
		fs.getline(id,32,';');
		fs.getline(unit,32,';');
		fs.getline(description,128,';');
		attrList.push_back(new Attribute(id,unit,description));
		fs.getline(forgot,256);
	}
	fs.close();
}
