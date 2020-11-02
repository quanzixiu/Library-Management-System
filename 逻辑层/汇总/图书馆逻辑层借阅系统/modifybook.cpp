#pragma once
#include "supervisor.h"
#include<string>

//�޸�ͼ����Ϣ
//�߼��㺯�����ƣ��޸�ͼ�� modifybook()
//���õײ㺯����bookmodify(string id)
//�ײ㺯������ֵ��bool

void supervisor::modifybook(bookdocking& bd) {
	string ISBN;
	string name;
	string author;
	string type;
	string borrowtime, returntime, history, onsheelf, isovertime;
	borrowtime= "00-00-00";
	returntime = "00-00-00";
	history = "";
	onsheelf = "1";
	isovertime = "0";
	string op1;
	int id;
	string value;
	string ID;
	cout << "��������޸�ͼ���ID��";
	cin >> ID;
	while (ID.length() > 6 || atoi(ID.c_str()))//ID���ܳ��ȳ���6���߰�����ĸ���ߵ���Ϊ0
	{
		cout << "������������������:";
		cin >> ID;
	}
	id = atoi(ID.c_str());
	if (!bd.bookexist(id)) cout << "��ͼ�鲻���ڣ�" << endl;
	else {
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
		cout << "�Ƿ���: " << isovertime << endl;
		//����޸�ѡ��
		while (true)
		{
			cout << "1.ISBN" << endl;
			cout << "2.����" << endl;
			cout << "3.����" << endl;
			cout << "4.����" << endl;
			cout << "5.����ʱ��" << endl;
			cout << "6.Ӧ��ʱ��" << endl;
			cout << "7.�ڼ�״̬" << endl;
			cout << "8.�Ƿ���" << endl;
			cout << "0.�˳�" << endl;
			cout << "���������ѡ��:";
			cin >> op1;
			if (op1 == "0")
				break;
			else if (op1 == "1") 
			{
				cout << "������ͼ���ISBN: ";
				cin >> ISBN;
				while (ISBN.length() > 6)
				{
					cout << "������������������6λ���ڵ�ISBN��";
					cin >> ISBN;
				}
				ISBN = dataformatting(6, ISBN);
				if (bd.bookmodifyISBN(id, ISBN))
				{
					cout << "�޸ĳɹ���" << endl;
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
					cout << "�Ƿ���: " << isovertime << endl;
				}
				else
					cout << "�޸�ʧ�ܣ�" << endl;
			}
			else if (op1 == "2")
			{
				cout << "������ͼ�������: ";
				cin >> name;
				while (name.length() > 8)
				{
					cout << "������������������8λ���ڵ�������";
					cin >> name;
				}
				name = dataformatting(8, name);
				if (bd.bookmodifyname(id, name))
				{
					cout << "�޸ĳɹ���" << endl;
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
					cout << "ID:" << id << " ISBN: " << ISBN << " ����: " << name << " ����: " << author << " ����: " << type << endl;
					cout << "����ʱ��: " << borrowtime << endl;
					cout << "Ӧ��ʱ��: " << returntime << endl;
					cout << "������ʷ: " << history << endl;
					cout << "�Ƿ��ڼ�: " << onsheelf << endl;
					cout << "�Ƿ���: " << isovertime << endl;
				}
				else
					cout << "�޸�ʧ�ܣ�" << endl;
			}
			else if (op1 == "3")
			{
				cout << "������ͼ�������: ";
				cin >> author;
				while (author.length() > 4)
				{
					cout << "������������������4λ���ڵ���������";
					cin >> author;
				}
				author = dataformatting(4, author);
				if (bd.bookmodifyauthor(id, author))
				{
					cout << "�޸ĳɹ���" << endl;
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
					cout << "�Ƿ���: " << isovertime << endl;
				}
				else
					cout << "�޸�ʧ�ܣ�" << endl;
			}
			else if (op1 == "4")
			{
				cout << "������ͼ��ķ���: ";
				cin >> type;
				while (type.length() > 4)
				{
					cout << "������������������4λ���ڵķ�������";
					cin >> type;
				}
				type = dataformatting(4, type);
				if (bd.bookmodifytype(id, type))
				{
					cout << "�޸ĳɹ���" << endl;
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
					cout << "�Ƿ���: " << isovertime << endl;
				}
				else
					cout << "�޸�ʧ�ܣ�" << endl;
			}
			else if (op1 == "5")
			{
				cout << "���������ʱ��:";
				cin >> borrowtime;
				while (borrowtime.length() > 8)
				{
					cout << "������������������8λ���ڵĽ���ʱ�䣺";
					cin >> borrowtime;
				}
				borrowtime = dataformatting(8, borrowtime);
				if (bd.bookmodifyborrowtime(id, borrowtime))
				{
					cout << "�޸ĳɹ���" << endl;
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
					cout << "�Ƿ���: " << isovertime << endl;
				}
				else
					cout << "�޸�ʧ�ܣ�" << endl;
			}
			else if (op1 == "6")
			{
				cout << "������Ӧ��ʱ��:";
				cin >> returntime;
				while (returntime.length() > 8)
				{
					cout << "������������������8λ���ڵ�Ӧ��ʱ�䣺";
					cin >> returntime;
				}
				returntime = dataformatting(8, returntime);
				if (bd.bookmodifyreturntime(id, returntime))
				{
					cout << "�޸ĳɹ���" << endl;
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
					cout << "�Ƿ���: " << isovertime << endl;
				}
				else
					cout << "�޸�ʧ�ܣ�" << endl;
			}
			else if (op1 == "7")
			{
				cout << "�������Ƿ��ڼ�:";
				cin >> onsheelf;
				while (onsheelf.length() > 1)
				{
					cout << "������������������1��0��";
					cin >> onsheelf;
				}
				//onsheelf = dataformatting(1, onsheelf);
				if (bd.bookmodifyonsheelf(id, onsheelf))
				{
					cout << "�޸ĳɹ���" << endl;
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
					cout << "�Ƿ���: " << isovertime << endl;
				}
				else
					cout << "�޸�ʧ�ܣ�" << endl;
			}
			else if (op1 == "8")
			{
				cout << "�������Ƿ���:";
				cin >> isovertime;
				while (isovertime.length() > 1)
				{
					cout << "������������������1��0��";
					cin >> isovertime;
				}
				isovertime = dataformatting(1, isovertime);
				if (bd.bookmodifyisovertime(id, isovertime))
				{
					cout << "�޸ĳɹ���" << endl;
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
					cout << "�Ƿ���: " << isovertime << endl;
				}
				else
					cout << "�޸�ʧ�ܣ�" << endl;
			}
			else
				cout << "�Ƿ������룡" << endl;
	
		}
	}
}