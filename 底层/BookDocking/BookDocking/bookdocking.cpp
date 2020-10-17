#include "bookdocking.h"

bookdocking::bookdocking(){}

string bookdocking::dataformatting(int n, string data)
{
	data.append(n - data.size(), ' ');
	return data;
}

void bookdocking::formatting(string ISBN, string name, string author, string type, string histroy) {
	ISBN = dataformatting(6, ISBN);
	name = dataformatting(8, name);
	author = dataformatting(4, author);
	type = dataformatting(4, type);
	histroy = dataformatting(20, histroy);
}

void bookdocking::negativedataformatting(string value, string ISBN, string name, string author, string type, string borrowtime, string returntime, string histroy, string onsheelf, string isovertime) {
	ISBN = value.substr(0, 6);
	name = value.substr(6, 8);
	author = value.substr(14, 4);
	type = value.substr(18, 4);
	borrowtime = value.substr(22, 8);
	returntime = value.substr(30, 8);
	histroy = value.substr(38, 20);
	onsheelf = value.substr(58, 1);
	isovertime = value.substr(59, 1);
}

bool bookdocking::bookadd(int id,string ISBN, string name, string author, string type, string borrowtime, string returntime, string histroy, string onsheelf, string isovertime)
{
	value = ISBN + name + author + type + borrowtime + returntime + histroy + onsheelf + isovertime;
	if (database.insert(id, value))
	return true;
	else
	return false;

}
bool bookdocking::bookdelete(int id) {
	if (database.remove(id))
	return true;
	else
	return false;
}

string bookdocking::booksearch(int id) {
	if (database.select(id, value))
	return value;
}

bool bookdocking::bookexist(int id) {
	if (database.select(id, value))
		return true;
	else
		return false;
}
bool bookdocking::bookmodifyISBN(int id, string ISBN) {
	if (database.select(id, value)) {
		value.replace(0, 6, ISBN);
		if (database.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool bookdocking::bookmodifyname(int id, string name) {
	if (database.select(id, value)){
		value.replace(6, 8, name);
		if (database.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool bookdocking::bookmodifyauthor(int id, string author) {
	if (database.select(id, value)){
		value.replace(14, 4, author);
		if (database.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool bookdocking::bookmodifytype(int id, string type) {
	if (database.select(id, value)){
		value.replace(18, 4, type);
		if (database.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool bookdocking::bookmodifyborrowtime(int id, string borrowtime) {
	if (database.select(id, value)){
		value.replace(22, 8, borrowtime);
		if (database.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool bookdocking::bookmodifyreturntime(int id, string returntime) {
	if (database.select(id, value)){
		value.replace(30, 8, returntime);
		if (database.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool bookdocking::bookmodifyhistroy(int id, string histroy) {
	if (database.select(id, value)){
		value.replace(38, 20, histroy);
		if (database.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool bookdocking::bookmodifyonsheelf(int id, string onsheelf) {
	if (database.select(id, value)){
		value.replace(58, 1, onsheelf);
		if (database.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}bool bookdocking::bookmodifyisovertime(int id, string isovertime) {
	if (database.select(id, value)){
		value.replace(59, 1, isovertime);
		if (database.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
