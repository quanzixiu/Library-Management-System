#pragma once
#include "supervisor.h"

//删除图书
//逻辑层函数名称：删除图书 deletebook()
//调用底层函数：bookdelete(string id)
//底层函数返回值：bool
void supervisor::deletebook(bookdocking& bd) {
	string value;
	int id;
	cout << "请输入待删除图书的ID：";
	cin >> id;
	if (!bd.bookexist(id)) cout << "该图书不存在！" << endl;	
	else {
		value = bd.booksearch(id);
		if (value.substr(78, 1) == "1")//如果该图书在架
		{
			if (bd.bookdelete(id))
				cout << "删除成功！" << endl;
			else
				cout << "删除失败！" << endl;
		}
		else cout << "该图书尚未归还，无法删除！" << endl;
	}
}