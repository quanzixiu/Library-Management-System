#include<iostream>
#include<string>
#include"supervisor.h"
#include"userdocking.h"
#include"userstatesdocking.h"



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
	//string bklist;
	//bklist = "123";
	//bklist = dataformatting(120, bklist);
	cout << "�������ɾ���û���ID��";
	cin >> id;
	if (!udocking.userexist(id))
		cout << "���û������ڣ�"<<endl;
	else
	{
		//usdocking.uscreate(id, bklist);
		bookid = usdocking.ussearch(id);//��ǰ�û��Ľ�����Ϣ
		bookid = bookid.substr(0, 120);
		cout <<"���û��ѽ�ͼ��ID��"<< bookid << endl;
		if (bookid.at(0)==' ')
		{
			if (udocking.userdelete(id))
				cout << "ɾ���û��ɹ���" << endl;
			else
				cout << "ɾ���û�ʧ�ܣ������ԣ�" << endl;
		}
		else
			cout << "���û�δ�黹ȫ��ͼ�飬����ɾ����" << endl;
	}
	
}