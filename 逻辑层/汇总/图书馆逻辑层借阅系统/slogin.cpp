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