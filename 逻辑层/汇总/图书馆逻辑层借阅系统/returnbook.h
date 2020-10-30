#pragma once
#include<iostream>
#include"supervisor.h"
using namespace std;

//还书
class returnbook {
public:
	void returnBook(bookdocking& bd, userstatesdocking& usd);//还书函数，根据id修改图书的用户借阅状态和在架与否
};