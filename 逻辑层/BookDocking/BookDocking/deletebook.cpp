#include "bookdocking.h"
#include "supervisor.h"

//ɾ��ͼ��
//�߼��㺯�����ƣ�ɾ��ͼ�� deletebook()
//���õײ㺯����bookdelete(string id)
//�ײ㺯������ֵ��bool
bool supervisor::deletebook() {
	supervisor admin;
	bookdocking docking;
	string value;
	int id;
	cout << "�������ɾ��ͼ���ID��";
	cin >> id;
	value = docking.booksearch(id);
	if (!admin.existbook(id)) cout << "��ͼ�鲻���ڣ�" << endl;
	else {
		if (value.substr(58, 1) == "1")
		{
			if (docking.bookdelete(id))
				cout << "success" << endl;
			else
				cout << "failure" << endl;
		}
		else cout << "��ͼ����δ�黹���޷�ɾ����";
	}
}