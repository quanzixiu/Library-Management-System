#include<string>
#include"userdocking.h"
#include"supervisor.h"
using namespace std;

void supervisor::searchuser() {
	int id;
	string name;
	string college;
	string major;
	string password;
	string email;
	string value;
	userdocking udocking;
	cout << "������Ҫ���ҵ��û�ID:";
	cin >> id;
	if (udocking.userexist(id)) //ÿ�β�ѯǰҪ���ж�
	{
		value = udocking.usersearch(id);
		//�ѵõ��İ���������Ϣ���ַ����ַ��������ֶ�
		name = value.substr(0, 8);
		college = value.substr(8, 4);
		major = value.substr(12, 4);
		password = value.substr(16, 16);
		email = value.substr(32, 24);

		cout << "���û���ǰ��Ϣ���£�" << endl;
		cout << "1.����" << name << endl;
		cout << "2.ѧУ" << college << endl;
		cout << "3.רҵ" << major << endl;
		cout << "4.����" << password << endl;
		cout << "5.����" << email << endl;
	}
	else
	{
		cout << "���û������ڣ�" << endl;
	}
}
	