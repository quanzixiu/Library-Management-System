#include<iostream>
#include<string>
#include <sstream>
#include <iomanip>
#include <chrono>
#include"returnbook.h"
#include"../BookDocking/BookDocking/bookdocking.h"
#include"../UserstatesDocking/UserstatesDocking/userstatesdocking.h"
using namespace std;


void returnbook::returnBook() {
	bookdocking docking;
	userstatesdocking usdocking;
	int id;
	int userid;
	char c[10];
	string bookid;
	string value;
	string onsheelf;
	string lastHistory;

	cout << "请输入要归还图书的ID：";
	cin >> id;
	if (!docking.bookexist(id))
		cout << "该图书不存在！";
	else
	{
		value = docking.booksearch(id);
		onsheelf = value.substr(58, 1);
		if (onsheelf == "1")
			cout << "该图书已归还！";
		else
		{
			/* 缺少判断是否超期的相关函数内容，对比borrowtime和returntime，修改isovertime*/

			//修改图书信息
			if (docking.bookmodifyonsheelf(id, "1"))
			{
				//给图书增加归还时间

				auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
				std::stringstream ss;//转为字符串

				// 可以分别以不同的形式进行显示
				ss << std::put_time(std::localtime(&t), "%Y-%m-%d-%H-%M-%S");
				//ss << std::put_time(std::localtime(&t), "%Y年%m月%d日%H时%M分%S秒");
				//ss << std::put_time(std::localtime(&t), "%Y%m%d%H%M%S");

				std::string str_time = ss.str();

				docking.bookmodifyreturntime(id, str_time);

				

				//修改用户借阅信息
				lastHistory = value.substr(70, 4);//最后一个借书的用户id(string)
				userid = atoi(lastHistory.c_str());//string转换成int
				bookid = std::to_string(id);//输入的图书id int转换成string
				if (usdocking.usdelete(userid, bookid))
					cout << "还书成功！";
				else
					cout << "还书失败！";
			}
			else
				cout << "还书失败！";
		}	
	}
}