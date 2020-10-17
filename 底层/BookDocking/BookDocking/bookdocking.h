#include <iostream>
#include <fstream>
#include <string>
#include "Database.h"
using namespace std;

class bookdocking {
public:
	bookdocking();
	string dataformatting(int n, string data);//把输入的信息转换成规定的大小的工具函数
	void formatting(string ISBN, string name, string author, string type, string histroy);//把输入的信息转换成规定的大小
	//把得到的包含所有信息的字符串分发给各个字段
	void negativedataformatting(string value, string ISBN, string name, string author, string type, string borrowtime, string returntime, string histroy, string onsheelf, string isovertime);
	bool bookadd(int id, string ISBN, string name, string author, string type, string borrowtime, string returntime, string histroy, string onsheelf, string isovertime);
	bool bookdelete(int id);
	string booksearch(int id);
	bool bookexist(int id);
	bool bookmodifyISBN(int id, string ISBN);
	bool bookmodifyname(int id, string name);
	bool bookmodifyauthor(int id, string author);
	bool bookmodifytype(int id, string type);
	bool bookmodifyborrowtime(int id, string borrowtime);
	bool bookmodifyreturntime(int id, string returntime);
	bool bookmodifyhistroy(int id, string history);
	bool bookmodifyonsheelf(int id, string sheelf);
	bool bookmodifyisovertime(int id, string isorvertime);

private:
	Database database;
	int id;
	string value;
};