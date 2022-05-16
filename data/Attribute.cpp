#include "Attribute.h"
#include <iostream>

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

void Attribute::printInfo()
{
  std::printf("<--Attribute Info Start-->\n");
  std::printf("Id: ", id, "\n");
  std::printf("Unit: ", unit, "\n");
  std::printf("Description: ", description, "\n");
  std::printf("<-- Attribute Info End -->\n\n");
}