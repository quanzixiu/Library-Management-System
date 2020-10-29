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
