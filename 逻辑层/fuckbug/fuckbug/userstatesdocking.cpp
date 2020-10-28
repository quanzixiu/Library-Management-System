#include "userstatesdocking.h"

userstatesdocking::userstatesdocking(){}



bool userstatesdocking::uscreate(int id,string bookid)
{
	
	value = bookid;
	if (userstatesdatabase.insert(id, value))
	return true;
	else
	return false;

}

bool userstatesdocking::usadd(int id, string bookid) {
	if (userstatesdatabase.select(id, value)) {
		
		for (int i = 0; i < 20; i++) {
			if (value.substr(i * 6, 6).compare("      ")==0) {
				value.replace(i * 6, 6, bookid);
				break;
			}
			
		}
		if (userstatesdatabase.update(id, value)) {
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

bool userstatesdocking::usdelete(int id,string bookid) {
	string str;
	if (userstatesdatabase.select(id, value))
	{
		for (int i = 0; i < 20; i++) {
			if (value.substr(i * 6, 6).compare(bookid)==0) {
				str = value.substr(i * 6 + 6, 120 - (i * 6 + 6));
				value.replace(i * 6, 120-(i*6), str);
				value = value + "      ";
				value = value.substr(0, 120);
				break;	
			}
		}
		if (userstatesdatabase.update(id, value)) {
			return true;
		}
		else
			return false;
	}
	
	else
		return false;
}

string userstatesdocking::ussearch(int id) {
	if (userstatesdatabase.select(id, value))
		return value;
}

bool userstatesdocking::usexist(int id) {
	if (userstatesdatabase.select(id, value))
		return true;
	else
		return false;
}

bool userstatesdocking::usdeleteall(int id) {
	if (userstatesdatabase.remove(id))
		return true;
	else
		return false;
}

