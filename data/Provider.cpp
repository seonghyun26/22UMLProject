#include "Provider.h"

Provider::Provider(string id, string login, string password):User(id,login,password,0){
	this->cleaner_list=vector<Cleaner *>();
}
vector<Cleaner *> Provider::getCleaners() { return cleaner_list; }
void Provider::addCleaner(Cleaner *cleaner) { cleaner_list.push_back(cleaner); }
