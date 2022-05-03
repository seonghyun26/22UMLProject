#ifndef SENSOR_H
#define SENSOR_H

#include <Measurement.h>
#include <vector>

class Sensor
{
protected:
  long id;
  double latitude;
  double longitude;
  bool reliability;
  vector<Measurement *> measurement_list;

public:
  Sensor(int id_, double latitude_, double longitude_, bool reliability_)
  {
    id = id_;
    latitude = latitude_;
    longitude = longitude_;
    reliability = reliability_;
  }

  void setId(long id) { this->id = id; }
  void setLatitude(double latitude) { this->latitude = latitude; }
  void setLongitude(double longitude) { this->longitude = longitude; }
  void setReliability(bool reliability) { this->reliability = reliability; }
  void addMeasurement(Measurement *measurement) { this->measurement_list.push_back(measurement); }

  long getId() { return id; }
  double getLatitude() { return latitude; }
  double getLongitude() { return longitude; }
  long getReliability() { return reliability; }
  vector<Measurement *> getMeasurement() { return measurement_list; }
};

#endif