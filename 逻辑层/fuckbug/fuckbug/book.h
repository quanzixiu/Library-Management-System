#pragma once
#include<string>
#include"book.h"
using namespace std;

class book {

private:

	string id;//图书编号

	string ISBN;//书号

	string name;//书名

	string author;//作者

	string publisher;//出版社

	string type;//图书类别

	//int num_total; //总数

	//int num_remain; //可借本数

	string borrowtime;//借书时间

	string returntime;//还书时间

	string history;//借阅历史

	string onsheelf;//是否在架

	string isovertime;//是否超期

public:

	book* next;

	friend ostream& operator <<(ostream & out, book & b);

	friend istream& operator >>(ostream & in, book & b);

	bookdata() { ; }

	bookdata(string ISBN, string id, string name, string author = 'NULL', string publisher = 'NULL', string type = 'NULL'); //其他参	数同，默认为NULL，需要手动指定或者后期修改


	//以下get方法为获取图书相关参数

	string getISBN() { return ISBN; };

	string getid() { return id; };

	string getname() { return name; };

	string getauthor() { return author; };

	string getpublisher() { return publisher; };

	string getborrowtime() { return borrowtime; };

	string getreturntime() { return returntime; };

	string gettype() { return type; };


	//以下set方法为输入图书相关参数

	void setISBN(string  ISBN) {};

	void setid(string id) {  };

	void setname(string name) {  };

	void  setauthor() { };

	void  setpublisher() {  };

	void  settype() {  };
};