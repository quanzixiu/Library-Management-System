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
	//���캯��
	Search();
	//������������ʽΪ[id ������],idΪ8λ�������������ַ��洢��������Ϊ�������ַ���ȫ��
	bool indexFile_Create();
	//indexFile_Create()�ı��֣����ɵ�������Ϊ�ַ����е�һ����
	bool indexFile_Create_mod(string mod);
	//indexFile_Create()�ı��֣����ɵ�������Ϊ�ַ�������str_min�𳤶�Ϊstr_len�Ĳ���
	bool indexFile_Create_mod(int str_min, int str_len);
	//���ú���
	bool indexFile_Traverse();
	//���ú����ı��֣����������������
	bool indexFile_Traverse(string mod);
	//���ú����ı��֣��������������ַ����е���ʼλ���볤��
	bool indexFile_Traverse(int str_min, int str_len);
	//������������database���������ݶ�ȡ���ڴ�
	bool indexFile_Search();
	//��ʼ��������ȷ��database�����ݹؼ��ֵķ�Χ���ϸ񵥵���
	bool indexFile_Init();
	~Search();
private:
	int max_key;//���ؼ���
	int min_key;//��С�ؼ���
	vector<int>id;//id����
	vector<string>value;//value�ַ�������
};

#endif // !SEARCH_H
#pragma once