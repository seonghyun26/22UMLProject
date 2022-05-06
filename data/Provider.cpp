Provider::Provider(){
	this.cleaner_list=vector<Cleaner *>();
}
vector<Cleaner *> Cleaner::getCleaners() { return cleaner_list; }
void Cleaner::addCleaner(Cleaner *cleaner) { cleaner_list.push_back(cleaner); }
