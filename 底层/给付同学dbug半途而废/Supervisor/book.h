#pragma once
#include<string>
#include"book.h"
using namespace std;

class book {

private:

	string id;//ͼ����

	string ISBN;//���

	string name;//����

	string author;//����

	string publisher;//������

	string type;//ͼ�����

	//int num_total; //����

	//int num_remain; //�ɽ豾��

	string borrowtime;//����ʱ��

	string returntime;//����ʱ��

	string history;//������ʷ

	string onsheelf;//�Ƿ��ڼ�

	string isovertime;//�Ƿ���

public:

	book* next;

	friend ostream& operator <<(ostream & out, book & b);

	friend istream& operator >>(ostream & in, book & b);

	bookdata() { ; }

	bookdata(string ISBN, string id, string name, string author = 'NULL', string publisher = 'NULL', string type = 'NULL'); //������	��ͬ��Ĭ��ΪNULL����Ҫ�ֶ�ָ�����ߺ����޸�


	//����get����Ϊ��ȡͼ����ز���

	string getISBN() { return ISBN; };

	string getid() { return id; };

	string getname() { return name; };

	string getauthor() { return author; };

	string getpublisher() { return publisher; };

	string getborrowtime() { return borrowtime; };

	string getreturntime() { return returntime; };

	string gettype() { return type; };


	//����set����Ϊ����ͼ����ز���

	void setISBN(string  ISBN) {};

	void setid(string id) {  };

	void setname(string name) {  };

	void  setauthor() { };

	void  setpublisher() {  };

	void  settype() {  };
};