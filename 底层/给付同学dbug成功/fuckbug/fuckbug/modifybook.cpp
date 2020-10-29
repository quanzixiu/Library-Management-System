#include "bookdocking.h"
#include "supervisor.h"
#include<string>

//�޸�ͼ����Ϣ
//�߼��㺯�����ƣ��޸�ͼ�� modifybook()
//���õײ㺯����bookmodify(string id)
//�ײ㺯������ֵ��bool

void supervisor::modifybook() {
	bookdocking docking;
	string ISBN;
	string name;
	string author;
	string type;
	string borrowtime, returntime, history, onsheelf, isovertime;
	borrowtime= "00-00-00";
	returntime = "00-00-00";
	history = "history:";
	onsheelf = "1";
	isovertime = "0";
	int op1;
	int id;
	string value;
	cout << "��������޸�ͼ���ID��";
	cin >> id;
	const int id1 = id;
	if (!docking.bookexist(id)) cout << "��ͼ�鲻���ڣ�" << endl;
	else {
		//չʾͼ����Ϣ
		value = docking.booksearch(id);
		//�ѵõ��İ���������Ϣ���ַ����ַ��������ֶ�
		ISBN = value.substr(0, 6);
		name = value.substr(6, 8);
		author = value.substr(14, 4);
		type = value.substr(18, 4);
		borrowtime = value.substr(22, 8);
		returntime = value.substr(30, 8);
		history = value.substr(38, 20);
		onsheelf = value.substr(58, 1);
		isovertime = value.substr(59, 1);
		cout << "id: " << id << " ISBN: " << ISBN << " name: " << name << " author: " << author << " type: " << type << endl;
		cout << "borrowtime: " << borrowtime << endl;
		cout << "returntime: " << returntime << endl;
		cout << "histroy: " << endl << history << endl;
		cout << "onsheelf: " << onsheelf << " isovertime: " << isovertime << endl;
		//����޸�ѡ��
		while (true)
		{
			cout << "1.ISBN" << endl;
			cout << "2.name" << endl;
			cout << "3.author" << endl;
			cout << "4.borrowtime" << endl;
			cout << "5.returntime" << endl;
			cout << "6.history" << endl;
			cout << "7.onsheelf" << endl;
			cout << "8.isovertime" << endl;
			cout << "0.quit" << endl;
			cout << "Please input a number:";
			cin >> op1;
			if (op1 == 0)
				break;
			switch (op1)
			{
			case 1:
				cout << "Please input ISBN:";
				cin >> ISBN;
				ISBN = dataformatting(6, ISBN);
				if (docking.bookmodifyISBN(id1, ISBN))
				{
					cout << "success" << endl;
					//չʾͼ����Ϣ
					value = docking.booksearch(id1);
					//�ѵõ��İ���������Ϣ���ַ����ַ��������ֶ�
					ISBN = value.substr(0, 6);
					name = value.substr(6, 8);
					author = value.substr(14, 4);
					type = value.substr(18, 4);
					borrowtime = value.substr(22, 8);
					returntime = value.substr(30, 8);
					history = value.substr(38, 20);
					onsheelf = value.substr(58, 1);
					isovertime = value.substr(59, 1);
					cout << "id: " << id1 << " ISBN: " << ISBN << " name: " << name << " author: " << author << " type: " << type << endl;
					cout << "borrowtime: " << borrowtime << endl;
					cout << "returntime: " << returntime << endl;
					cout << "histroy: " << endl << history << endl;
					cout << "onsheelf: " << onsheelf << " isovertime: " << isovertime << endl;
				}
				else
					cout << "failure" << endl;
				break;
			case 2:
				cout << "Please input name:";
				cin >> name;
				name = dataformatting(8, name);
				if (docking.bookmodifyname(id1, name))
				{
					cout << "success" << endl;
					//չʾͼ����Ϣ
					value = docking.booksearch(id1);
					//�ѵõ��İ���������Ϣ���ַ����ַ��������ֶ�
					ISBN = value.substr(0, 6);
					name = value.substr(6, 8);
					author = value.substr(14, 4);
					type = value.substr(18, 4);
					borrowtime = value.substr(22, 8);
					returntime = value.substr(30, 8);
					history = value.substr(38, 20);
					onsheelf = value.substr(58, 1);
					isovertime = value.substr(59, 1);
					cout << "id: " << id1 << " ISBN: " << ISBN << " name: " << name << " author: " << author << " type: " << type << endl;
					cout << "borrowtime: " << borrowtime << endl;
					cout << "returntime: " << returntime << endl;
					cout << "histroy: " << endl << history << endl;
					cout << "onsheelf: " << onsheelf << " isovertime: " << isovertime << endl;
				}
				else
					cout << "failure" << endl;
				break;
			case 3:
				cout << "Please input author:";
				cin >> author;
				author = dataformatting(4, author);
				if (docking.bookmodifyauthor(id1, author))
				{
					cout << "success" << endl;
					//չʾͼ����Ϣ
					value = docking.booksearch(id1);
					//�ѵõ��İ���������Ϣ���ַ����ַ��������ֶ�
					ISBN = value.substr(0, 6);
					name = value.substr(6, 8);
					author = value.substr(14, 4);
					type = value.substr(18, 4);
					borrowtime = value.substr(22, 8);
					returntime = value.substr(30, 8);
					history = value.substr(38, 20);
					onsheelf = value.substr(58, 1);
					isovertime = value.substr(59, 1);
					cout << "id: " << id1 << " ISBN: " << ISBN << " name: " << name << " author: " << author << " type: " << type << endl;
					cout << "borrowtime: " << borrowtime << endl;
					cout << "returntime: " << returntime << endl;
					cout << "histroy: " << endl << history << endl;
					cout << "onsheelf: " << onsheelf << " isovertime: " << isovertime << endl;
				}
				else
					cout << "failure" << endl;
				break;
			case 4:
				cout << "Please input type:";
				cin >> type;
				type = dataformatting(4, type);
				if (docking.bookmodifytype(id1, type))
				{
					cout << "success" << endl;
					//չʾͼ����Ϣ
					value = docking.booksearch(id1);
					//�ѵõ��İ���������Ϣ���ַ����ַ��������ֶ�
					ISBN = value.substr(0, 6);
					name = value.substr(6, 8);
					author = value.substr(14, 4);
					type = value.substr(18, 4);
					borrowtime = value.substr(22, 8);
					returntime = value.substr(30, 8);
					history = value.substr(38, 20);
					onsheelf = value.substr(58, 1);
					isovertime = value.substr(59, 1);
					cout << "id: " << id1 << " ISBN: " << ISBN << " name: " << name << " author: " << author << " type: " << type << endl;
					cout << "borrowtime: " << borrowtime << endl;
					cout << "returntime: " << returntime << endl;
					cout << "histroy: " << endl << history << endl;
					cout << "onsheelf: " << onsheelf << " isovertime: " << isovertime << endl;
				}
				else
					cout << "failure" << endl;
				break;
			case 5:
				cout << "Please input borrowtime:";
				cin >> borrowtime;
				borrowtime = dataformatting(8, borrowtime);
				if (docking.bookmodifyborrowtime(id1, borrowtime))
				{
					cout << "success" << endl;
					//չʾͼ����Ϣ
					value = docking.booksearch(id1);
					//�ѵõ��İ���������Ϣ���ַ����ַ��������ֶ�
					ISBN = value.substr(0, 6);
					name = value.substr(6, 8);
					author = value.substr(14, 4);
					type = value.substr(18, 4);
					borrowtime = value.substr(22, 8);
					returntime = value.substr(30, 8);
					history = value.substr(38, 20);
					onsheelf = value.substr(58, 1);
					isovertime = value.substr(59, 1);
					cout << "id: " << id1 << " ISBN: " << ISBN << " name: " << name << " author: " << author << " type: " << type << endl;
					cout << "borrowtime: " << borrowtime << endl;
					cout << "returntime: " << returntime << endl;
					cout << "histroy: " << endl << history << endl;
					cout << "onsheelf: " << onsheelf << " isovertime: " << isovertime << endl;
				}
				else
					cout << "failure" << endl;
				break;
			case 6:
				cout << "Please input returntime:";
				cin >> returntime;
				returntime = dataformatting(8, returntime);
				if (docking.bookmodifyreturntime(id1, returntime))
				{
					cout << "success" << endl;
					//չʾͼ����Ϣ
					value = docking.booksearch(id1);
					//�ѵõ��İ���������Ϣ���ַ����ַ��������ֶ�
					ISBN = value.substr(0, 6);
					name = value.substr(6, 8);
					author = value.substr(14, 4);
					type = value.substr(18, 4);
					borrowtime = value.substr(22, 8);
					returntime = value.substr(30, 8);
					history = value.substr(38, 20);
					onsheelf = value.substr(58, 1);
					isovertime = value.substr(59, 1);
					cout << "id: " << id1 << " ISBN: " << ISBN << " name: " << name << " author: " << author << " type: " << type << endl;
					cout << "borrowtime: " << borrowtime << endl;
					cout << "returntime: " << returntime << endl;
					cout << "histroy: " << endl << history << endl;
					cout << "onsheelf: " << onsheelf << " isovertime: " << isovertime << endl;
				}
				else
					cout << "failure" << endl;
				break;
			case 7:
				cout << "Please input onsheelf:";
				cin >> onsheelf;
				onsheelf = dataformatting(1, onsheelf);
				if (docking.bookmodifyonsheelf(id1, onsheelf))
				{
					cout << "success" << endl;
					//չʾͼ����Ϣ
					value = docking.booksearch(id1);
					//�ѵõ��İ���������Ϣ���ַ����ַ��������ֶ�
					ISBN = value.substr(0, 6);
					name = value.substr(6, 8);
					author = value.substr(14, 4);
					type = value.substr(18, 4);
					borrowtime = value.substr(22, 8);
					returntime = value.substr(30, 8);
					history = value.substr(38, 20);
					onsheelf = value.substr(58, 1);
					isovertime = value.substr(59, 1);
					cout << "id: " << id1 << " ISBN: " << ISBN << " name: " << name << " author: " << author << " type: " << type << endl;
					cout << "borrowtime: " << borrowtime << endl;
					cout << "returntime: " << returntime << endl;
					cout << "histroy: " << endl << history << endl;
					cout << "onsheelf: " << onsheelf << " isovertime: " << isovertime << endl;
				}
				else
					cout << "failure" << endl;
				break;
			case 8:
				cout << "Please input isovertime:";
				cin >> isovertime;
				isovertime = dataformatting(1, isovertime);
				if (docking.bookmodifyisovertime(id1, isovertime))
				{
					cout << "success" << endl;
					//չʾͼ����Ϣ
					value = docking.booksearch(id1);
					//�ѵõ��İ���������Ϣ���ַ����ַ��������ֶ�
					ISBN = value.substr(0, 6);
					name = value.substr(6, 8);
					author = value.substr(14, 4);
					type = value.substr(18, 4);
					borrowtime = value.substr(22, 8);
					returntime = value.substr(30, 8);
					history = value.substr(38, 20);
					onsheelf = value.substr(58, 1);
					isovertime = value.substr(59, 1);
					cout << "id: " << id1 << " ISBN: " << ISBN << " name: " << name << " author: " << author << " type: " << type << endl;
					cout << "borrowtime: " << borrowtime << endl;
					cout << "returntime: " << returntime << endl;
					cout << "histroy: " << endl << history << endl;
					cout << "onsheelf: " << onsheelf << " isovertime: " << isovertime << endl;
				}
				else
					cout << "�޸�ʧ�ܣ�" << endl;
				break;
			default:
				cout << "�Ƿ������룡" << endl;
				break;
			}
		}
	}
}