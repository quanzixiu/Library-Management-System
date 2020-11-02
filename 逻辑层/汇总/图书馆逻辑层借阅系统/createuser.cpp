#pragma once
#include<iostream>
#include<string>
#include"supervisor.h"
using namespace std;

//创建新用户
/*
逻辑层函数名称：增加用户 createuser
底层函数输入参数：userid
调用底层函数：bool useradd(int id, string name, string college, string major, string password, string email);
底层函数返回值：bool
*/
void supervisor::createuser(userdocking& ud) {
	int id;
	string name;
	string college;
	string major;
	string password;
	string email;
	string ID;

	//输入检查
	cout << "请输入要增加的用户ID:";
	cin >> ID;
	while (ID.length() > 8 || atoi(ID.c_str()))//ID不能长度超过6或者包含字母或者单独为0
	{
		cout << "输入有误，请重新输入:";
		cin >> ID;
	}
	id = atoi(ID.c_str());

	if (ud.userexist(id))
		cout << "该用户ID已经存在！"<<endl;
	else
	{
		cout << "请输入要增加的用户姓名: ";
		cin >> name;
		while (name.length() > 8)
		{
			cout << "输入有误，请重新输入8位以内的用户姓名：";
			cin >> name;
		}

		cout << "请输入要增加的用户学校: ";
		cin >> college;
		while (college.length() > 4)
		{
			cout << "输入有误，请重新输入4位以内的用户学校：";
			cin >> college;
		}

		cout << "请输入要增加的用户专业: ";
		cin >> major;
		while (major.length() > 4)
		{
			cout << "输入有误，请重新输入4位以内的用户专业：";
			cin >> major;
		}

		cout << "请输入要增加的用户密码: ";
		cin >> password;
		while (password.length() > 16)
		{
			cout << "输入有误，请重新输入16位以内的用户密码：";
			cin >> password;
		}

		cout << "请输入要增加的用户邮箱: ";
		cin >> email;
		while (email.length() > 24)
		{
			cout << "输入有误，请重新输入24位以内的用户邮箱：";
			cin >> email;
		}

		//把输入的信息转换成规定的大小 
		name = dataformatting(8, name);
		college = dataformatting(4, college);
		major = dataformatting(4, major);
		password = dataformatting(16, password);
		email = dataformatting(24, email);

		if (ud.userexist(id))
			cout << "该用户ID已经存在！";
		else {
			if (ud.useradd(id, name, college, major, password, email))
			{
				cout << "增加用户成功！" << endl;
				cout << "该用户当前信息如下：" << endl;
				cout << "1.ID：" << id << endl;
				cout << "2.姓名：" << name << endl;
				cout << "3.学校：" << college << endl;
				cout << "4.专业：" << major << endl;
				cout << "5.密码：" << password << endl;
				cout << "6.邮箱：" << email << endl;
			}
			else
			{
				cout << "增加用户失败，请重试。" << endl;
			}
		}

	}

	

	
		
}