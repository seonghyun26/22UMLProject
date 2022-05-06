#ifndef SERVICEGOVERNEMENT_H
#define SERVICEGOVERNEMENT_H
#include "Sensor.h"
class ServiceGovernement{
public:
	int calc_airQualityMean(long latitude, long longitude, long diameter, Date time, long duration/*hour*/ );
	int calc_airQualityAtPosition(long latitude, long longitude, Date time);
	vector<pair<Sensor,int>> rankSensor(Sensor s); // rank sensor in comparaison of this one
	Sensor flag_as_ureliable(User u);
	Sensor unflag(User u);
}
#endif
