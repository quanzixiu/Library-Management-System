#include<iostream>
#include"supervisor.h"
#include"returnbook.h"


int main()
{
	supervisor admin;
	//returnbook book;
	string choice;
	while (true)
	{
		if (admin.slogin())
		{
			cout << "��ѡ���ܣ�" << endl;
			cout << "1.ͼ�����" << endl;
			cout << "2.�û�����" << endl;
			cout << "0.�˳�" << endl;
			cin >> choice;
			if (choice == "1")
			{
				admin.managebook();
			}
			else if (choice == "2")
			{
				admin.manageuser();
			}
			else if (choice == "0")
			{
				break;
			}
			else
			{
				cout << "�Ƿ������룬�����ԣ�";
			}
		}
	}
	//����Ӧ�ú����˵���һ�𣬼�����ѡ�1����Ա��¼ 2�û���¼ 3���� 
	//book.returnBook();
	return 0;
}