#pragma once
#include<iostream>
#include<string>

using namespace std;

class supervisor {

public:
	supervisor() { ; }

	//����Ա��½���� ID��123 ���룺admin
	bool login(int id, string password);

	//�û�������
	string DisplayUser(int id);//�����û�������Ϣ�ַ�������ȡ����������Ѷ�ĵ��ṩ
	string DisplayUserBookid(int id);//�����û�������Ϣ�ַ�������ȡÿ6λΪһ��bookid
	bool createuser(int id, string name, string password, string college,string major, string email);//�������û�
	bool deleteuser(int id);//ɾ���û���Ϣ
	bool modifyuserName(int id, string name);//�޸��û�����
	bool modifyuserCollege(int id, string college);//�޸��û�ѧУ
	bool modifyuserMajor(int id, string major);//�޸��û�רҵ
	bool modifyuserEmail(int id, string email);//�޸��û�����
	bool modifyuserPassword(int id, string password);//�޸��û�����
	
	//ͼ�������
	string DisplayBook(int id);//չʾͼ����Ϣ�������ַ���
	bool createbook(int id, string ISBN, string name, string author, string type);//������ͼ��
	bool deletebook(int id);//ɾ��ͼ��
	bool modifybookISBN(int id, string ISBN);//�޸�ͼ���ISBN
	bool modifybookName(int id, string name);//�޸�ͼ�������
	bool modifybookAuthor(int id, string author);//�޸�ͼ�������
	bool modifybookType(int id, string type);//�޸�ͼ��ķ���
	bool modifybookOnsheelf(int id, string onsheelf);//�޸�ͼ����ڼ�״̬
	bool modifybookIsovertime(int id, string isovertime);//�޸�ͼ��ĳ���״̬
	
	string dataformatting(int n, string data);//������亯�������Ϻ������е��ã���Ҫ����
};