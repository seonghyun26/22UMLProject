#ifndef SIMPLEUSER_H
#define SIMPLEUSER_H

#include <vector>
#include "Sensor.h"

using namespace std;

class SimpleUser : public User {
	public:
		int rewardCount;
		vector<Sensor> sensors;
	private:
	int getRewardCount(){return rewardCount;}
	vector<Sensor> getSensors(){return sensors;}
	void setRewardCount(int rewardCount){this.rewardCount=rewardCount;}
	void setSensors(vector<Sensor> sensors){this.sensors=sensors;}
}

#endif
