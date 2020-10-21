#include"../BookDocking/BookDocking/bookdocking.h"
#include "supervisor.h"

//删除图书
//逻辑层函数名称：删除图书 deletebook()
//调用底层函数：bookdelete(string id)
//底层函数返回值：bool
void supervisor::deletebook() {
	bookdocking docking;
	string value;
	int id;
	cout << "请输入待删除图书的ID：";
	cin >> id;
	value = docking.booksearch(id);
	if (!docking.bookexist(id)) cout << "该图书不存在！" << endl;
	else {
		if (value.substr(58, 1) == "1")//如果该图书在架
		{
			if (docking.bookdelete(id))
				cout << "删除成功！" << endl;
			else
				cout << "删除失败！" << endl;
		}
		else cout << "该图书尚未归还，无法删除！";
	}
}