

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

### 3. 使用说明

​	为使用Search类函数功能，请调用Search::indexFile_Traverse()函数，此函数会调用Search类的各个成员函数以生成快速索引。此函数有1个原型与2个重载：

​	原型不需要提供参数，生成的findex.txt文件中，键值对以(id, value)的形式存储，其中value是长度为80的数据串。

​	重载Search::indexFile_Traverse(string mod)的参数mod是生成模式，可接受的输入是"ISBN"."name"."author"三者之一，会按提供的参数分别生成fISBNindex.txt、fnameindex.txt、fauthorindex.txt三种文件，键值对分别以(id, somevalue)的形式存储，其中somevalue是长度分别为6、8、4的短字符串，从value字符串的0-5位、6-13位、14-17位截取而得。

​	重载Search::indexFile_Traverse(int str_min, int str_len)的两个参数是截取字符串的起始位与长度（从0开始），会从value中截取第str_min位到第str_min+str_len位的数据，与ID一起存入fmindex.txt中，格式与前述类似。读取fmindex.txt时需要事先规定读取的位数str_len，不然可能会导致逻辑混乱。

​	Search::indexFile_Traverse()不需要手动运行，在对底层的增删改查结束后，退出管理员系统时会自动运行，更新对应的快速索引文件以备用户系统使用。也可以在管理员系统中手动调用，以便管理员使用。完全遍历一次数据的时间复杂度较高，所以请谨慎使用Search::indexFile_Traverse()函数，切不可将其加入任何形式的循环或者嵌套调用之中，以免影响使用体验。

​	此外，应注意的是，Search::indexFile_Traverse()会调用Search::indexFile_Search()与Search::indexFile_Create()函数，涉及C++ STL的vector容器，尤其是vector<string>操作，若容器存取的string是空串('\0')，会引发std::out_of_range异常。Search::indexFile_Search()与Search::indexFile_Create()会默认创建失败，进而退出函数体。

## 三、运行与调试

### 1. Search::indexFile_Traverse()

未定义相关调用，请修改main.cpp文件以使用

### 2. Search::indexFile_Traverse(string mod)

#### (1). mod == ISBN

![VsDebugConsole_[44] 2020-10-25 19_50_57](img/VsDebugConsole_[44] 2020-10-25 19_50_57.png)

#### (2). mod == name

![VsDebugConsole_[45] 2020-10-25 19_51_21](img/VsDebugConsole_[45] 2020-10-25 19_51_21.png)

由于value中不包含name，所以vector<string>会读取到空串，进而引发std::out_of_range异常，被catch子句捕获并退出函数。

#### (3). mod == author

![VsDebugConsole_[46] 2020-10-25 19_51_48](img/VsDebugConsole_[46] 2020-10-25 19_51_48.png)

由于value中不包含author，所以vector<string>会读取到空串，进而引发std::out_of_range异常，被catch子句捕获并退出函数。



## 四、备注

​	需要结合定义后的database后台文件使用。尚未使用数据进行验证，仅保证能运行。对于初始状态的index、data文件，运行所需时间为3s，占用内存3MB。

​	一种改进方法：对文件尾的空串判断为读取成功，文件中部的空串判断为读取错误。上述功能有待实际验证。