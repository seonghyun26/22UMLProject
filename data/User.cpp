#include "User.h"

User::User(string id, string login, string password, int type)
{
	this->id = id;
	this->login = login;
	this->password = password;
	this->type = type;
}
string User::getId() { return id; }
string User::getLogin() { return login; }
string User::getPassword() { return password; }
int User::getType() { return type; }

void User::setId(string id) { this->id = id; }
void User::setLogin(string login) { this->login = login; }
void User::setPassword(string password) { this->password = password; }
void User::setType(int type) { this->type = type; }
