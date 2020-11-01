#pragma once
#include "supervisor.h"
#include <iostream>
using namespace std;

void supervisor::manageuser(userdocking& ud, userstatesdocking& usd) {
	//用户管理界面，调用上述几个用户管理函数 
	int id;
	string op;
	string value;
	string name, college, major, password, email;

	while (true)
	{
		system("cls");
		cout << "1.查找用户" << endl;
		cout << "2.增加用户" << endl;
		cout << "3.删除用户" << endl;
		cout << "4.修改用户信息" << endl;
		cout << "0.退出" << endl;
		cout << "请输入对应数字进行选择:";
		cin >> op;
		if (op == "0")
		{
			cout << "再见！";
			break;
		}
		else if(op=="1")
			searchuser(ud);
		else if (op == "2")
			createuser(ud);
		else if (op == "3")
			deleteuser(ud,usd);
		else if (op == "4")
			modifyuserdata(ud);
		else
			cout << "非法的输入，请重试！" << endl;
		
	}
}

