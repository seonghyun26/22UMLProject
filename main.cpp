#include <iostream>
#include <string>
#include "interface/Login.h"
#include "DAO/AttributesDAO.h"
#include "DAO/ProviderDAO.h"
#include "TESTS/TestDAO.h"
#include "TESTS/TestSevice.h"

#include "./data/Sensor.h"
//vector<Sensor *> sensorList;

int main()
{
  cout << "	AIR WATCHER	\n";

  // TEST
  testAllDAO();
  testAllService();
  // INITIALIZATION
  AttributesDAO daoAttr = AttributesDAO();
  daoAttr.parseAttributesMeasurementSensorAndUser("csv/attributes.csv","csv/measurement.csv","csv/sensors.csv","csv/users.csv");
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
