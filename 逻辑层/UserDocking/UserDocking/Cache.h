#ifndef CACHE_H
#define CACHE_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define GETSET(x) (0x3FFF&x)
#define GETTAG(x) (x&0xFFFFC00)
//#define GETVALIDBIT(x) (x&0x1)
//#define SETVALIDBIT0(x) (x&0xFFFFFFFe)
//#define SETVALIDBIT1(x) (x|0x1)
//#define GETDIRTYBIT(x) ((x&0x2)>>1)
//#define SETDIRTYBIT0(x) (x&0xFFFFFFFD)
//#define SETDIRTYBIT1(x) (x|0x2)

struct Set
{
	int key;
	string value;
	bool valid;
	bool dirty;
};

class Cache
{
public:
	Cache();
	bool select(const int key, string &value);
	int insert(const int key, const string &value,int *oldKey,string *oldValue);
	void remove(const int key);
	bool update(const int key, string &value);
	void save(vector<int> *key, vector<string> *value);
	~Cache() {}
private:
	vector<Set> cache;
	const int CACHESIZE = 16384;
	const int SETBITS = 14;
	const int TAGBITS = 18;
};

#endif // !DATABASE_H
