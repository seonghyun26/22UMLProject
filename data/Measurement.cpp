#include "Measurement.h"
#include <string.h>
#include <time.h>

Measurement::Measurement(struct tm *timestamp_)
{
  timestamp = timestamp_;
}
Measurement::Measurement(struct tm *timestamp_, double value_)
{
  timestamp = timestamp_;
  value = value_;
}

void Measurement::setTimestamp(struct tm *timestamp) { this->timestamp = timestamp; }
// strptime(timestamp_str, "%Y-%Om-%Od %OH:%OM:%OS", this->timestamp)
void Measurement::setValue(double value) { this->value = value; }
void Measurement::addAttribute(Attribute *attribute) { this->attribute_list.push_back(attribute); }

struct tm *Measurement::getTimestamp() { return timestamp; }
double Measurement::getValue() { return value; }
vector<Attribute *> Measurement::getAttributeList() { return attribute_list; }

void Measurement::printInfo()
{
  std::printf("<--Measurement Info Start-->\n");
  char buf[80];
  strftime(buf, 80, "TimeStamp: %F %t", timestamp);
  puts(buf);
  std::printf("Value: ", to_string(value), "\n");
  std::printf("Number of Attributes: ", to_string(getAttributeList().size()), "\n");
  std::printf("<-- Measurement Info End -->\n\n");
}
