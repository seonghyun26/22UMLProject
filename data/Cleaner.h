#ifndef CLEANER_H
#define CLEANER_H

#include <string>
#include <ctime>
class Provider;
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
  Cleaner(Provider *provider_, string id_, struct tm *start_tm_, struct tm *end_tm_, double latitude_, double longitude_);

  void setProvider(Provider *provider);
  void setId(string id);
  void setStartTM(struct tm *start_tm);
  void setEndTM(struct tm *end_tm);
  void setLatitude(double latitude);
  void setLongitude(double longitude);

  Provider *getProvider();
  string getId();
  struct tm *getStartTM();
  struct tm *getEndTM();
  double getLatitude(); 
  double getLongitude();
};

#endif
