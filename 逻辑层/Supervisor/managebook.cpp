#include"supervisor.h"


void supervisor::managebook() {
	int op;
	while (true)
	{
		cout << "1.����ͼ��" << endl;
		cout << "2.ɾ��ͼ��" << endl;
		cout << "3.�޸�ͼ����Ϣ" << endl;
		cout << "0.quit" << endl;
		cout << "���������ѡ��:";
		cin >> op;
		if (op == 0)
			break;
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
		}
	}
}