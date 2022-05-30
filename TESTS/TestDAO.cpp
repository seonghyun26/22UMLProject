#include <iostream>
#include "TestDAO.h"
#include "../DAO/AttributesDAO.h"
#include "../DAO/ProviderDAO.h"


void testAllDAO()
{
	testAttributesDAO();
	testProviderDAO();
}
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
void testProviderDAO()
{
	ProviderDAO daoProv= ProviderDAO();
	daoProv.parseProviderAndCleaner("csv/providers.csv","csv/cleaners.csv");
	for(Provider p : providerList)
	{
		cout << "{id:"<< p.getId();
		cout << ", login:"<<p.getLogin();
		cout << ", password:"<<p.getPassword();
		cout << ", cleaners:[" <<endl;
		for(Cleaner *c : p.getCleaners()){
			cout << "  {id:"<<c->getId();
			cout << ", start:"<<(c->getStartTM().tm_hour)<<":"<<(c->getStartTM().tm_min);
			cout << ", end:"<<(c->getEndTM().tm_hour)<<":"<<(c->getEndTM().tm_min);
			cout << ", lat:"<<c->getLatitude();
			cout << ", long:"<<c->getLongitude();
			cout << "}"<<endl;
		}
		cout << "}" <<endl;
	}
}
