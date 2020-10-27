#include"supervisor.h"


void supervisor::managebook() {
	int op;
	while (true)
	{
		cout << "1.增加图书" << endl;
		cout << "2.删除图书" << endl;
		cout << "3.修改图书信息" << endl;
		cout << "0.quit" << endl;
		cout << "请输入你的选择:";
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
			cout << "非法的输入！";
		}
	}
}