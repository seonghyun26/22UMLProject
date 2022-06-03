#include "SimpleUser.h"
SimpleUser::SimpleUser(string id, string login, string password):User(id,login,password,0){
	this->rewardCount=0;
	this->sensors=vector<Sensor *>();
}
int SimpleUser::getRewardCount() { return rewardCount; }
vector<Sensor *> SimpleUser::getSensors() { return sensors; }
void SimpleUser::setRewardCount(int rewardCount) { this->rewardCount = rewardCount; }
void SimpleUser::addSensor(Sensor *newSensor){sensors.push_back(newSensor);}
