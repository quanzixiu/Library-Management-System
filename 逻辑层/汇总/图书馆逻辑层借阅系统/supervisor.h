#pragma once
#include<iostream>
#include<string>
#include"BookDocking/bookdocking.h"
#include"UserDocking/userdocking.h"
#include"UserstatesDocking/userstatesdocking.h"

using namespace std;

class supervisor {

public:
	bool islogin;
	void adminmain(bookdocking& bd, userdocking& ud, userstatesdocking& usd);
	bool slogin();//����Ա��¼;
	void searchuser(userdocking& ud);//�����û�
	void createuser(userdocking& ud);//�������û�
	void modifyuserdata(userdocking& ud);//�޸��û�������Ϣ
	void deleteuser(userdocking& ud, userstatesdocking& usd);//ɾ���û�

	supervisor() { islogin=false; }

	void createbook(bookdocking& bd);//������ͼ��
	void modifybook(bookdocking& bd);//�޸�ͼ����Ϣ
	void deletebook(bookdocking& bd);//ɾ��ͼ��

	void manageuser(userdocking& ud, userstatesdocking& usd);//�û�������棬�������������û�������
	void managebook(bookdocking& bd);//ͼ�������棬��������ͼ�������
	string dataformatting(int n, string data);
};