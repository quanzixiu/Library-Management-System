#include<iostream>
#include"supervisor.h"
#include"returnbook.h"


int main()
{
	supervisor admin;
	//returnbook book;
	string choice;
	while (true)
	{
		if (admin.slogin())
		{
			cout << "请选择功能：" << endl;
			cout << "1.图书管理" << endl;
			cout << "2.用户管理" << endl;
			cout << "0.退出" << endl;
			cin >> choice;
			if (choice == "1")
			{
				admin.managebook();
			}
			else if (choice == "2")
			{
				admin.manageuser();
			}
			else if (choice == "0")
			{
				break;
			}
			else
			{
				cout << "非法的输入，请重试！";
			}
		}
	}
	//还书应该和主菜单在一起，即三个选项：1管理员登录 2用户登录 3还书 
	//book.returnBook();
	return 0;
}