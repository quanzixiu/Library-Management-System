#include "bookdocking.h"
#include "supervisor.h"

//������ͼ��
//�߼��㺯�����ƣ�����ͼ�� createbook
//���õײ㺯����bookadd(string ISBN,string name,string author,string type,string id,string borrowtime,string returntime,string history, bool onsheelf,bool isovertime;)
//�ײ㺯������ֵ��bool
bool supervisor::createbook() {
	bookdocking docking;
	string ISBN;
	string name;
	string author;
	string type;
	int id;
	string borrowtime, returntime, history, onsheelf, isovertime;
	borrowtime = "00-00-00";
	returntime = "00-00-00";
	history = "history:";
	onsheelf = "1";
	isovertime = 0;

	cout << "����Ҫ���ӵ�ͼ��ID��" << endl;
	cin >> id;
	if (existbook(id)) {
		cout << "��ͼ���Ѿ����ڣ�" << endl;
		return false;
	}
	else {
		cout << "����������ͼ���ID,ISBN,name,author,type: ";
		cin >> id >> ISBN >> name >> author >> type;
		//���������Ϣת���ɹ涨�Ĵ�С 
		ISBN = dataformatting(6, ISBN);
		name = dataformatting(8, name);
		author = dataformatting(4, author);
		type = dataformatting(4, type);
		history = dataformatting(20, history);
		if (docking.bookadd(id, ISBN, name, author, type, borrowtime, returntime, history, onsheelf, isovertime))
			cout << "success" << endl;
		else
			cout << "failure" << endl;
	}
}

