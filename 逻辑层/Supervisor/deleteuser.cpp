#include<iostream>
#include<string>
#include"supervisor.h"
#include"../UserDocking/UserDocking/userdocking.h"


//ɾ���û�
/*
�߼��㺯�����ƣ�ɾ���û� deleteuser()
�ײ㺯��������� ��userid
���õײ㺯����userdelete(int id)
�ײ㺯������ֵ��bool
*/
void supervisor::deleteuser() {
	int id;
	string bookid;
	userdocking udocking;
	cout << "�������ɾ���û���ID��";
	cin >> id;
	if (!udocking.userexist(id))
		cout << "���û������ڣ�";
	else
	{
		if (udocking.userdelete(id))
			cout << "ɾ���û��ɹ���" << endl;
		else
			cout << "ɾ���û�ʧ�ܣ������ԣ�" << endl;
	}
	
}