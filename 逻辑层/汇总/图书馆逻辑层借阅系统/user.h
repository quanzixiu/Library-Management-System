#pragma once
#include <string>
using namespace std;
class user
{

	private:

		int id; //学号

		string name; //姓名

		string college; //学院
		string password;
		string major;
		string email;

	public:

		//student *next;

		/*friend ostream& operator <<(ostream& out, user& b);

		friend istream& operator >>(ostream& in, user& b);*/

		//以下两个函数的形式不是完全确定

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




				//以下get方法为获取用户相关参数

		int getid() { return id; }

		string getname() { return name; }


		string getcollege() { return college; }

		string getpassword() { return password; }

		string getmajor() { return major; }

		string getemail() { return email; }
		//以下set方法为设置用户相关参数
		void setpassword(string password) { user::password = password; }

		void setid(int id) { user::id = id; }

		void setname(string name) { user::name = name; }

		void setcollege(string college) { user::college = college; }

		void setmajor(string major) { user::major = major; }


		void setemail(string email) { user::email = email; }

};

