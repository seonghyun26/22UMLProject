#include "Sensor.h"
#include <cmath>
#include <algorithm>

bool cmpMeasurementByTM(Measurement *a, Measurement *b)
{
  return mktime(a->getTimestamp()) > mktime(b->getTimestamp());
}

Sensor::Sensor(int id_, double latitude_, double longitude_, bool reliability_)
{
  id = id_;
  latitude = latitude_;
  longitude = longitude_;
  reliability = reliability_;
  distance_from_coordinate = 0;
}

void Sensor::setId(long id) { this->id = id; }
void Sensor::setLatitude(double latitude) { this->latitude = latitude; }
void Sensor::setLongitude(double longitude) { this->longitude = longitude; }
void Sensor::setReliability(bool reliability) { this->reliability = reliability; }
void Sensor::addMeasurement(Measurement *measurement)
{
  this->measurement_list.push_back(measurement);
  // Sort measurement list by timestamp!
  sort(this->getMeasurement().begin(), this->getMeasurement().end(), cmpMeasurementByTM);
}
void Sensor::calcDistanceFromCoordinate(double latitude, double longitude)
{
  this->distance_from_coordinate = sqrt(pow(latitude - this->latitude, 2) + pow(longitude - this->longitude, 2));
}

long Sensor::getId() { return id; }
double Sensor::getLatitude() { return latitude; }
double Sensor::getLongitude() { return longitude; }
long Sensor::getReliability() { return reliability; }
vector<Measurement *> Sensor::getMeasurement() { return measurement_list; }
double Sensor::getDistanceFromCoordinate() { return distance_from_coordinate; }
