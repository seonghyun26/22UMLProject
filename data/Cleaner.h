#ifndef CLEANER_H
#define CLEANER_H

#include <string>
#include <ctime>
#include "Provider.h"

using namespace std;

class Cleaner
{
protected:
  Provider *provider;
  string id;
  struct tm *startTM;
  struct tm *endTM;
  double latitude;
  double longitude;

public:
  Cleaner(Provider *provider_, string id_, struct tm *start_tm_, struct tm *end_tm_, double latitude_, double longitude_)
  {
    provider = provider_;
    id = id_;
    startTM = start_tm_;
    endTM = end_tm_;
    latitude = latitude_;
    longitude = longitude_;
  }

  void setProvider(Provider *provider) { this->provider = provider; }
  void setId(string id) { this->id = id; }
  void setStartTM(struct tm *start_tm) { this->startTM = start_tm; }
  void setEndTM(struct tm *end_tm) { this->endTM = end_tm; }
  void setLatitude(double latitude) { this->latitude = latitude; }
  void setLongitude(double longitude) { this->longitude = longitude; }

  Provider *getProvider() { return provider; }
  string getId() { return id; }
  struct tm *getStartTM() { return startTM; }
  struct tm *getEndTM() { return endTM; }
  double getLatitude() { return latitude; }
  double getLongitude() { return longitude; }
};

#endif