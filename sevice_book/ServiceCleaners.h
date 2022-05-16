#ifndef SERVICECLEANERS_H
#define SERVICECLEANERS_H

#include "../data/Cleaner.h"

class ServiceCleaners
{
public:
  void provideCleaner(Provider *p, Cleaner *c);
  long calcRadiusCleanedArea(Cleaner *c, vector<Sensor *> sensor_list);
  double calcImprovementAirQuality(long latitude, long longitude);
};

#endif
