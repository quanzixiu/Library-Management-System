#ifndef SEARCH_H
#define SEARCH_H
#define START_ISBN 0
#define START_NAME 6
#define START_AUTHOR 14
#define LENGTH_ID 8
#define LENGTH_ISBN 6
#define LENGTH_NAME 8
#define LENGTH_AUTHOR 4
#define LENGTH_VALUE 80
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Database.h"
#include<cctype>
using namespace std;

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

#endif // !SEARCH_H
#pragma once