#include <ctime>
#include "ServiceCleaners.h"
#include "../data/Sensor.h"

void ServiceCleaners::provide_cleaner(Provider *p, Cleaner *c)
{
  p->addCleaner(c);
  c->setProvider(p);
}

// Needs the whole sensor* vecotr list as input
long ServiceCleaners::calc_radius_cleaned_area(Cleaner *c)
{
  // Return Radiues cleaned by cleaners
  struct tm *startTM = c->getStartTM();
  struct tm *endTM = c->getEndTM();
  int latitude = c->getLatitude();
  int longitude = c->getLongitude();
  vector<Sensor *> sensor_list_by_distance;

  // Sort the sensors by distance from cleaner

  // Get the measurements of sensor and see if air is cleaned
  // by comparing before & after the cleaner activation
}

double ServiceCleaners::calc_improvement_airQuality(long latitude, long longitude)
{
}
