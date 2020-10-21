#include<iostream>
#include<string>
#include"../UserDocking/UserDocking/userdocking.h"
#include"supervisor.h"
using namespace std;

//创建新用户
/*
逻辑层函数名称：增加用户 createuser
底层函数输入参数：userid
调用底层函数：bool useradd(int id, string name, string college, string major, string password, string email);
底层函数返回值：bool
*/
void supervisor::createuser() {
	int id;
	string name;
	string college;
	string major;
	string password;
	string email;
	userdocking udocking;

	cout << "请输入要增加的用户ID 姓名 大学 专业 密码 邮箱:";
	cin >> id >> name >> college >> major >> password >> email;

	//把输入的信息转换成规定的大小 
	name = dataformatting(8, name);
	college = dataformatting(4, college);
	major = dataformatting(4, major);
	password = dataformatting(16, password);
	email = dataformatting(24, email);
	if (udocking.userexist(id))
		cout << "该用户已经存在！";
	else {
		if (udocking.useradd(id, name, college, major, password, email))
		{
			cout << "增加用户成功！" << endl;
			cout << "该用户当前信息如下：" << endl;
			cout << "1.姓名" << name << endl;
			cout << "2.姓名" << name << endl;
			cout << "3.学校" << college << endl;
			cout << "4.专业" << major << endl;
			cout << "5.密码" << password << endl;
			cout << "6.邮箱" << email << endl;
		}
		else
		{
			cout << "增加用户失败，请重试。" << endl;
		}
	}
		
}