#pragma once
#include "supervisor.h"
#include<string>

//修改图书信息
//逻辑层函数名称：修改图书 modifybook()
//调用底层函数：bookmodify(string id)
//底层函数返回值：bool

void supervisor::modifybook(bookdocking& bd) {
	string ISBN;
	string name;
	string author;
	string type;
	string borrowtime, returntime, history, onsheelf, isovertime;
	borrowtime= "00-00-00";
	returntime = "00-00-00";
	history = "";
	onsheelf = "1";
	isovertime = "0";
	string op1;
	int id;
	string value;
	string ID;
	cout << "请输入待修改图书的ID：";
	cin >> ID;
	while (ID.length() > 6 || atoi(ID.c_str()))//ID不能长度超过6或者包含字母或者单独为0
	{
		cout << "输入有误，请重新输入:";
		cin >> ID;
	}
	id = atoi(ID.c_str());
	if (!bd.bookexist(id)) cout << "该图书不存在！" << endl;
	else {
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
		cout << "是否超期: " << isovertime << endl;
		//输出修改选项
		while (true)
		{
			cout << "1.ISBN" << endl;
			cout << "2.书名" << endl;
			cout << "3.作者" << endl;
			cout << "4.分类" << endl;
			cout << "5.借书时间" << endl;
			cout << "6.应还时间" << endl;
			cout << "7.在架状态" << endl;
			cout << "8.是否超期" << endl;
			cout << "0.退出" << endl;
			cout << "请输入你的选择:";
			cin >> op1;
			if (op1 == "0")
				break;
			else if (op1 == "1") 
			{
				cout << "请输入图书的ISBN: ";
				cin >> ISBN;
				while (ISBN.length() > 6)
				{
					cout << "输入有误，请重新输入6位以内的ISBN：";
					cin >> ISBN;
				}
				ISBN = dataformatting(6, ISBN);
				if (bd.bookmodifyISBN(id, ISBN))
				{
					cout << "修改成功！" << endl;
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
					cout << "是否超期: " << isovertime << endl;
				}
				else
					cout << "修改失败！" << endl;
			}
			else if (op1 == "2")
			{
				cout << "请输入图书的书名: ";
				cin >> name;
				while (name.length() > 8)
				{
					cout << "输入有误，请重新输入8位以内的书名：";
					cin >> name;
				}
				name = dataformatting(8, name);
				if (bd.bookmodifyname(id, name))
				{
					cout << "修改成功！" << endl;
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
					cout << "ID:" << id << " ISBN: " << ISBN << " 书名: " << name << " 作者: " << author << " 分类: " << type << endl;
					cout << "借书时间: " << borrowtime << endl;
					cout << "应还时间: " << returntime << endl;
					cout << "借阅历史: " << history << endl;
					cout << "是否在架: " << onsheelf << endl;
					cout << "是否超期: " << isovertime << endl;
				}
				else
					cout << "修改失败！" << endl;
			}
			else if (op1 == "3")
			{
				cout << "请输入图书的作者: ";
				cin >> author;
				while (author.length() > 4)
				{
					cout << "输入有误，请重新输入4位以内的作者名：";
					cin >> author;
				}
				author = dataformatting(4, author);
				if (bd.bookmodifyauthor(id, author))
				{
					cout << "修改成功！" << endl;
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
					cout << "是否超期: " << isovertime << endl;
				}
				else
					cout << "修改失败！" << endl;
			}
			else if (op1 == "4")
			{
				cout << "请输入图书的分类: ";
				cin >> type;
				while (type.length() > 4)
				{
					cout << "输入有误，请重新输入4位以内的分类名：";
					cin >> type;
				}
				type = dataformatting(4, type);
				if (bd.bookmodifytype(id, type))
				{
					cout << "修改成功！" << endl;
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
					cout << "是否超期: " << isovertime << endl;
				}
				else
					cout << "修改失败！" << endl;
			}
			else if (op1 == "5")
			{
				cout << "请输入借书时间:";
				cin >> borrowtime;
				while (borrowtime.length() > 8)
				{
					cout << "输入有误，请重新输入8位以内的借书时间：";
					cin >> borrowtime;
				}
				borrowtime = dataformatting(8, borrowtime);
				if (bd.bookmodifyborrowtime(id, borrowtime))
				{
					cout << "修改成功！" << endl;
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
					cout << "是否超期: " << isovertime << endl;
				}
				else
					cout << "修改失败！" << endl;
			}
			else if (op1 == "6")
			{
				cout << "请输入应还时间:";
				cin >> returntime;
				while (returntime.length() > 8)
				{
					cout << "输入有误，请重新输入8位以内的应还时间：";
					cin >> returntime;
				}
				returntime = dataformatting(8, returntime);
				if (bd.bookmodifyreturntime(id, returntime))
				{
					cout << "修改成功！" << endl;
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
					cout << "是否超期: " << isovertime << endl;
				}
				else
					cout << "修改失败！" << endl;
			}
			else if (op1 == "7")
			{
				cout << "请输入是否在架:";
				cin >> onsheelf;
				while (onsheelf.length() > 1)
				{
					cout << "输入有误，请重新输入1或0：";
					cin >> onsheelf;
				}
				//onsheelf = dataformatting(1, onsheelf);
				if (bd.bookmodifyonsheelf(id, onsheelf))
				{
					cout << "修改成功！" << endl;
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
					cout << "是否超期: " << isovertime << endl;
				}
				else
					cout << "修改失败！" << endl;
			}
			else if (op1 == "8")
			{
				cout << "请输入是否超期:";
				cin >> isovertime;
				while (isovertime.length() > 1)
				{
					cout << "输入有误，请重新输入1或0：";
					cin >> isovertime;
				}
				isovertime = dataformatting(1, isovertime);
				if (bd.bookmodifyisovertime(id, isovertime))
				{
					cout << "修改成功！" << endl;
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
					cout << "是否超期: " << isovertime << endl;
				}
				else
					cout << "修改失败！" << endl;
			}
			else
				cout << "非法的输入！" << endl;
	
		}
	}
}