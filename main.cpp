#include <iostream>
#include <string>
#include "interface/Login.h"
#include "DAO/AttributesDAO.h"
#include "DAO/ProviderDAO.h"

int main()
{
  cout << "	AIR WATCHER	\n";

  // INITIALIZATION
  AttributesDAO daoAttr = AttributesDAO();
  daoAttr.parseAttributes("csv/attributes.csv");
  ProviderDAO daoProv = ProviderDAO();
  daoProv.parseProviderAndCleaner("csv/providers.csv", "csv/cleaners.csv");
  // TODO: initialization for other things ex) Sensor,  etc..
  //
  //

  // LOGIN
  Login userLogin = Login();
  userLogin.check();

  return 0;
}
