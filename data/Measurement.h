#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <ctime>
#include <Attribute.h>

class Measurement
{
protected:
  struct tm *timestamp;
  double value;
  Attribute *attribute;

public:
  Measurement(struct tm *timestamp_, double value_, Attribute *attribute_)
  {
    timestamp = timestamp_;
    value = value_;
    attribute = attribute_;
  }

  void setTimestamp(string timestamp_str) { strptime(timestamp_str, "%Y-%Om-%Od %OH:%OM:%OS", this->timestamp); }
  void setValue(double value) { this->value = value; }
  void setAttribute(Attribute *attribute) { this->attribute = attribute; }

  struct tm *getTimestamp() { return timestamp; }
  double getValue() { return value; }
  Attribute *getAttribute() { return attribute; }
};

#endif