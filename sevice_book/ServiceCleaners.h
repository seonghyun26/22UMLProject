#ifndef SERVICECLEANERS_H
#define SERVICECLEANERS_H

#include "../data/Cleaner.h"

class ServiceCleaners
{
public:
  void provide_cleaner(Provider *p, Cleaner *c);
  long calc_radius_cleaned_area(Cleaner *c, vector<Sensor *> sensor_list);
  double calc_improvement_airQuality(long latitude, long longitude);
};

#endif
