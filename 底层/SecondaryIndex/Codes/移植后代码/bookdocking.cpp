#include "bookdocking.h"

bookdocking::bookdocking(){
	Empty.open("valEmpty.txt", ios::in | ios::out | ios::binary);
	secData.open("secIndex.txt", ios::in | ios::out | ios::binary);
	if (!secData) {
		Empty.close();
		secData.close();
		ofstream uEmpty("valEmpty.txt", ios::binary);
		ofstream pData("secIndex.txt", ios::binary);
		uEmpty.close();
		pData.close();
		Empty.open("valEmpty.txt", ios::in | ios::out | ios::binary);
		secData.open("secIndex.txt", ios::in | ios::out | ios::binary);
	}
	secData.write("\n", sizeof(char));
	blank_str = string(LENGTH_ID + LENGTH_VALUE, ' ');
	firstEmpty = 0;//firstEmpty shows the first empty destination to store new datas when new data is inputed
	secEmpty = 0;
	cir_time = 0;
	zero_str = "00000000";
}

bookdocking::~bookdocking() {
	//file_update();
	Empty.close();
	secData.close();
}

bool bookdocking::bookadd(int id,string ISBN, string name, string author, string type, string borrowtime, string returntime, string histroy, string onsheelf, string isovertime)
{
	Empty.clear();
	secData.clear();
	to_id = to_string(id);
	value = ISBN + name + author + type + borrowtime + returntime + histroy + onsheelf + isovertime;
	to_value = value;
	if (bookdatabase.insert(id, value)) {
		if (Empty.peek() != EOF) {
			Empty.seekg(0, ios::beg);
			getline(Empty, v_index);//read a line (serves as an address (8 bytes data per line), indicates an empty in fIndex
			while (!atoi(v_index.c_str())) {
				firstEmpty = Empty.tellg();
				if (Empty.peek() == EOF) goto SIG_3;
				getline(Empty, v_index);//id not non-zero, read a new data (in a new line)
			}
			Empty.clear();
			secData.seekp(atoi(v_index.c_str()), ios::beg);
			secData.write(to_id.c_str(), LENGTH_ID);
			secData.write(to_value.c_str(), LENGTH_ISBN + LENGTH_NAME + LENGTH_AUTHOR);
			secData.write("\n", sizeof(char));
			secData.clear();
			Empty.seekp(firstEmpty, ios::beg);
			Empty.write(zero_str.c_str(), LENGTH_INDEXADDRESS);
		
			firstEmpty =  Empty.tellp();
			firstEmpty += 1;
		}
		else {
		SIG_3:
			Empty.clear();
			secData.seekp(0, ios::end);
			secData.write(to_id.c_str(), LENGTH_ID);
			secData.write(to_value.c_str(), LENGTH_ISBN + LENGTH_NAME + LENGTH_AUTHOR);
			secData.write("\n", sizeof(char));
		}
		return true;
	}
	else	return false;
}
bool bookdocking::bookdelete(int id) {
	string temp;
	Empty.clear();
	secData.clear();
	if (bookdatabase.remove(id))
		if (search_delete(id))
			return true;
		else return false;
	else return false;
}

string bookdocking::booksearch(int id) {
	if (bookdatabase.select(id, value))
	return value;
}

bool bookdocking::search_delete(int id) {
	int red = 0, ret = 0;
	string rec, recc;
	int tmpPr = 0;
	Empty.clear();
	secData.clear();
	if (secData.peek() == EOF) 
		return false;
	secData.seekg(0, ios::beg);
	getline(secData, rec);
	p_index = secData.tellg();
	getline(secData, rec);
	recc = rec.substr(0, LENGTH_ID);
	red = atoi(recc.c_str());
	while (red != id) {
		if (secData.eof()) {
			break;
		}
		p_index = secData.tellg();
		getline(secData, rec);
		recc = rec.substr(0, LENGTH_ID);
		red = atoi(recc.c_str());
	}
	if (red != id) {
		secData.clear();
		return false;
	}
	else {
		secData.clear();
		secData.seekp(p_index, ios::beg);
		secData.write(blank_str.c_str(), LENGTH_ID + LENGTH_ISBN + LENGTH_NAME + LENGTH_AUTHOR/*LENGTH_VALUE*/);//replace the datas with a blank string (88 bytes, a line).
		secData.clear();
		Empty.clear();
		v_index = to_string(p_index);
		if (Empty.peek() == EOF) {
			Empty.clear();
			Empty.seekp(0, ios::beg);
			Empty.write(v_index.c_str(), LENGTH_INDEXADDRESS);
			Empty.clear();
		}
		else {
			Empty.seekg(0, ios::end);
			secEmpty = Empty.tellg();
			cout << secEmpty;
			Empty.clear();
			Empty.seekp(secEmpty + 1, ios::beg); 
			Empty.write("\n", sizeof(char));
			Empty.write(v_index.c_str(), LENGTH_INDEXADDRESS);
			Empty.clear();
		}
		return true;
	}
}

