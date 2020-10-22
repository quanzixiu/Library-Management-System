#include<string>
#include"userdocking.h"
#include"supervisor.h"
using namespace std;

void supervisor::searchuser() {
	int id;
	string name;
	string college;
	string major;
	string password;
	string email;
	string value;
	userdocking udocking;
	cout << "请输入要查找的用户ID:";
	cin >> id;
	if (udocking.userexist(id)) //每次查询前要先判断
	{
		value = udocking.usersearch(id);
		//把得到的包含所有信息的字符串分发给各个字段
		name = value.substr(0, 8);
		college = value.substr(8, 4);
		major = value.substr(12, 4);
		password = value.substr(16, 16);
		email = value.substr(32, 24);

		cout << "该用户当前信息如下：" << endl;
		cout << "1.姓名" << name << endl;
		cout << "2.学校" << college << endl;
		cout << "3.专业" << major << endl;
		cout << "4.密码" << password << endl;
		cout << "5.邮箱" << email << endl;
	}
	else
	{
		cout << "该用户不存在！" << endl;
	}
}
	