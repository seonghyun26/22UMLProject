#ifndef GOVAGENT_UI_H
#define GOVAGENT_UI_H

#include "Interface.h"

class GovAgentInterface : public Interface
{
protected:
public:
  GovAgentInterface();
  bool executeFunction(int funcNum);
  bool calculateAQMean();
  bool calculateAQatPosition();
  bool rankSensor();
  bool analyzeDataSensor();
  bool flagUnreliable();
  bool Unflag();
  bool eraseDataUnreliableSensor();
};

#endif