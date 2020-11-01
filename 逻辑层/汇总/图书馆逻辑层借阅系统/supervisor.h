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
	bool slogin();//管理员登录;
	void searchuser(userdocking& ud);//查找用户
	void createuser(userdocking& ud);//创建新用户
	void modifyuserdata(userdocking& ud);//修改用户借阅信息
	void deleteuser(userdocking& ud, userstatesdocking& usd);//删除用户

	supervisor() { islogin=false; }

	void createbook(bookdocking& bd);//增加新图书
	void modifybook(bookdocking& bd);//修改图书信息
	void deletebook(bookdocking& bd);//删除图书

	void manageuser(userdocking& ud, userstatesdocking& usd);//用户管理界面，调用上述几个用户管理函数
	void managebook(bookdocking& bd);//图书管理界面，调用下述图书管理函数
	string dataformatting(int n, string data);
};