#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "time.h"
#include<string>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <vector>
#include <list>
#include"returnbook.h"
#include"bookdocking.h"
#include"userstatesdocking.h"
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


bool returnbook::returnBook(int id) {
	bookdocking docking;
	userstatesdocking usdocking;
	int i;
	int count=0;
	int cutCount;
	int userid;
	char c[10];
	string bookid;
	string value;
	string onsheelf;
	string returntime;
	string history;
	string lastHistory;

	if (!docking.bookexist(id))
		return false;
	else
	{
		value = docking.booksearch(id);
		onsheelf = value.substr(78, 1);
		returntime = value.substr(30, 8);
		if (onsheelf == "1")
			return false;//��ͼ���ѹ黹��
		else
		{
			if (isovertime(returntime))
				return false;// "δ�ڹ涨ʱ���ڹ黹ͼ�飬����ϵ������ɷ���"
			else
			{
				//�޸�ͼ���ڼ���Ϣ
				if (docking.bookmodifyonsheelf(id, "1"))
				{
					//�޸��û�������Ϣ
					history = value.substr(38, 40);//��ͼ��Ľ����¼

					//�����һ�������û�ID
					for (i = 40; i > 0; i--)
					{
						if (history[i] = ' ')//���������ʷ��¼����������Ŀ��ַ����ü�������һ
							count++;
						else
							break;//�ҵ���һ�����������ַ�λ�ã����������һ�������û�id��
					}
					cutCount = 8 - count % 8;//���һ�������û�IDλ��
					lastHistory = history.substr(40 - count - cutCount, 8);//��ȡ���һ�������û���8λid��string��
					userid = atoi(lastHistory.c_str());//stringת����int
					bookid = std::to_string(id);//�����ͼ��id intת����string
					if (usdocking.usdelete(userid, bookid))
					{
						return true;
						if (count == 32) usdocking.usdeleteall(id);//��ǰ�û��Ѿ��黹����ͼ��
					}

					else
						return false;
				}
				else
					return false;
			}
		}
			
	}
}