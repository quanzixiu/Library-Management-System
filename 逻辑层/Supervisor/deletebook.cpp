#include"../BookDocking/BookDocking/bookdocking.h"
#include "supervisor.h"

//ɾ��ͼ��
//�߼��㺯�����ƣ�ɾ��ͼ�� deletebook()
//���õײ㺯����bookdelete(string id)
//�ײ㺯������ֵ��bool
void supervisor::deletebook() {
	bookdocking docking;
	string value;
	int id;
	cout << "�������ɾ��ͼ���ID��";
	cin >> id;
	value = docking.booksearch(id);
	if (!docking.bookexist(id)) cout << "��ͼ�鲻���ڣ�" << endl;
	else {
		if (value.substr(58, 1) == "1")//�����ͼ���ڼ�
		{
			if (docking.bookdelete(id))
				cout << "ɾ���ɹ���" << endl;
			else
				cout << "ɾ��ʧ�ܣ�" << endl;
		}
		else cout << "��ͼ����δ�黹���޷�ɾ����";
	}
}