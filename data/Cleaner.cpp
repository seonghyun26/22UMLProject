#include "Cleaner.h"
Cleaner::Cleaner(Provider *provider_, string id_, struct tm start_tm_, struct tm end_tm_, double latitude_, double longitude_)
{
	provider = provider_;
	id = id_;
	startTM = start_tm_;
	endTM = end_tm_;
	latitude = latitude_;
	longitude = longitude_;
}

void Cleaner::setProvider(Provider *provider) { this->provider = provider; }
void Cleaner::setId(string id) { this->id = id; }
void Cleaner::setStartTM(struct tm start_tm) { this->startTM = start_tm; }
void Cleaner::setEndTM(struct tm end_tm) { this->endTM = end_tm; }
void Cleaner::setLatitude(double latitude) { this->latitude = latitude; }
void Cleaner::setLongitude(double longitude) { this->longitude = longitude; }

Provider *Cleaner::getProvider() { return provider; }
string Cleaner::getId() { return id; }
struct tm Cleaner::getStartTM() { return startTM; }
struct tm Cleaner::getEndTM() { return endTM; }
double Cleaner::getLatitude() { return latitude; }
double Cleaner::getLongitude() { return longitude; }
