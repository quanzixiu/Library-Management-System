#pragma once
#include <string>
using namespace std;
class user
{

	private:

		int id; //ѧ��

		string name; //����

		string college; //ѧԺ
		string password;
		string major;
		string email;

	public:

		//student *next;

		/*friend ostream& operator <<(ostream& out, user& b);

		friend istream& operator >>(ostream& in, user& b);*/

		//����������������ʽ������ȫȷ��

		~user() {}
		user() 
		{
			id = 0;
			name = "123";
			college = "1213";
			password = "0";
			major = "0";
			email = "0";
		}




				//����get����Ϊ��ȡ�û���ز���

		int getid() { return id; }

		string getname() { return name; }


		string getcollege() { return college; }

		string getpassword() { return password; }

		string getmajor() { return major; }

		string getemail() { return email; }
		//����set����Ϊ�����û���ز���
		void setpassword(string password) { user::password = password; }

		void setid(int id) { user::id = id; }

		void setname(string name) { user::name = name; }

		void setcollege(string college) { user::college = college; }

		void setmajor(string major) { user::major = major; }


		void setemail(string email) { user::email = email; }

};

