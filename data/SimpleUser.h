#ifndef SIMPLEUSER_H
#define SIMPLEUSER_H

#include <vector>
#include "Sensor.h"
#include "User.h"

using namespace std;

class SimpleUser : public User
{
protected:
  int rewardCount;
  vector<Sensor> sensors;

public:
	SimpleUser();
  int getRewardCount() { return rewardCount; }
  vector<Sensor> getSensors() { return sensors; }
  void setRewardCount(int rewardCount) { this->rewardCount = rewardCount; }
  void setSensors(vector<Sensor> sensors) { this->sensors = sensors; }
};

#endif