vector<string> bookdocking::search(string mod, string value) {
	vector<string> datas;
	string temp, temp1;
	int par = 0;
	int len = 0;
	secData.clear();
	getline(secData, temp);
	if (mod == "ISBN") {
		par = LENGTH_ID + START_ISBN;
		len = LENGTH_ISBN;
	}
	else if (mod == "name") {
		par = LENGTH_ID + START_NAME;
		len = LENGTH_NAME;
	}
	else if (mod == "author") {
		par = LENGTH_ID + START_AUTHOR;
		len = LENGTH_AUTHOR;
	}
	else if (mod == "type") {
		par = LENGTH_ID + START_TYPE;
		len = LENGTH_TYPE;
	}
	else {
		cout << "Invalid searching mod detected." << endl;
		goto SIG_4;
	}
	while (secData.peek() != EOF) {
		getline(secData, temp);
		temp1 = temp.substr(0, LENGTH_ID);
		temp = temp.substr(par, len);
		if (temp == mod) {
			datas.push_back(temp1);
		}
		//datas.push_back(temp);
	}
	reverse(datas.begin(), datas.end());
	return datas;
SIG_4:
	datas.clear();
	return datas;
}

bool bookdocking::file_update() {
	vector<string>cache;
	string temp = "";
	Empty.clear();
	while (Empty.peek() != EOF) {
		getline(Empty, temp);
		temp = temp.substr(0, LENGTH_INDEXADDRESS);
		if (temp == "        ") continue;
		if (atoi(temp.c_str()))cache.push_back(temp);
	}
	fstream f("valEmpty.txt", fstream::out | ios_base::trunc);
	reverse(cache.begin(), cache.end());
	while (!cache.empty()) {
		temp = cache.back();
		cache.pop_back();
		f.write(temp.c_str(), LENGTH_INDEXADDRESS);
		f.write("\n", sizeof(char));
	}
	return true;
}

bool bookdocking::bookexist(int id) {
	if (bookdatabase.select(id, value))
		return true;
	else
		return false;
}
bool bookdocking::bookmodifyISBN(int id, string ISBN) {
	if (bookdatabase.select(id, value)) {
		value.replace(0, 6, ISBN);
		if (bookdatabase.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool bookdocking::bookmodifyname(int id, string name) {
	if (bookdatabase.select(id, value)){
		value.replace(6, 8, name);
		if (bookdatabase.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool bookdocking::bookmodifyauthor(int id, string author) {
	if (bookdatabase.select(id, value)){
		value.replace(14, 4, author);
		if (bookdatabase.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool bookdocking::bookmodifytype(int id, string type) {
	if (bookdatabase.select(id, value)){
		value.replace(18, 4, type);
		if (bookdatabase.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool bookdocking::bookmodifyborrowtime(int id, string borrowtime) {
	if (bookdatabase.select(id, value)){
		value.replace(22, 8, borrowtime);
		if (bookdatabase.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool bookdocking::bookmodifyreturntime(int id, string returntime) {
	if (bookdatabase.select(id, value)){
		value.replace(30, 8, returntime);
		if (bookdatabase.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool bookdocking::bookmodifyhistory(int id, string history) {
	if (bookdatabase.select(id, value)){
		value.replace(38, 40, history);
		if (bookdatabase.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool bookdocking::bookmodifyonsheelf(int id, string onsheelf) {
	if (bookdatabase.select(id, value)){
		value.replace(78, 1, onsheelf);
		if (bookdatabase.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}bool bookdocking::bookmodifyisovertime(int id, string isovertime) {
	if (bookdatabase.select(id, value)){
		value.replace(79, 1, isovertime);
		if (bookdatabase.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}



