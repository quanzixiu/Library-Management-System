#include"supervisor.h"


void supervisor::managebook() {
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
			createbook();
		else if (op == "2")
			deletebook();
		else if (op == "3")
			modifybook();
		else
			cout << "�Ƿ������룬�����ԣ�"<<endl;
		/*
		switch (op)
		{
		case 1:
			createbook();
			break;
		case 2:
			deletebook();
			break;
		case 3:
			modifybook();
			break;
		default:
			cout << "�Ƿ������룡";
			break;
		}
		*/
	}
}