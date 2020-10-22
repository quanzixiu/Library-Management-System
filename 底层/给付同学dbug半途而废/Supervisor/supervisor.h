#pragma once
#include<iostream>
#include<string>

using namespace std;

class supervisor {

public:

	void searchuser();//查找用户
	void createuser();//创建新用户
	void modifyuserdata();//修改用户借阅信息
	void deleteuser();//删除用户

	supervisor() { ; }

	void createbook();//增加新图书
	void modifybook();//修改图书信息
	void deletebook();//删除图书

	void manageuser();//用户管理界面，调用上述几个用户管理函数
	void managebook();//图书管理界面，调用下述图书管理函数
};