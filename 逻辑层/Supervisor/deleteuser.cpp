#include<iostream>
#include<string>
#include"supervisor.h"
#include"../UserDocking/UserDocking/userdocking.h"
#include"../UserstatesDocking/UserstatesDocking/userstatesdocking.h"


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
	userstatesdocking usdocking;
	cout << "�������ɾ���û���ID��";
	cin >> id;
	if (!udocking.userexist(id))
		cout << "���û������ڣ�";
	else
	{
		bookid = usdocking.ussearch(id);//��ǰ�û��Ľ�����Ϣ
		if (bookid == "")
		{
			if (udocking.userdelete(id))
				cout << "ɾ���û��ɹ���" << endl;
			else
				cout << "ɾ���û�ʧ�ܣ������ԣ�" << endl;
		}
		else
			cout << "���û�δ�黹ȫ��ͼ�飬����ɾ����";
	}
	
}