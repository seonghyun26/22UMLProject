#ifndef SENSOR_H
#define SENSOR_H

#include <vector>
#include "Measurement.h"

class Sensor
{
protected:
  long id;
  double latitude;
  double longitude;
  bool reliability;
  double distance_from_cleaner;
  vector<Measurement *> measurement_list;

public:
  Sensor(int id_, double latitude_, double longitude_, bool reliability_);

  void setId(long id);
  void setLatitude(double latitude);
  void setLongitude(double longitude);
  void setReliability(bool reliability);
  void addMeasurement(Measurement *measurement);
  void calculate_distance_from_cleaner(double latitude, double longitude);

  long getId();
  double getLatitude();
  double getLongitude();
  long getReliability();
  vector<Measurement *> getMeasurement();
  double getDistanceFromCleaner();
};

#endif
