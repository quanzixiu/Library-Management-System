#include <iostream>
#include <fstream>
#include <string>
#include "Database.h"
using namespace std;

class userdocking {
public:
	userdocking();

	bool useradd(int id, string name, string college, string major, string password, string email);
	bool userdelete(int id);
	string usersearch(int id);
	bool userexist(int id);
	bool usermodifyname(int id, string name);
	bool usermodifycollege(int id, string college);
	bool usermodifymajor(int id, string major);
	bool usermodifypassword(int id, string password);
	bool usermodifyemail(int id, string eamil);


private:
	Database database;
	int id;
	string value;
};

/*以下工具函数供你们使用*/

string dataformatting(int n, string data);////字段如果没有达到规定大小则 将空余的地方填充空格 


