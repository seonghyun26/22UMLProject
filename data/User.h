#ifndef USER_H
#define USER_H
using namespace std;

class User{
procted:
	long id;
	string login;
	string password;
	int type;

public:
	long getId(){return id;}
	string getLogin(){return login;}
	string getPassword(){return password;}
	int getType(){return type;}
	
	void set(long id){this.id=id;}
	void set(string login){this.login=login;}
	void set(string password){this.password=password;}
	void set(int type){this.type=type;}

}
#endif
