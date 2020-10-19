#include "bookdocking.h"
#include "supervisor.h"

//增加新图书
//逻辑层函数名称：增加图书 createbook
//调用底层函数：bookadd(string ISBN,string name,string author,string type,string id,string borrowtime,string returntime,string history, bool onsheelf,bool isovertime;)
//底层函数返回值：bool
bool supervisor::createbook() {
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
	isovertime = 0;

	cout << "请入要增加的图书ID：" << endl;
	cin >> id;
	if (existbook(id)) {
		cout << "该图书已经存在！" << endl;
		return false;
	}
	else {
		cout << "请依次输入图书的ID,ISBN,name,author,type: ";
		cin >> id >> ISBN >> name >> author >> type;
		//把输入的信息转换成规定的大小 
		ISBN = dataformatting(6, ISBN);
		name = dataformatting(8, name);
		author = dataformatting(4, author);
		type = dataformatting(4, type);
		history = dataformatting(20, history);
		if (docking.bookadd(id, ISBN, name, author, type, borrowtime, returntime, history, onsheelf, isovertime))
			cout << "success" << endl;
		else
			cout << "failure" << endl;
	}
}

