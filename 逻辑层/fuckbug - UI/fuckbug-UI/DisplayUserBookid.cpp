#include<iostream>
#include<string>
#include"supervisor.h"
#include"userdocking.h"
#include"userstatesdocking.h"

string supervisor::DisplayUserBookid(int id) {
	string bookid;
	userdocking udocking;
	userstatesdocking usdocking;
	bookid = usdocking.ussearch(id);//��ǰ�û��Ľ�����Ϣ
	bookid = bookid.substr(0, 120);
	return bookid;
}