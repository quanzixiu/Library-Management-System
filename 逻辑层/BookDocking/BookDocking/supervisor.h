#include<iostream>
#include<string>
#include"user.h"
#include"book.h"
#include"userstates.h"

using namespace std;

class supervisor {

public:

	bool createuser();//�������û�
	bool modifyuserdata(int id);//�޸��û�������Ϣ
	bool deleteuser(int id);//ɾ���û�
	bool existuser(int id);//�����û��Ƿ��Ѿ�����

	supervisor() { ; }

	bool createbook();//������ͼ��
	void modifybook();//�޸�ͼ����Ϣ
	bool deletebook();//ɾ��ͼ��
	bool existbook(int id);//����ͼ���Ƿ����

	void manageuser();//�û�������棬�������������û�������
	void managebook();//ͼ�������棬��������ͼ�������
};
