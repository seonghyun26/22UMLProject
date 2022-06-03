#include <fstream>
#include <cstring>
#include <map>
#include "AttributesDAO.h"

vector<Attribute> attrList=vector<Attribute>();
vector<Sensor> sensorList=vector<Sensor>();
vector<SimpleUser> userList=vector<SimpleUser>();
vector<Measurement> measurementList=vector<Measurement>();

void parseAttributesMeasurementSensorAndUser(
				string attributesPath,
				string measurementsPath,
				string sensorsPath,
				string usersPath
			){
	fstream fs;
	attrList=vector<Attribute>();
	sensorList=vector<Sensor>();
	userList=vector<SimpleUser>();
	measurementList=vector<Measurement>();

	map<string,int> attrById=map<string,int>();
	map<string,int> sensorById=map<string,int>();
	map<string,int> userById=map<string,int>();
	map<string,int> measurementById=map<string,int>();

	char forgot[256];
	char attrId[32];
	char unit[32];
	char description[128];

	char sensorId[32];
	char idStr[16];
	int id;
	char latitudeStr[32];
	double latitude;
	char longitudeStr[32];
	double longitude;

	char userId[32];

	int yy, month, dd, hh, mm, ss;
	char TMStr[128];
	struct tm measTM;

	char valueStr[8];
	double value;

	Sensor * currentSensor;
	SimpleUser * currentUser;
	Measurement * currentMeasurement;
	Attribute * currentAttribute;
	fs.open (attributesPath, fstream::in);
	fs.getline(forgot,256);
	// hacky solution but works for now
	while(fs.getline(attrId,32,';') || strlen(attrId)!=0){
		fs.getline(unit,32,';');
		fs.getline(description,128,';');
		attrById.insert(pair<string,int>(attrId,attrList.size()));
		attrList.push_back(Attribute(attrId,unit,description));
		fs.getline(forgot,256);
	}
	fs.close();
  fs.open(sensorsPath, fstream::in);
  while(fs.getline(sensorId,32,';') || strlen(sensorId)!=0){
    strcpy(idStr,sensorId+6);
    //idStr=(sensorId+6); //skip 'Sensor'
    id=atoi(idStr);
    fs.getline(latitudeStr,32,';');
    latitude=atof(latitudeStr);
    fs.getline(longitudeStr,32,';');
    longitude=atof(longitudeStr);
    sensorById.insert(pair<string,int>(sensorId, sensorList.size()));
    sensorList.push_back(Sensor(id,latitude,longitude,true));
    fs.getline(forgot,256);
  }
  fs.close();
  fs.open(usersPath, fstream::in);
  while(fs.getline(userId,32,';') || strlen(userId)!=0){
    fs.getline(sensorId,32,';');
    if(userById.count(userId)==0){
      userById.insert(pair<string, int>(userId,userList.size()));
      userList.push_back(SimpleUser(userId,userId,""));
    }
    currentUser= &userList[userById[userId]];
    currentSensor= &sensorList[sensorById[sensorId]];
    currentUser->addSensor(currentSensor);
    fs.getline(forgot,256);
  }
  fs.close();
  fs.open(measurementsPath, fstream::in);
  while (fs.getline(TMStr,128,';') || strlen(TMStr)!=0){
		sscanf(TMStr,"%d-%d-%d %d:%d:%d",&yy,&month,&dd,&hh,&mm,&ss);
    measTM.tm_year=yy-1900;
    measTM.tm_mon= month -1;
    measTM.tm_mday=dd;
    measTM.tm_hour=hh;
    measTM.tm_min=mm;
    measTM.tm_sec=ss;
    measTM.tm_isdst=-1;
    fs.getline(sensorId,32,';');
		currentSensor= &sensorList[sensorById[sensorId]];
    fs.getline(attrId,32,';');
		currentAttribute= &attrList[attrById[attrId]];
		fs.getline(valueStr,8,';');
		value=atof(valueStr);

		measurementList.push_back(Measurement(measTM, value));
		currentMeasurement=&measurementList.back();
		currentMeasurement->setAttribute(currentAttribute);
		currentSensor->addMeasurement(currentMeasurement);
    fs.getline(forgot,256);
  }
	fs.close();
}
