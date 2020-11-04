#include "bookdocking.h"

bookdocking::bookdocking(){
	blank_str = string(LENGTH_ID + LENGTH_VALUE, ' ');
	firstEmpty = 0;//firstEmpty shows the first empty destination to store new datas when new data is inputed
	zero_str = "0000";//zero_str is a string to rewrite the address in fEmpty to change the isEmpty information
}


bool bookdocking::bookadd(int id,string ISBN, string name, string author, string type, string borrowtime, string returntime, string histroy, string onsheelf, string isovertime)
{	
	to_id = to_string(id);
	value = ISBN + name + author + type + borrowtime + returntime + histroy + onsheelf + isovertime;
	to_value = value;
	if (database.insert(id, value)) {
		fEmpty.open("fEmpty.txt", ios::binary); //open the file that indicates the empty place in the datafile fIndex
		
		fEmpty.write("123123123", 9);
		
		if (fEmpty.peek() != EOF) {//check if the fEmpty file is not an empty one. if so, execute the following codes.
			fIndex.open("fIndex.txt", ios::binary);//open the file fIndex to add items
			fEmpty.seekg(0, ios::beg);//go to the head of the fEmpty
			getline(fEmpty, v_index);//read a line (serves as an address (4 bytes data per line), indicates an empty in fIndex
			while (!atoi(v_index.c_str())) {	//find the first non-zero destination of fEmpty
				firstEmpty = fEmpty.tellg();//store the present destination that the file pointer fEmpty points, in file fEmpty(read)
				getline(fEmpty, v_index);//id not non-zero, read a new data (in a new line)
			}
			fIndex.seekp(atoi(v_index.c_str()), ios::beg);//move the pointer fIndex to the empty destination
			//fEmpty.read(c_to_str.c_str(), 4);
			fIndex.write(to_id.c_str(), LENGTH_ID);//write the id data (within 8(?) bytes) into the fIndex
			fIndex.write(to_value.c_str(), LENGTH_VALUE);//write the value data (within 80 bytes) into the fIndex, whithout any blanks between id data
			fIndex.write("\n", sizeof(char));//start a new line in fIndex for another new datas
			fEmpty.seekp(firstEmpty, ios::beg);//go to the empty place indicated in fEmpty
			fEmpty.write(zero_str.c_str(), LENGTH_INDEXADDRESS);//change the address data to 0000(if trans to int, is 0)
		}
		else {//if the fEmpty is empty, execute the following codes
			fIndex.open("fIndex.txt", ios::binary | ios::app);//no free spaces to write on, so start a new line at the rear of the file
			fIndex.write(to_id.c_str(), LENGTH_ID);//write id data
			fIndex.write(to_value.c_str(), LENGTH_VALUE);//write value data
			//no changes in fEmpty, so no need to change it.
			//fEmpty.write();
		}
		fIndex.close();
		fEmpty.close();
		return true;
	}
	else
		return false;

}
bool bookdocking::bookdelete(int id) {
	string temp;
	if (database.remove(id)) {
		fEmpty.open("fEmpty.txt", ios::binary);
		fIndex.open("fIndex.txt", ios::binary);
		line_num = search(id);// get the correct destination the fIndex stores that line of data (return the address of it.)
		v_index = to_string(line_num);//transform the line_num(int) to string
		for (int i = 0; i < line_num; i++) getline(fIndex, temp);
		//[warning: line_num is the num of line, not the true address!]fIndex.seekp(line_num/*address*/, ios::beg);//move the pointer of fIndex to the place of address
		fIndex.write(blank_str.c_str(), LENGTH_ID + LENGTH_VALUE);//replace the datas with a blank string (88 bytes, a line).
		if (fEmpty.peek() == EOF) {//if fEmpty is empty
			fEmpty.seekp(0, ios::beg);
			fEmpty.write(v_index.c_str(), LENGTH_INDEXADDRESS);//write the position data into the fEmpty
			// not [fEmpty.write(new_str.c_str(), LENGTH_INDEXADDRESS);]!!!!
		}
		else {//fEmpty is not empty
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
			fEmpty.seekp(0, ios::beg);
			getline(fEmpty, new_str);
			while (atoi(new_str.c_str()))//while new_str receives not "0000" (0 in int), keep traversing for the next line,
			//until find a "0000" to rewrite into.
			{
				firstEmpty = fEmpty.tellg();
				getline(fEmpty, new_str);
			}
			fEmpty.seekp(firstEmpty, ios::beg); //move the pointer to the empty(0000) place
			fEmpty.write(v_index.c_str(), LENGTH_INDEXADDRESS);//write the position data into the fEmpty
		}
		fEmpty.close();
		fIndex.close();
		return true;
	}
	else
		return false;
}
int bookdocking::search(int id) {// get the correct destination the fIndex stores that line of data (return the address of it.)
	int red = 0, ret = 0;//red is the receiver of the data, ret to return the num of line the data lies on
	string rec, recc;//rec to receive data, recc to save a part of rec
	fIndex.open("fIndex.txt", ios::binary);//opens fIndex directly, ignore the fIndex opened outside the func domain
	if (fIndex.peek() == EOF) return ret;
	getline(fIndex, rec);//get a line in fIndex, save the data in rec
	recc = rec.substr(0, LENGTH_ID);//cut the rec, remaining the ID data only
	red = atoi(recc.c_str());//trans into integer
	ret += 1;
	while (red != id) {//if not equal, re-get a new data from next line in fIndex
		if (fIndex.peek() == EOF) break;
		getline(fIndex, rec);
		recc = rec.substr(0, LENGTH_ID);
		red = atoi(recc.c_str());
		ret += 1;
	}
	if (red != id) {
		return ret;
	}
	else return ret - 1;
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

