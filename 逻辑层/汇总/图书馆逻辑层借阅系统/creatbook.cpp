#pragma once
#include "supervisor.h"

//增加新图书
//逻辑层函数名称：增加图书 createbook
//调用底层函数：bookadd(string ISBN,string name,string author,string type,string id,string borrowtime,string returntime,string history, bool onsheelf,bool isovertime;)
//底层函数返回值：bool
void supervisor::createbook(bookdocking& bd) {
	string ISBN;
	string name;
	string author;
	string type;
	int id;
	string borrowtime, returntime, history, onsheelf, isovertime;
	borrowtime = "00000000";
	returntime = "00000000";
	history = "";
	onsheelf = "1";
	isovertime = "0";
	string value;
	string ID;

	cout << "请入要增加的图书ID：" << endl;
	cin >> ID;
	while (ID.length() > 6 || atoi(ID.c_str()))//ID不能长度超过6或者包含字母或者单独为0
	{
		cout << "输入有误，请重新输入:";
		cin >> ID;
	}
	id = atoi(ID.c_str());

	if (bd.bookexist(id)) {
		cout << "该图书已经存在！" << endl;
	}
	else {
		cout << "请输入图书的ISBN: ";
		cin >> ISBN ;
		while (ISBN.length() > 6)
		{
			cout << "输入有误，请重新输入6位以内的ISBN：";
			cin >> ISBN;
		}

		cout << "请输入图书的书名: ";
		cin >>  name ;
		while (name.length() > 8)
		{
			cout << "输入有误，请重新输入8位以内的书名：";
			cin >> name;
		}

		cout << "请输入图书的作者: ";
		cin >>  author ;
		while (author.length() > 8)
		{
			cout << "输入有误，请重新输入8位以内的作者名：";
			cin >> author;
		}

		cout << "请输入图书的分类: ";
		cin >>  type ;
		while (type.length() > 8)
		{
			cout << "输入有误，请重新输入8位以内的分类：";
			cin >> type;
		}
		//把输入的信息转换成规定的大小 
		ISBN = dataformatting(6, ISBN);
		name = dataformatting(8, name);
		author = dataformatting(4, author);
		type = dataformatting(4, type);
		history = dataformatting(40, history);
		if (bd.bookadd(id, ISBN, name, author, type, borrowtime, returntime, history, onsheelf, isovertime))
		{
			cout << "添加成功！" << endl;
			//展示图书信息
			value = bd.booksearch(id);
			//把得到的包含所有信息的字符串分发给各个字段
			ISBN = value.substr(0, 6);
			name = value.substr(6, 8);
			author = value.substr(14, 4);
			type = value.substr(18, 4);
			borrowtime = value.substr(22, 8);
			returntime = value.substr(30, 8);
			history = value.substr(38, 40);
			onsheelf = value.substr(78, 1);
			isovertime = value.substr(79, 1);
			cout << "ID: " << id << " ISBN: " << ISBN << " 书名: " << name << " 作者: " << author << " 分类: " << type << endl;
			cout << "借书时间: " << borrowtime << endl;
			cout << "应还时间: " << returntime << endl;
			cout << "借阅历史: " << history << endl;
			cout << "是否在架: " << onsheelf << endl;
			cout <<"是否超期: " << isovertime << endl;
		}
			
		else
			cout << "添加失败！" << endl;
	}
}

