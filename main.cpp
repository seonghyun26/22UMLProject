#include <iostream>
#include "DAO/AttributesDAO.h"

int main(){
	AttributesDAO daoAttr=AttributesDAO();
	daoAttr.parseAttributes("csv/attributes.csv");
	for(Attribute a: attrList){
		cout << "{id:" << a.getId();
		cout << ", unit:" << a.getUnit();
		cout << ", description:" << a.getDescription() << "}" <<endl;
	}
}
