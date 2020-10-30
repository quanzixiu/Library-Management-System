#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class book
{
private:

	int id;//图书编号

	string borrowtime;//借书时间

	string returntime;//还书时间

	string history;//借阅历史

	string onsheelf;//是否在架

	string isovertime;//是否超期

	string ISBN;//书号

	string name;//书名

	string author;//作者

	string publisher;//出版社

	string type;//图书类别


public:

	book* next;

	//friend ostream& operator <<(ostream& out, book& b);

	//friend istream& operator >>(ostream& in, book& b);

	int bookdata() { }

	int bookdata(string ISBN, string id, string name, string author = "NULL", string publisher = "NULL", string type = "NULL"); //其他参	数同，默认为NULL，需要手动指定或者后期修改


	//以下get方法为获取图书相关参数
	string gethistory() { return history; }

	string getonsheelf(){ return onsheelf; }

	string getisovertime() { return isovertime; }

	string getISBN() { return ISBN; }

	int getid() { return id; }

	string getname() { return name; }

	string getauthor() { return author; }

	string getpublisher() { return publisher; }

	string getborrowtime() { return borrowtime; }

	string getreturntime() { return returntime; }

	string gettype() { return type; }


	//以下set方法为输入图书相关参数
	void sethistory(string history) { book::history = history; }

	void setonsheelf(string onsheelf) { book::onsheelf=onsheelf; }

	void setisovertime(string isovertime) { book::isovertime = isovertime; }

	void setISBN(string  ISBN) { book::ISBN = ISBN; }

	void setid(int id) { book::id = id; }

	void setname(string name) { book::name = name; }

	void  setauthor(string author) { book::author = author; }

	void  setpublisher(string publisher) { book::publisher = publisher; }

	void setborrowtime(string borrowtime) { book::borrowtime = borrowtime; }

	void setreturntime(string returntime) { book::returntime = returntime; }

	void  settype(string type) { book::type = type; }

};
