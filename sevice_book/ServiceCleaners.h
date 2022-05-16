#ifndef SERVICECLEANERS_H
#define SERVICECLEANERS_H

#include "../data/Cleaner.h"
#include <vector>

class ServiceCleaners
{
public:
  void provideCleaner(Provider *p, Cleaner *c);
  double calcRadiusCleanedArea(Cleaner *c, vector<Sensor *> sensor_list);
  vector<pair<string, double>> calcImprovementAirQuality(double latitude, double longitude, struct tm *startTM, struct tm *endTM, vector<Sensor *> sensor_list);
};

#endif
