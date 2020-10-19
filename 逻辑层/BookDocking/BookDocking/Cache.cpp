#include "Cache.h"

Cache::Cache()
{
	cache.resize(CACHESIZE);
	for (int i = 0; i < CACHESIZE; ++i)
		cache[i].valid = false;
}

bool Cache::select(const int key, string &value)
{
	int set = GETSET(key);
	int tag = GETTAG(key);
	if (tag != GETTAG(cache[set].key) || !cache[set].valid)
		return false;
	value = cache[set].value;
	return true;
}

int Cache::insert(const int key, const string &value, int *oldKey, string *oldValue)
{
	int set = GETSET(key);
	int tag = GETTAG(key);
	if (tag == GETTAG(cache[set].key) && cache[set].valid)
		return 0;
	int result = 1;
	if (cache[set].valid && cache[set].dirty)
	{
		*oldKey = cache[set].key;
		*oldValue = cache[set].value;
		result = 2;
	}
	cache[set].key = key;
	cache[set].value = value;
	cache[set].valid = true;
	cache[set].dirty = false;
	return result;
}

void Cache::remove(const int key)
{
	int set = GETSET(key);
	int tag = GETTAG(key);
	if (tag == GETTAG(cache[set].key))
		cache[set].valid = 0;
}

bool Cache::update(const int key, string &value)
{
	int set = GETSET(key);
	int tag = GETTAG(key);
	if (tag != GETTAG(cache[set].key) || !cache[set].valid)
		return false;
	cache[set].value = value;
	cache[set].dirty = true;
}

void Cache::save(vector<int> *key, vector<string> *value)
{
	for (int i = 0; i < CACHESIZE; ++i)
	{
		if (cache[i].valid && cache[i].dirty)
		{
			key->push_back(cache[i].key);
			value->push_back(cache[i].value);
		}
	}
}