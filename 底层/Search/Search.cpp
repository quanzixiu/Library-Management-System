#include "Search.h"
Database database;

Search::Search() {
	min_key = 0;
	max_key = 9999;
}

Search::~Search() {
}

bool Search::indexFile_Init() {
	/*fstream index, data;
	index.open("index.txt", ios::binary, 1);
	data.open("data.txt", ios::binary, 1);
	*/
	string value;
	while (!database.select(min_key, value)) min_key++;
	while (!database.select(max_key, value)) max_key--;
	/*
	index.close();
	data.close();
	*/
	return true;
}
bool Search::indexFile_Search() {
	string v;
	/*fstream index, data;
	index.open("index.txt", ios::binary, 1);
	data.open("data.txt", ios::binary, 1);
	*/
	//ofstream findex("findex.txt", ios::binary);
	try {
		for (int i = min_key; i < max_key; i++) {
			if (database.select(i, v)) {
				id.push_back(i);
				value.push_back(v);
			}
		}
	}
	catch (std::out_of_range& exc) {
		std::cerr << exc.what() << endl;
		return false;
	}
	/*index.close();
	data.close();
	*/
	return true;
}

bool Search::indexFile_Create() {//È«×Ö·û´®°æ±¾
	ofstream findex("findex.txt", ios::binary);
	//int* data_id = (int*)malloc(sizeof(int));
	string data_id;
	string data_value;// = (string*)malloc(LENGTH_VALUE);
	while (!id.empty()) {
		data_id = to_string(id.back());
		id.pop_back();
		data_value = value.back();
		value.pop_back();
		findex.write(data_id.c_str(), LENGTH_ID);
		findex.write(data_value.c_str(), LENGTH_VALUE);
	}
	findex.close();
	return true;
}

bool Search::indexFile_Create_mod(string mod) {
	string data_id;
	string data_value;
	try {
		if (mod == "ISBN") {
			ofstream fmindex("fISBNindex.txt", ios::binary);
			while (!id.empty()) {
				data_id = to_string(id.back());
				id.pop_back();
				data_value = value.back().substr(START_ISBN, LENGTH_ISBN);
				value.pop_back();
				fmindex.write(data_id.c_str(), LENGTH_ID);
				fmindex.write(data_value.c_str(), LENGTH_ISBN);
				fmindex.close();
			}
		}
		if (mod == "name") {
			ofstream fmindex("fnameindex.txt", ios::binary);
			while (!id.empty()) {
				data_id = to_string(id.back());
				id.pop_back();
				data_value = value.back().substr(START_NAME, LENGTH_NAME);
				value.pop_back();
				fmindex.write(data_id.c_str(), LENGTH_ID);
				fmindex.write(data_value.c_str(), LENGTH_NAME);
				fmindex.close();
			}
		}
		if (mod == "author") {
			ofstream fmindex("fauthorindex.txt", ios::binary);
			while (!id.empty()) {
				data_id = to_string(id.back());
				id.pop_back();
				data_value = value.back().substr(START_AUTHOR, LENGTH_AUTHOR);
				value.pop_back();
				fmindex.write(data_id.c_str(), LENGTH_ID);
				fmindex.write(data_value.c_str(), LENGTH_AUTHOR);
				fmindex.close();
			}
		}
	}
	catch (std::out_of_range& exc) {//Óöµ½¿Õ×Ö·ûÊ±£¬¶ÁÈ¡Ê§°Ü
		std::cerr << exc.what() << endl;
		return false;
	}
	return true;
}
bool Search::indexFile_Create_mod(int str_min, int str_len) {
	ofstream fmindex("fmindex.txt", ios::binary);
	string data_id;
	string data_value;
	while (!id.empty()) {
		data_id = to_string(id.back());
		id.pop_back();
		data_value = value.back().substr(str_min, str_len);
		value.pop_back();
		fmindex.write(data_id.c_str(), LENGTH_ID);
		fmindex.write(data_value.c_str(), str_len);
	}
	fmindex.close();
	return true;
}

bool Search::indexFile_Traverse() {
	indexFile_Init();
	indexFile_Search();
	indexFile_Create();
	return true;
}

bool Search::indexFile_Traverse(string mod) {
	indexFile_Init();
	if (indexFile_Search())
		cout << "Search Successfully." << endl;
	else
		cout << "Search Failed" << endl;
	if (indexFile_Create_mod(mod)) {
		cout << "FastIndex create successfully." << endl;
		return true;
	}
	else
	{
		cout << "FastIndex create failed." << endl;
		return false;
	}
}

bool Search::indexFile_Traverse(int str_min, int str_len) {
	indexFile_Init();
	if (indexFile_Search())
		cout << "Search Successfully." << endl;
	else
		cout << "Search Failed" << endl;
	if (indexFile_Create_mod(str_min, str_len)) {
		cout << "FastIndex create successfully." << endl;
		return true;
	}
	else
	{
		cout << "FastIndex create failed." << endl;
		return false;
	}
}