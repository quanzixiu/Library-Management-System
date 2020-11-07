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
	zero_str = "00000000";//zero_str is a string to rewrite the address in fEmpty to change the isEmpty information
	//zero_str = "    ";
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
	if (database.insert(id, value)) {
		if (Empty.peek() != EOF) {//check if the fEmpty file is not an empty one. if so, execute the following codes.
			Empty.seekg(0, ios::beg);//go to the head of the fEmpty
			//Empty.seekg(firstEmpty,ios::beg);//move to pos that indicates the last add
			getline(Empty, v_index);//read a line (serves as an address (8 bytes data per line), indicates an empty in fIndex
			while (!atoi(v_index.c_str())) {	//find the first non-zero destination of fEmpty
				firstEmpty = Empty.tellg();//store the present destination that the file pointer fEmpty points, in file fEmpty(read)
				if (Empty.peek() == EOF) goto SIG_3;
				getline(Empty, v_index);//id not non-zero, read a new data (in a new line)
			}
			Empty.clear();
			secData.seekp(atoi(v_index.c_str()), ios::beg);//move the pointer fIndex to the empty destination
			secData.write(to_id.c_str(), LENGTH_ID);//write the id data (within 8(?) bytes) into the fIndex
			secData.write(to_value.c_str(), LENGTH_ISBN + LENGTH_NAME + LENGTH_AUTHOR/*LENGTH_VALUE*/);//write the value data (within 80 bytes) into the fIndex, whithout any blanks between id data
			secData.write("\n", sizeof(char));//start a new line in fIndex for another new datas
			secData.clear();
			Empty.seekp(firstEmpty, ios::beg);//go to the empty place indicated in fEmpty
			//change the address data to 0000(if trans to int, is 0)
			//change the address data to "00000000", which indicates nothing
			Empty.write(zero_str.c_str(), LENGTH_INDEXADDRESS);
			//no need to write "\n" to file here
			firstEmpty = /*0;*/ Empty.tellp();
			firstEmpty += 1;//need to skip the zero ones
		}
	else {//if the fEmpty is empty, execute the following codes
		SIG_3:
		Empty.clear();
		secData.seekp(0, ios::end);//no free spaces to write on, so start a new line at the rear of the file
		secData.write(to_id.c_str(), LENGTH_ID);//write id data
		secData.write(to_value.c_str(), LENGTH_ISBN + LENGTH_NAME + LENGTH_AUTHOR/*LENGTH_VALUE*/);//write value data
		secData.write("\n", sizeof(char));//start a new line in fIndex for another new datas
		//no changes in fEmpty, so no need to change it.
	}
	return true;
	}
	else
		return false;
}


