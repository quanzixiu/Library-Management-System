#pragma once
#include<string>
#include"supervisor.h"
using namespace std;

void supervisor::searchuser(userdocking& ud) {
	int id;
	string name;
	string college;
	string major;
	string password;
	string email;
	string value;
	string ID;
	cout << "�������ɾ���û���ID��";
	cin >> ID;
	while (ID.length() > 8 || atoi(ID.c_str()))//ID���ܳ��ȳ���6���߰�����ĸ���ߵ���Ϊ0
	{
		cout << "������������������8λ���ڵ�����:";
		cin >> ID;
	}
	id = atoi(ID.c_str());

	if (ud.userexist(id)) //ÿ�β�ѯǰҪ���ж�
	{
		value = ud.usersearch(id);
		//�ѵõ��İ���������Ϣ���ַ����ַ��������ֶ�
		name = value.substr(0, 8);
		college = value.substr(8, 4);
		major = value.substr(12, 4);
		password = value.substr(16, 16);
		email = value.substr(32, 24);

		cout << "���û���ǰ��Ϣ���£�" << endl;
		cout << "1.����:" << name << endl;
		cout << "2.ѧУ:" << college << endl;
		cout << "3.רҵ:" << major << endl;
		cout << "4.����:" << password << endl;
		cout << "5.����:" << email << endl;
	}
	else
	{
		cout << "���û������ڣ�" << endl;
	}
}
	