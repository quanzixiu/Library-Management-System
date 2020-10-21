#include "userstatesdocking.h"

int main()
{
	userstatesdocking usdocking;
	int op,id;
	string value;
	string bookid;

	while (true)
	{
		cout << "1.search" << endl;
		cout << "2.create" << endl;
		cout << "3.add" << endl;
		cout << "4.delete" << endl;
		cout << "0.quit" << endl;
		cout << "Please input a number:";
		cin >> op;
		if (op == 0)
			break;
		switch (op)
		{
		case 1:
			cout << "Search: please input id: ";
			cin >> id;
			if (usdocking.usexist(id))
			{
				value = usdocking.ussearch(id);
				value = value.substr(0, 120);
				cout << value << endl;
			}
			else
			{
				cout << "failure"<<endl;
			}
			break;
		case 2:
			cout << "Create: please input id bookid: ";
			cin >> id >> bookid;
			if (usdocking.uscreate(id, bookid)) {
				cout << "sucess" << endl;
			}
			else
			{
				cout << "failure" << endl;
			}
			break;
		case 3:
			cout << "Add: please input id bookid: ";
			cin >> id >> bookid;
			if (usdocking.usadd(id, bookid)) {
				cout << "sucess" << endl;
			}
			else
			{
				cout << "failure" << endl;
			}
			break;
		case 4:
			cout << "Delete: please input id bookid: ";
			cin >> id >> bookid;
			if (usdocking.usdelete(id, bookid)) {
				cout << "sucess" << endl;
			}
			else
			{
				cout << "failure" << endl;
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