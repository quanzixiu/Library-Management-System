#include<iostream>
#include<string>
#include"supervisor.h"
#include"userdocking.h"
#include"userstatesdocking.h"

string supervisor::DisplayUserBookid(int id) {
	string bookid;
	userdocking udocking;
	userstatesdocking usdocking;
	bookid = usdocking.ussearch(id);//当前用户的借阅信息
	bookid = bookid.substr(0, 120);
	return bookid;
}