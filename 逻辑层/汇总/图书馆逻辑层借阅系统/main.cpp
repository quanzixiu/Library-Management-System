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
	borrow br;

	/*int userid = 1;
	tuple<int,int*> t=br.qtrebookbor(1,usd);
	int cnt=get<0>(t);
	int* p = get<1>(t);
	for (int i = 0; i < cnt; i++)
	{
		cout<<p[i]<<endl;
	}
	delete[] p;
	*/

	//下面注释内容用于自动添加6个用户和21本书用作测试
	/*for (int i = 0; i < 6; i++)
	{
		ud.useradd(i + 1, br.dataformatting(8, to_string(i + 1)), br.dataformatting(4, to_string(i + 1)), br.dataformatting(4, to_string(i + 1)), br.dataformatting(16, to_string(i + 1)), br.dataformatting(24, to_string(i + 1)));
	}
	for (int i = 0; i < 21; i++)
	{
		bd.bookadd(i + 1, br.dataformatting(6, to_string(i + 1)), br.dataformatting(8, to_string(i + 1)), br.dataformatting(4, to_string(i + 1)), br.dataformatting(4, to_string(i + 1)), br.dataformatting(8, "00000000"), br.dataformatting(8, "00000000"), br.dataformatting(40, " "), br.dataformatting(1, to_string(1)), br.dataformatting(1, to_string(0)));
	}*/
	
	int n = 0;
	while (n!=-1)
	{
		cout << "首页" << endl;
		cout << "1.用户借阅系统" << endl;
		cout << "2.管理员系统" << endl;
		cout << "3.还书系统" << endl;
		cout << "-1.退出" << endl;
		string str;
		cin >> str;
		n = atoi(str.c_str());
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
		case -1:
			break;
		default:
			system("cls");
			cout << "输入错误！请重新输入！" << endl;
			break;
		}
	
	}
	
	return 0;
}