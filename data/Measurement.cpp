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
void Measurement::setAttribute(Attribute *attribute) { this->attribute = attribute; }

struct tm Measurement::getTimestamp() { return timestamp; }
struct tm *Measurement::getTimestampAddress() { return &timestamp; }
double Measurement::getValue() { return value; }
Attribute *Measurement::getAttribute() { return attribute; }

void Measurement::printInfo()
{
  cout << "<--Measurement Info Start-->\n";
  // strftime(buf, 80, "TimeStamp: %F %t", timestamp);
  cout << "Value: " << value << "\n";
  cout << "Attribute: " << getAttribute() << "\n";
  cout << "<-- Measurement Info End -->\n\n";
}
