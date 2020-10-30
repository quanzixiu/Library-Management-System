#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "time.h"
#pragma once
#include<string>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <vector>
#include <list>
#include"returnbook.h"
using namespace std;


string num2str(int i)
{
	char ss[10];
	sprintf(ss, "%02d", i);
	return ss;
}

bool isovertime(string returntime)
{
	string nowtime;
	time_t* timer = NULL;
	time_t timet = time(timer);
	const  time_t* timerp = &timet;
	tm* t = localtime(timerp);
	nowtime = to_string(t->tm_year + 1900) + num2str(t->tm_mon + 1) + num2str(t->tm_mday);
	if (nowtime <= returntime)return true;
	else return false;
}


void returnbook::returnBook(bookdocking& bd,userstatesdocking& usd) {
	
	int i;
	int count=0;
	int cutCount;
	int id;
	int userid;
	char c[10];
	string bookid;
	string value;
	string onsheelf;
	string returntime;
	string history;
	string lastHistory;

	cout << "请输入要归还图书的ID：";
	cin >> id;

	if (!bd.bookexist(id))
		cout << "该图书不存在！";
	else
	{
		value = bd.booksearch(id);
		onsheelf = value.substr(78, 1);
		returntime = value.substr(30, 8);
		if (onsheelf == "1")
			cout << "该图书已归还！";
		else
		{
			if (!isovertime(returntime))
				cout << "未在规定时间内归还图书，请联系管理缴纳罚金。";
			else
			{
				//修改用户借阅信息
				history = value.substr(38, 40);//该图书的借书记录
				//找最后一个借书用户ID
				for (i = 40; i > 0; i--)
				{
					if (history[i] == ' ')//逆序遍历历史记录，如果是填充的空字符就让计数器加一
						count++;
					else
						break;//找到第一个不是填充的字符位置，包括在最后一个借阅用户id中
				}
				cutCount = 8 - count % 8;//最后一个借阅用户ID位数
				lastHistory = history.substr(40 - count - cutCount, 8);//截取最后一个借阅用户的8位id（string）
				userid = atoi(lastHistory.c_str());//string转换成int
				bookid = std::to_string(id);//输入的图书id int转换成string
				if (usd.usdelete(userid, bookid))
				{
					if (count == 32) usd.usdeleteall(id);//当前用户已经归还所有图书
					//修改图书在架信息
					if (bd.bookmodifyonsheelf(id, "1"))
						cout << "还书成功！";
					else
						cout << "还书失败！";
				}
				else
					cout << "删除用户借阅记录，还书失败！";
			}
		}
			
	}
	int ppp=-1;
	cin >> ppp;
	while (ppp!=0)
	{
		cin >> ppp;
	}
}