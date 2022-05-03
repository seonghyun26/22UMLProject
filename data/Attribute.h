#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <string>

using namespace std;

class Attribute
{
protected:
  string id;
  string unit;
  string description;

public:
  Attribute(string id_, string unit_, string description_)
  {
    id = id_;
    unit = unit_;
    description = description_;
  }

  void setId(string id) { this->id = id; }
  void setUnit(string unit) { this->unit = unit; }
  void setDescription(string description) { this->description = description; }

  string getId() { return id; }
  string getUnit() { return unit; }
  string getDescription() { return description; }
};

#endif