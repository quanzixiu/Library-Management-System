#pragma once
#include<iostream>
#include<string>
#include"supervisor.h"
using namespace std;


//修改用户借阅信息
/*
逻辑层函数名称：修改用户 modifyuserdata()
底层函数输入参数：userid  要修改的信息
调用底层函数：
-   bool usermodifyname(int id, string name);
-   bool usermodifycollege(int id, string college);
-   bool usermodifymajor(int id, string major);
-   bool usermodifypassword(int id, string password);
-   bool usermodifyremail(int id, string email);
底层函数返回值：bool
*/
void supervisor::modifyuserdata(userdocking& ud) {
	int id;
	string op1;
	string name;
	string college;
	string major;
	string password;
	string email;
	string value;
	string ID;
	cout << "请输入待删除用户的ID：";
	cin >> ID;

	while (ID.length() > 8 || atoi(ID.c_str()))//ID不能长度超过6或者包含字母或者单独为0
	{
		cout << "输入有误，请重新输入8位以内的数字:";
		cin >> ID;
	}
	id = atoi(ID.c_str());

	if (!ud.userexist(id))
		cout << "该用户不存在！";
	else
	{
		value = ud.usersearch(id);
		//把得到的包含所有信息的字符串分发给各个字段
		name = value.substr(0, 8);
		college = value.substr(8, 4);
		major = value.substr(12, 4);
		password = value.substr(16, 16);
		email = value.substr(32, 24);
		cout << "该用户当前信息如下：" << endl;
		cout << "1.姓名:" << name << endl;
		cout << "2.学校:" << college<< endl;
		cout << "3.专业:" << major <<endl;
		cout << "4.密码:" << password <<endl;
		cout << "5.邮箱:" << email << endl;

		while (true)
		{
			cout << "可修改的用户信息:" << endl;
			cout << "1.姓名" << endl;
			cout << "2.学校" << endl;
			cout << "3.专业" << endl;
			cout << "4.密码" << endl;
			cout << "5.邮箱" << endl;
			cout << "0.退出" << endl;
			cout << "请输入对应数字进行修改:";
			cin >> op1;
			if (op1 == "0")
				break;
			else if (op1 == "1")
			{
				cout << "请依次输入要修改用户的姓名:";
				cin >> name;
				while (name.length() > 8)
				{
					cout << "输入有误，请重新输入8位以内的用户姓名：";
					cin >> name;
				}
				name = dataformatting(8, name);
				if (ud.usermodifyname(id, name))
				{
					cout << "用户信息修改成功！修改后信息如下：" << endl;
					value = ud.usersearch(id);
					//把得到的包含所有信息的字符串分发给各个字段
					name = value.substr(0, 8);
					college = value.substr(8, 4);
					major = value.substr(12, 4);
					password = value.substr(16, 16);
					email = value.substr(32, 24);
					cout << "该用户当前信息如下：" << endl;
					cout << "1.姓名:" << name << endl;
					cout << "2.学校:" << college << endl;
					cout << "3.专业:" << major << endl;
					cout << "4.密码:" << password << endl;
					cout << "5.邮箱:" << email << endl;
				}
				else
					cout << "用户信息修改失败，请重试！" << endl;
			}
			else if (op1 == "2")
			{
				cout << "请依次输入要修改用户的学校:";
				cin >> college;
				while (college.length() > 4)
				{
					cout << "输入有误，请重新输入4位以内的用户学校：";
					cin >> college;
				}
				college = dataformatting(4, college);
				if (ud.usermodifycollege(id, college))
				{
					cout << "用户信息修改成功！修改后的信息如下：" << endl;
					value = ud.usersearch(id);
					//把得到的包含所有信息的字符串分发给各个字段
					name = value.substr(0, 8);
					college = value.substr(8, 4);
					major = value.substr(12, 4);
					password = value.substr(16, 16);
					email = value.substr(32, 24);
					cout << "该用户当前信息如下：" << endl;
					cout << "1.姓名:" << name << endl;
					cout << "2.学校:" << college << endl;
					cout << "3.专业:" << major << endl;
					cout << "4.密码:" << password << endl;
					cout << "5.邮箱:" << email << endl;
				}

				else
					cout << "用户信息修改失败，请重试！" << endl;
			}
			else if (op1 == "3")
			{
				cout << "请依次输入要修改用户的专业:";
				cin >> major;
				while (major.length() > 4)
				{
					cout << "输入有误，请重新输入4位以内的用户专业：";
					cin >> major;
				}
				major = dataformatting(4, major);
				if (ud.usermodifymajor(id, major))
				{
					cout << "用户信息修改成功！" << endl;
					value = ud.usersearch(id);
					//把得到的包含所有信息的字符串分发给各个字段
					name = value.substr(0, 8);
					college = value.substr(8, 4);
					major = value.substr(12, 4);
					password = value.substr(16, 16);
					email = value.substr(32, 24);
					cout << "该用户当前信息如下：" << endl;
					cout << "1.姓名:" << name << endl;
					cout << "2.学校:" << college << endl;
					cout << "3.专业:" << major << endl;
					cout << "4.密码:" << password << endl;
					cout << "5.邮箱:" << email << endl;
				}
				else
					cout << "用户信息修改失败，请重试！" << endl;
			}
			else if (op1 == "4")
			{
				cout << "请依次输入要修改用户的密码:";
				cin >> password;
				while (password.length() > 16)
				{
					cout << "输入有误，请重新输入16位以内的用户密码：";
					cin >> password;
				}
				password = dataformatting(16, password);
				if (ud.usermodifypassword(id, password))
				{
					cout << "用户信息修改成功！" << endl;
					value = ud.usersearch(id);
					//把得到的包含所有信息的字符串分发给各个字段
					name = value.substr(0, 8);
					college = value.substr(8, 4);
					major = value.substr(12, 4);
					password = value.substr(16, 16);
					email = value.substr(32, 24);
					cout << "该用户当前信息如下：" << endl;
					cout << "1.姓名:" << name << endl;
					cout << "2.学校:" << college << endl;
					cout << "3.专业:" << major << endl;
					cout << "4.密码:" << password << endl;
					cout << "5.邮箱:" << email << endl;
				}
				else
					cout << "用户信息修改失败，请重试！" << endl;
			}
			else if (op1 == "5")
			{
				cout << "请依次输入要修改用户的邮箱:";
				cin >> email;
				while (email.length() > 24)
				{
					cout << "输入有误，请重新输入24位以内的用户邮箱：";
					cin >> email;
				}
				email = dataformatting(24, email);
				if (ud.usermodifyemail(id, email))
				{
					cout << "用户信息修改成功！" << endl;
					value = ud.usersearch(id);
					//把得到的包含所有信息的字符串分发给各个字段
					name = value.substr(0, 8);
					college = value.substr(8, 4);
					major = value.substr(12, 4);
					password = value.substr(16, 16);
					email = value.substr(32, 24);
					cout << "该用户当前信息如下：" << endl;
					cout << "1.姓名:" << name << endl;
					cout << "2.学校:" << college << endl;
					cout << "3.专业:" << major << endl;
					cout << "4.密码:" << password << endl;
					cout << "5.邮箱:" << email << endl;
				}
				else
					cout << "用户信息修改失败，请重试！" << endl;
			}
			else
				cout << "无效的输入，请重试！" << endl;
		}
	}
	
}