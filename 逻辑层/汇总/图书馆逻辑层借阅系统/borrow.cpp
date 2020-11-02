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
	//�����û���½��Ϣ�ı���
	string value, name, college, major, email;
	//��½
	while (!islogin)
	{
		if (ud.userexist(id))
		{
			if (login(id, password, ud))
			{
				value = ud.usersearch(id);
				//�ѵõ��İ���������Ϣ���ַ����ַ��������ֶ�
				name = value.substr(0, 8);
				college = value.substr(8, 4);
				major = value.substr(12, 4);
				password = value.substr(16, 16);
				email = value.substr(32, 24);


				//��Student������Ϣ
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
	//�ж��鼮�Ƿ��ڼ�
	if (bd.bookexist(id))
	{
		string value, borrowtime, returntime, onsheelf, history;
		value = bd.booksearch(id);
		//�ѵõ��İ���������Ϣ���ַ����ַ��������ֶ�
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
	//����ʱ����ͼ������ڼܡ����黹��ʱ�䡢������ʷ
	//�޸Ľ��ļ�¼��
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
	//�ѵõ��İ���������Ϣ���ַ����ַ��������ֶ�
	name = value.substr(0, 8);
	college = value.substr(8, 4);
	major = value.substr(12, 4);
	password = value.substr(16, 16);
	email = value.substr(32, 24);

	//��Student������Ϣ
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
			cout << "����:" << value.substr(0, 6) << endl;
			cout << "����:" << value.substr(14, 4) << endl;
			cout << "����:" << value.substr(18, 4) << endl;
			cout << "�Ƿ��ڼ�:" << value.substr(78, 1) << endl;
			cout << "����ʱ��:" << value.substr(22, 8) << endl;
			cout << "����ʱ��:" << value.substr(30, 8) << endl;
			cout << "������ʷ:" << value.substr(38, 40) << endl;
		}
	}
	int p;
	cout << "������Ҫ�����鼮��ID����0�˳�����";
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
	cout << "������ISBN��";
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
			cout << "����:" << value.substr(0, 6) << endl;
			cout << "����:" << value.substr(14, 4) << endl;
			cout << "����:" << value.substr(18, 4) << endl;
			cout << "�Ƿ��ڼ�:" << value.substr(78, 1) << endl;
			cout << "����ʱ��:" << value.substr(22, 8) << endl;
			cout << "����ʱ��:" << value.substr(30, 8) << endl;
			cout << "������ʷ:" << value.substr(38, 40) << endl;
		}
	}
	int p;
	cout << "������Ҫ�����鼮��ID����0�˳�����";
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
	cout << "���������֣�";
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
			cout << "����:" << value.substr(0, 6) << endl;
			cout << "����:" << value.substr(14, 4) << endl;
			cout << "����:" << value.substr(18, 4) << endl;
			cout << "�Ƿ��ڼ�:" << value.substr(78, 1) << endl;
			cout << "����ʱ��:" << value.substr(22, 8) << endl;
			cout << "����ʱ��:" << value.substr(30, 8) << endl;
			cout << "������ʷ:" << value.substr(38, 40) << endl;
		}
	}
	int p;
	cout << "������Ҫ�����鼮��ID����0�˳�����";
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
	cout << "������Ҫ�鿴����ı�ţ���0�˳�����";
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
	

	//�ж��鼮�Ƿ��ڼ�
	if (bd.bookexist(id))
	{
		string value, borrowtime, returntime, onsheelf, history;
		value = bd.booksearch(id);
		//�ѵõ��İ���������Ϣ���ַ����ַ��������ֶ�
		borrowtime = value.substr(22, 8);
		returntime = value.substr(30, 8);
		history = value.substr(38, 40);
		onsheelf = value.substr(78, 1);

		if (onsheelf == "0") {
			system("cls");
			cout << "��ҳ�����û�����ϵͳ�����桷���û���ҳ��������ͼ��" << endl;
			cout << "�鼮���ڼܣ�" << endl;
			return;
		}
		else
		{
			bool flag = true;
			if (!usd.usexist(student.getid()))
			{
				cout << "�����ڼ�¼" << endl;
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
					cout << "��ҳ�����û�����ϵͳ�����桷���û���ҳ��������ͼ��" << endl;
					cout << "�ѽ���20�����޷����ģ�" << endl;
					flag = false;
					return;
				}
				else
				{
					cout << "��Ӽ�¼" << endl;
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
				cout << "��ҳ�����û�����ϵͳ�����桷���û���ҳ��������ͼ��" << endl;
				cout << "���ĳɹ���" << endl;
				return;
			}

		}

	}
	else { 
		system("cls");
		cout << "��ҳ�����û�����ϵͳ�����桷���û���ҳ��������ͼ��" << endl;
		cout << "�鼮�����ڣ�" << endl; 
		return;
	}
	//����ʱ����ͼ������ڼܡ����黹��ʱ�䡢������ʷ
	//�޸Ľ��ļ�¼��

}

