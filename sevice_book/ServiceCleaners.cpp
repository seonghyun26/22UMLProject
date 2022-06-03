#include <ctime>
#include <algorithm>
#include <string>
#include <iostream>
#include <iomanip>
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

bool cmpSensor(Sensor a, Sensor b)
{
  return a.getDistanceFromCoordinate() > b.getDistanceFromCoordinate();
}

bool cmpMeasurementByTM(Measurement *a, Measurement *b)
{
  return mktime(a->getTimestampAddress()) > mktime(b->getTimestampAddress());
}

// Return Radius cleaned by cleaners
// Needs the whole sensor* vector list as input
double ServiceCleaners::calcRadiusCleanedArea(Cleaner *c, vector<Sensor> sensor_list)
{
  struct tm startTM = c->getStartTM();
  struct tm endTM = c->getEndTM();
  double latitude = c->getLatitude();
  double longitude = c->getLongitude();
  double radiusCleanedArea = 0;
  double attributeStartUnit;
  double attributeEndUnit;
  vector<Sensor> sensor_list_by_distance(sensor_list);
  double measurementStartValue, measurementEndValue;

  // Sort the sensors by distance from cleaner
  if (sensor_list_by_distance.size() == 0)
  {
    cout << "No Sensors in List\n";
    return -1;
  }
  for (auto it : sensor_list_by_distance)
  {
    it.calcDistanceFromCoordinate(latitude, longitude);
  }
  sort(sensor_list_by_distance.begin(), sensor_list_by_distance.end(), cmpSensor);

  // Get the measurements starting from the closest sensor
  vector<Measurement *> measurement_list;
  for (auto sensor_it : sensor_list_by_distance)
  {
    // cout << "Distance: " << sensor_it.getDistanceFromCoordinate() << "\n";
    measurement_list = sensor_it.getMeasurement();

    // Get the measurements before & after the cleaner activation
    // Measurement *dummyStartTM = new Measurement(startTM);
    // Measurement *dummyEndTM = new Measurement(endTM);
    for (auto meas_it : measurement_list)
    {
      if (mktime(meas_it->getTimestampAddress()) > mktime(&startTM))
      {
        measurementStartValue = meas_it->getValue();
        break;
      }
    }
    for (auto meas_it : measurement_list)
    {
      if (mktime(meas_it->getTimestampAddress()) > mktime(&endTM))
      {
        measurementEndValue = meas_it->getValue();
        break;
      }
    }
    // cout << "Distance " << sensor_it.getDistanceFromCoordinate() << " ( ID " << sensor_it.getId() << " ): " << measurementEndValue << " -> " << measurementStartValue << "\n";

    // measurementStartValue = (*lower_bound(measurement_list.begin(), measurement_list.end(), dummyStartTM, cmpMeasurementByTM))->getValue();
    // measurementEndValue = (*upper_bound(measurement_list.begin(), measurement_list.end(), dummyEndTM, cmpMeasurementByTM))->getValue();

    // int startFlag = 0, endFlag = 0;
    // vector<double> measurementStartAttributes;
    // vector<double> measurementEndAttributes;
    // for (auto meas_it : measurement_list)
    // {
    //   if (startFlag >= 4 && endFlag >= 4)
    //     break;
    //   if (mktime(meas_it->getTimestampAddress()) > mktime(&startTM) && startFlag < 4)
    //   {
    //     startFlag++;
    //     measurementStartAttributes.push_back(meas_it->getValue());
    //   }
    //   if (mktime(meas_it->getTimestampAddress()) < mktime(&endTM) && endFlag < 4)
    //   {
    //     endFlag++;
    //     measurementEndAttributes.push_back(meas_it->getValue());
    //   }
    // }

    // // If all the attributes did Improve, Update cleaned radius
    // int improvedAttributeCnt = 0;
    // for (int i = 0; i < 4; i++)
    // {
    //   if (measurementStartAttributes[i] < measurementEndAttributes[i])
    //     improvedAttributeCnt++;
    // }
    // if (improvedAttributeCnt == 4)
    if (measurementStartValue > measurementEndValue)
      radiusCleanedArea = sensor_it.getDistanceFromCoordinate();
  }

  return radiusCleanedArea;
}

/*
  User Input: Coordinate(latitude, longitude), time(start timestamp, end timestamp)
  Output: returns a vector pair<string, double>, with the attribute ID and unit
*/
double ServiceCleaners::calcImprovementAirQuality(double latitude, double longitude, struct tm startTM, struct tm endTM, vector<Sensor> sensor_list)
{
  // Sort the sensors by distance from coordinate, get the closest one
  vector<Sensor> sensor_list_by_distance(sensor_list);

  if (sensor_list_by_distance.size() == 0)
  {
    cout << "No Sensors in List\n";
    return -1;
  }

  for (auto it : sensor_list_by_distance)
  {
    it.calcDistanceFromCoordinate(latitude, longitude);
  }
  sort(sensor_list_by_distance.begin(), sensor_list_by_distance.end(), cmpSensor);
  Sensor closest_sensor = sensor_list_by_distance[0];

  // Get the attribute list of a measurement closet to the two timestamps
  vector<Measurement *> measurement_list;
  measurement_list = closest_sensor.getMeasurement();
  Measurement *dummyStartTM = new Measurement(startTM);
  Measurement *dummyEndTM = new Measurement(startTM);
  // double valueStartTM = (*lower_bound(measurement_list.begin(), measurement_list.end(), dummyStartTM, cmpMeasurementByTM))->getValue();
  // double valueEndTM = (*upper_bound(measurement_list.begin(), measurement_list.end(), dummyEndTM, cmpMeasurementByTM))->getValue();
  double valueStartTM, valueEndTM;
  for (auto meas_it : measurement_list)
  {
    if (mktime(meas_it->getTimestampAddress()) > mktime(&startTM))
    {
      valueStartTM = meas_it->getValue();
      break;
    }
  }
  for (auto meas_it : measurement_list)
  {
    if (mktime(meas_it->getTimestampAddress()) > mktime(&endTM))
    {
      valueEndTM = meas_it->getValue();
      break;
    }
  }

  // Compare the two attributes by id
  double difference = valueEndTM - valueStartTM;

  return difference;
}
