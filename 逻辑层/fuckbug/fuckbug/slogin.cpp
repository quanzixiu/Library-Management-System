#include<iostream>
#include"supervisor.h"
#include<string>

bool supervisor::slogin() {
	int id;
	string password;
	int ID=000;
	string Password;
	Password = "admin";
	cout << "请输入管理员ID：";
	cin >> id;
	cout << "请输入管理员密码：";
	cin >> password;
	if (id == ID)
		if (Password == password)
			return true;
		else
			return false;
	else return false;
}