#include "bookdocking.h"
#include "supervisor.h"

//删除图书
//逻辑层函数名称：删除图书 deletebook()
//调用底层函数：bookdelete(string id)
//底层函数返回值：bool
bool supervisor::deletebook() {
	supervisor admin;
	bookdocking docking;
	string value;
	int id;
	cout << "请输入待删除图书的ID：";
	cin >> id;
	value = docking.booksearch(id);
	if (!admin.existbook(id)) cout << "该图书不存在！" << endl;
	else {
		if (value.substr(58, 1) == "1")
		{
			if (docking.bookdelete(id))
				cout << "success" << endl;
			else
				cout << "failure" << endl;
		}
		else cout << "该图书尚未归还，无法删除！";
	}
}