#include <iostream>
#include "TestDAO.h"
#include "../DAO/AttributesDAO.h"


void testAllDAO(){}
void testAttributesDAO()
{
  AttributesDAO daoAttr = AttributesDAO();
  daoAttr.parseAttributes("csv/attributes.csv");
  for (Attribute a : attrList)
  {
  	cout << "{id:" << a.getId();
  	cout << ", unit:" << a.getUnit();
  	cout << ", description:" << a.getDescription() << "}" << endl;
  }

}
