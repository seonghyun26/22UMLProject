#include "SimpleUser.h"
SimpleUser::SimpleUser(){
	this->rewardCount=0;
	this->sensors=vector<Sensor>();
}
int SimpleUser::getRewardCount() { return rewardCount; }
vector<Sensor> SimpleUser::getSensors() { return sensors; }
void SimpleUser::setRewardCount(int rewardCount) { this->rewardCount = rewardCount; }
void SimpleUser::setSensors(vector<Sensor> sensors) { this->sensors = sensors; }
