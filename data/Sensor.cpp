#include "Sensor.h"
Sensor::Sensor(int id_, double latitude_, double longitude_, bool reliability_)
{
	id = id_;
	latitude = latitude_;
	longitude = longitude_;
	reliability = reliability_;
}

void Sensor::setId(long id) { this->id = id; }
void Sensor::setLatitude(double latitude) { this->latitude = latitude; }
void Sensor::setLongitude(double longitude) { this->longitude = longitude; }
void Sensor::setReliability(bool reliability) { this->reliability = reliability; }
void Sensor::addMeasurement(Measurement *measurement) { this->measurement_list.push_back(measurement); }

long Sensor::getId() { return id; }
double Sensor::getLatitude() { return latitude; }
double Sensor::getLongitude() { return longitude; }
long Sensor::getReliability() { return reliability; }
vector<Measurement *> Sensor::getMeasurement() { return measurement_list; }
