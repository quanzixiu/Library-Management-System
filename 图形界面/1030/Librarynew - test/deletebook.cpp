#include "bookdocking.h"
#include "supervisor.h"
#include <string>

//ɾ��ͼ��
//�߼��㺯�����ƣ�ɾ��ͼ�� deletebook()
//���õײ㺯����bookdelete(string id)
//�ײ㺯������ֵ��bool
bool supervisor::deletebook(int id) {
	bookdocking docking;
	string value;
	if (!docking.bookexist(id)) return false;
	else {
		value = docking.booksearch(id);
		if (value.substr(78, 1) == "1")//�����ͼ���ڼ�
		{
			if (docking.bookdelete(id))
				return true;
			else
				return false;
		}
		else return false;
	}
}