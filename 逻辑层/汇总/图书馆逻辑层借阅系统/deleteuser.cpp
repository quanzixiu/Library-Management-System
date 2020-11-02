#pragma once
#include<iostream>
#include<string>
#include"supervisor.h"


//删除用户
/*
逻辑层函数名称：删除用户 deleteuser()
底层函数输入参数 ：userid
调用底层函数：userdelete(int id)
底层函数返回值：bool
*/
void supervisor::deleteuser(userdocking& ud, userstatesdocking& usd) {
	int id;
	string bookid;
	string ID;
	cout << "请输入待删除用户的ID：";
	cin >> ID;
	while (ID.length() > 8 || atoi(ID.c_str()))//ID不能长度超过6或者包含字母或者单独为0
	{
		cout << "输入有误，请重新输入8位以内的数字:";
		cin >> ID;
	}
	id = atoi(ID.c_str());
	if (!ud.userexist(id))
		cout << "该用户不存在！"<<endl;
	else
	{
		bookid = usd.ussearch(id);//当前用户的借阅信息
		bookid = bookid.substr(0, 120);
		cout <<"该用户已借图书ID："<< bookid << endl;
		if (bookid.at(0)==' ')
		{
			if (ud.userdelete(id))
				cout << "删除用户成功！" << endl;
			else
				cout << "删除用户失败，请重试！" << endl;
		}
		else
			cout << "该用户未归还全部图书，不能删除！" << endl;
	}
	
}