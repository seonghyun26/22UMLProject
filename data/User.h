#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

#include <vector>
#include "Sensor.h"

class User
{
protected:
	string id;
	string login;
	string password;
	int type;
	vector<Sensor *> sensorList;

public:
	User(string id, string login, string password, int type);
	string getId();
	string getLogin();
	string getPassword();
	int getType();
	vector<Sensor *> getSensorList();

	void setId(string id);
	void setLogin(string login);
	void setPassword(string password);
	void setType(int type);
	void addSensor(Sensor *newSensor);
};

#endif
