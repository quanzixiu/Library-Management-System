#include "bookdocking.h"
#include "supervisor.h"

//����ͼ���Ƿ����
//�߼��㺯�����ƣ���ͼ���Ƿ��Ѿ����� existbook()
//���õײ㺯����bookexist(string id)
//�ײ㺯������ֵ��bool
bool supervisor::existbook(int id) {
	bookdocking docking;
	if (docking.bookexist(id)) return true;
	else return false;
}