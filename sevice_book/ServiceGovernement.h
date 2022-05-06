#ifndef SERVICEGOVERNEMENT_H
#define SERVICEGOVERNEMENT_H
using namespace std;
#include "../data/Sensor.h"
#include "../data/User.h"
class ServiceGovernement{
public:
	int calc_airQualityMean(long latitude, long longitude, long diameter, struct tm time, long duration/*hour*/ );
	int calc_airQualityAtPosition(long latitude, long longitude, struct tm time);
	vector<pair<Sensor,int>> rankSensor(Sensor s); // rank sensor in comparaison of this one
	Sensor flag_as_ureliable(User u);
	Sensor unflag(User u);
};
#endif
