#include <ctime>
#include <algorithm>
#include <string>
#include "ServiceCleaners.h"
#include "../data/Sensor.h"
#include "../data/Measurement.h"
#include "../data/Attribute.h"

void ServiceCleaners::provide_cleaner(Provider *p, Cleaner *c)
{
  p->addCleaner(c);
  c->setProvider(p);
}

bool cmpSensor(Sensor *a, Sensor *b)
{
  return a->getDistanceFromCleaner() > b->getDistanceFromCleaner();
}

bool cmpMeasurementByTM(Measurement *a, Measurement *b)
{
  return mktime(a->getTimestamp()) > mktime(b->getTimestamp());
}

// Return Radius cleaned by cleaners
// Needs the whole sensor* vector list as input
long ServiceCleaners::calc_radius_cleaned_area(Cleaner *c, vector<Sensor *> sensor_list)
{
  struct tm *startTM = c->getStartTM();
  struct tm *endTM = c->getEndTM();
  double latitude = c->getLatitude();
  double longitude = c->getLongitude();
  double radiusCleanedArea = 0;
  double attributeStartUnit;
  double attributeEndUnit;
  vector<Sensor *> sensor_list_by_distance(sensor_list);
  vector<Attribute *> attributeListStartTM;
  vector<Attribute *> attributeListEndTM;

  // Sort the sensors by distance from cleaner
  for (auto it : sensor_list_by_distance)
  {
    it->calculate_distance_from_cleaner(latitude, longitude);
  }
  sort(sensor_list_by_distance.begin(), sensor_list_by_distance.end(), cmpSensor);

  // Get the measurements starting from the closest sensor
  vector<Measurement *> measurement_list;
  for (auto sensor_it : sensor_list_by_distance)
  {
    measurement_list = sensor_it->getMeasurement();

    // Get the measurements before & after the cleaner activation
    Measurement *dummyStartTM = new Measurement(startTM);
    Measurement *dummyEndTM = new Measurement(startTM);
    attributeListStartTM = (*lower_bound(measurement_list.begin(), measurement_list.end(), dummyStartTM, cmpMeasurementByTM))->getAttributeList();
    attributeListEndTM = (*upper_bound(measurement_list.begin(), measurement_list.end(), dummyEndTM, cmpMeasurementByTM))->getAttributeList();

    // If all the attributes did Improve, Update cleaned radius
    int improvedAttributeCnt = 0;
    for (int i = 0; i < attributeListStartTM.size(); i++)
    {
      attributeStartUnit = stod(attributeListStartTM[i]->getUnit());
      attributeEndUnit = stod(attributeListEndTM[i]->getUnit());
      if (attributeStartUnit > attributeEndUnit)
        improvedAttributeCnt++;
    }
    if (attributeListStartTM.size() == improvedAttributeCnt)
      radiusCleanedArea = sensor_it->getDistanceFromCleaner();
  }

  return radiusCleanedArea;
}

double ServiceCleaners::calc_improvement_airQuality(long latitude, long longitude)
{
}
