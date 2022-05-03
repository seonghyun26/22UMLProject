#ifndef SERVICECLEANERS_H
#define SERVICECLEANERS_H

#include "Cleaner.h"

class ServiceCleaners
{
public:
	Cleaner provide_cleaner(Cleaner c);
	long calc_radius_cleaned_area(Cleaner c);
	double calc_improvement_airQuality(long latitude, long longitude);
};

#endif