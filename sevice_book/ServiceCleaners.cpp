#include <ctime>
#include <algorithm>
#include <string>
#include <iostream>
#include "ServiceCleaners.h"
#include "../data/Sensor.h"
#include "../data/Measurement.h"
#include "../data/Attribute.h"

bool ServiceCleaners::provideCleaner(Provider *p, Cleaner *c)
{
  bool funcResult;
  funcResult = p->addCleaner(c);
  c->setProvider(p);
  return funcResult;
}

bool cmpSensor(Sensor *a, Sensor *b)
{
  return a->getDistanceFromCoordinate() > b->getDistanceFromCoordinate();
}

bool cmpMeasurementByTM(Measurement *a, Measurement *b)
{
  return mktime(a->getTimestampAddress()) > mktime(b->getTimestampAddress());
}

// Return Radius cleaned by cleaners
// Needs the whole sensor* vector list as input
double ServiceCleaners::calcRadiusCleanedArea(Cleaner *c, vector<Sensor *> sensor_list)
{
  struct tm startTM = c->getStartTM();
  struct tm endTM = c->getEndTM();
  double latitude = c->getLatitude();
  double longitude = c->getLongitude();
  double radiusCleanedArea = 0;
  double attributeStartUnit;
  double attributeEndUnit;
  vector<Sensor *> sensor_list_by_distance(sensor_list);
  vector<Attribute *> attributeListStartTM;
  vector<Attribute *> attributeListEndTM;

  // Sort the sensors by distance from cleaner
  if (sensor_list_by_distance.size() == 0)
  {
    cout << "No Sensors in List\n";
    return -1;
  }
  for (auto it : sensor_list_by_distance)
  {
    it->calcDistanceFromCoordinate(latitude, longitude);
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
      radiusCleanedArea = sensor_it->getDistanceFromCoordinate();
  }

  return radiusCleanedArea;
}

/*
  User Input: Coordinate(latitude, longitude), time(start timestamp, end timestamp)
  Output: returns a vector pair<string, double>, with the attribute ID and unit
*/
vector<pair<string, double>> ServiceCleaners::calcImprovementAirQuality(double latitude, double longitude, struct tm startTM, struct tm endTM, vector<Sensor *> sensor_list)
{
  // Sort the sensors by distance from coordinate, get the closest one
  vector<Sensor *> sensor_list_by_distance(sensor_list);
  for (auto it : sensor_list_by_distance)
  {
    it->calcDistanceFromCoordinate(latitude, longitude);
  }
  sort(sensor_list_by_distance.begin(), sensor_list_by_distance.end(), cmpSensor);
  Sensor *closest_sensor = sensor_list_by_distance[0];

  // Get the attribute list of a measurement closet to the two timestamps
  vector<Measurement *> measurement_list;
  measurement_list = closest_sensor->getMeasurement();
  Measurement *dummyStartTM = new Measurement(startTM);
  Measurement *dummyEndTM = new Measurement(startTM);
  vector<Attribute *> attributeListStartTM = (*lower_bound(measurement_list.begin(), measurement_list.end(), dummyStartTM, cmpMeasurementByTM))->getAttributeList();
  vector<Attribute *> attributeListEndTM = (*upper_bound(measurement_list.begin(), measurement_list.end(), dummyEndTM, cmpMeasurementByTM))->getAttributeList();

  // Compare the two attributes by id
  vector<pair<string, double>> airQualityImprovement;
  double difference;
  for (int i = 0; i < attributeListStartTM.size(); i++)
  {
    string unitStartTM = attributeListStartTM[i]->getId();
    for (int j = 0; j < attributeListEndTM.size(); j++)
    {
      string unitEndTM = attributeListEndTM[j]->getId();
      if (unitStartTM == unitEndTM)
      {
        difference = stod(attributeListStartTM[i]->getUnit()) - stod(attributeListEndTM[j]->getUnit());
        airQualityImprovement.push_back(make_pair(unitStartTM, difference));
      }
    }
  }

  return airQualityImprovement;
}
