#include "bookdocking.h"
#include "supervisor.h"
#include <string>

//删除图书
//逻辑层函数名称：删除图书 deletebook()
//调用底层函数：bookdelete(string id)
//底层函数返回值：bool
bool supervisor::deletebook(int id) {
	bookdocking docking;
	string value;
	if (!docking.bookexist(id)) return false;
	else {
		value = docking.booksearch(id);
		if (value.substr(78, 1) == "1")//如果该图书在架
		{
			if (docking.bookdelete(id))
				return true;
			else
				return false;
		}
		else return false;
	}
}