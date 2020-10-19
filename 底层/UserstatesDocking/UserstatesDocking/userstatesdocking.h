#include <iostream>
#include <fstream>
#include <string>
#include "Database.h"
using namespace std;

class userstatesdocking {
public:
	userstatesdocking();
	bool uscreate(int userid, string bookid);
	bool usadd(int userid,string bookid);
	bool usdelete(int id,string bookid);
	string ussearch(int id);
	bool usexist(int id);

private:
	Database database;
	int id;
	string value;
};

/*以下工具函数供你们使用*/

string dataformatting(int n, string data);////字段如果没有达到规定大小则 将空余的地方填充空格 


