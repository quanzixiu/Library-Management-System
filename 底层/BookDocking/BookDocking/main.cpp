#include "bookdocking.h"

int main()
{
	bookdocking docking;
	int op,op1,id;
	string value;
	string ISBN, name, author, type, borrowtime, returntime, histroy, onsheelf, isovertime;
	borrowtime = returntime = "00-00-00";
	histroy = "历史记录";
	onsheelf = isovertime = "1";
	while (true)
	{
		cout << "1.search" << endl;
		cout << "2.add" << endl;
		cout << "3.delete" << endl;
		cout << "4.modify" << endl;
		cout << "0.quit" << endl;
		cout << "Please input a number:";
		cin >> op;
		if (op == 0)
			break;
		switch (op)
		{
			case 1:
				cout << "Please input the id:";
				cin >> id;
				value = docking.booksearch(id);
				//把得到的包含所有信息的字符串分发给各个字段
				ISBN = value.substr(0, 6);
				name = value.substr(6, 8);
				author = value.substr(14, 4);
				type = value.substr(18, 4);
				borrowtime = value.substr(22, 8);
				returntime = value.substr(30, 8);
				histroy = value.substr(38, 20);
				onsheelf = value.substr(58, 1);
				isovertime = value.substr(59, 1);
				cout << "id: "<< id <<" ISBN: "<< ISBN <<" name: "<< name <<" author: "<< author <<" type: "<< type << endl;
				cout << "borrowtime: "<< borrowtime << endl;
				cout << "returntime: " << returntime << endl;
				cout << "histroy: " << endl << histroy << endl;
				cout << "onsheelf: "<< onsheelf <<" isovertime: " << isovertime << endl;
				break;
			case 2:
				cout << "Please input id ISBN name author type:";
				cin >> id >> ISBN >> name >> author >> type;
				//把输入的信息转换成规定的大小 

				ISBN = dataformatting(6, ISBN);
				name = dataformatting(8, name);
				author = dataformatting(4, author);
				type = dataformatting(4, type);
				histroy = dataformatting(20, histroy);
				if (docking.bookadd(id, ISBN, name, author, type, borrowtime, returntime, histroy, onsheelf, isovertime))
					cout << "success" << endl;
				else
					cout << "failure" << endl;

				break;
			case 3:
				cout << "Please input the id:";
				cin >> id;
				if (docking.bookdelete(id))
					cout << "success" << endl;
				else
					cout << "failure" << endl;
				break;
			case 4:
				while (true)
				{
					cout << "1.ISBN" << endl;
					cout << "2.name" << endl;
					cout << "3.author" << endl;
					cout << "4.borrowtime" << endl;
					cout << "5.returntime" << endl;
					cout << "6.history" << endl;
					cout << "7.onsheelf" << endl;
					cout << "8.isovertime" << endl;
					cout << "0.quit" << endl;
					cout << "Please input a number:";
					cin >> op1;
					if (op1 == 0)
						break;
					switch (op1)
					{
					case 1:
						cout << "Please input id ISBN:";
						cin >> id;
						cin >> ISBN;
						ISBN = dataformatting(6, ISBN);
						if (docking.bookmodifyISBN(id, ISBN))
							cout << "success" << endl;
						else
							cout << "failure" << endl;
						break;
					case 2:
						cout << "Please input id name:";
						cin >> id;
						cin >> name;
						name = dataformatting(8, name);
						if (docking.bookmodifyname(id, name))
							cout << "success" << endl;
						else
							cout << "failure" << endl;
						break;
					case 3:
						cout << "Please input id author:";
						cin >> id;
						cin >> author;
						author = dataformatting(4, author);
						if (docking.bookmodifyauthor(id, author))
							cout << "success" << endl;
						else
							cout << "failure" << endl;
						break;
					case 4:
						cout << "Please input id type:";
						cin >> id;
						cin >> type;
						type = dataformatting(4, type);
						if (docking.bookmodifytype(id, type))
							cout << "success" << endl;
						else
							cout << "failure" << endl;
						break;
					case 5:
						cout << "Please input id borrowtime:";
						cin >> id;
						cin >> borrowtime;
						borrowtime = dataformatting(8, borrowtime);
						if (docking.bookmodifyborrowtime(id, borrowtime))
							cout << "success" << endl;
						else
							cout << "failure" << endl;
						break;
					case 6:
						cout << "Please input id returntime:";
						cin >> id;
						cin >> returntime;
						returntime = dataformatting(8, returntime);
						if (docking.bookmodifyreturntime(id, returntime))
							cout << "success" << endl;
						else
							cout << "failure" << endl;
						break;
					case 7:
						cout << "Please input id onsheelf:";
						cin >> id;
						cin >> onsheelf;
						onsheelf = dataformatting(8, onsheelf);
						if (docking.bookmodifyonsheelf(id, onsheelf))
							cout << "success" << endl;
						else
							cout << "failure" << endl;
						break;
					case 8:
						cout << "Please input id isovertime:";
						cin >> id;
						cin >> isovertime;
						isovertime = dataformatting(8, isovertime);
						if (docking.bookmodifyisovertime(id, isovertime))
							cout << "success" << endl;
						else
							cout << "failure" << endl;
						break;
					default:
						cout << "Invalid input" << endl;
						break;
					}
				}
				
				break;
			default:
				cout << "Invalid input" << endl;
				break;
		}
	}

	cout << "Bye" << endl;
	return 0;
}