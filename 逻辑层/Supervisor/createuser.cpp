#include<iostream>
#include<string>
#include"../UserDocking/UserDocking/userdocking.h"
#include"supervisor.h"
using namespace std;

//�������û�
/*
�߼��㺯�����ƣ������û� createuser
�ײ㺯�����������userid
���õײ㺯����bool useradd(int id, string name, string college, string major, string password, string email);
�ײ㺯������ֵ��bool
*/
void supervisor::createuser() {
	int id;
	string name;
	string college;
	string major;
	string password;
	string email;
	userdocking udocking;

	cout << "������Ҫ���ӵ��û�ID ���� ��ѧ רҵ ���� ����:";
	cin >> id >> name >> college >> major >> password >> email;

	//���������Ϣת���ɹ涨�Ĵ�С 
	name = dataformatting(8, name);
	college = dataformatting(4, college);
	major = dataformatting(4, major);
	password = dataformatting(16, password);
	email = dataformatting(24, email);
	if (udocking.userexist(id))
		cout << "���û��Ѿ����ڣ�";
	else {
		if (udocking.useradd(id, name, college, major, password, email))
		{
			cout << "�����û��ɹ���" << endl;
			cout << "���û���ǰ��Ϣ���£�" << endl;
			cout << "1.����" << name << endl;
			cout << "2.����" << name << endl;
			cout << "3.ѧУ" << college << endl;
			cout << "4.רҵ" << major << endl;
			cout << "5.����" << password << endl;
			cout << "6.����" << email << endl;
		}
		else
		{
			cout << "�����û�ʧ�ܣ������ԡ�" << endl;
		}
	}
		
}