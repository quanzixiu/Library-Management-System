#include "userdocking.h"

userdocking::userdocking(){}



bool userdocking::useradd(int id, string name, string college, string major, string password, string email)
{
	value = name + college + major + password + email;
	if (userdatabase.insert(id, value))
	return true;
	else
	return false;
}
bool userdocking::userdelete(int id) {
	if (userdatabase.remove(id))
	return true;
	else
	return false;
}

string userdocking::usersearch(int id) {
	if (userdatabase.select(id, value))
	return value;
}

bool userdocking::userexist(int id) {
	if (userdatabase.select(id, value))
		return true;
	else
		return false;
}
bool userdocking::usermodifyname(int id, string name) {
	if (userdatabase.select(id, value)) {
		value.replace(0, 8, name);
		if (userdatabase.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool userdocking::usermodifycollege(int id, string college) {
	if (userdatabase.select(id, value)){
		value.replace(8, 4, college);
		if (userdatabase.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool userdocking::usermodifymajor(int id, string major) {
	if (userdatabase.select(id, value)){
		value.replace(12, 4, major);
		if (userdatabase.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool userdocking::usermodifypassword(int id, string password) {
	if (userdatabase.select(id, value)){
		value.replace(16, 16, password);
		if (userdatabase.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool userdocking::usermodifyemail(int id, string email) {
	if (userdatabase.select(id, value)){
		value.replace(32, 24, email);
		if (userdatabase.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}



