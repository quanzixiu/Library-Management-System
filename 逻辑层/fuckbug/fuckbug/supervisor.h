#pragma once
#include<iostream>
#include<string>

using namespace std;

class supervisor {

public:
	bool slogin();//����Ա��¼;
	void searchuser();//�����û�
	void createuser();//�������û�
	void modifyuserdata();//�޸��û�������Ϣ
	void deleteuser();//ɾ���û�

	supervisor() { ; }

	void createbook();//������ͼ��
	void modifybook();//�޸�ͼ����Ϣ
	void deletebook();//ɾ��ͼ��

	void manageuser();//�û�������棬�������������û�������
	void managebook();//ͼ�������棬��������ͼ�������
	string dataformatting(int n, string data);
};