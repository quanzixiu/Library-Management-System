#include<iostream>
#include<string>
#include"../UserDocking/UserDocking/userdocking.h"
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
void supervisor::modifyuserdata() {
	int id;
	int op1;
	userdocking udocking;
	string name;
	string college;
	string major;
	string password;
	string email;
	string value;

	cout << "请输入要修改用户的ID：";
	cin >> id;
	if (!udocking.userexist(id))
		cout << "该用户不存在！";
	else
	{
		value = udocking.usersearch(id);
		//把得到的包含所有信息的字符串分发给各个字段
		name = value.substr(0, 8);
		college = value.substr(8, 4);
		major = value.substr(12, 4);
		password = value.substr(16, 16);
		email = value.substr(32, 24);
		cout << "该用户当前信息如下：" << endl;
		cout << "1.姓名" << name << endl;
		cout << "2.学校" << college<< endl;
		cout << "3.专业" << major <<endl;
		cout << "4.密码" << password <<endl;
		cout << "5.邮箱" << email << endl;

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
			if (op1 == 0)
				break;
			switch (op1)
			{
			case 1:
				cout << "请依次输入要修改用户的姓名:";
				cin >> name;
				name = dataformatting(8, name);
				if (udocking.usermodifyname(id, name))
				{
					cout << "用户信息修改成功！修改后信息如下：" << endl;
					value = udocking.usersearch(id);
					//把得到的包含所有信息的字符串分发给各个字段
					name = value.substr(0, 8);
					college = value.substr(8, 4);
					major = value.substr(12, 4);
					password = value.substr(16, 16);
					email = value.substr(32, 24);
					cout << "该用户当前信息如下：" << endl;
					cout << "1.姓名" << name << endl;
					cout << "2.学校" << college << endl;
					cout << "3.专业" << major << endl;
					cout << "4.密码" << password << endl;
					cout << "5.邮箱" << email << endl;
				}
				else
					cout << "用户信息修改失败，请重试！" << endl;
				break;
			case 2:
				cout << "请依次输入要修改用户的学校:";
				cin >> college;
				college = dataformatting(4, college);
				if (udocking.usermodifycollege(id, college))
				{
					cout << "用户信息修改成功！修改后的信息如下：" << endl;
					value = udocking.usersearch(id);
					//把得到的包含所有信息的字符串分发给各个字段
					name = value.substr(0, 8);
					college = value.substr(8, 4);
					major = value.substr(12, 4);
					password = value.substr(16, 16);
					email = value.substr(32, 24);
					cout << "该用户当前信息如下：" << endl;
					cout << "1.姓名" << name << endl;
					cout << "2.学校" << college << endl;
					cout << "3.专业" << major << endl;
					cout << "4.密码" << password << endl;
					cout << "5.邮箱" << email << endl;
				}

				else
					cout << "用户信息修改失败，请重试！" << endl;
				break;
			case 3:
				cout << "请依次输入要修改用户的专业:";
				cin >> major;
				major = dataformatting(4, major);
				if (udocking.usermodifymajor(id, major))
				{
					cout << "用户信息修改成功！" << endl;
					value = udocking.usersearch(id);
					//把得到的包含所有信息的字符串分发给各个字段
					name = value.substr(0, 8);
					college = value.substr(8, 4);
					major = value.substr(12, 4);
					password = value.substr(16, 16);
					email = value.substr(32, 24);
					cout << "该用户当前信息如下：" << endl;
					cout << "1.姓名" << name << endl;
					cout << "2.学校" << college << endl;
					cout << "3.专业" << major << endl;
					cout << "4.密码" << password << endl;
					cout << "5.邮箱" << email << endl;
				}
				else
					cout << "用户信息修改失败，请重试！" << endl;
				break;
			case 4:
				cout << "请依次输入要修改用户的密码:";
				cin >> password;
				password = dataformatting(4, password);
				if (udocking.usermodifypassword(id, password))
				{
					cout << "用户信息修改成功！" << endl;
					value = udocking.usersearch(id);
					//把得到的包含所有信息的字符串分发给各个字段
					name = value.substr(0, 8);
					college = value.substr(8, 4);
					major = value.substr(12, 4);
					password = value.substr(16, 16);
					email = value.substr(32, 24);
					cout << "该用户当前信息如下：" << endl;
					cout << "1.姓名" << name << endl;
					cout << "2.学校" << college << endl;
					cout << "3.专业" << major << endl;
					cout << "4.密码" << password << endl;
					cout << "5.邮箱" << email << endl;
				}
				else
					cout << "用户信息修改失败，请重试！" << endl;
				break;
			case 5:
				cout << "请依次输入要修改用户的邮箱:";
				cin >> email;
				email = dataformatting(8, email);
				if (udocking.usermodifyemail(id, email))
				{
					cout << "用户信息修改成功！" << endl;
					value = udocking.usersearch(id);
					//把得到的包含所有信息的字符串分发给各个字段
					name = value.substr(0, 8);
					college = value.substr(8, 4);
					major = value.substr(12, 4);
					password = value.substr(16, 16);
					email = value.substr(32, 24);
					cout << "该用户当前信息如下：" << endl;
					cout << "1.姓名" << name << endl;
					cout << "2.学校" << college << endl;
					cout << "3.专业" << major << endl;
					cout << "4.密码" << password << endl;
					cout << "5.邮箱" << email << endl;
				}
				else
					cout << "用户信息修改失败，请重试！" << endl;
				break;
			default:
				cout << "无效的输入，请重试！" << endl;
				break;
			}
		}
	}
	
}