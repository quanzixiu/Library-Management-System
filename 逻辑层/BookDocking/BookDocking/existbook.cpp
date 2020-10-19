#include "bookdocking.h"
#include "supervisor.h"

//查找图书是否存在
//逻辑层函数名称：该图书是否已经存在 existbook()
//调用底层函数：bookexist(string id)
//底层函数返回值：bool
bool supervisor::existbook(int id) {
	bookdocking docking;
	if (docking.bookexist(id)) return true;
	else return false;
}