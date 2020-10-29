#include "bookdocking.h"

bookdocking::bookdocking(){}

bool bookdocking::bookadd(int id,string ISBN, string name, string author, string type, string borrowtime, string returntime, string histroy, string onsheelf, string isovertime)
{
	value = ISBN + name + author + type + borrowtime + returntime + histroy + onsheelf + isovertime;
	if (bookdatabase.insert(id, value))
	return true;
	else
	return false;

}
bool bookdocking::bookdelete(int id) {
	if (bookdatabase.remove(id))
	return true;
	else
	return false;
}

string bookdocking::booksearch(int id) {
	if (bookdatabase.select(id, value))
	return value;
}

bool bookdocking::bookexist(int id) {
	if (bookdatabase.select(id, value))
		return true;
	else
		return false;
}
bool bookdocking::bookmodifyISBN(int id, string ISBN) {
	if (bookdatabase.select(id, value)) {
		value.replace(0, 6, ISBN);
		if (bookdatabase.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool bookdocking::bookmodifyname(int id, string name) {
	if (bookdatabase.select(id, value)){
		value.replace(6, 8, name);
		if (bookdatabase.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool bookdocking::bookmodifyauthor(int id, string author) {
	if (bookdatabase.select(id, value)){
		value.replace(14, 4, author);
		if (bookdatabase.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool bookdocking::bookmodifytype(int id, string type) {
	if (bookdatabase.select(id, value)){
		value.replace(18, 4, type);
		if (bookdatabase.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool bookdocking::bookmodifyborrowtime(int id, string borrowtime) {
	if (bookdatabase.select(id, value)){
		value.replace(22, 8, borrowtime);
		if (bookdatabase.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool bookdocking::bookmodifyreturntime(int id, string returntime) {
	if (bookdatabase.select(id, value)){
		value.replace(30, 8, returntime);
		if (bookdatabase.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool bookdocking::bookmodifyhistory(int id, string history) {
	if (bookdatabase.select(id, value)){
		value.replace(38, 40, history);
		if (bookdatabase.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool bookdocking::bookmodifyonsheelf(int id, string onsheelf) {
	if (bookdatabase.select(id, value)){
		value.replace(78, 1, onsheelf);
		if (bookdatabase.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}bool bookdocking::bookmodifyisovertime(int id, string isovertime) {
	if (bookdatabase.select(id, value)){
		value.replace(79, 1, isovertime);
		if (bookdatabase.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}



