

# Search类使用说明

## 一、介绍

​	Database类的数据存储形式为树形（B+树），虽然查找的时间复杂度为<img src="img/image-20201012211813060.png" alt="image-20201012211813060" style="zoom:150%;" />,且树中数据按关键字严格有序，遍历数据需要的时间复杂度仍然很高，约为<img src="img/WINWORD_[42] 2020-10-23 14_38_28.png" alt="WINWORD_[42] 2020-10-23 14_38_28" style="zoom:50%;" />，对于N很大的场景系统开销将非常大，因而设计一种专门的遍历索引就非常有必要。

​	Search类建立findex/fmindex/fISBNindex+fnameindex+fauthorindex文件，存储每一个数据的关键字（id）及对应的部分值。完成对database类的增删改查后，在**退出系统时**运行。

## 二、定义

​	存储形式：8个字节的ID+80字节的value（finedx.txt)

​												x字节的数据项（fmindex.txt)

​												6字节的数据项（fISBNindex.txt)

​												8字节的数据项（fnameindex.txt)

​												4字节的数据项（fauthorindex.txt）

​	Search类

```C++
class Search
{
public:
	//构造函数
	Search();
	//生成索引表，格式为[id 索引项],id为8位整数按二进制字符存储、索引项为二进制字符串全串
	bool indexFile_Create();
	//indexFile_Create()的变种，生成的索引项为字符串中的一部分
	bool indexFile_Create_mod(string mod);
	//indexFile_Create()的变种，生成的索引项为字符串中自str_min起长度为str_len的部分
	bool indexFile_Create_mod(int str_min, int str_len);
	//调用函数
	bool indexFile_Traverse();
	//调用函数的变种，给定索引项的类型
	bool indexFile_Traverse(string mod);
	//调用函数的变种，给定索引项在字符串中的起始位置与长度
	bool indexFile_Traverse(int str_min, int str_len);
	//遍历函数，对database中所有数据读取到内存
	bool indexFile_Search();
	//初始化函数，确定database中数据关键字的范围（严格单调）
	bool indexFile_Init();
	~Search();
private:
	int max_key;//最大关键字
	int min_key;//最小关键字
	vector<int>id;//id容器
	vector<string>value;//value字符串容器
};
```

### 1. 实现

indexFile_Init()函数：判断树（实际是index文件）中最小的key和最大的key（关键字）

```C++
bool Search::indexFile_Init() {
	string value;
	while (!database.select(min_key, value)) min_key++;
	while (!database.select(max_key, value)) max_key--;
	return true;
}
```

indexFile_Search()函数：遍历树，将每一个(id,value)分别放入容器id，value。

```C++
bool Search::indexFile_Search() {
	string v;
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
	return true;
}
```

indexFile_Create()函数：将id与value两个vector容器中的内容逆序存入fintex.txt文件中。


```C++
bool Search::indexFile_Create() {//全字符串版本
	ofstream findex("findex.txt", ios::binary);
	string data_id;
	string data_value;
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
```

indexFile_Create_mod(string mod)函数：indexFile_Create()函数的衍生，将id与value两个vector容器中的内容逆序存入f+“mod”+intex.txt文件中，但每个value只截取mod对应的部分，比如ISBN，name，author。注：vector容器读写，遇到空字符会发生std::out_of_range错误。

```C++
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
	catch (std::out_of_range& exc) {//遇到空字符时，读取失败
		std::cerr << exc.what() << endl;
		return false;
	}
	return true;
}
```

indexFile_Create_mod(int str_min, int str_len)函数：indexFile_Create()函数的衍生，将id与value两个vector容器中的内容逆序存入fmintex.txt文件中，但每个value只截取第str_min位到第str_len位。

```C++
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
```

indexFile_Traverse()函数：调用上述函数。在main文件中使用。

```C++
bool Search::indexFile_Traverse() {
	indexFile_Init();
	indexFile_Search();
	indexFile_Create();
	return true;
}
```

```C++
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

```

```C++
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
```

### 2. 使用

#### (1). 主程序代码片

```C++
	Search search;
	int min = 0, len = 0;
	string mod;
```

```C++
case 4:
				cout << "Please input the mod:";
				cin >> mod;
				if (search.indexFile_Traverse(mod))
					cout << "Search traverse successfully." << endl;
				else
					cout << "Search traverse failed." << endl;
				goto END;
```

```C++
END:
		cout << "Bye" << endl;
		return 0;
```



#### (2). main.cpp

```C++
#include "Database.h"
#include "Search.h"
int main()
{
	Database database;
	Search search;
	int op, key;
	int min = 0, len = 0;
	string value, mod;
	while (true)
	{
		cout << "0.SELECT" << endl;
		cout << "1.INSERT" << endl;
		cout << "2.REMOVE" << endl;
		cout << "3.UPDATE" << endl;
		cout << "4.quit" << endl;
		cout << "Please input a number:";
		cin >> op;
		//if (op == 4)
			//break;
		switch (op)
		{
			case 0:
				cout << "Please input the key:";
				cin >> key;
				if (database.select(key, value))
					cout << "key:" << key << " value:" << value << endl;
				else
					cout << "key:" << key << " NOT FOUND" << endl;
				break;
			case 1:
				cout << "Please input the key:";
				cin >> key;
				cout << "Please input the value:";
				cin >> value;
				if (database.insert(key, value))
					cout << "INSERT key:" << key << " value:" << value << endl;
				else
					cout << "INSERT key:" << key << " ALREADY EXISTS" << endl;
				break;
			case 2:
				cout << "Please input the key:";
				cin >> key;
				if (database.remove(key))
					cout << "REMOVE key:" << key << endl;
				else
					cout << "REMMOVE key:" << key << " NOT FOUND" << endl;
				break;
			case 3:
				cout << "Please input the key:";
				cin >> key;
				cout << "Please input the value:";
				cin >> value;
				if (database.update(key, value))
					cout << "UPDATE key:" << key << " value:" << value << endl;
				else
					cout << "UPDATE key:" << key << " NOT FOUND" << endl;
				break;
			case 4:
				cout << "Please input the mod:";
				cin >> mod;
				if (search.indexFile_Traverse(mod))
					cout << "Search traverse successfully." << endl;
				else
					cout << "Search traverse failed." << endl;
				goto END;
			default:
				cout << "Invalid input" << endl;
				break;
		}
	}
	END:
		cout << "Bye" << endl;
		return 0;
}

```



## 三、备注

需要结合定义后的database后台文件使用。尚未使用数据进行验证，仅保证能运行。对于初始状态的index、data文件，运行所需时间为3s，占用内存3MB。