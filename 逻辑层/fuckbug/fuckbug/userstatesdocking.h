#include <iostream>
#include <fstream>
#include <string>
#include "userstatesDatabase.h"
using namespace std;

class userstatesdocking {
public:
	userstatesdocking();
	bool uscreate(int userid, string bookid);
	bool usadd(int userid,string bookid);
	bool usdelete(int id,string bookid);
	string ussearch(int id);
	bool usexist(int id);
	bool usdeleteall(int id);

private:
	userstatesDatabase userstatesdatabase;
	int id;
	string value;
};