void borrow::clickinPanel()
{
	int id;
	cout << "��������鿴������鼮ID:";
	cin >> id;
	//չʾ����

}

void borrow::main1Panel(bookdocking& bd, userdocking& ud, userstatesdocking& usd, deque<int>& dqID, deque<string>& dqNAME, deque<string>& dqISBN, deque<string>& dqTYPE, bool& dqflag)
{
    int n;
	while (islogin)
	{
		n = -1;
		cout << "1.���ҹ���" << endl;
		cout << "2.�鿴������Ϣ" << endl;
		cout << "3.�鿴�ѽ�ͼ��" << endl;
		cout << "0.�ǳ�" << endl;
		cin >> n;
		switch (n)
		{
		case 1://����
			system("cls");
			cout << "��ҳ�����û�����ϵͳ�����桷���û���ҳ��������ͼ��" << endl;
			searchbookPanel(bd,usd,dqID,dqNAME,dqISBN,dqTYPE,dqflag); 
			break;
		case 2://������Ϣ
			system("cls");
			cout << "��ҳ�����û�����ϵͳ�����桷���û���ҳ����������Ϣ" << endl;
			informationPanel(ud);
			break;
		case 3://�ѽ�ͼ��
			system("cls");
			cout << "��ҳ�����û�����ϵͳ�����桷���û���ҳ�����ѽ�ͼ��" << endl;
			bookborrowedPanel(bd,usd);
			break;
		case 0://�˳�
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
	cout << "��ҳ�����û�����ϵͳ�����桷����½����" << endl;
	//�����û���½��Ϣ�ı���
	string value,name,college,major,password,email;
    int id;
	//��½
    while (!islogin)
    {
        cout << "����������ID��";
        cin >> id;
        cout << "���������룺";
        cin >> password;
        if (ud.userexist(id))
        {
            if (login(id, password,ud))
            {
				value = ud.usersearch(id);
				//�ѵõ��İ���������Ϣ���ַ����ַ��������ֶ�
				name = value.substr(0, 8);
				college = value.substr(8, 4);
				major = value.substr(12, 4);
				password = value.substr(16, 16);
				email = value.substr(32, 24);


                //��Student������Ϣ
				student.setid(id);
				student.setpassword(password);
				student.setname(name);
				student.setcollege(college);
				student.setmajor(major);
				student.setemail(email);
                islogin = true;
				system("cls");
				cout << "��ҳ�����û�����ϵͳ�����桷���û���ҳ" << endl;
                cout << "��½�ɹ���"<<endl;
            }
			else
			{
				system("cls");
				cout << "��ҳ�����û�����ϵͳ�����桷����½����" << endl;
				cout << "�����������" << endl;
			}
        }
		else
		{
			system("cls");
			cout << "��ҳ�����û�����ϵͳ�����桷����½����" << endl;
			cout << "�û������ڣ�" << endl;
		}
		
    }
}

void borrow::registerPanel(userdocking& ud)
{
	system("cls");
	cout << "��ҳ�����û�����ϵͳ�����桷��ע�����" << endl;
	string name, college, major, password, email;
	int id;
    //����ע����Ϣ
	bool flag = true;
	while (flag)
	{
		cout << "������ID��" ;
		cin >> id;
		cout << "������������" ;
		cin >> name;
		cout << "�������ѧ��" ;
		cin >> college;
		cout << "������רҵ��" ;
		cin >> major;
		cout << "���������룺" ;
		cin >> password;
		cout << "���������䣺" ;
		cin >> email;
		if (ud.userexist(id))
		{
			system("cls");
			cout << "��ҳ�����û�����ϵͳ�����桷��ע�����" << endl;
			cout << "�û�ID�Ѵ��ڣ����������룡" << endl;
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
				cout << "��ҳ�����û�����ϵͳ������" << endl;
				cout << "ע��ɹ���" << endl;
				flag = false;
			}
			else
			{
				system("cls"); 
				cout << "��ҳ�����û�����ϵͳ�����桷��ע�����" << endl;
				cout << "ע��ʧ�ܣ�������ע�ᣡ" << endl;
			}
			
		}
	}

    //����student����  ���ID�Ƿ��ظ�   
    //�ɹ��������ݿ�  ת���ϼ��˵�
}

int borrow::mainPanel(userdocking& ud)
{
	cout << "��ҳ�����û�����ϵͳ������" << endl;
    int n=0;
	while (n != -1&&!islogin)//�û�ѡ���˳����ߵ�½�ɹ�ʱ �����ý���
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
				cout << "��ҳ�����û�����ϵͳ������" << endl;
			cout << "��Ч���룡�����ԣ�" << endl;
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
		cout << "1.��ID����" << endl;
		cout << "2.��ISBN����" << endl;
		cout << "3.����������" << endl;
		cout << "4.�������" << endl;
		cout << "0.�˳�" << endl;
		cin >> m;
		switch (m)
		{
		case 1:
			system("cls");
			cout << "��ҳ�����û�����ϵͳ�����桷���û���ҳ��������ͼ�顷����ID����" << endl;
			int n;
			cout << "����Ҫ���鼮ID";
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
				cout << "����:" << b.getname() << endl;
				cout << "����:" << b.getauthor() << endl;
				cout << "����:" << b.gettype() << endl;
				cout << "�Ƿ��ڼ�:" << b.getonsheelf() << endl;
				cout << "����ʱ��:" << b.getborrowtime() << endl;
				cout << "����ʱ��:" << b.getreturntime() << endl;
				cout << "������ʷ:" << b.gethistory() << endl;

				cout << "��ѡ����Ļ��˳���1/0��:";
			}
			else
			{
				cout<<"���鲻���ڣ�����0�˳���"<<endl;
			}
			int choice;
			cin >> choice;
			if(choice==1)borrowbook(n,bd,usd);
			else
			{
				system("cls");
				cout << "��ҳ�����û�����ϵͳ�����桷���û���ҳ��������ͼ��" << endl;
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
			cout << "��ҳ�����û�����ϵͳ�����桷���û���ҳ"<< endl;
			break;
		default:
			cout << "��������������룡" << endl;
			break;
		}
	}
}

