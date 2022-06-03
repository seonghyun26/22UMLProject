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
  vector<Sensor *> sensors;

public:
	SimpleUser(string id,string login, string password);
  int getRewardCount();
  vector<Sensor *> getSensors() ;
  void setRewardCount(int rewardCount) ;
	void addSensor(Sensor *newSensor);
};

#endif
