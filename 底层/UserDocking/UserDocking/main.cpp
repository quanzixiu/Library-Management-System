#include "userdocking.h"

int main()
{
	userdocking udocking;
	int op,op1,id;
	string value;
	string name, college, major, password, email;
	
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
				cout << "Search: Please input the id:";
				cin >> id;
				if (udocking.userexist(id)) //每次查询前要先判断
				{
					value = udocking.usersearch(id);
					//把得到的包含所有信息的字符串分发给各个字段
					name = value.substr(0, 8);
					college = value.substr(8, 4);
					major = value.substr(12, 4);
					password = value.substr(16, 16);
					email = value.substr(32, 24);

					cout << "id: " << id << " name: " << name << " college: " << college << " major: " << major << endl;
					cout << "password: " << password << endl;
					cout << "email: " << email << endl;
				}
				else
				{
					cout << "failure" << endl;
				}
				break;
			case 2:
				cout << "Add: Please input id name college major password email:";
				cin >> id >> name >> college >> major >> password >> email;
				//把输入的信息转换成规定的大小 

				name = dataformatting(8, name);
				college = dataformatting(4, college);
				major = dataformatting(4, major);
				password = dataformatting(16, password);
				email = dataformatting(24, email);
				if (udocking.useradd(id, name, college, major, password, email))
					cout << "success" << endl;
				else
					cout << "failure" << endl;

				break;
			case 3:
				cout << "Delete: Please input the id:";
				cin >> id;
				if (udocking.userdelete(id))
					cout << "success" << endl;
				else
					cout << "failure" << endl;
				break;
			case 4:
				while (true)
				{
					cout << "Usermodify:" << endl;
					cout << "1.name" << endl;
					cout << "2.college" << endl;
					cout << "3.major" << endl;
					cout << "4.password" << endl;
					cout << "5.email" << endl;

					cout << "0.quit" << endl;
					cout << "Please input a number:";
					cin >> op1;
					if (op1 == 0)
						break;
					switch (op1)
					{
					case 1:
						cout << "Please input id name:";
						cin >> id;
						cin >> name;
						name = dataformatting(8, name);
						if (udocking.usermodifyname(id, name))
							cout << "success" << endl;
						else
							cout << "failure" << endl;
						break;
					case 2:
						cout << "Please input id college:";
						cin >> id;
						cin >> college;
						college = dataformatting(4, college);
						if (udocking.usermodifycollege(id, college))
							cout << "success" << endl;
						else
							cout << "failure" << endl;
						break;
					case 3:
						cout << "Please input id major:";
						cin >> id;
						cin >> major;
						major = dataformatting(4, major);
						if (udocking.usermodifymajor(id, major))
							cout << "success" << endl;
						else
							cout << "failure" << endl;
						break;
					case 4:
						cout << "Please input id password:";
						cin >> id;
						cin >> password;
						password = dataformatting(4, password);
						if (udocking.usermodifypassword(id, password))
							cout << "success" << endl;
						else
							cout << "failure" << endl;
						break;
					case 5:
						cout << "Please input id borrowtime:";
						cin >> id;
						cin >> email;
						email = dataformatting(8, email);
						if (udocking.usermodifyemail(id, email))
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