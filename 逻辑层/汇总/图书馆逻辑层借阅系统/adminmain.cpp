#pragma once
#include<iostream>
#include"supervisor.h"


void supervisor::adminmain(bookdocking& bd,userdocking& ud,userstatesdocking& usd)
{
	string choice;
	while (true)
	{
		if (islogin || slogin()) {
			cout << "��ѡ���ܣ�" << endl;
			cout << "1.ͼ�����" << endl;
			cout << "2.�û�����" << endl;
			cout << "0.�˳�" << endl;
			cin >> choice;
			if (choice == "1")
			{
				managebook(bd);
				system("cls");
			}
			else if (choice == "2")
			{
				manageuser(ud, usd);
				system("cls");
			}
			else if (choice == "0")
			{
				islogin = false;
				break;
			}
			else
			{
				cout << "�Ƿ������룬�����ԣ�";
			}
		}
	}
}