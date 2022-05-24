#include "Measurement.h"
#include <string.h>
#include <time.h>
#include <iostream>

using namespace std;

Measurement::Measurement(struct tm timestamp_)
{
  timestamp = timestamp_;
}
Measurement::Measurement(struct tm timestamp_, double value_)
{
  timestamp = timestamp_;
  value = value_;
}

void Measurement::setTimestamp(struct tm timestamp) { this->timestamp = timestamp; }
// strptime(timestamp_str, "%Y-%Om-%Od %OH:%OM:%OS", this->timestamp)
void Measurement::setValue(double value) { this->value = value; }
void Measurement::addAttribute(Attribute *attribute) { this->attribute_list.push_back(attribute); }

struct tm Measurement::getTimestamp() { return timestamp; }
struct tm *Measurement::getTimestampAddress() { return &timestamp; }
double Measurement::getValue() { return value; }
vector<Attribute *> Measurement::getAttributeList() { return attribute_list; }

void Measurement::printInfo()
{
  cout << "<--Measurement Info Start-->\n";
  // strftime(buf, 80, "TimeStamp: %F %t", timestamp);
  cout << "Value: " << value << "\n";
  cout << "Number of Attributes: " << getAttributeList().size() << "\n";
  cout << "<-- Measurement Info End -->\n\n";
}
