#ifndef BOOKDOCKING_H
#define BOOKDOCKING_H
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "bookDatabase.h"
#define LENGTH_INDEXADDRESS 8/*4*/
#define START_ISBN 0
#define START_NAME 6
#define START_AUTHOR 14
#define START_TYPE 18
#define LENGTH_ID 6
#define LENGTH_ISBN 6
#define LENGTH_NAME 8
#define LENGTH_AUTHOR 4
#define LENGTH_TYPE 4
#define LENGTH_VALUE 80
using namespace std;



class bookdocking {
public:
	bookdocking();
	~bookdocking();

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

	bool search_delete(int id);
	bool file_update();
	vector<string> search(string method, string value);


private:
	bookDatabase bookdatabase;
	int id;
	int firstEmpty;
	int p_index;
	int secEmpty;
	int line_num;
	int cir_time;
	string value, v_index, zero_str, new_str, blank_str;
	string to_id, to_value, c_to_str;
	fstream secData, Empty;
};

#endif // !
