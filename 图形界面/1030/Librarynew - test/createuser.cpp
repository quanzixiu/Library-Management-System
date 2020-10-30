#include<iostream>
#include<string>
#include"userdocking.h"
#include"supervisor.h"
using namespace std;

//创建新用户
/*
逻辑层函数名称：增加用户 createuser
底层函数输入参数：userid
调用底层函数：bool useradd(int id, string name, string college, string major, string password, string email);
底层函数返回值：bool
*/
bool supervisor::createuser(int id,string name,string password,string college,
							string major, string email) 
{
	userdocking udocking;
	if (udocking.userexist(id))
		return false;
	else
	{
		//把输入的信息转换成规定的大小 
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
