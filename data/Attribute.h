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
  Attribute(string id_, string unit_, string description_);

  void setId(string id);
  void setUnit(string unit);
  void setDescription(string description);

  string getId();
  string getUnit();
  string getDescription();
};

#endif
