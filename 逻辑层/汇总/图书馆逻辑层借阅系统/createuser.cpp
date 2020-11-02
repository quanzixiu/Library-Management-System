#pragma once
#include<iostream>
#include<string>
#include"supervisor.h"
using namespace std;

//�������û�
/*
�߼��㺯�����ƣ������û� createuser
�ײ㺯�����������userid
���õײ㺯����bool useradd(int id, string name, string college, string major, string password, string email);
�ײ㺯������ֵ��bool
*/
void supervisor::createuser(userdocking& ud) {
	int id;
	string name;
	string college;
	string major;
	string password;
	string email;
	string ID;

	//������
	cout << "������Ҫ���ӵ��û�ID:";
	cin >> ID;
	while (ID.length() > 8 || atoi(ID.c_str()))//ID���ܳ��ȳ���6���߰�����ĸ���ߵ���Ϊ0
	{
		cout << "������������������:";
		cin >> ID;
	}
	id = atoi(ID.c_str());

	if (ud.userexist(id))
		cout << "���û�ID�Ѿ����ڣ�"<<endl;
	else
	{
		cout << "������Ҫ���ӵ��û�����: ";
		cin >> name;
		while (name.length() > 8)
		{
			cout << "������������������8λ���ڵ��û�������";
			cin >> name;
		}

		cout << "������Ҫ���ӵ��û�ѧУ: ";
		cin >> college;
		while (college.length() > 4)
		{
			cout << "������������������4λ���ڵ��û�ѧУ��";
			cin >> college;
		}

		cout << "������Ҫ���ӵ��û�רҵ: ";
		cin >> major;
		while (major.length() > 4)
		{
			cout << "������������������4λ���ڵ��û�רҵ��";
			cin >> major;
		}

		cout << "������Ҫ���ӵ��û�����: ";
		cin >> password;
		while (password.length() > 16)
		{
			cout << "������������������16λ���ڵ��û����룺";
			cin >> password;
		}

		cout << "������Ҫ���ӵ��û�����: ";
		cin >> email;
		while (email.length() > 24)
		{
			cout << "������������������24λ���ڵ��û����䣺";
			cin >> email;
		}

		//���������Ϣת���ɹ涨�Ĵ�С 
		name = dataformatting(8, name);
		college = dataformatting(4, college);
		major = dataformatting(4, major);
		password = dataformatting(16, password);
		email = dataformatting(24, email);

		if (ud.userexist(id))
			cout << "���û�ID�Ѿ����ڣ�";
		else {
			if (ud.useradd(id, name, college, major, password, email))
			{
				cout << "�����û��ɹ���" << endl;
				cout << "���û���ǰ��Ϣ���£�" << endl;
				cout << "1.ID��" << id << endl;
				cout << "2.������" << name << endl;
				cout << "3.ѧУ��" << college << endl;
				cout << "4.רҵ��" << major << endl;
				cout << "5.���룺" << password << endl;
				cout << "6.���䣺" << email << endl;
			}
			else
			{
				cout << "�����û�ʧ�ܣ������ԡ�" << endl;
			}
		}

	}

	

	
		
}