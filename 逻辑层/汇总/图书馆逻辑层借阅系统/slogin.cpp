#pragma once
#include<iostream>
#include"supervisor.h"
#include<string>

bool supervisor::slogin() {
	string id;
	string password;
	string ID;
	ID = "0";
	string Password;
	Password = "admin";
	cout << "请输入管理员ID：";
	cin >> id;
	cout << "请输入管理员密码：";
	cin >> password;
	if (id == ID)
		if (Password == password)
		{
			system("cls");
			islogin = true;
			return true;
		}
		else {
			system("cls");
			cout << "登陆失败！请重新输入！" << endl;
			return false;
		}
	else {
		system("cls");
		cout << "登陆失败！请重新输入！" << endl;
		return false;
	}
}