void borrow::informationPanel(userdocking& ud)
{
	int n=-2;
	string na,co,ma,em,pa;
	while (n!=-1) {
		cout << "0.�û�ID��" << student.getid() << endl;
		cout << "1.�û����֣�" << student.getname() << endl;
		cout << "2.�û���ѧ��" << student.getcollege() << endl;
		cout << "3.�û�רҵ��" << student.getmajor() << endl;
		cout << "4.�û����䣺" << student.getemail() << endl;
		cout << "�޸���Ϣ���޸�����������5,-1�����ϼ�����";
		
		
		cin >> n;
		switch (n)
		{
		case 1:
			system("cls");
			cout << "��ҳ�����û�����ϵͳ�����桷���û���ҳ����������Ϣ" << endl;
			cout << "������Ҫ�޸ĵ�����:";
			cin >> na;
			na = dataformatting(8, na);
			if (ud.usermodifyname(student.getid(), na))
			{
				student.setname(na);
				system("cls");
				cout << "��ҳ�����û�����ϵͳ�����桷���û���ҳ����������Ϣ" << endl;
				cout << "�޸ĳɹ�"<<endl;
			}
			break;
		case 2:
			//string co;
			system("cls");
			cout << "��ҳ�����û�����ϵͳ�����桷���û���ҳ����������Ϣ" << endl;
			cout << "������Ҫ�޸ĵĴ�ѧ:";
			cin >> co;
			co = dataformatting(4, co);
			if (ud.usermodifycollege(student.getid(), co))
			{
				student.setcollege(co);
				system("cls");
				cout << "��ҳ�����û�����ϵͳ�����桷���û���ҳ����������Ϣ" << endl;
				cout << "�޸ĳɹ�" << endl;
			}
			break;
		case 3:
			//string ma;
			system("cls");
			cout << "��ҳ�����û�����ϵͳ�����桷���û���ҳ����������Ϣ" << endl;
			cout << "������Ҫ�޸ĵ�רҵ:";
			cin >> ma;
			ma = dataformatting(4, ma);
			if (ud.usermodifymajor(student.getid(), ma))
			{
				student.setmajor(ma);
				system("cls");
				cout << "��ҳ�����û�����ϵͳ�����桷���û���ҳ����������Ϣ" << endl;
				cout << "�޸ĳɹ�" << endl;
			}
			break;
		case 4:
			//string em;
			system("cls");
			cout << "��ҳ�����û�����ϵͳ�����桷���û���ҳ����������Ϣ" << endl;
			cout << "������Ҫ�޸ĵ�����:";
			cin >> em;
			em = dataformatting(24, em);
			if (ud.usermodifyemail(student.getid(), em))
			{
				student.setemail(em);
				system("cls");
				cout << "��ҳ�����û�����ϵͳ�����桷���û���ҳ����������Ϣ" << endl;
				cout << "�޸ĳɹ�" << endl;
			}
			break;
		case 5:
			//string pa;
			system("cls");
			cout << "��ҳ�����û�����ϵͳ�����桷���û���ҳ����������Ϣ" << endl;
			cout << "������Ҫ�޸ĵ�����:";
			cin >> pa;
			pa = dataformatting(16, pa);
			if (ud.usermodifypassword(student.getid(), pa))
			{
				student.setpassword(pa);
				system("cls");
				cout << "��ҳ�����û�����ϵͳ�����桷���û���ҳ����������Ϣ" << endl;
				cout << "�޸ĳɹ�" << endl;
			}
			break;
		case -1:
			system("cls");
			cout << "��ҳ�����û�����ϵͳ�����桷���û���ҳ" << endl;
			break;
		}

	}


}

void borrow::bookborrowedPanel(bookdocking& bd,userstatesdocking& usd)
{
	int m;
	if (!usd.usexist(student.getid())) 
	{
		cout << "û�н����¼��" << endl;
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
				cout << "����:" << b.getname() << endl;
				cout << "����:" << b.getauthor() << endl;
				cout << "����:" << b.gettype() << endl;
				cout << "�Ƿ��ڼ�:" << b.getonsheelf() << endl;
				cout << "����ʱ��:" << b.getborrowtime() << endl;
				cout << "����ʱ��:" << b.getreturntime() << endl;
				cout << "������ʷ:" << b.gethistory() << endl;
				cout << endl;
			}
		}
	}
	cout << "����0�˳���";
	cin >> m;
	if (m == 0)
	{
		system("cls");
		cout << "��ҳ�����û�����ϵͳ�����桷���û���ҳ" << endl;
		return;
	}
}

