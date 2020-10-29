#pragma once
#include<iostream>
#include<string>

using namespace std;

class supervisor {

public:
	supervisor() { ; }

	//管理员登陆函数 ID：123 密码：admin
	bool login(int id, string password);

	//用户管理函数
	string DisplayUser(int id);//返回用户各项信息字符串，截取方法已在腾讯文档提供
	string DisplayUserBookid(int id);//返回用户借阅信息字符串，截取每6位为一个bookid
	bool createuser(int id, string name, string password, string college,string major, string email);//创建新用户
	bool deleteuser(int id);//删除用户信息
	bool modifyuserName(int id, string name);//修改用户姓名
	bool modifyuserCollege(int id, string college);//修改用户学校
	bool modifyuserMajor(int id, string major);//修改用户专业
	bool modifyuserEmail(int id, string email);//修改用户邮箱
	bool modifyuserPassword(int id, string password);//修改用户密码
	
	//图书管理函数
	string DisplayBook(int id);//展示图书信息，返回字符串
	bool createbook(int id, string ISBN, string name, string author, string type);//增加新图书
	bool deletebook(int id);//删除图书
	bool modifybookISBN(int id, string ISBN);//修改图书的ISBN
	bool modifybookName(int id, string name);//修改图书的书名
	bool modifybookAuthor(int id, string author);//修改图书的作者
	bool modifybookType(int id, string type);//修改图书的分类
	bool modifybookOnsheelf(int id, string onsheelf);//修改图书的在架状态
	bool modifybookIsovertime(int id, string isovertime);//修改图书的超期状态
	
	string dataformatting(int n, string data);//数据填充函数，以上函数均有调用，需要保留
};