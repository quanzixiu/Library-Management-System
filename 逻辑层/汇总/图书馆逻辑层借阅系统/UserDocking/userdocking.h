#ifndef USERDOCKING_H
#define USERDOCKING_H
#include <iostream>
#include <fstream>
#include <string>
#include "userDatabase.h"
using namespace std;

class userdocking {
public:
	userdocking();

	bool useradd(int id, string name, string college, string major, string password, string email);
	bool userdelete(int id);
	string usersearch(int id);
	bool userexist(int id);
	bool usermodifyname(int id, string name);
	bool usermodifycollege(int id, string college);
	bool usermodifymajor(int id, string major);
	bool usermodifypassword(int id, string password);
	bool usermodifyemail(int id, string eamil);


private:
	userDatabase userdatabase;
	int id;
	string value;
};

#endif

