#pragma once
#include "supervisor.h"

//ɾ��ͼ��
//�߼��㺯�����ƣ�ɾ��ͼ�� deletebook()
//���õײ㺯����bookdelete(string id)
//�ײ㺯������ֵ��bool
void supervisor::deletebook(bookdocking& bd) {
	string value;
	int id;
	cout << "�������ɾ��ͼ���ID��";
	cin >> id;
	if (!bd.bookexist(id)) cout << "��ͼ�鲻���ڣ�" << endl;	
	else {
		value = bd.booksearch(id);
		if (value.substr(78, 1) == "1")//�����ͼ���ڼ�
		{
			if (bd.bookdelete(id))
				cout << "ɾ���ɹ���" << endl;
			else
				cout << "ɾ��ʧ�ܣ�" << endl;
		}
		else cout << "��ͼ����δ�黹���޷�ɾ����" << endl;
	}
}