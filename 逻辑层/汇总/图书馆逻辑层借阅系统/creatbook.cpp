#pragma once
#include "supervisor.h"

//������ͼ��
//�߼��㺯�����ƣ�����ͼ�� createbook
//���õײ㺯����bookadd(string ISBN,string name,string author,string type,string id,string borrowtime,string returntime,string history, bool onsheelf,bool isovertime;)
//�ײ㺯������ֵ��bool
void supervisor::createbook(bookdocking& bd) {
	string ISBN;
	string name;
	string author;
	string type;
	int id;
	string borrowtime, returntime, history, onsheelf, isovertime;
	borrowtime = "00000000";
	returntime = "00000000";
	history = "";
	onsheelf = "1";
	isovertime = "0";
	string value;
	string ID;

	cout << "����Ҫ���ӵ�ͼ��ID��" << endl;
	cin >> ID;
	while (ID.length() > 6 || atoi(ID.c_str()))//ID���ܳ��ȳ���6���߰�����ĸ���ߵ���Ϊ0
	{
		cout << "������������������:";
		cin >> ID;
	}
	id = atoi(ID.c_str());

	if (bd.bookexist(id)) {
		cout << "��ͼ���Ѿ����ڣ�" << endl;
	}
	else {
		cout << "������ͼ���ISBN: ";
		cin >> ISBN ;
		while (ISBN.length() > 6)
		{
			cout << "������������������6λ���ڵ�ISBN��";
			cin >> ISBN;
		}

		cout << "������ͼ�������: ";
		cin >>  name ;
		while (name.length() > 8)
		{
			cout << "������������������8λ���ڵ�������";
			cin >> name;
		}

		cout << "������ͼ�������: ";
		cin >>  author ;
		while (author.length() > 8)
		{
			cout << "������������������8λ���ڵ���������";
			cin >> author;
		}

		cout << "������ͼ��ķ���: ";
		cin >>  type ;
		while (type.length() > 8)
		{
			cout << "������������������8λ���ڵķ��ࣺ";
			cin >> type;
		}
		//���������Ϣת���ɹ涨�Ĵ�С 
		ISBN = dataformatting(6, ISBN);
		name = dataformatting(8, name);
		author = dataformatting(4, author);
		type = dataformatting(4, type);
		history = dataformatting(40, history);
		if (bd.bookadd(id, ISBN, name, author, type, borrowtime, returntime, history, onsheelf, isovertime))
		{
			cout << "��ӳɹ���" << endl;
			//չʾͼ����Ϣ
			value = bd.booksearch(id);
			//�ѵõ��İ���������Ϣ���ַ����ַ��������ֶ�
			ISBN = value.substr(0, 6);
			name = value.substr(6, 8);
			author = value.substr(14, 4);
			type = value.substr(18, 4);
			borrowtime = value.substr(22, 8);
			returntime = value.substr(30, 8);
			history = value.substr(38, 40);
			onsheelf = value.substr(78, 1);
			isovertime = value.substr(79, 1);
			cout << "ID: " << id << " ISBN: " << ISBN << " ����: " << name << " ����: " << author << " ����: " << type << endl;
			cout << "����ʱ��: " << borrowtime << endl;
			cout << "Ӧ��ʱ��: " << returntime << endl;
			cout << "������ʷ: " << history << endl;
			cout << "�Ƿ��ڼ�: " << onsheelf << endl;
			cout <<"�Ƿ���: " << isovertime << endl;
		}
			
		else
			cout << "���ʧ�ܣ�" << endl;
	}
}

