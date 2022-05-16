#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <ctime>
#include <vector>
#include "Attribute.h"

class Measurement
{
protected:
  struct tm *timestamp;
  double value;
  vector<Attribute *> attribute_list;

public:
  Measurement(struct tm *timestamp_);
  Measurement(struct tm *timestamp_, double value_);

  void setTimestamp(struct tm *timestamp);
  // strptime(timestamp_str, "%Y-%Om-%Od %OH:%OM:%OS", this->timestamp)
  void setValue(double value);
  void addAttribute(Attribute *attribute);

  struct tm *getTimestamp();
  double getValue();
  vector<Attribute *> getAttributeList();
  void printInfo();
};

#endif
