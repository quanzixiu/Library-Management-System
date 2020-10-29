#include"supervisor.h"


void supervisor::managebook() {
	string op;
	while (true)
	{
		cout << "1.增加图书" << endl;
		cout << "2.删除图书" << endl;
		cout << "3.修改图书信息" << endl;
		cout << "0.退出" << endl;
		cout << "请输入你的选择:";
		cin >> op;
		if (op == "0")
		{
			cout << "再见！"<<endl;
			break;
		}	
		if (op == "1")
			createbook();
		else if (op == "2")
			deletebook();
		else if (op == "3")
			modifybook();
		else
			cout << "非法的输入，请重试！"<<endl;
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
			cout << "非法的输入！";
			break;
		}
		*/
	}
}