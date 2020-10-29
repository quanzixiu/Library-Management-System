#include "bookdocking.h"
#include "supervisor.h"
#include <string>
#include <iostream>

//增加新图书
//逻辑层函数名称：增加图书 createbook
//调用底层函数：bookadd(string ISBN,string name,string author,string type,string id,string borrowtime,string returntime,string history, bool onsheelf,bool isovertime;)
//底层函数返回值：bool
bool supervisor::createbook(int id,string ISBN,string name,string author,string type) {
	bookdocking docking;
	string borrowtime, returntime, history, onsheelf, isovertime;
	borrowtime = "00-00-00";
	returntime = "00-00-00";
	history = "";
	onsheelf = "1";
	isovertime = "0";
	string value;

	if (docking.bookexist(id)) {
		return false;
	}
	else {
		//把输入的信息转换成规定的大小 
		ISBN = dataformatting(6, ISBN);
		name = dataformatting(8, name);
		author = dataformatting(4, author);
		type = dataformatting(4, type);
		history = dataformatting(40, history);
		if (docking.bookadd(id, ISBN, name, author, type, borrowtime, returntime, history, onsheelf, isovertime))
			return true;
		else
			return false;
	}
}

