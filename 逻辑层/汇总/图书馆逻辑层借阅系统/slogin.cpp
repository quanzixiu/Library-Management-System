#pragma once
#include<iostream>
#include"supervisor.h"
#include<string>

bool supervisor::slogin() {
	int id;
	string password;
	int ID=000;
	string Password;
	Password = "admin";
	cout << "���������ԱID��";
	cin >> id;
	cout << "���������Ա���룺";
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
			cout << "��½ʧ�ܣ����������룡" << endl;
			return false;
		}
	else {
		system("cls");
		cout << "��½ʧ�ܣ����������룡" << endl;
		return false;
	}
}