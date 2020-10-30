#include <string>
#include "bookdocking.h"
#include "user.h"
#include <ostream>
#include "time.h"
#include <sstream>
using namespace std;
string tostring(int n)
{
	stringstream ss;
	string str;
	ss << n;
	ss >> str;
	return str;
}

int toint(string str)
{
	int n;
	n = atoi(str.c_str());
}
void main() {
	time_t* timer = NULL;
	time_t timet = time(timer);
	const  time_t* timerp = &timet;
	tm* t = localtime(timerp);
	cout<<tostring(t->tm_year) + "//" + tostring(t->tm_mon + 1) + "//" + tostring(t->tm_mday)<<endl;
	cout<<tostring(t->tm_year) + "//" + tostring((t->tm_mon + 1) % 12 + 1) + "//" + tostring(t->tm_mday)<<endl;
}