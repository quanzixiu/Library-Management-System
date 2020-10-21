#include<iostream>
#include<string>
#include"../UserDocking/UserDocking/userdocking.h"
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
void supervisor::modifyuserdata() {
	int id;
	int op1;
	userdocking udocking;
	string name;
	string college;
	string major;
	string password;
	string email;
	string value;

	cout << "������Ҫ�޸��û���ID��";
	cin >> id;
	if (!udocking.userexist(id))
		cout << "���û������ڣ�";
	else
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
		cout << "2.ѧУ" << college<< endl;
		cout << "3.רҵ" << major <<endl;
		cout << "4.����" << password <<endl;
		cout << "5.����" << email << endl;

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
			if (op1 == 0)
				break;
			switch (op1)
			{
			case 1:
				cout << "����������Ҫ�޸��û�������:";
				cin >> name;
				name = dataformatting(8, name);
				if (udocking.usermodifyname(id, name))
				{
					cout << "�û���Ϣ�޸ĳɹ����޸ĺ���Ϣ���£�" << endl;
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
					cout << "�û���Ϣ�޸�ʧ�ܣ������ԣ�" << endl;
				break;
			case 2:
				cout << "����������Ҫ�޸��û���ѧУ:";
				cin >> college;
				college = dataformatting(4, college);
				if (udocking.usermodifycollege(id, college))
				{
					cout << "�û���Ϣ�޸ĳɹ����޸ĺ����Ϣ���£�" << endl;
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
					cout << "�û���Ϣ�޸�ʧ�ܣ������ԣ�" << endl;
				break;
			case 3:
				cout << "����������Ҫ�޸��û���רҵ:";
				cin >> major;
				major = dataformatting(4, major);
				if (udocking.usermodifymajor(id, major))
				{
					cout << "�û���Ϣ�޸ĳɹ���" << endl;
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
					cout << "�û���Ϣ�޸�ʧ�ܣ������ԣ�" << endl;
				break;
			case 4:
				cout << "����������Ҫ�޸��û�������:";
				cin >> password;
				password = dataformatting(4, password);
				if (udocking.usermodifypassword(id, password))
				{
					cout << "�û���Ϣ�޸ĳɹ���" << endl;
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
					cout << "�û���Ϣ�޸�ʧ�ܣ������ԣ�" << endl;
				break;
			case 5:
				cout << "����������Ҫ�޸��û�������:";
				cin >> email;
				email = dataformatting(8, email);
				if (udocking.usermodifyemail(id, email))
				{
					cout << "�û���Ϣ�޸ĳɹ���" << endl;
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
					cout << "�û���Ϣ�޸�ʧ�ܣ������ԣ�" << endl;
				break;
			default:
				cout << "��Ч�����룬�����ԣ�" << endl;
				break;
			}
		}
	}
	
}