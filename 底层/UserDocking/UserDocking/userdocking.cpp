#include "userdocking.h"

userdocking::userdocking(){}



bool userdocking::useradd(int id, string name, string college, string major, string password, string email)
{
	value = name + college + major + password + email;
	if (database.insert(id, value))
	return true;
	else
	return false;
}
bool userdocking::userdelete(int id) {
	if (database.remove(id))
	return true;
	else
	return false;
}

string userdocking::usersearch(int id) {
	if (database.select(id, value))
	return value;
}

bool userdocking::userexist(int id) {
	if (database.select(id, value))
		return true;
	else
		return false;
}
bool userdocking::usermodifyname(int id, string name) {
	if (database.select(id, value)) {
		value.replace(0, 8, name);
		if (database.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool userdocking::usermodifycollege(int id, string college) {
	if (database.select(id, value)){
		value.replace(8, 4, college);
		if (database.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool userdocking::usermodifymajor(int id, string major) {
	if (database.select(id, value)){
		value.replace(12, 4, major);
		if (database.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool userdocking::usermodifypassword(int id, string password) {
	if (database.select(id, value)){
		value.replace(16, 16, password);
		if (database.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool userdocking::usermodifyemail(int id, string email) {
	if (database.select(id, value)){
		value.replace(32, 24, email);
		if (database.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}


//字段如果没有达到规定大小则 将空余的地方填充空格
string dataformatting(int n, string data)
{
	data.append(n - data.size(), ' ');
	return data;
}

