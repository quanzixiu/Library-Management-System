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
bool supervisor::deleteuser(int id) {
	string bookid;
	userdocking udocking;
	userstatesdocking usdocking;
	//���²��Դ���ɺ���
	//string bklist;
	//bklist = "123";
	//bklist = dataformatting(120, bklist);
	if (!udocking.userexist(id))
		return false;
	else
	{
		//usdocking.uscreate(id, bklist);
		bookid = usdocking.ussearch(id);//��ǰ�û��Ľ�����Ϣ
		bookid = bookid.substr(0, 120);
		cout <<"���û��ѽ�ͼ��ID��"<< bookid << endl;
		if (bookid.at(0) == ' ')
		{
			if (udocking.userdelete(id))
				return true;
			else
				return false;
		}
		else
			return false;
	}
	
}