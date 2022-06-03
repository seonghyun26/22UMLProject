#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <ctime>
#include <vector>
#include "Attribute.h"

class Measurement
{
protected:
  struct tm timestamp;
  double value;
  Attribute *attribute;

public:
  Measurement(struct tm timestamp_);
  Measurement(struct tm timestamp_, double value_);

  void setTimestamp(struct tm timestamp);
  // strptime(timestamp_str, "%Y-%Om-%Od %OH:%OM:%OS", this->timestamp)
  void setValue(double value);
  void setAttribute(Attribute *attribute);

  struct tm getTimestamp();
  struct tm *getTimestampAddress();
  double getValue();
  Attribute *getAttribute();
  void printInfo();
};

#endif
