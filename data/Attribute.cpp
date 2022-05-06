#include "Attribute.h"
Attribute::Attribute(string id_, string unit_, string description_)
{
  id = id_;
	unit = unit_;
  description = description_;
}

void Attribute::setId(string id) { this->id = id; }
void Attribute::setUnit(string unit) { this->unit = unit; }
void Attribute::setDescription(string description) { this->description = description; }

string Attribute::getId() { return id; }
string Attribute::getUnit() { return unit; }
string Attribute::getDescription() { return description; }