bool bookdocking::bookdelete(int id) {
	string temp;
	Empty.clear();
	secData.clear();
	if (database.remove(id)) {
		//line_num = search_delete(id);// get the correct destination the fIndex stores that line of data (return the address of it.)
		if (search_delete(id)) {
			return true;
			//if (file_update()) return true;
			//else return false;
		}

		/*
		v_index = to_string(line_num);//transform the line_num(int) to string
		for (int i = 1; i < line_num; i++) getline(secData, temp);
		p_index = secData.tellg();
		secData.clear();
		secData.seekp(p_index, ios::beg);
		//[warning: line_num is the num of line, not the true address!]fIndex.seekp(line_num/*address*//*, ios::beg);//move the pointer of fIndex to the place of address
		/*secData.write(blank_str.c_str(), LENGTH_ID + LENGTH_VALUE);//replace the datas with a blank string (88 bytes, a line).
		secData.clear();
		*/


		//Empty.clear();
		/*if (Empty.peek() == EOF) {//if fEmpty is empty
			Empty.clear();
			Empty.seekp(0, ios::beg);
			Empty.write(v_index.c_str(), LENGTH_INDEXADDRESS);//write the position data into the fEmpty
			// not [fEmpty.write(new_str.c_str(), LENGTH_INDEXADDRESS);]!!!!
			Empty.clear();
		}*/
		/*		else {//fEmpty is not empty
					/*
					fEmpty.seekp(0, ios::beg);
					getline(fEmpty, new_str);
					while (atoi(new_str.c_str()) != line_num) {
						firstEmpty = fEmpty.tellg();
						getline(fEmpty, new_str);
						}
					fEmpty.seekp(firstEmpty, ios::beg);
					fEmpty.write(zero_str.c_str(),LENGTH_INDEXADDRESS);
					*/
					/*			Empty.seekg(0, ios::beg);
								getline(Empty, new_str);
								while (atoi(new_str.c_str()))//while new_str receives not "0000" (0 in int), keep traversing for the next line,
								//until find a "0000" to rewrite into.
								{
									firstEmpty = Empty.tellg();
									getline(Empty, new_str);
								}
								Empty.clear();
								Empty.seekp(firstEmpty, ios::beg); //move the pointer to the empty(0000) place
								Empty.write(v_index.c_str(), LENGTH_INDEXADDRESS);//write the position data into the fEmpty
								Empty.clear();
							}*/
							/*Empty.clear();
							Empty.close();
							secData.clear();
							secData.close();
							*/
		else return false;
	}
	else
		return false;
}
bool bookdocking::search_delete(int id) {// get the correct destination the fIndex stores that line of data (return the address of it.)
	int red = 0, ret = 0;//red is the receiver of the data, ret to return the num of line the data lies on
	//int cir_time = 0; //stores the circle time of the circle
	string rec, recc;//rec to receive data, recc to save a part of rec
	int tmpPr = 0;
	Empty.clear();
	secData.clear();
	if (secData.peek() == EOF) //return ret;
		return false;
	secData.seekg(0, ios::beg);
	getline(secData, rec);//skip the first blank line
	p_index = secData.tellg();//must find replacing position before read-pointer moved
	getline(secData, rec);//get a line in fIndex, save the data in rec
	recc = rec.substr(0, LENGTH_ID);//cut the rec, remaining the ID data only
	red = atoi(recc.c_str());//trans into integer
	//ret += 1;
	while (red != id) {//if not equal, re-get a new data from next line in fIndex
		/*if (secData.peek() == EOF) {
			secData.seekg(0, ios::beg);
			break;
		}*/
		if (secData.eof()) {
			break;
		}
		p_index = secData.tellg();//must find new replacing position before read-pointer moved
		getline(secData, rec);
		recc = rec.substr(0, LENGTH_ID);
		red = atoi(recc.c_str());
		//ret += 1;
	}
	if (red != id) {
		secData.clear();
		//return ret;
		return false;
	}
	else {
		secData.clear();
		secData.seekp(p_index, ios::beg);
		secData.write(blank_str.c_str(), LENGTH_ID + LENGTH_ISBN + LENGTH_NAME + LENGTH_AUTHOR/*LENGTH_VALUE*/);//replace the datas with a blank string (88 bytes, a line).
		secData.clear();
		Empty.clear();
		v_index = to_string(p_index);//trans p_index to v_index
		if (Empty.peek() == EOF) {//if fEmpty is empty
			Empty.clear();
			Empty.seekp(0, ios::beg);
			//v_index = to_string(p_index);//trans p_index to v_index
			Empty.write(v_index.c_str(), LENGTH_INDEXADDRESS);//write the position data into the fEmpty
			//Empty.write("\n", sizeof(char));//next line
			// not [fEmpty.write(new_str.c_str(), LENGTH_INDEXADDRESS);]!!!!
			Empty.clear();
		}
		else {//fEmpty is not empty

			Empty.seekg(0, ios::end);
			secEmpty = Empty.tellg();


			cout << secEmpty;
			Empty.clear();
			Empty.seekp(secEmpty + 1/*atoi(new_str.c_str())*//*new_str is indicated to place in secIndex!!!!*/, ios::beg); //move the pointer to the empty(0000) place
			Empty.write("\n", sizeof(char));
			Empty.write(v_index.c_str(), LENGTH_INDEXADDRESS);//write the position data into the fEmpty
			//Empty.write("\n", sizeof(char));//next line
			//secEmpty = Empty.tellp();//no need to +1 here!
			Empty.clear();
		}
		//return ret - 1;
		//cir_time += 1;
		return true;
	}
}

/*vector<string> bookdocking::search(string mod, string value) {
	vector<string> datas;
	string temp;
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
		temp = temp.substr(par, len);
		datas.push_back(temp);
	}
	reverse(datas.begin(), datas.end());
	return datas;
SIG_4:
	datas.clear();
	return datas;
}*/

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
		if(atoi(temp.c_str()))cache.push_back(temp);
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

string bookdocking::booksearch(int id) {
	if (database.select(id, value))
		return value;
	else return false;
}

bool bookdocking::bookexist(int id) {
	if (database.select(id, value))
		return true;
	else
		return false;
}
bool bookdocking::bookmodifyISBN(int id, string ISBN) {
	if (database.select(id, value)) {
		value.replace(0, 6, ISBN);
		if (database.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool bookdocking::bookmodifyname(int id, string name) {
	if (database.select(id, value)){
		value.replace(6, 8, name);
		if (database.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool bookdocking::bookmodifyauthor(int id, string author) {
	if (database.select(id, value)){
		value.replace(14, 4, author);
		if (database.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool bookdocking::bookmodifytype(int id, string type) {
	if (database.select(id, value)){
		value.replace(18, 4, type);
		if (database.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool bookdocking::bookmodifyborrowtime(int id, string borrowtime) {
	if (database.select(id, value)){
		value.replace(22, 8, borrowtime);
		if (database.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool bookdocking::bookmodifyreturntime(int id, string returntime) {
	if (database.select(id, value)){
		value.replace(30, 8, returntime);
		if (database.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool bookdocking::bookmodifyhistory(int id, string history) {
	if (database.select(id, value)){
		value.replace(38, 40, history);
		if (database.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool bookdocking::bookmodifyonsheelf(int id, string onsheelf) {
	if (database.select(id, value)){
		value.replace(78, 1, onsheelf);
		if (database.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}bool bookdocking::bookmodifyisovertime(int id, string isovertime) {
	if (database.select(id, value)){
		value.replace(79, 1, isovertime);
		if (database.update(id, value))
			return true;
		else
			return false;
	}
	else
		return false;
}

//�ֶ����û�дﵽ�涨��С�� ������ĵط����ո�
string dataformatting(int n, string data)
{
	data.append(n - data.size(), ' ');
	return data;
}

