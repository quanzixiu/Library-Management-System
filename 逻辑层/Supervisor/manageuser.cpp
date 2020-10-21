﻿#include "supervisor.h"
#include"../UserDocking/UserDocking/userdocking.h"
#include <iostream>
using namespace std;

void supervisor::manageuser() {
	//用户管理界面，调用上述几个用户管理函数 
	userdocking udocking;
	int op, id;
	string value;
	string name, college, major, password, email;

	while (true)
	{
		cout << "1.查找用户" << endl;
		cout << "2.增加用户" << endl;
		cout << "3.删除用户" << endl;
		cout << "4.修改用户信息" << endl;
		cout << "0.退出" << endl;
		cout << "请输入对应数字进行选择:";
		cin >> op;
		if (op == 0)
			break;
		switch (op)
		{
		case 1:
			searchuser();
			break;
		case 2:
			createuser();
			break;
		case 3:
			deleteuser();
			break;
		case 4:
			modifyuserdata();
			break;
		default:
			cout << "非法的输入,请重试！";
			break;
		}
		cout << "再见！" << endl;
	}
}

