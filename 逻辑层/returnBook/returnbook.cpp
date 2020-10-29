#include<iostream>
#include<string>
#include <sstream>
#include <iomanip>
#include <chrono>
#include"returnbook.h"
#include"../BookDocking/BookDocking/bookdocking.h"
#include"../UserstatesDocking/UserstatesDocking/userstatesdocking.h"
using namespace std;


void returnbook::returnBook() {
	bookdocking docking;
	userstatesdocking usdocking;
	int id;
	int userid;
	char c[10];
	string bookid;
	string value;
	string onsheelf;
	string lastHistory;

	cout << "������Ҫ�黹ͼ���ID��";
	cin >> id;
	if (!docking.bookexist(id))
		cout << "��ͼ�鲻���ڣ�";
	else
	{
		value = docking.booksearch(id);
		onsheelf = value.substr(58, 1);
		if (onsheelf == "1")
			cout << "��ͼ���ѹ黹��";
		else
		{
			/* ȱ���ж��Ƿ��ڵ���غ������ݣ��Ա�borrowtime��returntime���޸�isovertime*/

			//�޸�ͼ����Ϣ
			if (docking.bookmodifyonsheelf(id, "1"))
			{
				//��ͼ�����ӹ黹ʱ��

				auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
				std::stringstream ss;//תΪ�ַ���

				// ���Էֱ��Բ�ͬ����ʽ������ʾ
				ss << std::put_time(std::localtime(&t), "%Y-%m-%d-%H-%M-%S");
				//ss << std::put_time(std::localtime(&t), "%Y��%m��%d��%Hʱ%M��%S��");
				//ss << std::put_time(std::localtime(&t), "%Y%m%d%H%M%S");

				std::string str_time = ss.str();

				docking.bookmodifyreturntime(id, str_time);

				

				//�޸��û�������Ϣ
				lastHistory = value.substr(70, 4);//���һ��������û�id(string)
				userid = atoi(lastHistory.c_str());//stringת����int
				bookid = std::to_string(id);//�����ͼ��id intת����string
				if (usdocking.usdelete(userid, bookid))
					cout << "����ɹ���";
				else
					cout << "����ʧ�ܣ�";
			}
			else
				cout << "����ʧ�ܣ�";
		}	
	}
}