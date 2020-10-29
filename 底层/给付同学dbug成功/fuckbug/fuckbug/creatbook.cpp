#include "bookdocking.h"
#include "supervisor.h"

//增加新图书
//逻辑层函数名称：增加图书 createbook
//调用底层函数：bookadd(string ISBN,string name,string author,string type,string id,string borrowtime,string returntime,string history, bool onsheelf,bool isovertime;)
//底层函数返回值：bool
void supervisor::createbook() {
	bookdocking docking;
	string ISBN;
	string name;
	string author;
	string type;
	int id;
	string borrowtime, returntime, history, onsheelf, isovertime;
	borrowtime = "00-00-00";
	returntime = "00-00-00";
	history = "history:";
	onsheelf = "1";
	isovertime = "0";
	string value;

	cout << "请入要增加的图书ID：" << endl;
	cin >> id;
	if (docking.bookexist(id)) {
		cout << "该图书已经存在！" << endl;
	}
	else {
		cout << "请依次输入图书的ID,ISBN,书名,作者,分类: ";
		cin >> id >> ISBN >> name >> author >> type;
		//把输入的信息转换成规定的大小 
		ISBN = dataformatting(6, ISBN);
		name = dataformatting(8, name);
		author = dataformatting(4, author);
		type = dataformatting(4, type);
		history = dataformatting(20, history);
		if (docking.bookadd(id, ISBN, name, author, type, borrowtime, returntime, history, onsheelf, isovertime))
		{
			cout << "添加成功！" << endl;
			//展示图书信息
			value = docking.booksearch(id);
			//把得到的包含所有信息的字符串分发给各个字段
			ISBN = value.substr(0, 6);
			name = value.substr(6, 8);
			author = value.substr(14, 4);
			type = value.substr(18, 4);
			borrowtime = value.substr(22, 8);
			returntime = value.substr(30, 8);
			history = value.substr(38, 20);
			onsheelf = value.substr(58, 1);
			isovertime = value.substr(59, 1);
			cout << "id: " << id << " ISBN: " << ISBN << " name: " << name << " author: " << author << " type: " << type << endl;
			cout << "borrowtime: " << borrowtime << endl;
			cout << "returntime: " << returntime << endl;
			cout << "histroy: " << endl << history << endl;
			cout << "onsheelf: " << onsheelf << " isovertime: " << isovertime << endl;
		}
			
		else
			cout << "添加失败！" << endl;
	}
}

