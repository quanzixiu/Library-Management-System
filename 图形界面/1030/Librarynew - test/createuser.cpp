#include<iostream>
#include<string>
#include"userdocking.h"
#include"supervisor.h"
using namespace std;

//�������û�
/*
�߼��㺯�����ƣ������û� createuser
�ײ㺯�����������userid
���õײ㺯����bool useradd(int id, string name, string college, string major, string password, string email);
�ײ㺯������ֵ��bool
*/
bool supervisor::createuser(int id,string name,string password,string college,
							string major, string email) 
{
	userdocking udocking;
	if (udocking.userexist(id))
		return false;
	else
	{
		//���������Ϣת���ɹ涨�Ĵ�С 
		name = dataformatting(8, name);
		college = dataformatting(4, college);
		major = dataformatting(4, major);
		password = dataformatting(16, password);
		email = dataformatting(24, email);

			if (udocking.useradd(id, name, college, major, password, email))
				return true;
			else
				return false;


	}

	

	
		
}
