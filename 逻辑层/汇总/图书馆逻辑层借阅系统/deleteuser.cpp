#pragma once
#include<iostream>
#include<string>
#include"supervisor.h"


//ɾ���û�
/*
�߼��㺯�����ƣ�ɾ���û� deleteuser()
�ײ㺯��������� ��userid
���õײ㺯����userdelete(int id)
�ײ㺯������ֵ��bool
*/
void supervisor::deleteuser(userdocking& ud, userstatesdocking& usd) {
	int id;
	string bookid;
	//string bklist;
	//bklist = "";
	//bklist = dataformatting(120, bklist);
	cout << "�������ɾ���û���ID��";
	cin >> id;
	if (!ud.userexist(id))
		cout << "���û������ڣ�"<<endl;
	else
	{
		//usd.uscreate(id, bklist);
		bookid = usd.ussearch(id);//��ǰ�û��Ľ�����Ϣ
		bookid = bookid.substr(0, 120);
		cout <<"���û��ѽ�ͼ��ID��"<< bookid << endl;
		if (bookid.at(0)==' ')
		{
			if (ud.userdelete(id))
				cout << "ɾ���û��ɹ���" << endl;
			else
				cout << "ɾ���û�ʧ�ܣ������ԣ�" << endl;
		}
		else
			cout << "���û�δ�黹ȫ��ͼ�飬����ɾ����" << endl;
	}
	
}