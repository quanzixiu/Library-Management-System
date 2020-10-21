#include "userstatesdocking.h"

userstatesdocking::userstatesdocking(){}



bool userstatesdocking::uscreate(int id,string bookid)
{
	bookid = dataformatting(120, bookid);
	value = bookid;
	if (database.insert(id, value))
	return true;
	else
	return false;

}

bool userstatesdocking::usadd(int id, string bookid) {
	if (database.select(id, value)) {
		
		for (int i = 0; i < 20; i++) {
			if (value.substr(i * 6, 6).compare("      ")==0) {
				value.replace(i * 6, 6, bookid);
				break;
			}
			
		}
		if (database.update(id, value)) {
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
	if (database.select(id, value))
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
		if (database.update(id, value)) {
			return true;
		}
		else
			return false;
	}
	
	else
		return false;
}

string userstatesdocking::ussearch(int id) {
	if (database.select(id, value))
	return value;
}

bool userstatesdocking::usexist(int id) {
	if (database.select(id, value))
		return true;
	else
		return false;
}
 


//字段如果没有达到规定大小则 将空余的地方填充空格
string dataformatting(int n, string data)
{
	data.append(n - data.size(), ' ');
	return data;
}

