#pragma once
#include "borrow.h"
int borrow::getID()
{
    return student.getid();
}

string borrow::getPassWord()
{
    return student.getpassword();
}



void borrow::setID(int id)
{
	student.setid(id);
}

void borrow::setPassWord(string password)
{
    student.setpassword(password);
}


void borrow::main(bookdocking& bd, userdocking& ud, userstatesdocking& usd, deque<int>& dqID, deque<string>& dqNAME, deque<string>& dqISBN, deque<string>& dqTYPE, bool& dqflag)
{
	int n=0;
	while(1)
	{
		n=mainPanel(ud);
		if (n == -1)break;
		main1Panel(bd,ud,usd,dqID,dqNAME,dqISBN,dqTYPE,dqflag);
	}
}

bool borrow::qtlogin(int id, string password, userdocking& ud)
{
	//定义用户登陆信息的变量
	string value, name, college, major, email;
	//登陆
	while (!islogin)
	{
		if (ud.userexist(id))
		{
			if (login(id, password, ud))
			{
				value = ud.usersearch(id);
				//把得到的包含所有信息的字符串分发给各个字段
				name = value.substr(0, 8);
				college = value.substr(8, 4);
				major = value.substr(12, 4);
				password = value.substr(16, 16);
				email = value.substr(32, 24);


				//给Student传入信息
				student.setid(id);
				student.setpassword(password);
				student.setname(name);
				student.setcollege(college);
				student.setmajor(major);
				student.setemail(email);
				islogin = true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}

	}
	return false;
}

bool borrow::qtborrowbook(int id, bookdocking& bd, userstatesdocking& usd)
{
	//判断书籍是否在架
	if (bd.bookexist(id))
	{
		string value, borrowtime, returntime, onsheelf, history;
		value = bd.booksearch(id);
		//把得到的包含所有信息的字符串分发给各个字段
		borrowtime = value.substr(22, 8);
		returntime = value.substr(30, 8);
		history = value.substr(38, 40);
		onsheelf = value.substr(78, 1);

		if (onsheelf == "0") {
			return false;
		}
		else
		{
			bool flag = true;
			if (!usd.usexist(student.getid()))
			{
				string pp;
				pp = dataformatting(120, to_string(id));
				usd.uscreate(student.getid(), pp);
			}
			else
			{
				string value = usd.ussearch(student.getid());
				value = dataformatting(120, value);

				if (value.at(114) != ' ')
				{
					flag = false;
					return false;
				}
				else
				{
					usd.usadd(student.getid(), dataformatting(6, to_string(id)));
				}
			}
			if (flag)
			{
				onsheelf = "0";
				onsheelf = dataformatting(1, onsheelf);
				bd.bookmodifyonsheelf(id, onsheelf);


				if (history.at(32) != ' ')
					history = dataformatting(8, to_string(student.getid()));
				else
				{
					int cnt = 0;
					for (int i = 0; i <= 4; i++)
					{
						if (history.at(i * (8)) != ' ')cnt++;
					}
					history = history.substr(0, cnt * (8)) + dataformatting(8, to_string(student.getid()));
				}

				history = dataformatting(40, history);
				bd.bookmodifyhistory(id, history);

				time_t* timer = NULL;
				time_t timet = time(timer);
				const  time_t* timerp = &timet;
				tm* t = localtime(timerp);
				borrowtime = to_string(t->tm_year + 1900) + num2str((t->tm_mon + 1)) + num2str(t->tm_mday);
				returntime = to_string(t->tm_year + 1900) + num2str((t->tm_mon + 1) % 12 + 1) + num2str(t->tm_mday);

				dataformatting(8, borrowtime);
				dataformatting(8, returntime);
				bd.bookmodifyborrowtime(id, borrowtime);
				bd.bookmodifyreturntime(id, returntime);

				return true;
			}

		}

	}
	else {
		return false;
	}
	//借阅时更改图书借阅在架、借书还书时间、借阅历史
	//修改借阅记录类
}

book borrow::qtidsearchbook(int id, bookdocking& bd)
{
	string value;
	book b;
	value = bd.booksearch(id);
	b.setISBN(value.substr(0, 6));
	b.setname(value.substr(6, 8));
	b.setauthor(value.substr(14, 4));
	b.settype(value.substr(18, 4));
	b.setborrowtime(value.substr(22, 8));
	b.setreturntime(value.substr(30, 8));
	b.sethistory(value.substr(38, 40));
	b.setonsheelf(value.substr(78, 1));
	b.setisovertime(value.substr(79, 1));
	return b;
}

user borrow::qtidsearchuser(int id, userdocking& ud)
{
	user stu;
	string value, name, college, major, email,password;
	value = ud.usersearch(id);
	//把得到的包含所有信息的字符串分发给各个字段
	name = value.substr(0, 8);
	college = value.substr(8, 4);
	major = value.substr(12, 4);
	password = value.substr(16, 16);
	email = value.substr(32, 24);

	//给Student传入信息
	stu.setid(id);
	stu.setpassword(password);
	stu.setname(name);
	stu.setcollege(college);
	stu.setmajor(major);
	stu.setemail(email);
	
	return stu;
}

bool borrow::qtbookexist(int id, bookdocking& bd)
{
	return bd.bookexist(id);
}

tuple<int,int*> borrow::qtreusercard(int id, bookdocking& bd)
{
	string value;
	value = bd.booksearch(id);
	string history=value.substr(38, 40);
	int cnt = 0;
	for (int i = 0; i < 5; i++)
	{
		if (history.at(i * (8)) != ' ')cnt++;
	}
	int* temp = new int[cnt];
	for (int i = 0; i < cnt; i++)
	{
		temp[i] = atoi(history.substr(i*(8),8).c_str());
	}
	tuple<int, int*> t(cnt,temp);
	return t;
}

tuple<int,int*> borrow::qtrebookbor(int id, userstatesdocking& usd)
{
	string value;
	value = usd.ussearch(id);
	string list = value.substr(0, 120);
	int cnt = 0;
	for (int i = 0; i < 20; i++)
	{
		if (list.at(i * (6)) != ' ')cnt++;
	}
	int* temp = new int[cnt];
	for (int i = 0; i < cnt; i++)
	{
		temp[i] = atoi(value.substr(i * (6), 6).c_str());
	}
	tuple<int, int*> t(cnt, temp);
	return t;
}

bool borrow::login(int id, string password,userdocking& ud)
{
	string value=ud.usersearch(id);
	string pass = value.substr(16, 16);
	password = dataformatting(16, password);
	if (pass == password)return true;
	else return false;
}

void borrow::typeshowbook(string type,bookdocking& bd, userstatesdocking& usd, deque<int>& dqID, deque<string>& dqTYPE)
{
	int cnt = 0;
	for (int i = 0; i < dqID.size(); i++)
	{
		if (dqTYPE.at(i) == dataformatting(4,type)) {
			cnt++;
			string value;
			cout << cnt << "." << endl;
			value = bd.booksearch(dqID.at(i));
			cout << "ID:" << dqID.at(i) << endl;
			cout << "ISBN:" << value.substr(0, 6) << endl;
			cout << "书名:" << value.substr(0, 6) << endl;
			cout << "作者:" << value.substr(14, 4) << endl;
			cout << "分类:" << value.substr(18, 4) << endl;
			cout << "是否在架:" << value.substr(78, 1) << endl;
			cout << "借书时间:" << value.substr(22, 8) << endl;
			cout << "还书时间:" << value.substr(30, 8) << endl;
			cout << "借阅历史:" << value.substr(38, 40) << endl;
		}
	}
	int p;
	cout << "请输入要借阅书籍的ID（按0退出）：";
	cin >> p;
	if (p == 0)return;
	else
	{
		borrowbook(dqID.at(p - 1), bd, usd);
	}
}

void borrow::ISBNsearchbook(bookdocking& bd, userstatesdocking& usd, deque<int>& dqID, deque<string>& dqISBN)
{
	string isbn;
	int cnt = 0;
	cout << "请输入ISBN：";
	cin >> isbn;
	for (int i = 0; i < dqID.size(); i++)
	{
		if (dqISBN.at(i) == dataformatting(6,isbn)) {
			cnt++;
			string value;
			cout<<cnt<<"."<<endl;
			value=bd.booksearch(dqID.at(i));
			cout << "ID:" << dqID.at(i) << endl;
			cout << "ISBN:" << value.substr(0, 6) << endl;
			cout << "书名:" << value.substr(0, 6) << endl;
			cout << "作者:" << value.substr(14, 4) << endl;
			cout << "分类:" << value.substr(18, 4) << endl;
			cout << "是否在架:" << value.substr(78, 1) << endl;
			cout << "借书时间:" << value.substr(22, 8) << endl;
			cout << "还书时间:" << value.substr(30, 8) << endl;
			cout << "借阅历史:" << value.substr(38, 40) << endl;
		}
	}
	int p;
	cout << "请输入要借阅书籍的ID（按0退出）：";
	cin >> p;
	if (p == 0)return;
	else 
	{
		borrowbook(dqID.at(p-1),bd,usd);
	}
	
}

void borrow::namesearchbook(bookdocking& bd, userstatesdocking& usd, deque<int>& dqID, deque<string>& dqNAME)
{
	string name;
	int cnt = 0;
	cout << "请输入名字：";
	cin >> name;
	for (int i = 0; i < dqID.size(); i++)
	{
		if (dqNAME.at(i) == dataformatting(8,name)) {
			cnt++;
			string value;
			cout << cnt << "." << endl;
			value = bd.booksearch(dqID.at(i));
			cout << "ID:" << dqID.at(i) << endl;
			cout << "ISBN:" << value.substr(0, 6) << endl;
			cout << "书名:" << value.substr(0, 6) << endl;
			cout << "作者:" << value.substr(14, 4) << endl;
			cout << "分类:" << value.substr(18, 4) << endl;
			cout << "是否在架:" << value.substr(78, 1) << endl;
			cout << "借书时间:" << value.substr(22, 8) << endl;
			cout << "还书时间:" << value.substr(30, 8) << endl;
			cout << "借阅历史:" << value.substr(38, 40) << endl;
		}
	}
	int p;
	cout << "请输入要借阅书籍的ID（按0退出）：";
	cin >> p;
	if (p == 0)return;
	else
	{
		borrowbook(dqID.at(p - (1)), bd, usd);
	}
}


string borrow::typedisplay(deque<string>& dqTYPE)
{
	int cnt = 0;
	deque<string> type;
	int typenum,j;
	bool flag;
	for (int i = 0; i < dqTYPE.size(); i++)
	{
		flag = false;
		j = 0; 
		typenum=type.size();
		while(j<typenum)
		{
			if (dqTYPE.at(i) == type.at(j)) {
				flag = true;
				break;
			}
			j++;
		}	
		if (!flag) {
			cnt++;
			cout << cnt << "." << dqTYPE.at(i) << endl;
			type.push_back(dqTYPE.at(i));
		}
	}

	int p;
	cout << "请输入要查看的类的编号（按0退出）：";
	cin >> p;
	if (p == 0)return "NULL";
	else
	{
		return type.at(p - 1);
	}
	
}

void borrow::nextpage()
{
}

void borrow::borrowbook(int id,bookdocking& bd,userstatesdocking& usd)
{
	

	//判断书籍是否在架
	if (bd.bookexist(id))
	{
		string value, borrowtime, returntime, onsheelf, history;
		value = bd.booksearch(id);
		//把得到的包含所有信息的字符串分发给各个字段
		borrowtime = value.substr(22, 8);
		returntime = value.substr(30, 8);
		history = value.substr(38, 40);
		onsheelf = value.substr(78, 1);

		if (onsheelf == "0") {
			system("cls");
			cout << "首页》》用户借阅系统主界面》》用户主页》》查找图书" << endl;
			cout << "书籍不在架！" << endl;
			return;
		}
		else
		{
			bool flag = true;
			if (!usd.usexist(student.getid()))
			{
				cout << "不存在记录" << endl;
				string pp;
				pp = dataformatting(120, to_string(id));
				usd.uscreate(student.getid(), pp);
			}
			else
			{
				string value = usd.ussearch(student.getid());
				value = dataformatting(120, value);

				if (value.at(114)!=' ')
				{
					system("cls");
					cout << "首页》》用户借阅系统主界面》》用户主页》》查找图书" << endl;
					cout << "已借满20本！无法借阅！" << endl;
					flag = false;
					return;
				}
				else
				{
					cout << "添加记录" << endl;
					usd.usadd(student.getid(), dataformatting(6,to_string(id)));
				}
			}
			if (flag) 
			{
				onsheelf = "0";
				onsheelf = dataformatting(1, onsheelf);
				bd.bookmodifyonsheelf(id, onsheelf);


				if (history.at(32)!=' ')
					history = dataformatting(8, to_string(student.getid()));
				else
				{
					int cnt=0;
					for (int i=0; i <= 4; i++)
					{
						if (history.at(i*(8))!=' ')cnt++;
					}
					history=history.substr(0,cnt*(8)) + dataformatting(8, to_string(student.getid()));
				}

				history = dataformatting(40, history);
				bd.bookmodifyhistory(id, history);

				time_t* timer = NULL;
				time_t timet = time(timer);
				const  time_t* timerp = &timet;
				tm* t = localtime(timerp);
				borrowtime = to_string(t->tm_year + 1900) + num2str((t->tm_mon + 1)) + num2str(t->tm_mday);
				returntime = to_string(t->tm_year + 1900) + num2str((t->tm_mon + 1) % 12 + 1) + num2str(t->tm_mday);

				dataformatting(8, borrowtime);
				dataformatting(8, returntime);
				bd.bookmodifyborrowtime(id, borrowtime);
				bd.bookmodifyreturntime(id, returntime);

				system("cls");
				cout << "首页》》用户借阅系统主界面》》用户主页》》查找图书" << endl;
				cout << "借阅成功！" << endl;
				return;
			}

		}

	}
	else { 
		system("cls");
		cout << "首页》》用户借阅系统主界面》》用户主页》》查找图书" << endl;
		cout << "书籍不存在！" << endl; 
		return;
	}
	//借阅时更改图书借阅在架、借书还书时间、借阅历史
	//修改借阅记录类

}

void borrow::clickinPanel()
{
	int id;
	cout << "输入你想查看详情的书籍ID:";
	cin >> id;
	//展示详情

}

void borrow::main1Panel(bookdocking& bd, userdocking& ud, userstatesdocking& usd, deque<int>& dqID, deque<string>& dqNAME, deque<string>& dqISBN, deque<string>& dqTYPE, bool& dqflag)
{
    int n;
	while (islogin)
	{
		n = -1;
		cout << "1.查找功能" << endl;
		cout << "2.查看个人信息" << endl;
		cout << "3.查看已借图书" << endl;
		cout << "0.登出" << endl;
		cin >> n;
		switch (n)
		{
		case 1://查找
			system("cls");
			cout << "首页》》用户借阅系统主界面》》用户主页》》查找图书" << endl;
			searchbookPanel(bd,usd,dqID,dqNAME,dqISBN,dqTYPE,dqflag); 
			break;
		case 2://个人信息
			system("cls");
			cout << "首页》》用户借阅系统主界面》》用户主页》》个人信息" << endl;
			informationPanel(ud);
			break;
		case 3://已借图书
			system("cls");
			cout << "首页》》用户借阅系统主界面》》用户主页》》已借图书" << endl;
			bookborrowedPanel(bd,usd);
			break;
		case 0://退出
			islogin = false;
			break;

		}
	}
	system("cls");
}

void borrow::initdq(deque<int>& dqID, deque<string>& dqNAME, deque<string>& dqISBN, deque<string>& dqTYPE, bookdocking& bd,bool& dqflag)
{
	if (!dqflag) {
		for (int i = 0; i < 9999; i++)
		{
			if (bd.bookexist(i))
			{
				dqID.push_back(i);
				string value = bd.booksearch(i);
				dqNAME.push_back(value.substr(6, 8));
				dqISBN.push_back(value.substr(0, 6));
				dqTYPE.push_back(value.substr(18, 4));
			}
		}
		dqflag = true;
	}

	
	
}

void borrow::returnPrevious()
{
}

void borrow::loginPanel(userdocking& ud)
{
	system("cls");
	cout << "首页》》用户借阅系统主界面》》登陆界面" << endl;
	//定义用户登陆信息的变量
	string value,name,college,major,password,email;
    int id;
	//登陆
    while (!islogin)
    {
        cout << "请输入您的ID：";
        cin >> id;
        cout << "请输入密码：";
        cin >> password;
        if (ud.userexist(id))
        {
            if (login(id, password,ud))
            {
				value = ud.usersearch(id);
				//把得到的包含所有信息的字符串分发给各个字段
				name = value.substr(0, 8);
				college = value.substr(8, 4);
				major = value.substr(12, 4);
				password = value.substr(16, 16);
				email = value.substr(32, 24);


                //给Student传入信息
				student.setid(id);
				student.setpassword(password);
				student.setname(name);
				student.setcollege(college);
				student.setmajor(major);
				student.setemail(email);
                islogin = true;
				system("cls");
				cout << "首页》》用户借阅系统主界面》》用户主页" << endl;
                cout << "登陆成功！"<<endl;
            }
			else
			{
				system("cls");
				cout << "首页》》用户借阅系统主界面》》登陆界面" << endl;
				cout << "密码输入错误！" << endl;
			}
        }
		else
		{
			system("cls");
			cout << "首页》》用户借阅系统主界面》》登陆界面" << endl;
			cout << "用户不存在！" << endl;
		}
		
    }
}

void borrow::registerPanel(userdocking& ud)
{
	system("cls");
	cout << "首页》》用户借阅系统主界面》》注册界面" << endl;
	string name, college, major, password, email;
	int id;
    //输入注册信息
	bool flag = true;
	while (flag)
	{
		cout << "请输入ID：" ;
		cin >> id;
		cout << "请输入姓名：" ;
		cin >> name;
		cout << "请输入大学：" ;
		cin >> college;
		cout << "请输入专业：" ;
		cin >> major;
		cout << "请输入密码：" ;
		cin >> password;
		cout << "请输入邮箱：" ;
		cin >> email;
		if (ud.userexist(id))
		{
			system("cls");
			cout << "首页》》用户借阅系统主界面》》注册界面" << endl;
			cout << "用户ID已存在，请重新输入！" << endl;
		}
		else
		{
			name = dataformatting(8, name);
			college = dataformatting(4, college);
			major = dataformatting(4, major);
			password = dataformatting(16, password);
			email = dataformatting(24, email);
			if (ud.useradd(id, name, college, major, password, email))
			{
				system("cls");
				cout << "首页》》用户借阅系统主界面" << endl;
				cout << "注册成功！" << endl;
				flag = false;
			}
			else
			{
				system("cls"); 
				cout << "首页》》用户借阅系统主界面》》注册界面" << endl;
				cout << "注册失败！请重新注册！" << endl;
			}
			
		}
	}

    //传给student对象  检查ID是否重复   
    //成功后传入数据库  转到上级菜单
}

int borrow::mainPanel(userdocking& ud)
{
	cout << "首页》》用户借阅系统主界面" << endl;
    int n=0;
	while (n != -1&&!islogin)//用户选择退出或者登陆成功时 跳出该界面
	{
		n = 0;
		cout << "1.login" << endl;
		cout << "2.register" << endl;
		cout << "-1.return" << endl;
		string str;
		cin >> str;
		n=atoi(str.c_str());
		switch(n)
		{
		case 1:loginPanel(ud); break;

		case 2:registerPanel(ud); break;

		case -1:returnPrevious(); break;
		default:
			system("cls");
				cout << "首页》》用户借阅系统主界面" << endl;
			cout << "无效输入！请重试！" << endl;
			break;
		}
		//system("cls");
	}
	return n;
}

void borrow::searchbookPanel(bookdocking& bd,userstatesdocking& usd, deque<int>& dqID, deque<string>& dqNAME, deque<string>& dqISBN, deque<string>& dqTYPE, bool& dqflag)
{
	int m=-1;
	book b;
	string value;
	string ttt;
	while (m!=0)
	{
		m = -1;
		cout << "1.按ID查找" << endl;
		cout << "2.按ISBN查找" << endl;
		cout << "3.按书名查找" << endl;
		cout << "4.分类查找" << endl;
		cout << "0.退出" << endl;
		cin >> m;
		switch (m)
		{
		case 1:
			system("cls");
			cout << "首页》》用户借阅系统主界面》》用户主页》》查找图书》》按ID查找" << endl;
			int n;
			cout << "输入要借书籍ID";
			cin >> n;
			if (bd.bookexist(n))
			{
				value = bd.booksearch(n);
				b.setISBN(value.substr(0, 6));
				b.setname(value.substr(6, 8));
				b.setauthor(value.substr(14, 4));
				b.settype(value.substr(18, 4));
				b.setborrowtime(value.substr(22, 8));
				b.setreturntime(value.substr(30, 8));
				b.sethistory(value.substr(38, 40));
				b.setonsheelf(value.substr(78, 1));
				b.setisovertime(value.substr(79, 1));

				cout << "ISBN:" << b.getISBN() << endl;
				cout << "书名:" << b.getname() << endl;
				cout << "作者:" << b.getauthor() << endl;
				cout << "分类:" << b.gettype() << endl;
				cout << "是否在架:" << b.getonsheelf() << endl;
				cout << "借书时间:" << b.getborrowtime() << endl;
				cout << "还书时间:" << b.getreturntime() << endl;
				cout << "借阅历史:" << b.gethistory() << endl;

				cout << "请选择借阅或退出（1/0）:";
			}
			else
			{
				cout<<"该书不存在！（按0退出）"<<endl;
			}
			int choice;
			cin >> choice;
			if(choice==1)borrowbook(n,bd,usd);
			else
			{
				system("cls");
				cout << "首页》》用户借阅系统主界面》》用户主页》》查找图书" << endl;
			}
			break;
		case 2:
			initdq(dqID,dqNAME,dqISBN,dqTYPE,bd,dqflag);
			ISBNsearchbook(bd,usd,dqID,dqISBN);
			break;
		case 3:
			initdq(dqID, dqNAME, dqISBN, dqTYPE, bd, dqflag);
			namesearchbook(bd,usd,dqID,dqNAME);
			break;
		case 4:
			initdq(dqID, dqNAME, dqISBN, dqTYPE, bd, dqflag);
			ttt=typedisplay(dqTYPE);
			if(ttt!="NULL")typeshowbook(ttt,bd,usd,dqID,dqTYPE);
			break;
		case 0:
			system("cls");
			cout << "首页》》用户借阅系统主界面》》用户主页"<< endl;
			break;
		default:
			cout << "输入错误！重新输入！" << endl;
			break;
		}
	}
}

void borrow::informationPanel(userdocking& ud)
{
	int n=-2;
	string na,co,ma,em,pa;
	while (n!=-1) {
		cout << "0.用户ID：" << student.getid() << endl;
		cout << "1.用户名字：" << student.getname() << endl;
		cout << "2.用户大学：" << student.getcollege() << endl;
		cout << "3.用户专业：" << student.getmajor() << endl;
		cout << "4.用户邮箱：" << student.getemail() << endl;
		cout << "修改信息（修改密码请输入5,-1返回上级）：";
		
		
		cin >> n;
		switch (n)
		{
		case 1:
			system("cls");
			cout << "首页》》用户借阅系统主界面》》用户主页》》个人信息" << endl;
			cout << "请输入要修改的名字:";
			cin >> na;
			na = dataformatting(8, na);
			if (ud.usermodifyname(student.getid(), na))
			{
				student.setname(na);
				system("cls");
				cout << "首页》》用户借阅系统主界面》》用户主页》》个人信息" << endl;
				cout << "修改成功"<<endl;
			}
			break;
		case 2:
			//string co;
			system("cls");
			cout << "首页》》用户借阅系统主界面》》用户主页》》个人信息" << endl;
			cout << "请输入要修改的大学:";
			cin >> co;
			co = dataformatting(4, co);
			if (ud.usermodifycollege(student.getid(), co))
			{
				student.setcollege(co);
				system("cls");
				cout << "首页》》用户借阅系统主界面》》用户主页》》个人信息" << endl;
				cout << "修改成功" << endl;
			}
			break;
		case 3:
			//string ma;
			system("cls");
			cout << "首页》》用户借阅系统主界面》》用户主页》》个人信息" << endl;
			cout << "请输入要修改的专业:";
			cin >> ma;
			ma = dataformatting(4, ma);
			if (ud.usermodifymajor(student.getid(), ma))
			{
				student.setmajor(ma);
				system("cls");
				cout << "首页》》用户借阅系统主界面》》用户主页》》个人信息" << endl;
				cout << "修改成功" << endl;
			}
			break;
		case 4:
			//string em;
			system("cls");
			cout << "首页》》用户借阅系统主界面》》用户主页》》个人信息" << endl;
			cout << "请输入要修改的邮箱:";
			cin >> em;
			em = dataformatting(24, em);
			if (ud.usermodifyemail(student.getid(), em))
			{
				student.setemail(em);
				system("cls");
				cout << "首页》》用户借阅系统主界面》》用户主页》》个人信息" << endl;
				cout << "修改成功" << endl;
			}
			break;
		case 5:
			//string pa;
			system("cls");
			cout << "首页》》用户借阅系统主界面》》用户主页》》个人信息" << endl;
			cout << "请输入要修改的密码:";
			cin >> pa;
			pa = dataformatting(16, pa);
			if (ud.usermodifypassword(student.getid(), pa))
			{
				student.setpassword(pa);
				system("cls");
				cout << "首页》》用户借阅系统主界面》》用户主页》》个人信息" << endl;
				cout << "修改成功" << endl;
			}
			break;
		case -1:
			system("cls");
			cout << "首页》》用户借阅系统主界面》》用户主页" << endl;
			break;
		}

	}


}

void borrow::bookborrowedPanel(bookdocking& bd,userstatesdocking& usd)
{
	int m;
	if (!usd.usexist(student.getid())) 
	{
		cout << "没有借书记录！" << endl;
	}
	else {
		string value, va;
		book b;
		int cnt=0;
		va = usd.ussearch(student.getid());
		va = va.substr(0, 120);
		for (int i = 0; i < 20; i++)
		{
			if (va.at(i * (6)) != ' ')cnt++;
		}
		int n;
		for (int i = 0; i < cnt; i++)
		{
			if (!(va.substr(i * 6, 6).compare("      ") == 0))
			{
				n = atoi(va.substr(i * 6, 6).c_str());

				value = bd.booksearch(n);
				b.setISBN(value.substr(0, 6));
				b.setname(value.substr(6, 8));
				b.setauthor(value.substr(14, 4));
				b.settype(value.substr(18, 4));
				b.setborrowtime(value.substr(22, 8));
				b.setreturntime(value.substr(30, 8));
				b.sethistory(value.substr(38, 40));
				b.setonsheelf(value.substr(78, 1));
				b.setisovertime(value.substr(79, 1));

				cout << "ISBN:" << b.getISBN() << endl;
				cout << "书名:" << b.getname() << endl;
				cout << "作者:" << b.getauthor() << endl;
				cout << "分类:" << b.gettype() << endl;
				cout << "是否在架:" << b.getonsheelf() << endl;
				cout << "借书时间:" << b.getborrowtime() << endl;
				cout << "还书时间:" << b.getreturntime() << endl;
				cout << "借阅历史:" << b.gethistory() << endl;
				cout << endl;
			}
		}
	}
	cout << "输入0退出：";
	cin >> m;
	if (m == 0)
	{
		system("cls");
		cout << "首页》》用户借阅系统主界面》》用户主页" << endl;
		return;
	}
}

