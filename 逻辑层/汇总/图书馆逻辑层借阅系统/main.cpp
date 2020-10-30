#pragma once
#include "borrow.h"
#include "supervisor.h"
#include "returnbook.h"
int main()
{
	supervisor s;
	returnbook r;
	bookdocking bd;
	userdocking ud;
	userstatesdocking usd;
	//s.createbook();
	borrow br;
	int n = -1;
	while (n!=0)
	{
		cout << "首页" << endl;
		cout << "1.用户借阅系统" << endl;
		cout << "2.管理员系统" << endl;
		cout << "3.还书系统" << endl;
		cout << "0.退出" << endl;
		cin >> n;
		switch(n)
		{
		case 1:
			system("cls");
			br.main(bd, ud, usd);
			system("cls");
			break;
		case 2:
			system("cls");
			s.adminmain(bd,ud,usd);
			system("cls");
			break;
		case 3:
			system("cls");
			r.returnBook(bd,usd);
			system("cls");
		case 0:
			break;
		}
		//n = mainPanel();
		//if (n == 0)break;
		//main1Panel();
	}
	
	return 0;
}