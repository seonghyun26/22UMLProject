#ifndef ATTRIBUTESDAO_H
#define ATTRIBUTESDAO_H

#include <vector>
#include <string>
#include "../data/Attribute.h"
#include "../data/Measurement.h"
#include "../data/Sensor.h"
#include "../data/SimpleUser.h"

using namespace std;

extern vector<Attribute> attrList;
extern vector<Measurement> measurementList;
extern vector<Sensor> sensorList;
extern vector<SimpleUser> userList;

class AttributesDAO{
	public:
		void parseAttributesMeasurementSensorAndUser(
				string attributesPath,
				string measurementsPath,
				string sensorsPath,
				string usersPath
			);
};


#endif
