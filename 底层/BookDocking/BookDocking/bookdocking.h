#include <iostream>
#include <fstream>
#include <string>
#include "Database.h"
using namespace std;

class bookdocking {
public:
	bookdocking();

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
	bool bookmodifyhistory(int id, string history);
	bool bookmodifyonsheelf(int id, string onsheelf);
	bool bookmodifyisovertime(int id, string isorvertime);

private:
	Database database;
	int id;
	string value;
};

/*���¹��ߺ���������ʹ��*/

string dataformatting(int n, string data);////�ֶ����û�дﵽ�涨��С�� ������ĵط����ո� 


