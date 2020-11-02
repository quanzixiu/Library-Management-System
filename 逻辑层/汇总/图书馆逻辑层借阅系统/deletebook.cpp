#pragma once
#include "supervisor.h"

//删除图书
//逻辑层函数名称：删除图书 deletebook()
//调用底层函数：bookdelete(string id)
//底层函数返回值：bool
void supervisor::deletebook(bookdocking& bd) {
	string value;
	int id;
	string ID;
	cout << "请输入待删除图书的ID：";
	cin >> ID;
	while (ID.length() > 6 || atoi(ID.c_str()))//ID不能长度超过6或者包含字母或者单独为0
	{
		cout << "输入有误，请重新输入6位以内的数字:";
		cin >> ID;
	}
	id = atoi(ID.c_str());
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