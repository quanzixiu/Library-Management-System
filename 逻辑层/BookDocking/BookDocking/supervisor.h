#include<iostream>
#include<string>
#include"user.h"
#include"book.h"
#include"userstates.h"

using namespace std;

class supervisor {

public:

	bool createuser();//创建新用户
	bool modifyuserdata(int id);//修改用户借阅信息
	bool deleteuser(int id);//删除用户
	bool existuser(int id);//查找用户是否已经存在

	supervisor() { ; }

	bool createbook();//增加新图书
	void modifybook();//修改图书信息
	bool deletebook();//删除图书
	bool existbook(int id);//查找图书是否存在

	void manageuser();//用户管理界面，调用上述几个用户管理函数
	void managebook();//图书管理界面，调用下述图书管理函数
};
