#pragma once
#include<iostream>
#include<string>
#include"supervisor.h"
using namespace std;


//�޸��û�������Ϣ
/*
�߼��㺯�����ƣ��޸��û� modifyuserdata()
�ײ㺯�����������userid  Ҫ�޸ĵ���Ϣ
���õײ㺯����
-   bool usermodifyname(int id, string name);
-   bool usermodifycollege(int id, string college);
-   bool usermodifymajor(int id, string major);
-   bool usermodifypassword(int id, string password);
-   bool usermodifyremail(int id, string email);
�ײ㺯������ֵ��bool
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
	cout << "�������ɾ���û���ID��";
	cin >> ID;

	while (ID.length() > 8 || atoi(ID.c_str()))//ID���ܳ��ȳ���6���߰�����ĸ���ߵ���Ϊ0
	{
		cout << "������������������8λ���ڵ�����:";
		cin >> ID;
	}
	id = atoi(ID.c_str());

	if (!ud.userexist(id))
		cout << "���û������ڣ�";
	else
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
		cout << "2.ѧУ:" << college<< endl;
		cout << "3.רҵ:" << major <<endl;
		cout << "4.����:" << password <<endl;
		cout << "5.����:" << email << endl;

		while (true)
		{
			cout << "���޸ĵ��û���Ϣ:" << endl;
			cout << "1.����" << endl;
			cout << "2.ѧУ" << endl;
			cout << "3.רҵ" << endl;
			cout << "4.����" << endl;
			cout << "5.����" << endl;
			cout << "0.�˳�" << endl;
			cout << "�������Ӧ���ֽ����޸�:";
			cin >> op1;
			if (op1 == "0")
				break;
			else if (op1 == "1")
			{
				cout << "����������Ҫ�޸��û�������:";
				cin >> name;
				while (name.length() > 8)
				{
					cout << "������������������8λ���ڵ��û�������";
					cin >> name;
				}
				name = dataformatting(8, name);
				if (ud.usermodifyname(id, name))
				{
					cout << "�û���Ϣ�޸ĳɹ����޸ĺ���Ϣ���£�" << endl;
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
					cout << "�û���Ϣ�޸�ʧ�ܣ������ԣ�" << endl;
			}
			else if (op1 == "2")
			{
				cout << "����������Ҫ�޸��û���ѧУ:";
				cin >> college;
				while (college.length() > 4)
				{
					cout << "������������������4λ���ڵ��û�ѧУ��";
					cin >> college;
				}
				college = dataformatting(4, college);
				if (ud.usermodifycollege(id, college))
				{
					cout << "�û���Ϣ�޸ĳɹ����޸ĺ����Ϣ���£�" << endl;
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
					cout << "�û���Ϣ�޸�ʧ�ܣ������ԣ�" << endl;
			}
			else if (op1 == "3")
			{
				cout << "����������Ҫ�޸��û���רҵ:";
				cin >> major;
				while (major.length() > 4)
				{
					cout << "������������������4λ���ڵ��û�רҵ��";
					cin >> major;
				}
				major = dataformatting(4, major);
				if (ud.usermodifymajor(id, major))
				{
					cout << "�û���Ϣ�޸ĳɹ���" << endl;
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
					cout << "�û���Ϣ�޸�ʧ�ܣ������ԣ�" << endl;
			}
			else if (op1 == "4")
			{
				cout << "����������Ҫ�޸��û�������:";
				cin >> password;
				while (password.length() > 16)
				{
					cout << "������������������16λ���ڵ��û����룺";
					cin >> password;
				}
				password = dataformatting(16, password);
				if (ud.usermodifypassword(id, password))
				{
					cout << "�û���Ϣ�޸ĳɹ���" << endl;
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
					cout << "�û���Ϣ�޸�ʧ�ܣ������ԣ�" << endl;
			}
			else if (op1 == "5")
			{
				cout << "����������Ҫ�޸��û�������:";
				cin >> email;
				while (email.length() > 24)
				{
					cout << "������������������24λ���ڵ��û����䣺";
					cin >> email;
				}
				email = dataformatting(24, email);
				if (ud.usermodifyemail(id, email))
				{
					cout << "�û���Ϣ�޸ĳɹ���" << endl;
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
					cout << "�û���Ϣ�޸�ʧ�ܣ������ԣ�" << endl;
			}
			else
				cout << "��Ч�����룬�����ԣ�" << endl;
		}
	}
	
}