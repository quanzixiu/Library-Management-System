#include<iostream>
#include<string>
#include"supervisor.h"
#include"../UserDocking/UserDocking/userdocking.h"


//删除用户
/*
逻辑层函数名称：删除用户 deleteuser()
底层函数输入参数 ：userid
调用底层函数：userdelete(int id)
底层函数返回值：bool
*/
void supervisor::deleteuser() {
	int id;
	string bookid;
	userdocking udocking;
	cout << "请输入待删除用户的ID：";
	cin >> id;
	if (!udocking.userexist(id))
		cout << "该用户不存在！";
	else
	{
		if (udocking.userdelete(id))
			cout << "删除用户成功！" << endl;
		else
			cout << "删除用户失败，请重试！" << endl;
	}
	
}