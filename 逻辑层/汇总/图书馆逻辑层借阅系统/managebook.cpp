#pragma once
#include"supervisor.h"


void supervisor::managebook(bookdocking& bd) {
	string op;
	while (true)
	{
		cout << "1.����ͼ��" << endl;
		cout << "2.ɾ��ͼ��" << endl;
		cout << "3.�޸�ͼ����Ϣ" << endl;
		cout << "0.�˳�" << endl;
		cout << "���������ѡ��:";
		cin >> op;
		if (op == "0")
		{
			cout << "�ټ���"<<endl;
			break;
		}	
		if (op == "1")
			createbook(bd);
		else if (op == "2")
			deletebook(bd);
		else if (op == "3")
			modifybook(bd);
		else
			cout << "�Ƿ������룬�����ԣ�"<<endl;

	}
}