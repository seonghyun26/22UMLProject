#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User
{
protected:
	string id;
	string login;
	string password;
	int type;

public:
	User(string id, string login, string password, int type);
	string getId();
	string getLogin();
	string getPassword();
	int getType();

	void setId(string id);
	void setLogin(string login);
	void setPassword(string password);
	void setType(int type);
};

#endif
