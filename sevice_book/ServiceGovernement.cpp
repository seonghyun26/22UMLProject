#include <map>
#include "ServiceGovernement.h"


map<string,vector<int>> AQI_levels={
	{"O3",{0,30,55,80,105,130,150,180,210,240}},
	{"SO2",{0,40,80,120,160,200,250,300,400,500}},
	{"NO2",{0,30,55,85,110,135,165,200,275,400}},
	{"PM10",{0,7,14,21,28,35,42,50,65,80}}
}

int ServiceGovernement::calc_airQualityMean(long latitude, long longitude, long diameter, struct tm time, long duration)
{
	int maxLevel =0;
}
