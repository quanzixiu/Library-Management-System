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

/*���¹��ߺ���������ʹ��*/

string dataformatting(int n, string data);////�ֶ����û�дﵽ�涨��С�� ������ĵط����ո� 


