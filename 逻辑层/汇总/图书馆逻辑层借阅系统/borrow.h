#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "time.h"
#include <string>
#include"BookDocking/bookdocking.h"
#include"UserDocking/userdocking.h"
#include"UserstatesDocking/userstatesdocking.h"
#include "user.h"
#include "book.h"
#include <ostream>
#include "time.h"
#include <sstream>
#include <tuple>
using namespace std;



class borrow
{
private:
	user student;
	bool islogin;
public:
	~borrow() {}
	borrow() 
	{ 
		islogin = false; 
	}
	int getID();
	string getPassWord();
	void setID(int id);
	void setPassWord(string password);

	void main(bookdocking& bd, userdocking& ud, userstatesdocking& usd);//主控函数

	bool qtlogin(int id, string password, userdocking& ud);//存好用户信息
	bool qtborrowbook(int id,bookdocking& bd, userstatesdocking& usd);
	book qtidsearchbook(int id, bookdocking& bd);
	user qtidsearchuser(int id, userdocking& ud);
	bool qtbookexist(int id, bookdocking& bd);
	tuple<int,int*>  qtreusercard(int id, bookdocking& bd);//借书卡
	tuple<int,int*> qtrebookbor(int id, userstatesdocking& usd);//借阅信息

	bool login(int id, string password,userdocking& ud);//存好用户信息
	void loginPanel(userdocking& ud);
	void registerPanel(userdocking& ud);
	void returnPrevious();
	int mainPanel(userdocking& ud);


	void searchbookPanel(bookdocking& bd, userstatesdocking& usd);
	void informationPanel(userdocking& ud);
	void bookborrowedPanel(bookdocking& bd, userstatesdocking& usd);

	void namesearchbook();
	void ISBNsearchbook(); 
	void typedisplay();
	void typeshowbook();
	void nextpage();
	void borrowbook(int id, bookdocking& bd, userstatesdocking& usd);
	void clickinPanel();
	void main1Panel(bookdocking& bd, userdocking& ud, userstatesdocking& usd);


	string dataformatting(int n, string data)
	{
		data.append(n - data.size(), ' ');
		return data;
	}

	string num2str(int i)
	{
		char ss[10];
		sprintf(ss, "%02d", i);
		return ss;
	}
	/*void transfer(book& b, int id)
	{
		string value;
		value = bd.booksearch(id);
		b.setISBN(value.substr(0, 6));
		b.setname(value.substr(6, 8));
		b.setauthor(value.substr(14, 4));
		b.settype(value.substr(18, 4));
		b.setborrowtime(value.substr(22, 8));
		b.setreturntime(value.substr(30, 8));
		b.sethistory(value.substr(38, 40));
		b.setonsheelf(value.substr(78, 1));
		b.setisovertime(value.substr(79, 1));
	}*/

	void zip(book& b)
	{
		b.setISBN(dataformatting(6, b.getISBN()));

		b.setname(dataformatting(8, b.getname()));

		b.setauthor(dataformatting(4, b.getauthor()));

		b.settype(dataformatting(4, b.gettype()));

		b.sethistory(dataformatting(40, b.gethistory()));

		b.setborrowtime(dataformatting(8, b.getborrowtime()));

		b.setreturntime(dataformatting(8, b.getreturntime()));

		b.setonsheelf(dataformatting(1, b.getonsheelf()));

		b.setisovertime(dataformatting(1, b.getisovertime()));

	}
};



