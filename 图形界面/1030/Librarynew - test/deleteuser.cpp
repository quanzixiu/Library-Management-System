#include<iostream>
#include<string>
#include"supervisor.h"
#include"userdocking.h"
#include"userstatesdocking.h"



//删除用户
/*
逻辑层函数名称：删除用户 deleteuser()
底层函数输入参数 ：userid
调用底层函数：userdelete(int id)
底层函数返回值：bool
*/
bool supervisor::deleteuser(int id) {
	string bookid;
	userdocking udocking;
	userstatesdocking usdocking;
	//以下测试代码可忽略
	//string bklist;
	//bklist = "123";
	//bklist = dataformatting(120, bklist);
	if (!udocking.userexist(id))
		return false;
	else
	{
		//usdocking.uscreate(id, bklist);
		bookid = usdocking.ussearch(id);//当前用户的借阅信息
		bookid = bookid.substr(0, 120);
		cout <<"该用户已借图书ID："<< bookid << endl;
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