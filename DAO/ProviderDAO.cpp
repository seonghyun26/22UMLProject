#include <fstream>
#include <cstring>
#include <ctime>
#include <map>
#include "ProviderDAO.h"

vector<Provider> providerList=vector<Provider>();
vector<Cleaner> cleanerList=vector<Cleaner>();

void ProviderDAO::parseProviderAndCleaner(string providersPath,string cleanersPath){
	fstream fs;
	providerList=vector<Provider>();
	cleanerList=vector<Cleaner>();
	map<string,int> providerById=map<string,int>();
	map<string,int> cleanerById=map<string,int>();
	char forgot[256];
	char cleanerId[32];
	char latitudeStr[32];
	double latitude;
	char longitudeStr[32];
	double longitude;
	int yy, month, dd, hh, mm, ss;
	char startTMStr[128];
	struct tm startTM;
	char endTMStr[128];
	struct tm endTM;

	char providerId[32];
	Provider * currentProvider;
	Cleaner * currentCleaner;
	fs.open (cleanersPath, fstream::in);
	while(fs.getline(cleanerId,32,';') || strlen(cleanerId)!=0){
		fs.getline(latitudeStr,32,';');
		latitude=atof(latitudeStr);
		fs.getline(longitudeStr,32,';');
		longitude=atof(longitudeStr);
		fs.getline(startTMStr,128,';');
		sscanf(startTMStr,"%d-%d-%d %d:%d:%d",&yy,&month,&dd,&hh,&mm,&ss);
		startTM.tm_year=yy-1900;
		startTM.tm_mon= month -1;
		startTM.tm_mday=dd;
		startTM.tm_hour=hh;
		startTM.tm_min=mm;
		startTM.tm_sec=ss;
		startTM.tm_isdst=-1;
		//mktime(myTM)
		fs.getline(endTMStr,128,';');
		sscanf(endTMStr,"%d-%d-%d %d:%d:%d",&yy,&month,&dd,&hh,&mm,&ss);
		endTM.tm_year=yy-1900;
		endTM.tm_mon= month -1;
		endTM.tm_mday=dd;
		endTM.tm_hour=hh;
		endTM.tm_min=mm;
		endTM.tm_sec=ss;
		endTM.tm_isdst=-1;
		cleanerById.insert(pair<string,int>(cleanerId,cleanerList.size()));
		cleanerList.push_back(Cleaner(nullptr,cleanerId,startTM,endTM,latitude,longitude));
		fs.getline(forgot,256);
	}

	fs.open (providersPath, fstream::in);
	while(fs.getline(providerId,32,';') || strlen(providerId)!=0){
		fs.getline(cleanerId,32,';');
		if(providerById.count(providerId)==0){
			providerById.insert(pair<string,int>(providerId,providerList.size()));
																								//login and password not initialized because absent from the original csv file
			providerList.push_back(Provider(providerId,providerId,""));
		}
		currentProvider= &providerList[providerById[providerId]];
		currentCleaner= &cleanerList[cleanerById[cleanerId]];
		currentProvider->addCleaner(currentCleaner);
		fs.getline(forgot,256);
	}
	fs.close();
}
