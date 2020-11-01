#pragma once
#include<iostream>
#include"supervisor.h"


void supervisor::adminmain(bookdocking& bd,userdocking& ud,userstatesdocking& usd)
{
	string choice;
	while (true)
	{
		if (islogin || slogin()) {
			cout << "请选择功能：" << endl;
			cout << "1.图书管理" << endl;
			cout << "2.用户管理" << endl;
			cout << "0.退出" << endl;
			cin >> choice;
			if (choice == "1")
			{
				managebook(bd);
				system("cls");
			}
			else if (choice == "2")
			{
				manageuser(ud, usd);
				system("cls");
			}
			else if (choice == "0")
			{
				islogin = false;
				break;
			}
			else
			{
				cout << "非法的输入，请重试！";
			}
		}
	}
}