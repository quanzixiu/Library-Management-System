#pragma once
#include<iostream>
#include"supervisor.h"


void supervisor::adminmain(bookdocking& bd,userdocking& ud,userstatesdocking& usd)
{
	supervisor admin;
	string choice;
	while (true)
	{
		if (admin.slogin())
		{
			cout << "��ѡ���ܣ�" << endl;
			cout << "1.ͼ�����" << endl;
			cout << "2.�û�����" << endl;
			cout << "0.�˳�" << endl;
			cin >> choice;
			if (choice == "1")
			{
				admin.managebook(bd);
			}
			else if (choice == "2")
			{
				admin.manageuser(ud,usd);
			}
			else if (choice == "0")
			{
				break;
			}
			else
			{
				cout << "�Ƿ������룬�����ԣ�";
			}
		}
	}
}