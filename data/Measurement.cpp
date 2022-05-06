#include "Measurement.h"

Measurement::Measurement(struct tm *timestamp_, double value_, Attribute *attribute_)
{
	timestamp = timestamp_;
	value = value_;
	attribute = attribute_;
}

void Measurement::setTimestamp(struct tm *timestamp) { this->timestamp = timestamp; }
// strptime(timestamp_str, "%Y-%Om-%Od %OH:%OM:%OS", this->timestamp)
void Measurement::setValue(double value) { this->value = value; }
void Measurement::setAttribute(Attribute *attribute) { this->attribute = attribute; }

struct tm *Measurement::getTimestamp() { return timestamp; }
double Measurement::getValue() { return value; }
Attribute *Measurement::getAttribute() { return attribute; }

