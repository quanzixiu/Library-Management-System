#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class book
{
private:

	int id;//ͼ����

	string borrowtime;//����ʱ��

	string returntime;//����ʱ��

	string history;//������ʷ

	string onsheelf;//�Ƿ��ڼ�

	string isovertime;//�Ƿ���

	string ISBN;//���

	string name;//����

	string author;//����

	string publisher;//������

	string type;//ͼ�����


public:

	book* next;

	//friend ostream& operator <<(ostream& out, book& b);

	//friend istream& operator >>(ostream& in, book& b);

	int bookdata() { }

	int bookdata(string ISBN, string id, string name, string author = "NULL", string publisher = "NULL", string type = "NULL"); //������	��ͬ��Ĭ��ΪNULL����Ҫ�ֶ�ָ�����ߺ����޸�


	//����get����Ϊ��ȡͼ����ز���
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


	//����set����Ϊ����ͼ����ز���
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
